# Lab 8 - 多源最短路

本次我们需要完成Floyd多源最短路算法，**请在`Algorithms/FloydShortestPaths.h`中定义模板类`FloydShortestPaths`**。在`Algorithms/MultiSourceShortestPaths.h`中定义了一个多源最短路基类，你的实现需要继承这个基类。
（注：由于从`TGraph`中萃取出`TValue`的做法因人而异，因此`MultiSourceShortestPaths`的定义中略去了，你需要补上才能正确编译）

多源最短路类是一个模板类，接受一个参数`TGraph`表示图的类型，保证只会出现`WeightedGraph<TValue>`和`UndirectedWeightedGraph<TValue>`。（其中，`TValue`是权重的类型，保证它有默认构造函数，`operator+`和比较运算符，且默认构造函数返回的是`operator+`下的幺元。此外你还需要特别注意的是`operator+`未必满足交换律，因此你进行松弛的时候计算新的距离必须是已有距离加上边的权重，如果反过来加会导致错误。）

这个模板类具有以下成员：

1. 构造函数和析构函数
   - 构造函数接受一个指向对应类型图的指针
   - 析构函数是一个虚函数，负责释放申请的资源（注意不能删除图，因为图的生命周期显然超过这个类的对象）
2. `bool HasPathOf(int, int)`：返回从起点开始是否存在一条到达终点的路径。
3. `std::optional<TValue> TryGetDistanceOf(int, int)`：返回从起点到达终点的最短路径权重，如果不存在路径返回空，起点的距离定义为`TValue`类型的默认值`TValue()`（例如`int()`表示0）。
4. `std::optional<std::vector<int>> TryGetShortestPathOf(int, int)`：返回从起点到达终点的一条最短路径上所有点的编号（包含起点和终点），如果不存在返回空，如果存在多条返回任意一条。

本次的测试仍保证不存在负环。