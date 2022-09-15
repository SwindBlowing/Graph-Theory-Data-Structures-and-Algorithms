# Lab2 - 继承

本次实验我们需要实现`WeightedGraph`类表示有权图。你需要完成以下任务：

1. 创建`include/DataStructures/WeightedEdge.h`和`include/DataStructures/WeightedGraph.h`头文件
2. 在`WeightedEdge.h`中定义`WeightedEdge`类并实现各种接口
3. 在`WeightedGraph.h`中定义`WeightedGraph`类并实现各种接口

## Step 1 - 实现`WeightedEdge`

`WeightedEdge`类表示带有`int`类型权重的有向边，它具有构造函数、析构函数和三个接口：

- `WeightedEdge(int source, int destination, int weight)`：构造一条起点为`source`、终点为`destination`、权重为`weight`的边对象
- `~WeightedEdge()`：销毁这条边
- `int GetSource() const`：获取起点编号
- `int GetDestination() const`：获取终点编号
- `int GetWeight() const`：获取边的权重

提示：

1. `WeightedEdge`与Task1实现的`Edge`相比，只是多了一个新的权重属性，因此我们可以通过继承`Edge`类，继承后`WeightedEdge`就已经具有了并实现基类所没有的接口来实现。

## Step 2 - 实现`WeightedGraph`

`WeightedGraph`类表示带有`int`类型权重的有向边构成的有向图，它具有构造函数、析构函数和十五个接口：

- `WeightedGraph()`
- `~WeightedGraph()`
- `bool AddVertex(int vertex)`
- `bool RemoveVertex(int vertex)`
- `bool AddEdge(int vertex1, int vertex2, int weight)`：添加了权重参数
- `bool RemoveEdge(int vertex1, int vertex2)`
- `int CountVertices() const`
- `int CountEdges() const`
- `bool ContainsVertex(int vertex) const`
- `bool ContainsEdge(int vertex1, int vertex2) const`
- `int GetWeight(int vertex1, int vertex2) const`：查询`v1`指向`v2`的边的权重，如果这条边不存在则属于UB
- `std::vector<int> GetVertices() const`
- `std::vector<WeightedEdge> GetEdges() const`
- `std::vector<WeightedEdge> GetIncomingEdges(int vertex) const`
- `std::vector<WeightedEdge> GetOutgoingEdges(int vertex) const`
- `int GetDegree(int vertex) const`
- `std::vector<int> GetNeighbors(int vertex) const`

提示：

1. 除构造函数、析构函数外，有十五个接口，其中有十三个的含义是和无权重有向图`Graph`完全一致的
2. 这十三个接口中，有3个接口，其返回类型与`Graph`不一致
3. 请注意务必在`WeightedGraph.h`中引入（include）`WeightedEdge.h`文件，否则在正式评测中可能会发生错误