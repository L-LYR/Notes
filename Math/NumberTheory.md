## 整数与余数

### 带余除法定理

若$$ a,b\in Z,b\neq 0 $$,则存在唯一的整数$q$及$r$，满足$$a=bq+r$$，$$0\leqslant r< \left |b  \right |$$。当余数$$r=0$$，即$$a=bq$$时，我们称$$a$$被$$b$$整除，记为$$b\mid a$$。进而模运算定义为$a \mod q=r$。

注：应强调的是$$r$$的取值范围。

#### 性质

若$$b\mid a$$，则$$\pm b\mid\pm  a$$。

若$$a\mid b，b\mid c$$，则$$a\mid c$$。

若$a\mid a_i,i=1,2,\cdots,k$，则$$a\mid(c_1a_1+c_2a_2+\cdots+c_ka_k)$$，这里$$c_1,c_2,\cdots,c_k$$是任意整数。

若$a\mid b,a\mid c$，则$a\mid (b+c)$。

模运算对加法，减法和乘法及乘方“分配”，形式如下：
$$
(a@b)\mod m=((a\mod m)@(b\mod m))\mod m
$$

### 模同余关系

如果$a$和$b$为整数而$m$为正整数，且满足$m\mid (a-b)$，我们记$a\equiv b(mod \ m)$，表示$a$模$m$同余$b$。等价于$a\mod m=b\mod b$，也等价于存在整数$k$使得$a=b+km$。

#### 性质

若$a\equiv b(mod \ m),c\equiv d(mod \ m)$，则$a+c\equiv b+d(mod \ m),ac\equiv bd(mod \ m)$。

若$ac\equiv bc(mod \ m),gcd(c,m)=1$，则$a\equiv b(mod \ m)$。

## 快速幂

## 素数

1. 试除法
2. 筛法

### 最大公因数和最小公倍数

两个整数$a,b$，不全为0，能够使得$d\mid a,d\mid b$同时成立的最大正整数称为二者的最大公约数，记做$d=gcd(a,b)$。当$d=1$时，我们称二者互素。而满足$a\mid d,b\mid d$同时成立的最小正整数称为二者的最小公倍数，记做$d=lcm(a,b)$。

我们有如下性质（$a,b$均为正整数）
$$
ab=gcd(a,b)\cdot lcm(a,b)
$$

### 素数分解

利用素数分解求最大公约数

### 欧几里得算法（辗转相除法）

求最大公约数。

### 贝祖定理

如果$a,b$均为正整数，则存在整数$s,t$使得$gcd(a,b)=sa+tb$。

## 同余方程

### 线性同余方程

$$
ax\equiv b(mod\ m)
$$

$m$为正整数，$a,b$为整数，$x$为未知元。

### 模逆

使得$\overline a a\equiv 1(mod\ m)$成立的$\overline a$是$a$模$m$的逆，若$m>1,gcd(a,m)$则$a$模$m$的逆存在且唯一，即存在唯一小于$m$的正整数$\overline a$是$a$模$m$的你逆，并且$a$模$m$的其他没一个逆均和$\overline a$模$m$同余。

模逆的求法就是扩展欧几里得算法求贝祖系数。

### 费马小定理

若$p$为素数，$a$是一个不能被$p$整除的整数，则
$$
a^{p-1}\equiv 1(mod \ p)\ or \ a^p\equiv a(mod \ p)
$$

## 密码学

 ### 欧拉函数

We define a function to be the number of integers $k(1\le k\le n)$, such that $gcd(k, n) = 1$. This function is called the Euler $\Phi(p)$ function.

For any prime $p$, we have $\Phi(p)=p-1$, and suppose $n=pq$ is the prime factorization of $n$ and $p\ne q$. We can prove this important property:
$$
\Phi(pq)=pq-p-q+1
$$

### 欧拉定理

当$a$与$n$互素且小于$n$则$a^{\Phi(n)}\equiv 1(mod \ n)$。

费马小定理是他的特殊情况。

### RSA

#### 特点

- 公钥密码（加密公钥可见公开）
- 利用素数分解的困难性

#### 步骤

1. 随机选取两个足够大的素数$p,q(p<q)$，记$n=pq,\phi(n)=(p-1)(q-1)$。
2. 选择正整数$e$，要求$e$与$\phi(n)$互素，求$e$模$\phi(n)$的模逆$d=\overline e$。
3. 明文数字化，分成若干段，每段$m$要求$m<min(p,q)$，确保$m,n$互素。
4. 明文：$x_1,x_2,x_3,\ldots,x_n$，加密$c_i=x_i^emod \ n$，密文：$c_1,c_2,c_3,\ldots,c_n$。
5. 解密$x_i=c_i^dmod\ n$。

因为三个自然数是相邻的.每相邻的3个自然数中必有一个能被3整除.所以他们的积也一定能被3整除.
综上所述,他们的积能同时被2和3整除,即可被6整除.
如果要用数学的算法来推导,可以这样来理解.