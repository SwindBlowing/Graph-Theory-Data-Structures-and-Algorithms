# Lab 7 - 初探模板元编程

本次实验我们需要利用模板元编程中的一些奇技淫巧，来完成上次的思考题二。

## 更简洁的模板声明

你需要将`ShortestPaths`和`DijkstraShortestPaths`的模板声明变为

```c++
template<typename TGraph>
class ShortestPaths {
    // ...
};
```

修改过后，之前的调用代码需要进行相应的修改：

```diff
- *p = new DijkstraShortestPaths<WeightedGraph, int>(g, 1);
+ *p = new DijkstraShortestPaths<WeightedGraph<int>>(g, 1);
```

在只有`TGraph`一个模板参数的情况下，如何取得`TValue`呢？（请自行查阅`traits`或`萃取`的相关内容）

（注：要完成本实验，你大概率需要修改图部分的代码）

## 更友好的报错

在上次我们说到，`ShortestsPaths`中的`TValue`有默认构造函数、`operator+`和各种比较运算符。
然而，如果用户一不小心传了一个不支持的类型（比如没有`operator+`的`std::pair<int, int>`），
程序不仅没法编译，还会打印出一大串报错信息。（相信你们初学C++的时候，也一定遇到过类似的事，被满屏的报错信息淹没）

所以，我们可以让我们的库更加用户友好，我们可以让我们的代码在传入的`TGraph`对应的边权类型不满足条件时打印出适当的报错信息。需要注意的是，只有`ShortestsPaths`及其子类的`TValue`需要具有该性质，用户仍然可以创建`WeightedGraph<pair<int, int> >`。

由于模板元编程难度较大，此处我们仅要求完成下述错误类型中第一项的检查，其他内容感兴趣的同学可以自行尝试。

请自行查阅C++手册中[static_assert](https://en.cppreference.com/w/cpp/language/static_assert) 页面。（不一定要用`static_assert`，只要编译器编译时遇到错误且报错中包含对应的报错信息即可，我们会在g++的stderr输出中进行匹配。）

| 错误类型                 | 报错信息                            |
| ------------------------ | ----------------------------------- |
| `TValue`没有默认构造函数 | TValue requires default constructor |
| `TValue`没有`operator+`  | TValue requires operator+           |
| `TGraph`不是有权图       | TGraph should be weighted           |

## Bellman-Ford 算法

本次，你还需要实现Bellman-Ford单源最短路算法，请创建`include/Algorithms/BellmanFordShortestPaths.h`并定义：

```C++
template<typename TGraph>
class BellmanFordShortestPaths : ShortestPaths<TGraph> {
    //...
};
```

各接口与`ShortestPaths`保持一致。

## 测试说明

本次的测试继承了上次的测试，修改了其中最短路相关的模板参数，并增加了较严格的模板的检查、报错信息相关测试及Bellman-Ford相关测试。

本次测试保证，不含有从起点出发可达的负权环。（对于无向图，不含负权环等价于不含负权边）。