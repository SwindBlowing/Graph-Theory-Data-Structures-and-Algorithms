# Lab 9 - 异常

本次我们需要实现对异常的支持，在`include/Exceptions/GLException`中已经定义了`GLException`(其实现也已在`source/Exceptions/GLException.cpp`中给出)，**请在`include/Exceptions`中定义`NegativeCycleException`**，并继承自`GLException`。

## 不符合规约的情况

在以前的lab中，我们使用过`static_assert`来检查传入的模板参数是否符合某些约束条件（C++20中将引入concept以简化代码写法），以此在编译期拒绝掉不符合规约的情况。

然而，有一些不符合规约的情况，是难以或者无法在编译期检查出来的。此时，我们就要利用异常。

我们前两次实现的Bellman Ford和Floyd都是这样的例子。如果输入的图中存在负环（在Bellman-Ford中只需要检查从起点可达的负环即可），那么算法的更新就无法停止或者返回的结果没有意义。

所以，我们要以前的代码，在检测到这种情况时，通过`throw`抛出一个类型为`NegativeCycleException`或其子类的异常。

由于负环难以定义，所以抛出的异常中不需要包含负环。但为了方便潜在的用户debug，异常中需包含当前正在运行的算法名（分别是`Bellman-Ford`和`Floyd`）。（这样，如果用户在运行一个非常复杂的算法时遇到异常，他就可以通过异常中的信息，确定异常发生在哪个函数的内部）

你throw的异常的结构体里可以包含任意你觉得可能有助于debug的信息，我们只会通过`operator<<(std::ostream&, const GLException&)`对结果进行评判，因此你要确保`cout`的输出结果只包含算法名。

评判方式类似于：

```c++
try {
    // 建图、跑算法
} catch(const NegativeException& e) {
    cout << e;
}
```

所以，如果运行的是Bellman-Ford算法，你要确保`cout`打印出的值为`Bellman-Ford`；如果运行的是Floyd算法，你要确保`cout`打印出的值为`Floyd`（都不包含回车或括号）。

### 浮点误差

如果`TValue`都是整型，那么没有什么难度。但实际上，`TValue`可能是浮点数，那就有可能导致判断时发生误判。

这个问题比较难，因此这里直接给出解决方案。

我们在比较误差时，可以采用一个模板$\epsilon$：

```c++
template<typename TValue>
TValue epsilon();
```

我们希望，当`TValue`是浮点数时，epsilon返回`1e-6`，其他情况，则返回`TValue()`。

如何判断`TValue`是不是浮点数呢？我们可以用到`<type_traits>`里的`is_floating_point`。

`is_floating_point<TValue>()`是一个特殊的函数，当`TValue`是浮点数时，返回值的类型是`true_type`，否则，则是`false_type`。

`true_type`和`false_type`是什么呢？

还记得我们在讲迭代器的时候，讲到迭代器有一个tag域，用来表示自己是什么样的迭代器，进而使用不同的函数调用吗？

`true_type`和`false_type`也是类似的！

既然`is_floating_point<TValue>`的返回类型会根据`TValue`的类型而变，那么，我们就可以写出这样的实现

```c++
template<typename TValue>
TValue epsilon() {
    return epsilon_real<TValue>(std::is_floating_point<TValue>());
}
```

然后，把两种情况的`epsilon_real`（偏特化模板）分别实现：

```c++
template<typename TValue>
TValue epsilon_real(std::true_type) {
    return 1e-6;
}

template<typename TValue>
TValue epsilon_real(std::false_type) {
    return TValue();
}
```

而`epsilon`函数的调用，就是简单的`epsilon<TValue>()`。
