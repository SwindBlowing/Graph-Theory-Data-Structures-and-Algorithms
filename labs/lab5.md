# Lab 5 - 静态方法

本次需要大家实现BFS和DFS来遍历图上的所有点。

你需要实现两个**模板类**（头文件已给出）：

- `Algorithms/BreadthFirstSearcher`表示宽度优先搜索类
- `Algorithms/DepthFirstSearcher`表示深度优先搜索类

这两个类具有两个完全相同的接口：

- `void VisitAllVertices(const TGraph *graph, int start, const std::function<void(int)> &action)`表示从起点开始按照宽度优先或深度优先的方式遍历所有的点，并在每个点上调用`action`操作
- `std::optional<int> FindFirstVertex(const TGraph *graph, int start, const std::function<bool(int)> &predicate)`表示从起点开始按照宽度优先或深度优先的方式遍历所有的点，并找到第一个满足谓词`predicate`的点的编号。由于可能不存在这样的点，所以我们用`std::optional<int>`作为返回值类型，显示表明其可能为空。如果找到了，返回包含这个点编号的optional容器，否则，返回空容器。
- 对于每一个点，先调用它本身的`action`或`predicate`，然后再遍历其他的点
- 遍历可能从不存在的点开始，对于这种情况，第一个方法什么都不做，第二个方法直接返回空值
- 特别的，对于有权图，宽度/深度优先的定义和无权图是一致的，**不需要考虑边的权重**，不需要用优先队列

其中`std::optional`是C++17的新特性，用于存储某个可选的数值，特别用于处理某个值可能不存在的情况。你只需要通过阅读C++手册了解构造`std::optional<T>`对象的用法即可。

我们会按照如下方式测试你的代码：

- 四种图可能随机出现
- BFS遍历所有点必须是按照点的深度进行遍历的
- DFS遍历所有点必须是一种合法的深度优先搜索序列
- BFS找到的第一个符合谓词的点必须是深度最小的（可能有多个，任意一个都是正确的）
- DFS找到的第一个符合谓词的点没有任何要求，只要找到或者返回不存在就行了