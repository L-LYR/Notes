证明：$1,sinx,cosx,sin2x,cos2x,...,sinnx,cosnx$线性无关。

证明：首先我们先有从和差化积得到的以下的等式
$$
\begin{array}{1}
\cos m x \cos n x=\frac{1}{2}[\cos (m-n) x+\cos (m+n) x]\\ 
\sin m x \sin n x=\frac{1}{2}[\cos (m-n) x-\cos (m+n) x]\\ 
\cos m x \sin n x=\frac{1}{2}[\sin (m+n) x-\sin (m-n) x]\end{array}
$$
然后有
$$
\begin{array}{1}
\int_{-\pi}^{\pi} 1 \cdot \cos n x d x=0\\
\int_{-\pi}^{\pi} 1 \cdot \sin n x d x=0\\
\int_{-\pi}^{\pi} \cos m x \cos n x d x=\pi \delta_{m n}\\
\int_{-\pi}^{\pi} \sin m x \sin n x d x=\pi \delta_{m n}\\
\int_{-\pi}^{\pi} \cos m x \sin n x d x=0\\
其中\ \delta _{mn}=\begin{cases}1,\left( m=n\right) \\ 0,\left( m\neq n\right) \end{cases} \ m,n\in N^+ 
\end{array}
$$
设$a_1,a_2,...,a_{2n+1}$使得
$$
a_1+a_2\sin x+a_3\cos x+...+a_{2n}\sin nx+a_{2n+1}\cos nx=0
$$
等式两侧同乘$\sin jx$，得
$$
a_1\sin jx+a_2\sin jx sinx+a_3\sin jx \cos x+...+a_{2n}\sin jx\sin nx+a_{2n+1}\sin jx\cos nx=0
$$
此时$j$从$1$取至$n$，我们可以对等式两侧在区间$[-\pi,\pi]$进行积分，其中含$\sin jx \cos kx $项积分均为0，得到$n$个方程，即
$$
\begin{array}{1}
\pi a_2=\pi a_4=\pi a_6=...\pi a_{2n}=0
\end{array}
$$
同理，在等式两侧同乘$cos jx$，得
$$
a_1\cos jx+a_2\cos jx sinx+a_3\cos jx \cos x+...+a_{2n}\cos jx\sin nx+a_{2n+1}\cos jx\cos nx=0
$$
此时$j$从$1$取至$n$，我们可以对等式两侧在区间$[-\pi,\pi]$进行积分，其中含$\cos jx \sin kx $项积分均为0，得到$n$个方程，即
$$
\pi a_3=\pi a_5=...\pi a_{2n+1}=0
$$
故，最后有$a_1=0$，综上，$a_i=0,i=1,2,3,...,2n+1$，即$1,sinx,cosx,sin2x,cos2x,...,sinnx,cosnx$线性无关。



证明：$sinx,sin^2x,...,sin^nx$线性无关。

证明：设$a_1,a_2,...,a_{n} $使得
$$
a_1 \sin x+a_{2}\sin ^{2}x+\ldots +a_{n}\sin ^{n}x=0
$$
等式两侧对$x$进行求导得
$$
a_1 \cos x+2a_{2}\sin x \cos x+\ldots +n a_{n}\sin ^{n-1}x \cos x=0
$$
两侧同除$\cos x$（不恒为$0$），得
$$
a_1+2a_{2}\sin x+\ldots +n a_{n}\sin ^{n-1}x=0
$$
重复进行n次以上两步可得方程组
$$
a_1 \sin x+a_{2}\sin ^{2}x+\ldots +a_{n}\sin ^{n}x=0\\
a_1+2a_{2}\sin x+3a_{3}\sin ^{2}x+\ldots +n a_{n}\sin ^{n-1}x=0\\
2a_{2}+6a_{3}\sin x+\ldots+n(n-1)a_{n}\sin ^{n-2}x=0\\
\ldots\\
(n-1)!\ a_{n-1}+n!\ a_{n}\sin x=0\\
n!\ a_{n}=0
$$
由该阶梯型线性方程组很容易解出$a_1=a_2=\ldots=a_n=0$，即$sinx,sin^2x,...,sin^nx$线性无关。



证明：在单变量实函数空间中，向量$f_1,f_2,\ldots,f_n$线性无关当且仅当存在实数$a_1,a_2,\ldots,a_n$使得$det(f_i(a_j))\ne 0$。

证明：

$\Rightarrow$证明：

首先我们记
$$
D(a_1,a_2,\ldots,a_n)^T =\begin{vmatrix} f_{1}\left( a_{1}\right) \ldots f_{n}\left( a_{1}\right) \\ \vdots\ \ \ \  \ddots\ \ \ \  \vdots \\ f_{1}\left( a_{n}\right) \ldots f_{n}\left( a_{n}\right) \end{vmatrix}
$$
接着我们对$n$进行归纳

当$n=1$时，$f_1(x)$线性无关，即不存在非零常量$k_1$使得$k_1f_1(x)=0$，则存在$a_1$使得$D(a_1)=f_1(a_1)\ne 0$。

假设当$n=k$时，结论成立，即$f_1,f_2,\ldots,f_k$线性无关则有存在实数$a_1,a_2,\ldots,a_n$使得$det(f_i(a_j))\ne 0$，即$D(a_1,a_2,\ldots,a_n)\ne 0$。

当$n=k+1$时，考虑
$$
D(a_1,a_2,\ldots,a_k,a_{k+1})^T=
\begin{vmatrix} 
f_{1}\left( a_{1}\right) \ldots f_{k}\left( a_{1}\right)\  f_{k+1}(a_1)\\
\vdots\ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \  \ddots\ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \  \vdots \\
f_{k}\left( a_{k}\right)\  \ldots\  f_{k}\left( a_{k}\right)\ \  f_{k+1}(a_k)\\ 
f_{k+1}\left( a_{k+1}\right) \ldots f_{k}\left( a_{k+1}\right)\ f_{k+1}(a_{k+1})
\end{vmatrix}
$$


将$D(a_1,a_2,\ldots,a_k,a_{k+1})$按最后一列展开得
$$
D(a_1,a_2,\ldots,a_k,a_{k+1})^T=D_{1}f_{k+1}\left( a_{1}\right) +\ldots +D_{k+1}f_{k+1}\left( a_{k+1}\right)
$$
其中$D_i(i=1,\dots,k+1)$为$f_{k+1}(a_{i})$相应的代数余子式。

注意到$D_{k+1}= D(a_1,a_2,\ldots,a_n)^T\ne 0$，又因为$f_1,f_2,\dots,f_k,f_{k+1}$线性无关，则可知$D(a_1,a_2,\ldots,a_k,a_{k+1})^T不恒为0$。

$\Leftarrow$证明：

这里我们来证的是**在单变量实函数空间中有向量$f_1,f_2,\ldots,f_n$，如果存在实数$a_1,a_2,\ldots,a_n$使得$det(f_i(a_j))\ne 0$，那么向量$f_1,f_2,\ldots,f_n$线性无关。**

等价地，我们来证其逆否命题：**在单变量实函数空间中有向量$f_1,f_2,\ldots,f_n$，如果向量$f_1,f_2,\ldots,f_n$线性相关，那么对任意实数$a_1,a_2,\ldots,a_n$恒有$det(f_i(a_j))=0$。**

由线性相关得，存在不全为零的$k_1,k_2,\dots,k_n$使得
$$
k_1f_1(x)+k_2f_2(x)+\dots+k_nf_n(x)=0
$$
从而对于$a_1,a_2,\dots,a_n​$有关于$k_1,k_2,\dots,k_n​$的线性方程组
$$
\begin{cases}
k_{1}f_{1}\left( a_{1}\right) +\ldots +k_{n}f_{n}\left( a_{1}\right) =0\\ 
\ldots \\ 
k_{1}f_{1}\left( a_{n}\right) +\ldots +k_{n}f_{n}\left( a_{n}\right) =0
\end{cases}
$$
所以
$$
\Delta =\begin{vmatrix} f_{1}\left( a_{1}\right) \ldots f_{n}\left( a_{1}\right) \\ \vdots\ \ \ \  \ddots\ \ \ \  \vdots \\ f_{1}\left( a_{n}\right) \ldots f_{n}\left( a_{n}\right) \end{vmatrix} = 0\\
$$
即
$$
D(a_1,a_2,\ldots,a_n)=\Delta^T=0
$$
故
$$
D(a_1,a_2,\ldots,a_n)=0
$$
命题得证。