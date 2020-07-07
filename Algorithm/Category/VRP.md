#  VRP--数学模型

一个典型的VRP模型可以用回路来表示，也可以把时间、路程、花费等转化为运输成本来表示，其基本原理是相同的，这里我们使用回路表示法。

### 基本条件

现有$n$辆相同的车辆停在一个共同的源点（也就是物流中心）$O$，它需要给$m$个顾客提供货物。假设顾客为$a_1,a_2,...,a_m$，并且原点和顾客的位置是已知的。

### 模型目标

确定所需要的车辆数目$N$，并且指派这些车辆到一个回路中，同时包括回路内的路径安排和调度，使得运输的总距离$S$最小。

### 约束条件

1. $N \leq n$
2. 用$Q_{ij}$表示第$i$辆车在其子回路上对应的第$j$个客户的需求量。由于前面的假设条件，客户需求数量$Q_{ij}$较小，故客户的需求量不可能超过车的载重量。因此，设每个客户同一时刻只能接受一辆车的服务。一个子回路对应一辆车，设每条回路上的客户数为$l$，$i$为车辆对应的编号，由集合$c_i$表示第$i$辆车对应的路径，$c_{ij}$表示第$i$辆车对应的子回路顺序为$j$的客户点。如果$l_i=0$，则表示该车没有参加服务。由此可知$\sum^{n}_{i=1} l_i=m$。
3. 车辆完成任务后都要回到源点$a_0$。
4. 车辆不能超过最大载重量$W_i$和最大行驶长度$L_i$的限制。

### 数学模型

假设$d_{i(j-1)j}$表示第$i$辆车对应的路线中顺序排列的第$j-1$个客户与第$j$个客户之间的距离；$d_{i(l_{i})}$表示第$i$辆车对应的路线中第$l_i$个客户与源点之间的距离。由此可以建立以下的数学模型：
$$
\begin{align}
&\min s = \sum _ { i = 1 } ^ { N } \left[ \sum _ { j = 1 } ^ { l _ { i } } d _ { i ( j - 1 ) j } + d _ { i \left( l _ { i } \right)  } \cdot \operatorname { sign } \left( l _ { i } \right) \right]&(1)\\
s.t.&\sum _ { j = 1 } ^ { l _ { k } } Q _ { i j } \leq w _ { i }&(2)\\\\
& \sum _ { j = 1 } ^ { l _ { i } } d _ { i ( j - 1 ) j } + d _ { i \left( l _ { i } \right) } \cdot \operatorname { sign } \left( l _ { i } \right) \leq L _ { i }&(3)\\\\
& 0 \leq l _ { i } \leq m&(4)\\\\
& \sum _ { i = 1 } ^ { N } l _ { i } = m&(5)\\\\
& c _ { i } = \left\{ c _ { i j } | c _ { i j } \in \left\{ v _ { 1 } , v _ { 2 } , \ldots , v _ { n } \right\} , j = 1,2 , \dots , l _ { i } \right\}&(6)\\\\
& c _ { i } \cap c _ { j } = \empty , \forall i \neq j&(7)\\\\
& \operatorname { sign } \left( l _ { i } \right) = \left\{ \begin{array} { l } { 1 , l _ { i } \geq 1 } \\ { 0 , \text { others } } \end{array} \right.&(8)\\\\
& N \leq n&(9)
\end{align}
$$
(1)为目标函数，即：使车辆在完成配送任务时的总运行距离最短。
(2)为车辆的能力约束，即每个子回路中客户的需求总量不超过车辆的最大载重量，保证某辆车所访问的全部客户的需求量不能超过车辆本身的载重量。
(3)表示每个子回路中车辆的运行长度不超过其最大行驶里程。
(4)表示每辆车对应的客户数不超过总的客户数。
(5)表示所有参与运行的车，其所服务的客户总数与实际的客户数相等，即保证每个客户都得到服务。
(6)表示每辆车服务的对应客户集合。
(7)表示每个客户在同一时刻只能由一辆车来进行服务。
(8)表示第$i$辆车是否参与服务。
(9)表示不超过所提供的最大车辆数的限制。
$$
\begin{align}
&\min s = \sum _ { i = 1 } ^ { N } \left[ \sum _ { j = 1 } ^ { l _ { i } } d _ { i ( j - 1 ) j } + d _ { i \left( l _ { i } \right)  } \cdot \operatorname { sign } \left( l _ { i } \right) \right]&(1)\\
s.t.&\sum _ { j = 1 } ^ { l _ { k } } Q _ { i j } \leq w _ { i }&(2)\\\
& 0 \leq l _ { i } \leq m&(3)\\\\
& \sum _ { i = 1 } ^ { N } l _ { i } = m&(4)\\\\
& c _ { i } = \left\{ c _ { i j } | c _ { i j } \in \left\{ v _ { 1 } , v _ { 2 } , \ldots , v _ { n } \right\} , j = 1,2 , \dots , l _ { i } \right\}&(5)\\\\
& c _ { i } \cap c _ { j } = \empty , \forall i \neq j&(6)\\\\
& \operatorname { sign } \left( l _ { i } \right) = \left\{ \begin{array} { l } { 1 , l _ { i } \geq 1 } \\ { 0 , \text { others } } \end{array} \right.&(7)\\\\
& N \leq n&(8)
\end{align}
$$

### Reference

[1] 贾楠 吕永波 付蓬勃 任远.物流配送中VRP的数学模型及其求解算法（Mathematical Model and Arithmetic of VRP in Physical Distribution Routing）[J].物流技术，2007，(26)：54-56

[2]master苏.ortools系列：VRP问题[DB/OL].https://zhuanlan.zhihu.com/p/55868067，2019-01-30/2019-6-6