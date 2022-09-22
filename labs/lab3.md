# Lab3 - 虚函数

请实现下面两个类：

- `DataStructures/UndirectedGraph.h`中定义`UndirectedGraph`类表示无向无权图，无向无权图的所有接口和有向无权图（`Graph`类）完全相同（使用继承）
- `DataStructures/UndirectedWeightedGraph.h`中定义`UndirectedWeightedGraph`类表示无向有权图，无向有权图的所有接口和有向有权图（`WeightedGraph`类）完全相同（使用继承）
- 请在`source/DataStructures`中创建对应cpp文件，实现各种接口
- 请使用继承和虚函数，否则无法通过测试

这两个类的所有需要实现的接口都和父类相同，也就是说**最优情况**下只需要将`AddEdge`、`RemoveEdge`等方法进行重写（或重定义）即可，具体如何实现这些类由你自己决定，最坏情况下复制粘贴已有的代码也能通过测试（能AC的代码就是好代码）。

对一些可能存在歧义的函数我们做出如下约定：

1. 无向图中所有边虽然使用了有向图的数据结构，但是所有边都是没有方向的，也就是说`AddEdge(1, 2)`可以看作是添加了两条有向边，之后执行`AddEdge(2, 1)`时`2->1`这条边已经存在，应该返回`false`。
2. `CountEdges`返回的是无向边的数量。
3. `GetEdges`中，每条无向边可以以任意方向表示，但是不能出现重边（也就是说可以是`{{1, 2}}`，也可以是`{{2, 1}}`，但不能是`{{1, 2}, {2, 1}}`这样的结果）。
4. `GetDegree`中，自环对度数的贡献是2（无向图中所有点的度数之和等于边数的两倍）。
5. 小心特殊情况（无向图中的自环）。

测试时，会测试目前为止的四个所有的类：

1. `Graph`类和`WeightedGraph`类是前两次实验已经实现好了的类，你的新代码不能破坏这两个类的功能；
2. `UndirectedGraph`类和`UndirectedWeightedGraph`类是本次实验需要新添加的类，他们的所有接口都和有向图版本相同。

## 测试数据

|ID|图的大小|用到的接口|
|:-:|:-:|:-:|
|1-2|3|`AddVertex`, `AddEdge`, `RemoveEdge`, `CountEdges`, `ContainsEdge`|
|3|800|`AddVertex`, `AddEdge`, `RemoveEdge`, `CountVertices`, `CountEdges` `ContainsEdge`|
|4|800|`AddVertex`, `AddEdge`, `GetIncomingEdges`, `GetOutgoingEdges`|
|5|800|`AddVertex`, `AddEdge`, `GetDegree`, `GetNeighbors`|
|6|800|`AddVertex`, `AddEdge`, `ContainsEdge`, `GetWeight`（仅限有权图）|

---

## 拓展设计

如果你感兴趣的话，可以研究一下这种由于C++不存在接口类型但却允许多继承的奇怪机制*导致的奇怪又糟糕继承关系是如何实现的：

```
        UnweightedGeneric ------------->+<---------------- WeightedGeneric<T>
                ^                       |                          ^
                |                       |                          |
                |                       v                          |
              Graph -------------> Generic<T> <------------ WeightedGraph<T>
                ^                       ^                          ^
                |                       |                          |
                |                       |                          |
         UndirectedGraph -----> UndirectedGeneric <---- UndirectedWeightedGraph<T>
```

注：

1. 奇怪机制的意思是，如果C类同时继承了抽象类A和A的某一种实现B，由于C直接继承A，即使从B那里获得了这些纯虚函数的具体实现，由于他们是同名函数，所有的函数都被重写了，就导致(1)出现二义性，编译器不知道应该调用谁；或者(2)编译器认为纯虚函数没有被实现，C是一个纯虚类。（可以参考[这个Stackoverflow问题](https://stackoverflow.com/questions/29288295/c-abstract-class-implementation-in-another-base-class)）。
2. 这个设计出现了不可避免的菱形继承问题，使用了大量的虚继承。