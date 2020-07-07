# Multivariate Analysis

## 微分

### 多元函数的极限与连续性

首先，要掌握定义，会用定义来证明某极限存在。

其次，要理解，在讨论单变量函数的极限时，变动的自变量总是在过一个点的线段的左右两侧变化，因此两个单侧极限在在且相等就足保证极限的存在，但在多变量极限的情形，函数定义域$D$中的点向它的一个凝聚点趋近可以有各种不同的途径，可以是沿着种种不同的直线方向的，也可以是通过曲线路径去趋近的因此，情况变得异常复杂，所幸的是，函数极限可以转化为数列极限来研究。可取任意多组趋于凝聚点的点列，求取对于点列而言的数列极限，若存在不等的情况，则极限不存在。

最后，可以使用夹逼、等量代换、极坐标换元、等价无穷小等方法解题。

## 偏导数和全微分

偏导数简单，可以理解为寻求主元求单元导数。

> 全微分：设二元函数$z=f(x,y)$在某点$(x_0,y_0)$的某个邻域$N(x_0,y_0)$内有定义。如果对于$(x_0+\Delta x,y_0+\Delta y)\in N(x_0,y_0)$，函数$f$在$(x_0,y_0)$处有全增量
> $$
> \Delta z=f(x_0+\Delta x,y_0+\Delta y)-f(x_0,y_0)
> $$
> 可以表示为
> $$
> \Delta z=\alpha\Delta x+\beta\Delta y+o(\rho)
> $$
> 其中$\alpha,\beta$是与$\Delta x,\Delta y$无关的常数，$\rho =||(\Delta x ,\Delta y)||=\sqrt{(\Delta x)^2+(\Delta y)^2}$，则称$f$在$(x_0,y_0)$处可微，并称$\alpha\Delta x+\beta\Delta y$是$f$在$(x_0,y_0)$点的全微分，记为$ df\big|_{(x_0,y_0)}$。
>
> 由全微分的定义容易看出
> $$
> f _ { x } \left( x _ { 0 } , y _ { 0 } \right) = \lim _ { \Delta x \rightarrow 0 } \frac { f \left( x _ { 0 } + \Delta x , y _ { 0 } \right) - f \left( x _ { 0 } , y _ { 0 } \right) } { \Delta x } = \lim _ { a x \rightarrow 0 } \frac { \alpha \Delta x + o \sqrt { \Delta x ^ { 2 } } } { \Delta x } = \alpha
> $$
> 同理有$f_y=\beta$。可以看出可微则偏导数一定存在。但偏导数存在不一定可微。

**例**：证明函数
$$
f(x,y)=\begin{cases}
\frac{x^2y}{x^2+y^2}&x^2+y^2\ne0
\\
0&x^2+y^2=0
\end{cases}
$$
在原点有偏导数但不可微。

**证明**：

易得
$$
f_x(0,0)=\lim_{\Delta x\rightarrow0}\frac{f(0+\Delta x,0)-f(0,0)}{\Delta x}=0\\
f_y(0,0)=\lim_{\Delta y\rightarrow0}\frac{f(0,0+\Delta y)-f(0,0)}{\Delta y}=0
$$
即原函数在原点两个偏导数都存在。

假设原函数在原点可微，则有
$$
\Delta f=df+o(\rho)=f_x(0,0)\Delta x+f_y(0,0)\Delta y+o(\rho)=o(\rho)
$$
所以理应有
$$
\lim_{\rho\rightarrow0}\frac{\Delta f}{\rho}=0
$$
而
$$
\Delta f=f(0+\Delta x,0+\Delta y)-f(0,0)=\frac{\Delta x^2 \Delta y}{ \Delta x^2+\Delta y^2}
$$
故有
$$
\lim_{\rho\rightarrow0}\frac{\Delta f}{\rho}=\lim_{\rho\rightarrow0}\frac{\Delta x^2 \Delta y}{(\Delta x^2+\Delta y^2)^\frac{3}{2}}
$$
这个极限是不存在的，因此不可能等于$0$，故原函数在原点不可微。

>偏导数和可微的关系：
>
>若函数的偏导数在某点的某个邻域内均存在，且至多存在一个偏导数在该点不连续，那么函数在该点可微。
>
>这里存在加强推论：
>
>若函数的偏导数在某点的某个邻域内均存在，且所有的偏导数都在该点连续，那么函数在该点可微。
>
>但反过来不一定。

**例**：证明函数
$$
f(x,y)=\begin{cases}
(x^2+y^2)\sin \frac{1}{x^2+y^2}&x^2+y^2\ne0
\\
0&x^2+y^2=0
\end{cases}
$$
在原点可微，但$f_x,f_y$在原点间断。

**证明**：

易求得$f_x(0,0)=f_y(0,0)=0$，故
$$
\Delta f-f_x(0,0)\Delta x-f_y(0,0)\Delta y=f(\Delta x,\Delta y)-f(0,0)=(\Delta x^2+\Delta y^2)\sin \frac{1}{\Delta x^2+\Delta y^2}=(\rho^2)\sin \frac{1}{\rho^2}=o(\rho)
$$
即在原点可微，

当$x^2+y^2\ne0$时，
$$
f_x=2x\sin\frac{1}{x^2+y^2}-\frac{2x}{x^2+y^2}\cos \frac{1}{x^2+y^2}\\
f_y=2y\sin\frac{1}{x^2+y^2}-\frac{2y}{x^2+y^2}\cos \frac{1}{x^2+y^2}\\
$$
显然有$\lim_{(x,y)\rightarrow(0,0)}f_x$和$\lim_{(x,y)\rightarrow(0,0)}f_y$不存在。

> 综上，我们有如下关系：
>
> 1. 可微$\Rightarrow$连续，偏导数存在
> 2. 偏导数存在且至多有一个不连续$\Rightarrow$可微

### 高阶导数

对于函数$f(x_1,x_2,\dots,x_n)$一阶偏导数共有$n$个，而相对应的二阶偏导数就迅速增长到了$n

^2$个，再往高阶增长数量爆炸。

**例1：**

$f(x,y)=e^{2x+y}$的一阶二阶偏导数如下
$$
\frac{\partial f}{\partial x}=2e^{2x+y}\ \frac{\partial f}{\partial y}=e^{2x+y}
\\
\frac{\partial^2 f}{\partial^2 x}=4e^{2x+y} \ \frac{\partial^2 f}{\partial y \partial x}=2e^{2x+y} \ \frac{\partial^2 f}{\partial x \partial y}=2e^{2x+y} \ \frac{\partial^2 f}{\partial^2 y}=e^{2x+y}
$$
显然我们会下意识地去认为混合偏导数$\frac{\partial^2 f}{\partial x\partial y}=\frac{\partial^2 f}{\partial y\partial x}$成立，这种错觉来源于上述极佳的例子，$f(x,y)=e^{2x+y}$所具备太多优秀的性质，下面给出反例

**例2：**

给出以下函数
$$
f(x, y)=\begin{cases}{x y \frac{x^{2}-y^{2}}{x^{2}+y^{2}}} & {(x^2+y^2>0)}\\ {0}&  {(x^2+y^2=0)}\end{cases}
$$
我们来讨论一下其一阶及二阶混合偏导数

$(1)x^2+y^2>0$
$$
\begin{aligned}{\frac{\partial f(x, y)}{\partial x}=\frac{y\left(x^{4}+4 x^{2} y^{2}-y^{4}\right)}{\left(x^{2}+y^{2}\right)^{2}}} \\{\frac{\partial f(x, y)}{\partial y}=\frac{x\left(x^{4}-4 x^{2} y^{2}-y^{4}\right)}{\left(x^{2}+y^{2}\right)^{2}}}\end{aligned}
$$
$(2)x^2+y^2=0$
$$
\begin{aligned} \frac{\partial f(0,0)}{\partial x} =\lim _{x \rightarrow 0} \frac{f(x, 0)-f(0,0)}{x}=0 \\ \frac{\partial f(0,0)}{\partial y} =\lim _{y \rightarrow 0} \frac{f(0, y)-f(0,0)}{y}=0 \end{aligned}
$$
因此在$(0,0)$处的混合偏导数如下
$$
\begin{aligned}
\frac{\partial^2 f}{\partial y \partial x}(0,0) &= \lim _{y \rightarrow 0}\frac{ \frac{\partial f(0, y)}{\partial x}-\frac{\partial f(0, 0)}{\partial x}}{y}=-1
\\
\frac{\partial^2 f}{\partial x \partial y}(0,0) &= \lim _{x \rightarrow 0}\frac{ \frac{\partial f(x, 0)}{\partial y}-\frac{\partial f(0, 0)}{\partial y}}{x}=1
\end{aligned}
$$
显然有$f$在$(0,0) $点处的混合偏导数不相等。

以下给出相等的条件，先给出二元函数的定理及证明，多元函数及其高阶导数同理。

- 定义开集$D\sub R^2$以及函数$f:D\rightarrow R^2$，若对于点$\bold a\in D$，$f$的两个二阶混合偏导数在$D$上都存在且于该点连续，则有$\frac{\partial^2 f}{\partial x\partial y}=\frac{\partial^2 f}{\partial y\partial x}$成立。

**证明：**

### 隐函数存在定理和隐映射存在定理

### Taylor公式与极值问题

### 无约束极值

### 条件极值和Lagrange乘数法

## 向量、平面、曲面

###  内积、外积、混合积

#### 内积

已知向量$\boldsymbol x=(x_1,x_2,\dots,x_n), \boldsymbol y=(y_1,y_2,\dots,y_n)$，则二者的内积定义为$\langle\boldsymbol x,\boldsymbol y \rangle=\sum_{i=1}^{n}x_iy_i$，具有正定性、对称性、线性性，如下

1. $\langle \boldsymbol x, \boldsymbol x\rangle \geqslant 0$
2. $\langle\boldsymbol{x}, \boldsymbol{y}\rangle=\langle\boldsymbol{y}, \boldsymbol{x}\rangle$
3. $\langle \boldsymbol x,\boldsymbol y+\boldsymbol z\rangle=\langle\boldsymbol x,\boldsymbol y\rangle+\langle\boldsymbol x,\boldsymbol z\rangle$
4. $\langle\lambda \boldsymbol{x},\boldsymbol{y}\rangle=\lambda\langle\boldsymbol{x}, \boldsymbol{y}\rangle$（任意实数$\lambda$）

进而我们用内积定义了范数，对于任意向量$\boldsymbol x\in R^n$，有范数$||x||=\sqrt{\langle \boldsymbol x, \boldsymbol x\rangle}$，具有如下性质

1. $\ \boldsymbol|x\| \geqslant 0$
2. $\|\lambda \boldsymbol x\|=|\lambda|\| \boldsymbol x\|$（任意实数$\lambda$）
3. $\| \boldsymbol x+\boldsymbol y\| \leqslant\| \boldsymbol x\|+\| \boldsymbol y\|$（三角不等式）
4. $|\langle \boldsymbol x, \boldsymbol y\rangle| \leqslant\| \boldsymbol x\|\| \boldsymbol y\|$和$\langle  \boldsymbol x, \boldsymbol y\rangle^{2} \leqslant\langle \boldsymbol x,\boldsymbol  x\rangle\langle\boldsymbol  y,\boldsymbol  y\rangle$（Cauchy-Schwarz不等式）

我们有用范数和内积来定义了夹角，如果向量$\boldsymbol x $和$\boldsymbol y$都不是零向量，那么由以上不等式可知
$$
\frac{|\langle\boldsymbol{x}, \boldsymbol{y}\rangle|}{\|\boldsymbol{x}\|\|\boldsymbol{y}\|} \leqslant 1
$$
这表明我们能够找到唯一的$\theta \in  [0,\pi]$使得
$$
\cos \theta=\frac{\langle\boldsymbol{x}, \boldsymbol{y}\rangle}{\|\boldsymbol{x}\|\|\mathbf{y}\|}
$$
可见内积是一种向量到标量的降阶操作。

以上的定义可以看出内积是自然引导出范数和夹角的。

接下来我们从线性变换的角度来理解点积。

我们从夹角的定义返回去，将向量乘上夹角余弦视作该向量在另一个向量方向上的投影，同时注意到夹角的形成是两方面的，所以投影的方向可以交换，具有对称性。**虽然是从向量的夹角出发的定义，但是这种投影的定义并不是依靠矩阵乘法和点积运算而存在的，它仅仅是我们在从高维空间到一维空间之间构造出的一种线性映射**（原高维向量空间中等距的向量经过投影操作之后依然等距，同时在一维情形下显然保持这些向量的加法和数乘运算），进而它必定可由一种线性变换所表示，也就是上文所说的$1\times n$矩阵（这里不认为这样的矩阵是所谓的行向量，此外，个人认为向量就竖着写，不横着写），再根据矩阵乘法和内积定义二者之间运算的一致性以及线性变换矩阵和内积运算的向量坐标之间的”转置“关系，我们将二者联系起来，也就是所谓的对偶性。

#### 叉积

已知向量$\boldsymbol x=(x_1,x_2,\dots,x_n), \boldsymbol y=(y_1,y_2,\dots,y_n)$，则二者的叉积定义为$\boldsymbol u =\boldsymbol x \times \boldsymbol y$，其中$||\boldsymbol u ||=||\boldsymbol x||||\boldsymbol y||\sin<\boldsymbol x ,\boldsymbol y>$，且$\boldsymbol u$和$\boldsymbol x$，$\boldsymbol y$均垂直，同时符合右手系。有如下性质：

1. $\boldsymbol x \times \boldsymbol x= \boldsymbol 0$
2. $\boldsymbol a // \boldsymbol b \Leftrightarrow \boldsymbol a \times \boldsymbol b= \boldsymbol 0$
3. $\boldsymbol a \times \boldsymbol b=-\boldsymbol b \times \boldsymbol a$
4. $(\boldsymbol{a}+\boldsymbol{b}) \times \boldsymbol{c}=\boldsymbol{a} \times \boldsymbol{c}+\boldsymbol{b} \times \boldsymbol{c}$
5. $(\lambda \boldsymbol{a}) \times \boldsymbol{b}=\boldsymbol{a} \times(\lambda \boldsymbol{b})=\lambda(\boldsymbol{a} \times \boldsymbol{b})$
6. 坐标运算$\boldsymbol{a} \times \boldsymbol{b}  = (a_{x}, a_{y}, a_{z}) \times(b_{x}, b_{y}, b_{z}) =\left| \begin{array}{lll}{\boldsymbol{i}} & {\boldsymbol{j}} & {\boldsymbol{k}} \\ {a_{x}} & {a_{y}} & {a_{z}} \\ {b_{x}} & {b_{y}} & {b_{z}}\end{array}\right|$（对于三维）
7. 几何意义为以$\boldsymbol a ，\boldsymbol b $为边的平行四边形的面积。

#### 混合积

$[\boldsymbol a \boldsymbol b \boldsymbol c]=(\boldsymbol a \times \boldsymbol b) \cdot \boldsymbol c=\left| \begin{array}{lll}{a_{x}} & {a_{y}} & {a_{z}} \\ {b_{x}} & {b_{y}} & {b_{z}} \\ {c_{x}} & {c_{y}} & {c_{z}}\end{array}\right|$（对于三维）

几何意义为以$\boldsymbol a \boldsymbol b \boldsymbol c$为边的平行六面体的体积，因此共面条件就是混合积为0。

### 直线、平面

#### 平面方程

- 点法式方程

  - 已知平面法向量$\boldsymbol n=(A,B,C)$以及面上一点$M_{0}\left(x_{0}, y_{0}, z_{0}\right)$，则平面方程为

  - $$
    A\left(x-x_{0}\right)+B\left(y-y_{0}\right)+C\left(z-z_{0}\right)=0
    $$

- 一般方程

  - 由点法式方程变形可得

  - $$
    A x + B y + C z + D = 0
    $$

- 截距式

  - 对一般式方程进行变形可得

  - $$
    \frac { x } { a } + \frac { y } { b } + \frac { z } { c } = 1
    $$

- 三点式

  - 已知平面三点，根据向量叉积的性质来求取平面法向量，故可写成行列式

  - $$
    \left| \begin{array} { l l l } {  { x } -  { x } _ { 1 } } & {  { y } -  { y } _ { 1 } } & {  { z } -  { z } _ { 1 } } \\ {  { x } _ { 2 } -  { x } _ { 1 } } & {  { y } _ { 2 } -  { y } _ { 1 } } & {  { z } _ { 2 } - { z } _ { 1 } } \\ {  { x } _ { 3 } -  { x } _ { 1 } } & {  { y } _ { 3 } - { y } _ { 1 } } & { z _ { 3 } -  { z } _ { 1 } } \end{array} \right| = \mathbf { 0 }
    $$

#### 直线方程

- 点向式

  - 已知直线方向向量$\boldsymbol n=(a,b,c)$以及线上一点$M_{0}\left(x_{0}, y_{0}, z_{0}\right)$

  - $$
    \frac {  { x } -  { x } _ { 0 } } {  { a } } = \frac {  { y } - { y } _ { 0 } } {  { b } } = \frac {  { z } -  { z } _ { 0 } } {  { c } }
    $$

### 距离

#### 线面距离

已知平面$\pi : A x + B y + C z + D = 0$和平面外一点$P _ { 0 } \left( x _ { 0 } , y _ { 0 } , z _ { 0 } \right)$，则$P_0$到该平面的距离为
$$
d = \frac { \left| A x _ { 0 } + B y _ { 0 } + C z _ { 0 } + D \right| } { \sqrt { A ^ { 2 } + B ^ { 2 } + C ^ { 2 } } }
$$
推导过程如下

$\forall P _ { 1 } \left( x _ { 1 } , y _ { 1 } , z _ { 1 } \right) \in \pi \ A x _ { 1 } + B y _ { 1 } + C z _ { 1 } + D = 0$

$\overrightarrow { P _ { 1 }  P _ { 0 } }= (x _ { 0 } - x _ { 1 } , y _ { 0 } - y _ { 1 } , z _ { 0 } - z _ { 1 })$

$\overrightarrow { n _ { 0 } } = ( \frac { A } { \sqrt { A ^ { 2 } + B ^ { 2 } + C ^ { 2 } } } , \frac { B } { \sqrt { A ^ { 2 } + B ^ { 2 } + C ^ { 2 } } } , \frac { C } { \sqrt { A ^ { 2 } + B ^ { 2 } + C ^ { 2 } } } )$

$\begin{align}d &= | | \overrightarrow { P  _ { 1 } P _ { 0 }} | \cos \theta |\\
&= | | \overrightarrow { P  _ { 1 }  P  _ { 0 }} \left| \vec { n } _ { 0 } \right| \cos \theta |\\
&= \left| \overrightarrow { P _ { 1 } P } _ { 0 } \cdot \vec { n } _ { 0 } \right|\\&= |\frac { A \left( x _ { 0 } - x _ { 1 } \right) } { \sqrt { A ^ { 2 } + B ^ { 2 } + C ^ { 2 } } } + \frac { B \left( y _ { 0 } - y _ { 1 } \right) } { \sqrt { A ^ { 2 } + B ^ { 2 } + C ^ { 2 } } } + \frac { C \left( z _ { 0 } - z _ { 1 } \right) } { \sqrt { A ^ { 2 } + B ^ { 2 } + C ^ { 2 } } } |\\&=| \frac { A x _ { 0 } + B y _ { 0 } + C z _ { 0 } - \left( A x _ { 1 } + B y _ { 1 } + C z _ { 1 } \right) } { \sqrt { A ^ { 2 } + B ^ { 2 } + C ^ { 2 } } }|\\ &=|\frac { A x _ { 0 } + B y _ { 0 } + C z _ { 0 } + D } { \sqrt { A ^ { 2 } + B ^ { 2 } + C ^ { 2 } } }|\end{align}$

两平行平面间距可以将$P_0$视作位于另一平面，故有
$$
d = \frac { \left| D _ { 1 } - D _ { 2 } \right| } { \sqrt { A ^ { 2 } + B ^ { 2 } + C ^ { 2 } } }
$$
其中$\begin{array} { l } { \pi _ { 1 } : A x + B y + C z + D _ { 1 } = 0 } \\ { \pi _ { 2 } : A x + B y + C z + D _ { 2 } = 0 } \end{array}$。

#### 点线距离

已知直线$L:\frac {  { x } -  { x } _ { 0 } } {  { m } } = \frac {  { y } - { y } _ { 0 } } {  { n } } = \frac {  { z } -  { z } _ { 0 } } {  { p } }$，及直线外一点$P _ { 0 } \left( x _ { 0 } , y _ { 0 } , z _ { 0 } \right)$,则则$P_0$到该直线的距离为
$$
d = | | \overrightarrow { P _ { 1 } P _ { 0 } } | \cdot \sin \theta | = | | \overrightarrow { P _ { 1 } P _ { 0 } } | \cdot | \vec { s } _{ 0 } | \cdot \sin \theta | = \left| \overrightarrow { P _ { 1 } P } _ { 0 } \times \vec { s } _ { 0 } \right|
$$
其中$P _ { 1 } \left( x _ { 1 } , y _ { 1 } , z _ { 1 } \right)$为$L$上任意一点，$\vec { s } _0$为直线的单位方向向量，即$\frac { 1 } { \sqrt { m ^ { 2 } + n ^ { 2 } + p ^ { 2 } }} (m,n,p)$。

#### 线面关系

这些就只需注意方向向量和法向量之间的夹角关系就好。

#### 平面束

$\left\{ \begin{array} { l } { A _ { 1 } x + B _ { 1 } y + C _ { 1 } z + D _ { 1 } = 0 } \\ { A _ { 2 } x + B _ { 2 } y + C _ { 2 } z + D _ { 2 } = 0 } \end{array} \right.$确定直线$L$，其中系数不成比例，则$L$的平面束方程为
$$
\mu \left( A _ { 1 } x + B _ { 1 } y + C _ { 1 } z + D _ { 1 } \right) + \lambda \left( A _ { 2 } x + B _ { 2 } y + C _ { 2 } z + D _ { 2 } \right) = 0
$$
$\mu$和$\lambda$不同时为0。

### 曲线方程、曲面方程

曲面方程

重点是认识一些二次曲面
$$
\begin{align}
椭球面&\frac { x ^ { 2 } } { a ^ { 2 } } + \frac { y ^ { 2 } } { b ^ { 2 } } + \frac { z ^ { 2 } } { c ^ { 2 } } = 1&\\
抛物面&\frac { x ^ { 2 } } { 2 p } + \frac { y ^ { 2 } } { 2 q } = z&(pq>0)\\
双曲抛物面&- \frac { x ^ { 2 } } { 2 p } + \frac { y ^ { 2 } } { 2 q } = z&(pq>0)\\
单叶双曲面&\frac { x ^ { 2 } } { a ^ { 2 } } + \frac { y ^ { 2 } } { b ^ { 2 } } - \frac { z ^ { 2 } } { c ^ { 2 } } = 1\\
双叶双曲面&\frac { x ^ { 2 } } { a ^ { 2 } } + \frac { y ^ { 2 } } { b ^ { 2 } } - \frac { z ^ { 2 } } { c ^ { 2 } } = - 1
\end{align}
$$


曲线方程

- 空间曲线可看作空间两曲面的交线$\left\{ \begin{array} { l } { F ( x , y , z ) = 0 } \\ { G ( x , y , z ) = 0 } \end{array} \right.$
- $\left\{ \begin{array} { l } { x = x ( t ) } \\ { y = y ( t ) } \\ { z = z ( t ) } \end{array} \right.$参数式

### 曲线的切线和法平面

对于空间曲线$C :\vec  r = \vec r ( t ) = (x ( t ) , y ( t ) , z ( t ) ) ( a \leq t \leq b )$，有$\vec r'(t)=(x'(t),y'(t),z'(t))$，这是曲线的切线的方向向量，称为切向量，在曲线上某点$ \vec r ( t _0)$因此可以写作
$$
\vec\rho=\vec r(t_0)+t\vec r'(t_0)
$$
带入坐标式，消去参数，可得对称式
$$
\frac{x-x(t_0)}{x'(t_0)}=\frac{y-y(t_0)}{y'(t_0)}=\frac{z-z(t_0)}{z'(t_0)}
$$
那么法平面就顺势而出，即与切向量垂直的任意平面
$$
\vec r'(t_0)\cdot(\vec\rho-\vec r(t_0))=0
$$
同样地带入坐标式得
$$
x'(t_0)(x-x(t_0))+y'(t_0)(y-y(t_0))+z'(t_0)(z-z(t_0))=0
$$
若曲线式由$\left\{ \begin{array} { l } { F ( x , y , z ) = 0 } \\ { G ( x , y , z ) = 0 } \end{array} \right.$的形式给出，则相对应地于曲线上点$P(x_0,y_0,z_0)$处的

切线方程为
$$
\frac{x-x_0}{\frac{\partial(F,G)}{\partial(y,z)}\bigg|_P}=\frac{y-y_0}{\frac{\partial(F,G)}{\partial(z,x)}\bigg|_P}=\frac{z-z_0}{\frac{\partial(F,G)}{\partial(x,y)}\bigg|_P}
$$

法平面方程为
$$
(x-x_0)\frac{\partial(F,G)}{\partial(y,z)}\bigg|_P+(y-y_0)\frac{\partial(F,G)}{\partial(z,x)}\bigg|_P+(z-z_0)\frac{\partial(F,G)}{\partial(x,y)}\bigg|_P=0
$$

### 曲面的法线和切平面

对于空间曲面$\Omega:\vec R$

### 弧长、曲率、挠率

#### 弧长、曲率、挠率推导

弧长公式直接给出（如下），不证明了，还是靠达布和来证的。

对于空间曲线$C :\vec  r = \vec r ( t ) = (x ( t ) , y ( t ) , z ( t ) ) ( a \leq t \leq b )$，我们已经知道弧长公式
$$
L = \int _ { a } ^ { b } \sqrt { \dot { x } ( t ) ^ { 2 } + \dot { y } ( t ) ^ { 2 } + \dot { z } ( t ) ^ { 2 } } d t
$$
这里我们考虑变上限积分
$$
s ( t ) = \int _ { a } ^ { t } \sqrt { \dot { x } ( t ) ^ { 2 } + \dot { y } ( t ) ^ { 2 } + \dot { z } ( t ) ^ { 2 } } d t
$$
对它求导可得
$$
\frac{ds(t)}{dt}=\sqrt { \dot { x } ( t ) ^ { 2 } + \dot { y } ( t ) ^ { 2 } + \dot { z } ( t ) ^ { 2 } }=||\vec {\dot r(t)}||>0
$$
根据反函数定理可知$t(s)$是存在的，那么我们有$s(t(s))=s$，**进而我们将该曲线用弧长$s$作为参数重新表示为$\vec {\gamma (s)}$**（换句话说根据$t$和$s$之间的一一对应关系来看，曲线的表示根据自变量的不同有两种形式，我们以下的推到中会混合地使用它们），则有
$$
\vec{\dot {\gamma}(s)}=\frac{d\vec {\gamma(s)}}{ds}=\frac{d\vec{\gamma(s(t))}}{ds}=\frac{d\vec{r(t)}}{dt} \frac{dt(s)}{ds}=\vec{\dot r(t)}\frac{1}{\frac{ds(t)}{dt}}=\frac{\vec{\dot{r(t)}}}{||\vec {\dot r(t)}||}
$$
我们记$\boldsymbol T=\vec{\dot {\gamma}(s)}$，显然有$||\boldsymbol T||=1$，即有$<\boldsymbol T,\boldsymbol T>=1$，故等式两侧求导可得
$$
2<\frac{d \boldsymbol T}{ds},\boldsymbol T>=0
$$
又
$$
\frac{d \boldsymbol T}{ds}=\frac{d\vec{\dot {\gamma}(s)}}{ds}=\vec{ \ddot {\gamma}(s)}
$$
接着我们记
$$
\boldsymbol N=\frac{\vec{\ddot{\gamma(s)}}}{||\vec {\ddot \gamma(s)}||}
$$
所以
$$
\boldsymbol N\cdot \boldsymbol T=0
$$
进而记$\boldsymbol B=\boldsymbol T \times \boldsymbol N$，因为$||\boldsymbol T||=1，||\boldsymbol N||=1$，所以$||\boldsymbol B||=1$，这样我们就得到了在曲线$C$上任意给定一点的单位正交基$\{\boldsymbol B, \boldsymbol N, \boldsymbol T \}$。

![FrenetFrame](\img\FrenetFrame.png)

在该单位正交基下，最终我们定义

1. 曲率

$$
\boldsymbol \kappa(s)=||\frac{d\boldsymbol T}{ds}||=||\vec{ \ddot {\gamma}(s)}||
$$
2. 挠率

$$
\boldsymbol \tau(s)=- \dot{\boldsymbol  B}\cdot \boldsymbol  N
$$

#### Fernet 标架

接下来说明我们整出来的这个正交基的意义：

#### 计算公式

$$
\boldsymbol \kappa(s)=||\frac{d\boldsymbol T}{ds}||=||\vec{ \ddot {\gamma}(s)}||
$$

这样的曲率公式是不适合我们计算哈哈哈，接下来我们推导曲率公式：

- 参数$r(t)$式

由这个两个重要的关系式，
$$
\vec{\dot{\gamma}(s)}=\frac{\vec{\dot{r(t)}}}{||\vec {\dot r(t)}||}， \frac{ds(t)}{dt}=||\vec {\dot r(t)}||
$$
我们有
$$
\vec{\ddot{\gamma}(s)}=\frac{\vec {d{\dot{\gamma}(s)}}}{ds}=\frac{d\frac{\vec{\dot{r(t)}}}{||\vec {\dot r(t)}||}}{dt}\frac{1}{\frac{ds(t)}{dt}}=\frac{\vec {\ddot r(t)}\vec{||\dot r(t)||}-{\vec{||\dot r(t)||'}\vec{\dot r(t)}}}{\vec{||\dot r(t)||^{2}}}\frac{1}{||\vec{\dot r(t)}||}=\frac{\vec {\ddot r(t)}\vec{||\dot r(t)||}-{\vec{||\dot r(t)||'}\vec{\dot r(t)}}}{\vec{||\dot r(t)||^{3}}}
$$
其中
$$
{\vec{||\dot r(t)||'}}=\frac{\vec {\dot r(t)}\cdot \vec{\ddot r(t)}}{\vec{||\dot r(t)||}}
$$
带回上式得
$$
\vec {\ddot{\gamma}(s)}=\frac{\vec {\ddot r(t)}\vec{||\dot r(t)||}-{\frac{\vec {\dot r(t)}\cdot \vec{\ddot r(t)}}{\vec{||\dot r(t)||}}\vec{\dot r(t)}}}{\vec{||\dot r(t)||^{3}}}=\frac{\vec {\ddot r(t)}\vec{||\dot r(t)||^{2}}-<{{\vec {\dot r(t)}\cdot \vec{\ddot r(t)}}>\vec{\dot r(t)}}}{\vec{||\dot r(t)||^{4}}}
$$
因此
$$
\begin{align}
\boldsymbol \kappa(s)&=||\vec{ \ddot {\gamma}(s)}|| =(\frac{<(\vec {\ddot r(t)}\vec{||\dot r(t)||^{2}}-<{{\vec {\dot r(t)}\cdot \vec{\ddot r(t)}}>\vec{\dot r(t)}}),({\vec {\ddot r(t)}\vec{||\dot r(t)||^{2}}-<{{\vec {\dot r(t)}, \vec{\ddot r(t)}}>\vec{\dot r(t)}}})>}{\vec{||\dot r(t)||^{8}}}>^{\frac{1}{2}}\\
&=(\frac{(<\vec {\ddot r(t)}\vec{||\dot r(t)||},\vec {\ddot r(t)}\vec{||\dot r(t)||}>-2<\vec {\ddot r(t)}\vec{||\dot r(t)||^{2}}, <{{\vec {\dot r(t)},\vec{\ddot r(t)}}>\vec{\dot r(t)}}>+<{{\vec {\dot r(t)}, \vec{\ddot r(t)}}>^{2}\vec{\dot r(t)^{2}}})}{\vec{||\dot r(t)||^{8}}})^{\frac{1}{2}}\\
&=(\frac{(\vec {\ddot r(t)^{2}}\vec{||\dot r(t)||^{4}}-2 \vec{||\dot r(t)||^{2}}<{{\vec {\dot r(t)},\vec{\ddot r(t)}}>^{2}}+<{{\vec {\dot r(t)}, \vec{\ddot r(t)}}>^{2}\vec{||\dot r(t)||^{2}}})}{\vec{||\dot r(t)||^{8}}})^{\frac{1}{2}}\\
&=(\frac{(\vec {\ddot r(t)^{2}}\vec{||\dot r(t)||^{4}}-<{{\vec {\dot r(t)}, \vec{\ddot r(t)}}>^{2}\vec{||\dot r(t)||^{2}}})}{\vec{||\dot r(t)||^{8}}})^{\frac{1}{2}}\\
&=(\frac{(\vec {||\ddot r(t)||^{2}}\vec{||\dot r(t)||^{2}}-<{{\vec {\dot r(t)}, \vec{\ddot r(t)}}>^{2})}}{\vec{||\dot r(t)||^{6}}})^{\frac{1}{2}}\\
&=(\frac{(\vec {||\ddot r(t)||^{2}}\vec{||\dot r(t)||^{2}}-{\vec {||\dot r(t)||^{2}} \vec{||\ddot r(t)||^{2}\cos^{2} \theta}})}{\vec{||\dot r(t)||^{6}}})^{\frac{1}{2}}\\
&=(\frac{{\vec {||\dot r(t)||^{2}} \vec{||\ddot r(t)||^{2}\sin^{2} \theta}}}{\vec{||\dot r(t)||^{6}}})^{\frac{1}{2}}\\
&=\frac{{\vec {||\dot r(t)||} \vec{||\ddot r(t)||\sin \theta}}}{\vec{||\dot r(t)||^{3}}}\\
&=\frac{||{\vec {\dot r(t)}\times \vec{\ddot r(t)}}||}{\vec{||\dot r(t)||^{3}}}
\end{align}
$$
其中$\theta$是$\vec{\dot r(t)}$和$\vec {\ddot r(t)}$间的夹角。

- 直角坐标系

- 极坐标

  这些坐标系无非是将$\vec r ( t ) = (x ( t ) , y ( t ) , z ( t ) )$具体化为$\vec{r(t)}=(x,y(x),0)$和$\vec {r(t)}=(\rho \cos \theta,\rho \sin \theta,0)$，将相对应的向量带入计算即可。

$$
\boldsymbol \tau(s)=- \dot{\boldsymbol  B}\cdot \boldsymbol  N
$$

这样的挠率公式也不适合我们计算哈哈哈，接下来我们推导挠率公式：
$$
\boldsymbol \tau (s)=- \dot{\boldsymbol  B}\cdot \boldsymbol  N=\frac{<\vec{\dot \gamma(s)}\times {\vec{\ddot \gamma(s)}},\vec{\dddot \gamma(s)}>}{\vec{||\ddot \gamma(s)||^{2}}}=\frac{<\vec{\dot r(t)}\times {\vec{\ddot r(t)}},\vec{\dddot r(t)}>}{ ||\vec{\dot r{(t)}}\times \vec{\ddot r{(t)}}||^{2}}
$$

### 曲率、挠率与标架的关系

$$
\frac { d } { d s } \left[ \begin{array} { l } { T } \\ { N } \\ { B } \end{array} \right] = \left[ \begin{array} { r r r } { 0 } & { \kappa } & { 0 } \\ { - \kappa } & { 0 } & { \tau } \\ { 0 } & { - \tau } & { 0 } \end{array} \right] \left[ \begin{array} { c } { T } \\ { N } \\ { B } \end{array} \right]
$$

这个线性方程组有唯一解哦。

## 积分

**第一类曲线积分**是对一段曲线（弧）$L$的积分。积分微元为弧微分$ds$，被积函数由于在弧线上取值，因此是二元函数$f(x,y)$.积分值记为
$$
\int_L f(x,y)ds
$$

其中被积函数$f(x,y)$在$L$上取值。

弧$L$上的点满足的方程可以由两种形式给出，一种是$y=y(x)$,另一种则是参数方程的形式$x=\phi(t),y=\psi(t)$

对于第一种形式，被积函数可以写成只和$x$有关的一元函数，即$f(x,y(x))$，弧微分可以写成$ds=\sqrt{ (dx)^2+(dy)^2}=\sqrt{1+y'(x)^2}dx$,则曲线积分化为一重积分
$$
\int_{x_1}^{x_2 }f(x,y(x)) \sqrt{1+y'(x)^2}dx
$$
对于第二种形式，被积函数可以写成只和$t$有关的一元函数，即$f(\phi(t),\psi (t))$，弧微分可以写成
$$
ds=\sqrt{ (dx)^2+(dy)^2}=\sqrt{\phi'(t)^2+\psi'(t)^2}dt
$$

这就是第一类曲线积分，可用于求解不均匀曲线段的质量，被积函数即为**线质量密度**。

在第一类曲线积分中，被积函数是标量，积分微元也是标量，两个标量的乘积也是标量。注意到两个矢量的内积也是标量，这就形成了**第二类曲线积分**。典型的第二类曲线积分问题为变力沿着曲线做的总功，记为
$$
\int_L \vec{A}(x,y) \cdot d\vec{r}
$$
其中$d\vec{r}=dx \vec{i}+dy \vec{j}$为带方向的微分。

由内积的定义，积分化为
$$
\int_L A_x(x,y)dx+A_y(x,y)dy
$$

同样地，弧$L$的方程也可由两种形式给出，最终也可化为一重积分。

在**一重定积分**中，有**牛顿-莱布尼兹公式**，它联系了积分值和原函数在端点处的取值，即
$$
\int_a^b F'(x)dx=F(b)-F(a)
$$
在二重积分中，有类似的公式成立，即**格林公式**。由于积分区域是二维的，其边界不再是两个端点了，而是一个闭合的回路。

**格林定理**：设闭区域由分段光滑曲线$L$围成，函数$P(x,y),Q(x,y)$上有一阶连续偏导数，则
$$
\iint_D (\frac{\partial Q}{\partial x}-\frac{\partial P}{\partial y})dxdy=\oint_LPdx+Qdy
$$

等式左边是一个二重积分，右边是一个第二类曲线积分。定理的证明由偏导数的定义和牛顿-莱布尼兹公式可得到。

若进一步考虑一种特殊情况，即
$$
\frac{\partial Q}{\partial x}=\frac{\partial P}{\partial y}
$$
等式两边为$0$，即第二类曲线积分的值为$0$.而我们对积分路径$L$并没有什么要求，因此此时**曲线积分的值与路径无关**。

如果将积分区域的曲线变为曲面的话，同样可以定义出**第一类和第二类曲面积分**。

相应地，格林公式由高斯公式代替

**高斯公式**：设有界闭区域$V$是由分片光滑的闭曲面$S$所围成，函数$P(x,y,z),Q(x,y,z),R(x,y,z)$在$V$上有连续的一阶偏导数，则
$$
\iiint_V(\frac{\partial p}{\partial x}+\frac{\partial Q}{\partial y}+\frac{\partial R}{\partial z})dV=\oiint_SPdydz+Qdzdx+Rdxdy
$$
其中$S$取外侧。

特别地，在第二类曲线积分和第二类曲面积分之间存在一联系——**斯托克斯公式**。

**斯托克斯公式**：$L$是分段光滑的空间有向闭曲线，$S$是以$L$为边界的分片光滑的有向曲面，$L$的方向和$S$的侧符合右手法则，函数$P(x,y,z),Q(x,y,z),R(x,y,z)$在曲面$S$（包括边界）上具有一阶连续的pain倒数，则有
$$
\iint_S(\frac{\partial R}{\partial y}-\frac{\partial Q}{\partial z})dydz+(\frac{\partial P}{\partial z}-\frac{\partial R}{\partial x})dzdx+(\frac{\partial Q}{\partial x}-\frac{\partial P}{\partial y})dxdy=\oint_LPdx+Qdy+Rdz
$$
以上是书本上讲的一些玩意，接下来我们来考虑一些有趣的东西，因为这些积分在物理上有很广泛的应用，所以存在着一些不一样的审视角度。

### 标量与向量

### 通量

### 环量

### 含参变量积分

### $\Beta(p,q)\&\Gamma(s)$

以上俩函数就长这样：
$$
\Gamma ( s ) = \int _ { 0 } ^ { + \infty } t ^ { s - 1 } e ^ { - t } d t\\
B ( p , q ) = \int _ { 0 } ^ { 1 } t ^ { p - 1 } ( 1 - t ) ^ { q - 1 } d t
$$
以下我们对他们做一些讨论。

#### 定义域

