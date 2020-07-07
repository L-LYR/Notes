# Ordinary Differential Equation

本学习记录弱化了对概念与定义的阐述和理解，偏重于对解题方法的剖析。

---

> In mathematics, an ordinary differential equation (ODE) is a differential equation containing one or more functions of one independent variable and the derivatives of those functions. The term ordinary is used in contrast with the term partial differential equation which may be with respect to more than one independent variable.

> $$
> \mathrm{F}\left(\mathrm{x}, \mathrm{y}, \frac{\mathrm{dy}}{\mathrm{dx}}, \cdots, \frac{d^{n} y}{d x^{n}}\right)=0
> $$
>

## 几个名词

- 阶

- 类型

  - 线性
    > $$
    > \frac{d^{n} y}{d x^{n}}+a_{1}(x) \frac{d^{n-1} y}{d x^{n-1}}+\ldots+a_{n}(x) y=f(x)
    > $$
    >

  - 非线性

  - 齐次

  - 非齐次

- 解

  - 通解

    > 如果微分方程的解中含有任意常数，且所含的相互独立的任意常数的个数与微分方程的阶数相同，则称这样的解为该方程的通解。

    - 显式

    - 隐式

      > 如果关系式$\Psi(x, y)=0$所确定的隐函数$\mathrm{y}=\varphi(\mathrm{x}), \mathrm{x} \in \mathrm{I}$为方程$\mathrm{F}\left(\mathrm{x}, \mathrm{y}, \frac{\mathrm{dy}}{\mathrm{dx}}, \cdots, \frac{d^{n} y}{d x^{n}}\right)=0$的解，则称$\Psi(x, y)=0$是方程的一个隐式解。

  - 特解

    > 在通解中给任意常数以确定的值而得到的解称为方程的特解。

- 初值问题

  > $$
  > \left\{\begin{array}{l}{F\left(x, y, \frac{d y}{d x}, \cdots, \frac{d^{n} y}{d x^{n}}\right)=0} \\ {y\left(x_{0}\right)=y_{0}, \frac{d y\left(x_{0}\right)}{d x}=y_{0}^{(1)}, \cdots, \frac{d^{(n-1)} y\left(x_{0}\right)}{d x^{n-1}}=y_{0}^{(n-1)}}\end{array}\right.
  > $$
  >

- 积分曲线

  > 一阶微分方程$\frac{\mathrm{dy}}{\mathrm{dx}}=f(x, y)$的解$\mathrm{y}=\varphi(\mathrm{x})$，在$xOy$平面上所表示的一条曲线称为微分方程的积分曲线。

## 解题方法

以下我们针对不同形式微分方程的解题方法进行循序渐进地研究，旨在形成先知先觉的思考方向。

### （可）分离变量方程

形如
$$
\begin{equation}
\frac{\mathrm{d} y}{\mathrm{d} x}=f_{1}(x) f_{2}(y) 
\end{equation}
$$

$$
\begin{equation}
{M_{1}(x) M_{2}(y) \mathrm{d} x+N_{1}(x) N_{2}(y) \mathrm{d} y=0}
\end{equation}
$$

以上两种皆可化为以下方程（除的时候要注意分母为零的情况，可能有特解产生）
$$
\begin{equation}
{g(y) \mathrm{d} y=f(x) \mathrm{d} x}
\end{equation}
$$
接着等式两侧积分即可
$$
\begin{equation}
\int g(y) \mathrm{d} y=\int f(x) \mathrm{d} x
\end{equation}
$$
即得
$$
\begin{equation}
G(y)=F(x)+C
\end{equation}
$$

同理，对于一阶线性方程
$$
\frac{d y}{d x}+P(x) y=Q(x)
$$
先考虑齐次方程，解出通解$y=Cf(x)$，再使用常数变易法，即设$y=C(x)f(x)$，可解得非齐次的通解。

特别地，我们考虑$Bernoulli\ Equation$
$$
\frac{d y}{d x}+P(x) y=Q(x) y^{n}\ (n \neq 0,1)
$$
先做一些变换
$$
y^{-n} \frac{d y}{d x}+P(x) y^{1-n}=Q(x)
$$
此时换元
$$
t=y^{1-n}
$$
则（复合函数求导）
$$
\frac{d t}{d x}=(1-n) y^{-n} \frac{d y}{d x}
$$
代回有
$$
\frac{1}{(1-n)}\frac{d t}{d x}+ P(x) t= Q(x)
$$
即化归线性方程。

### 齐次方程

形如
$$
\begin{equation}
\frac{d y}{d x}=f\left(\frac{y}{x}\right)
\end{equation}
$$
我们进行如下换元操作
$$
u=\frac{y}{x}
$$
则有
$$
\frac{d y}{d x}=u+x \frac{d u}{d x}
$$
进而
$$
u+x \frac{d u}{d x}=f(u)
$$
即
$$
xdu=(f(u)-u)dx
$$
故考虑
$$
(1)\ f(u)-u=0 \Rightarrow u=k_1 \dots u=k_m \Rightarrow y=k_1x \dots y=k_mx \\
(2)\ f(u)-u\ne 0 \Rightarrow \frac{d u}{f(u)-u}=\frac{d x}{x} \Rightarrow \int \frac{d u}{f(u)-u}=\int \frac{d x}{x}\ \ (u=\frac{y}{x})
$$
更一般地，对于如下方程
$$
\frac{d y}{d x}=f\left(\frac{a x+b y+c}{a_{1} x+b_{1} y+c_{1}}\right)
$$

$(1)c^2+c_1^2=0$

$$
\left. \begin{array}{}\Rightarrow\frac{a x+b y}{a_{1} x+b_{1} y} \Rightarrow \frac{a+b \frac{y}{x}}{a_{1} +b_{1} \frac{y}{x}} \\\left \{ \begin{array}{} u=\frac{y}{x} \\ \frac{d y}{d x}=u+x \frac{d u}{d x} \end{array} \right. \end{array} \right \}\Rightarrow u+x \frac{d u}{d x}=f( \frac{a+bu}{a_{1} +b_{1}u} )
$$

此后即可按以上更简情况操作。

$(2)c^2+c_1^2\ne 0$

考虑线性方程组
$$
\begin{cases}ax+by+c=0\\ a_{1}x+b_{1}y+c_{1}=0\end{cases}
$$

$1）\begin{vmatrix} a & b \\ a_{1} & b_{1} \end{vmatrix} \ne 0 $

解得
$$
\begin{cases}
x=x_0\\
y=y_0
\end{cases}
$$
接下来做代换
$$
\begin{cases}
x=x_0+x'\\
y=y_0+y'
\end{cases}
$$
则有
$$
\frac{d y'}{d x'}=f\left(\frac{a x'+b y'}{a_{1} x'+b_{1} y'}\right)
$$
即化归情况$(1)$，该操作实质是一个平移的过程。

$2）\begin{vmatrix} a & b \\ a_{1} & b_{1} \end{vmatrix} = 0 $

无解，则可知线性相关性
$$
a x + b y =\lambda（a_1 x +  b_1 y）
$$
故做如下代换
$$
u=a_1 x+b_1 y
$$
则可得
$$
\dfrac {du}{dx}=a_{1}+b_{1}\dfrac {dy}{dx}=a_{1}+b_{1}f\left(\frac{\lambda u+c}{u+c_1}\right)
$$
同样化归情况$(1)$。

### 参数法

使用此方法的前提是你对变元间的关系有一定的先知先觉，或者说使用参数式之后结构有大幅度的优化，常用基本的参数式如下
$$
(1)\begin{cases}y=\varphi \left( t\right) \\ y'=\psi \left( t\right) \end{cases} \Rightarrow dx=\dfrac {dy}{y'}=\dfrac {\varphi' \left( t\right) }{\psi \left( t\right) }dt
$$

$$
(2)\begin{cases}x=\varphi \left( t\right) \\ y'=\psi \left( t\right) \end{cases}\Rightarrow dy=y'dx=\psi(t)\varphi'(t)dt
$$

$$
(3)y'=p \Rightarrow y''=\dfrac {dy'}{dx}=\dfrac {dy'}{dy} \dfrac {dy}{dx}=\dfrac{dp}{dy}p
$$



$Clairaut Equation$
$$
y=xy'+f(y')
$$
使用$(3)$换元
$$
y=xp+f(p)
$$
故有
$$
p=\frac{dy}{dx}=p+x\frac{dp}{dx}+f'(p)\frac{dp}{dx}
$$
即
$$
(x+f'(p))\frac{dp}{dx}=0
$$
讨论得
$$
(1)(x+f'(p))=0\Rightarrow \begin{cases}x=-f'\left( y'\right) \\ y=xy'+f(y')\end{cases}（解出通解）\\
(2)\frac{dp}{dx}=0\Rightarrow p=C \Rightarrow y=Cx+f(C)（特解）
$$

### 高阶

#### 可降阶

$$
y^{(n)}=f(x) \Rightarrow t=y^{(n-1)} \\
y^{\prime \prime}=f\left(x, y^{\prime}\right) \Rightarrow y'=p\\
y^{\prime \prime}=f\left(y, y^{\prime}\right) \Rightarrow y'=p \Rightarrow y''=\dfrac {dy'}{dx}=\dfrac {dy'}{dy} \dfrac {dy}{dx}=\dfrac{dp}{dy}p
$$

#### 解的结构

若$y_1,y_2,\dots,y_n$是$n$阶齐次线性方程$y^{(n)}+a_{1}(x) y^{(n-1)}+\cdots+a_{n-1}(x) y^{\prime}+a_{n}(x) y=0$的一组线性无关解，则其通解为$y=C_{1} y_{1}+\cdots+C_{n} y_{n}$。这个可以从线性方程组的解的角度来理解，这里不再详述。

进而对于非齐次方程有，$y^*$是$y^{(n)}+a_{1}(x) y^{(n-1)}+\cdots+a_{n-1}(x) y^{\prime}+a_{n}(x) y=f(x)$一个的特解，则其相应的通解为$y=C_{1} y_{1}+C_{2} y_{2}+\cdots+C_{n} y_{n}+y *$。这个可以从向量组的线性表出来看。

#### 常系数齐次

$$
y^{(n)}+a_{1} y^{(n-1)}+\cdots+a_{n-1} y^{\prime}+a_{n} y=0(a_i均为常数)
$$

特征方程为
$$
r^{n}+a_{1} r^{n-1}+\cdots+a_{n-1} r+a_{n}=0
$$
$( 1)$若特征方程含$k $重实根$ r $， 则对应$k$个线性无关的解：
$$
e^{r x}, x e^{r x}, x^{2} e^{r x}, \cdots, x^{k-1} e^{r x}
$$
$(2)$若特征方程含$k $重复根$r=\alpha \pm i \beta$，则有$2k$个线性无关解：
$$
\begin{array}{l}{e^{\alpha x} \cos \beta x, \quad x e^{\alpha x} \cos \beta x, \cdots, x^{k-1} e^{\alpha x} \cos \beta x} \\ {e^{\alpha x} \sin \beta x, \quad x e^{\alpha x} \sin \beta x, \cdots, x^{k-1} e^{\alpha x} \sin \beta x}\end{array}
$$
注：不同特征根对应的解是线性无关的。

#### 常系数非齐次

$$
y^{(n)}+a_{1} y^{(n-1)}+\cdots+a_{n-1} y^{\prime}+a_{n} y=f(x)(a_i均为常数)
$$

根据解的结构来看，我们只需要找个特解就可以化归问题，以下给出两种特殊方程的特解求法。

##### $f(x)=e^{\lambda x} P_{m}(x)$型（其中$\lambda$为实数，$P_m(x)$为$m$次多项式）

考虑到$e^x$的求导性质，可设特解为$y^{*}=e^{\lambda x} Q(x)$（$Q(x)$为待定多项式），计算特解的各项导数，
$$
y^{*'}=e^{\lambda x} (Q'(x)+\lambda Q(x))\\
y^{*''}=e^{\lambda x}(Q''(x)+C^1_2\lambda Q'(x) +\lambda^2 Q(x))\\
\dots\\
y^{*(n)}=e^{\lambda x}(Q^{n}(x)+C^1_n\lambda Q^{n-1}(x)+\dots+\lambda^nQ(x))
$$
带入方程得
$$
Q^{n}(x)+(C^1_n\lambda+1)Q^{n-1}(x)+\dots+(\lambda^n+a_1\lambda^{n-1}+\dots+a_{n-2}\lambda^2+a_{n-1}\lambda+a_n)Q(x)=P_m(x)
$$
若$\lambda$不是特征方程的根，则$\lambda^n+a_1\lambda^{n-1}+\dots+a_{n-2}\lambda^2+a_{n-1}\lambda+a_n\ne0$，那么$Q(x )$即为$m$次多项式，进而使用待定系数法求$Q( x)$，特解即为$y^{*}=e^{\lambda x} Q(x)$。

若$\lambda$是特征方程的$k$重根$(k>0)$，则$Q(x ),Q'(x),\dots,Q^{k-1}(x)$的系数均为$0$，则$Q^{k}(x)$是$m$次多项式，进而使用待定系数法求$Q( x)$，特解即为$y^{*}=x^{k}e^{\lambda x} Q(x)$。

综上，特解为$y^{*}=x^{k}e^{\lambda x} Q(x)(0 \le k)$。

#### $f(x)=e^{\lambda x}\left[P_{l}(x) \cos \omega x+\widetilde{P}_{n}(x) \sin \omega x\right]$型

使用欧拉公式
$$
\begin{align*}
f(x)&=e^{\lambda x}\left[P_{l}(x) \frac{e^{i \omega x}+e^{-i \omega x}}{2}+\widetilde{P}_{n}(x) \frac{e^{i \omega x}-e^{-i \omega x}}{2 i}\right]
\\
&=\left[\frac{P_{l}(x)}{2}+\frac{\widetilde{P}_{n}(x)}{2 i}\right] e^{(\lambda+i \omega) x}+\left[\frac{P_{l}(x)}{2}-\frac{\widetilde{P}_{n}(x)}{2 i}\right] e^{(\lambda-i \omega) x}
\\
&=P_{m}(x) e^{(\lambda+i \omega) x}+\overline{P_{m}(x)} e^{(\lambda-i \omega) x}
(m=\max \{n, l\})
\\
&=P_{m}(x) e^{(\lambda+i \omega) x}+\overline{P_{m}(x) e^{(\lambda+i \omega) x}}
\end{align*}
$$
接着只需求以下两个方程的特解
$$
y^{(n)}+a_{1} y^{(n-1)}+\cdots+a_{n-1} y^{\prime}+a_{n} y=P_{m}(x) e^{(\lambda+i \omega) x}\\
y^{(n)}+a_{1} y^{(n-1)}+\cdots+a_{n-1} y^{\prime}+a_{n} y=\overline{P_{m}(x) e^{(\lambda+i \omega) x}}
$$
即化归为以上类型，特解有
$$
y_{1}^{*}=x^{k} Q_{m}(x) e^{(\lambda+i \omega) x}\\
y_{2}^{*}=\overline{y_{1}^{*}}=\overline{x^{k} Q_{m}(x) e^{(\lambda+i \omega) x}}
$$
故原方程特解为
$$
\begin{align*}
y^{*}&=y_{1}^{*}+y_{2}^{*}
\\
&=x^{k} e^{\lambda x}\left[Q_{m} e^{i \omega x}+\overline{Q_{m}} e^{-i \omega x}\right]
\\
&={x^{k} e^{\lambda x}\left[Q_{m}(\cos \omega x+i \sin \omega x)\right.} {+\overline{Q_{m}}(\cos \omega x-i \sin \omega x) ]}
\\
&=x^{k} e^{\lambda x}\left[R_{m} \cos \omega x+\widetilde{R}_{m} \sin \omega x\right]
\end{align*}
$$

#### $Euler Equation$

$$
x^{n} y^{(n)}+p_{1} x^{n-1} y^{(n-1)}+\cdots p_{n-1} x y^{\prime}+p_{n} y=f(x)(p_k为常数)
$$

我们做换元
$$
x=e^{t}\Rightarrow t=\ln x(x>0)
$$
则
$$
\frac{\mathrm{d} y}{\mathrm{d} x}=\frac{\mathrm{d} y}{\mathrm{d} t} \frac{\mathrm{d} t}{\mathrm{d} x}=\frac{1}{x} \frac{\mathrm{d} y}{\mathrm{d} t}\Rightarrow x y^{\prime}=\frac{\mathrm{d} y}{\mathrm{d} t}
\\
\frac{\mathrm{d}^{2} y}{\mathrm{d} x^{2}}=\frac{\mathrm{d}}{\mathrm{d} t}\left(\frac{1}{x} \frac{\mathrm{d} y}{\mathrm{d} t}\right) \cdot \frac{\mathrm{d} t}{\mathrm{d} x}=\frac{1}{x^{2}}\left(\frac{\mathrm{d}^{2} y}{\mathrm{d} t^{2}}-\frac{\mathrm{d} y}{\mathrm{d} t}\right) \Rightarrow x^{2} y^{\prime \prime}=\frac{\mathrm{d}^{2} y}{\mathrm{d} t^{2}}-\frac{\mathrm{d} y}{\mathrm{d} t}
\\\dots\dots
$$
我们记
$$
D=\frac{\mathrm{d}}{\mathrm{d} t}, D^{k}=\frac{\mathrm{d}^{k}}{\mathrm{d} t^{k}}(k=2,3, \cdots)
$$
由上述计算归纳可知
$$
x^{k} y^{(k)}=D(D-1) \cdots(D-k+1) y
$$
则可将原方程化为
$$
D^{n} y+b_{1} D^{n-1} y+\cdots+b_{n} y=f\left(e^{t}\right)
$$
即
$$
\frac{\mathrm{d}^{n} y}{\mathrm{d} t^{n}}+b_{1} \frac{\mathrm{d}^{n-1} y}{\mathrm{d} t^{n-1}}+\cdots+b_{n} y=f\left(e^{t}\right)
$$
