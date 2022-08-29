# lab0 - 熟悉实验环境（不计分）

为了帮助大家熟悉实验环境，我们节选了`lab1`的一小部分，并去掉了思考题，放入`lab0`。当然，你可以选择忽略此次试验，等`lab1`发布再一起完成。

本次实验我们需要实现一个类：

- `Edge`：有向边

你不能修改给定的接口，但可以随意决定类的内部实现（类有哪些数据成员、类有哪些其他的接口、这些接口都是怎么实现的等等）。评测时，会使用默认的配置文件进行编译。

## `Edge`

`Edge`类表示有向边，它具有构造函数、析构函数和两个接口：

- `Edge(int source, int destination)`：构造一条起点为`source`、终点为`destination`的边对象
- `~Edge()`：销毁这条边
- `int GetSource() const`：获取起点编号
- `int GetDestination() const`：获取终点编号

用例：

```c++
Edge e(1, 2); // 创建一条1指向2的有向边
assert(e.GetSource() == 1);
assert(e.GetDestination() == 2);
```