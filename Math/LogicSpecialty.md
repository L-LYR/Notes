# 逻辑与证明

## 命题逻辑

### 命题

> A proposition is a declarative sentence (that is, a sentence that declares a fact) that is either true or false, but not both.

命题是一个判断句，或者说它是一个陈述可以使用某种方式辨别真假的事实的语句，同时它与时间跨度无关。要注意的是，感叹句带有强烈主观色彩，不是客观冷静的判断，故不是命题。

**例**：

1. 空气是人生存所必需的。
2. 请把门关上。
3. 南京是中国的首都。
4. 你吃饭了吗？
5. x=3
6. 啊，真美呀！
7. 明年春节是个大晴天。
8. 地球外的星球上也有人
9. 小王是我的好朋友

**解**：(1)(3)(7)(8)(9)是命题。

### 联结词

- > 原子命题：由简单句形成的命题。
- > 复合命题：由一个或几个原子命题通过联结词的联接而构成的命题。
- 真值
- 命题演算（命题逻辑）
- 逻辑联结词（运算符)
    - 否定$\neg p$
    - 析取$p\lor q$
    - 合取$p\land q$
    - 异或$p\oplus q$
    - 蕴含$p\rightarrow q$（p是前件，q是后件）
    - 等值$p\leftrightarrow q$
- 逆命题，反命题，逆否命题

**注**：

1. 否定联结词否定在外部。
2. 异或联结词的等价表示：
$$
(P\land \neg Q)\lor(\neg P\land Q)=P\oplus Q
$$
3. 蕴含联结词的一些等价汉语表达：
    1. p蕴含q
    2. q的充分条件是p
    3. q仅当p
    4. q每当p
    5. q是p的必要条件
    6. q由p得出
4. 蕴含联结词的前件为假时我们不能称其为假。

### 命题公式

- > 命题变元：一个没有指定具体内容的命题符号。

- > 命题常元：一个表示确定命题的大写字母。

- > 命题公式：由0、1和命题变元以及命题联结词按一定的规则产生的符号串。（递归定义。）

  >1. 0，1是命题公式；
  >2. 命题变元是命题公式；
  >3. 如果$A$是命题公式，则$\neg A$是命题公式；
  >4. 如果$A$和$B$是命题公式，则$A\lor B,A\land B,A\rightarrow B,A\leftrightarrow B$也是命题公式；
  >5. 有限次地利用上述1-4而产生的符号串是命题公式。 
  
- > 真值指派：设$F$为含有命题变元$P_1,P_2,\dots , P_n$的命题公式，对$P_1,P_2,\dots ,P_n$分别指定一个真值，称为对公式$F$的一组真值指派。

- 公式类型

  - 重言式（永真式）
  - 矛盾式（永假式）
  - 可满足式

- > 等值关系：设$A$和$B$是两个命题公式,$P _ { 1 } , P _ { 2 } , \dots , P _ { n }$是所有出现于$A,B$中的命题变元，如果对于$P _ { 1 } , P _ { 2 } , \dots , P _ { n }$的任一组真值指派，$A,B$的真值都相同则称公式$A$和$B$等值，记为$A\Leftrightarrow B$，$A\Leftrightarrow B$称为等值式。

- > 蕴含关系：设$A$和$B$是两个公式，若公式$A\rightarrow B$是重言式，即$A\rightarrow B\Leftrightarrow 1$，则称公式$A$蕴含公式$B$，记作$A\Rightarrow B$，称$A\Rightarrow B$为蕴含

- 等值式与蕴含式的判别

  - 真值表
  - 等值演算
    - 代入规则：单一变元的等值代换。
    - 置换规则：子公式的等值置换。
    - 假定前件为真（顺推）
    - 假定后件为假（逆推）（逆否命题）

- 等值演算实例：

  1. 证明等值关系：$( P \wedge Q ) \vee ( \neg P \vee ( \neg P \vee Q ) ) \Leftrightarrow \neg P \vee Q$

     证明：
     $$
     \begin{align}
     ( P \wedge Q ) \vee ( \neg P \vee ( \neg P \vee Q ) ) \Leftrightarrow & ( P \wedge Q ) \vee ( \neg P \vee \neg P ) \vee Q )\\
     \Leftrightarrow &( P \wedge Q ) \vee ( \neg P \vee Q )\\
     \Leftrightarrow &( \neg P \vee Q ) \vee ( P \wedge Q )\\
     \Leftrightarrow & \neg \mathbf { P } \vee ( \mathbf { Q } \vee ( \mathbf { P } \wedge \mathbf { Q } ) )\\
     \Leftrightarrow & \neg P \vee Q
     \end{align}
     $$

  2. 证明蕴含关系：$P \wedge ( P \rightarrow Q ) \Rightarrow Q$

     证明：
     $$
     \begin{align}
     ( P \wedge ( P \rightarrow Q ) ) \rightarrow Q \Leftrightarrow & \neg ( \mathrm { P } \wedge ( \neg \mathrm { P } \vee  \mathrm { Q }  ) \vee \mathrm { Q }\\
     \Leftrightarrow &( \neg \mathrm { P } \vee \neg ( \neg \mathrm { P } \vee  \mathrm { Q }  ) \vee \mathrm { Q }\\
     \Leftrightarrow & ( \neg \mathrm { P } \vee ( \mathrm { P } \wedge \neg \mathrm { Q }  ) \vee \mathrm { Q }\\
     \Leftrightarrow &(( \neg \mathrm { P } \vee  \mathrm { P } )\wedge( P \vee \neg \mathrm { Q }  )) \vee \mathrm { Q } \\
     \Leftrightarrow & P \vee \neg \mathrm { Q }   \vee \mathrm { Q } \\
     \Leftrightarrow & 1
     \end{align}
     $$

  3. 证明：$\neg Q \wedge ( P \rightarrow Q ) \Rightarrow \neg P$

     证明：

     假定前件为真，则有$\neg Q$和$P\rightarrow Q$为真，则$Q$为假，进而$P$为假，所有$\neg P$为真，故蕴含式成立。

  4. 证明：$( \mathbf { P } \rightarrow \mathbf { Q } ) \wedge ( \mathbf { R } \rightarrow \mathbf { S } ) \Rightarrow ( \mathbf { P } \wedge \mathbf { R } ) \rightarrow ( \mathbf { Q } \wedge \mathbf { S } )$

     证明：

     假定后件为假，即$( \mathbf { P } \wedge \mathbf { R } ) \rightarrow ( \mathbf { Q } \wedge \mathbf { S } )$为假，则$P\wedge R$为真，$Q\wedge S$为假，故$P,R$均为真，$Q,S$中至少有一个为假，则$P\rightarrow Q$和$R\rightarrow S$中至少有一个为假，则$( \mathbf { P } \rightarrow \mathbf { Q } ) \wedge ( \mathbf { R } \rightarrow \mathbf { S } ) $为假，故蕴含式成立。

**注**：

1. $\Leftrightarrow$和$\Rightarrow$不是联结词，要区分于$\leftrightarrow$，前者表示一种关系。$A\Leftrightarrow B$当且仅当$A\leftrightarrow B$是永真式。$A\Rightarrow B$当且仅当$A\rightarrow B$是永真式。

2. 等值关系是一种等价关系。这个很好证。

3. 蕴含关系是一种偏序关系。下给出证明：

   1. 自反性：$A\Rightarrow A$。

   因为$(A\rightarrow A)\Leftrightarrow (\neg A\vee A)\Leftrightarrow1$。

   2. 反对称性：若$A\Rightarrow B$，$B\Rightarrow A$，则$A\Leftrightarrow B$。

   因为$A\Rightarrow B$，$B\Rightarrow A$，则有$A\rightarrow B \Leftrightarrow 1$和$B\rightarrow A \Leftrightarrow 1$。故有
   $$
   \begin{aligned} \mathbf { A } \leftrightarrow \mathbf { B } & \Leftrightarrow ( \mathbf { A } \rightarrow \mathbf { B } ) \wedge ( \mathbf { B } \rightarrow \mathbf { A } ) \\ & \Leftrightarrow \mathbf { 1 } \wedge \mathbf { 1 } \\ & \Leftrightarrow \mathbf { 1 } \end{aligned}
   $$
   
   即有$A\Leftrightarrow B$。
   
   3. 传递性：若$A\Rightarrow B $，$B\Rightarrow C$，则$A\Rightarrow C$
   
   因为$A\Rightarrow B$，$B\Rightarrow C $，则$A\rightarrow B \Leftrightarrow 1$和$B\rightarrow C \Leftrightarrow 1$。故有
   $$
   \begin{align}
   A\rightarrow C \Leftrightarrow&\neg A\vee C\\
   \Leftrightarrow&\neg A\vee B \vee \neg B\vee C\\
   \Leftrightarrow&(A\rightarrow B)\vee(B\rightarrow C)\\
   \Leftrightarrow&1\vee 1\\
   \Leftrightarrow&1
   \end{align}
   $$
   即$A\Rightarrow C$。

### 基本等值关系

$$
\begin{array} { l } {\mathrm { P } \vee \mathrm { Q } \Leftrightarrow \mathrm { Q } \vee \mathrm { P } } & (1)\\ 
{ \mathrm { P } \wedge \mathrm { Q } \Leftrightarrow \mathrm { Q } \wedge \mathrm { P } }& (2)\\
( P \vee Q ) \vee R \Leftrightarrow P \vee ( Q \vee R )& (3)\\
( P \wedge Q ) \wedge R \Leftrightarrow P \wedge ( Q \wedge R )& (4)\\
\mathrm { P } \wedge ( \mathrm { Q } \vee \mathrm { R } ) \Leftrightarrow ( \mathrm { P } \wedge \mathrm { Q } ) \vee ( \mathrm { P } \wedge \mathrm { R } )& (5)\\
P \vee ( Q \wedge R ) \Leftrightarrow ( P \vee Q ) \wedge ( P \vee R )& (6)\\
\mathrm { P } \vee 0 \Leftrightarrow \mathrm { P }& (7)\\
P \wedge 1 \Leftrightarrow P& (8)\\
\neg ( \neg \mathrm { P } ) \Leftrightarrow \mathrm { P }& (9)\\
P \vee P \Leftrightarrow P& (10)\\
P \wedge P \Leftrightarrow P& (11)\\
P \vee 1 \Leftrightarrow 1& (12)\\
\mathrm { P } \wedge 0 \Leftrightarrow 0& (13)\\
P \vee ( P \wedge Q ) \Leftrightarrow P& (14)\\
P \wedge ( P \vee Q ) \Leftrightarrow P& (15)\\
\neg ( \mathrm { P \vee Q } ) \Leftrightarrow \neg \mathrm { P } \wedge \neg \mathrm { Q }& (16)\\
\neg ( \mathrm { P } \wedge \mathrm { Q } ) \Leftrightarrow \neg \mathrm { P } \vee \neg \mathrm { Q }& (17)\\
\mathrm { P } \rightarrow \mathrm { Q } \Leftrightarrow \neg \mathrm { P } \vee \mathrm { Q }& (18)\\
\mathrm { P } \leftrightarrow \mathrm { Q } \Leftrightarrow ( \mathrm { P } \wedge \mathrm { Q } ) \vee ( \neg \mathrm { P } \wedge \neg \mathrm { Q } )& (19)\\
P \rightarrow ( Q \rightarrow R ) \Leftrightarrow ( P \wedge Q ) \rightarrow R& (20)\\
\mathrm { P } \leftrightarrow \mathrm { Q } \Leftrightarrow ( \mathrm { P } \rightarrow \mathrm { Q } ) \wedge ( \mathrm { Q } \rightarrow \mathrm { P } )& (21)\\
P \rightarrow Q \Leftrightarrow \neg Q \rightarrow \neg P& (22)\\
\neg(P\leftrightarrow Q)\Leftrightarrow P\leftrightarrow \neg Q &(23)\\
P\vee \neg P\Leftrightarrow 1&(24)\\
P\wedge \neg P\Leftrightarrow 0&(25)\\
\end{array}
$$

针对式（20）的简单证明：
$$
\begin{align}
& P \rightarrow ( Q \rightarrow R )&\\
\Leftrightarrow & P\rightarrow (\neg Q \vee R)& \\
\Leftrightarrow & \neg P \vee \neg Q \vee R&\\
\Leftrightarrow & \neg(P \wedge Q) \vee R&\\
\Leftrightarrow& ( P \wedge Q ) \rightarrow R&
\end{align}
$$

### 基本蕴含式

$$
\begin{array} { l } 
{ \mathrm { P } \wedge \mathrm { Q } \Rightarrow \mathrm { P } } &(1)\\
{ \mathrm { P } \wedge \mathrm { Q } \Rightarrow \mathrm { Q } } &(2)\\
\mathrm { P } \Rightarrow \mathrm { P \vee Q }&(3)\\
Q \Rightarrow P \vee Q&(4)\\
\neg P \Rightarrow P \rightarrow Q&(5)\\
\mathrm { Q } \Rightarrow \mathrm { P } \rightarrow \mathrm { Q }&(6)\\
\neg ( \mathbf { P } \rightarrow \mathbf { Q } ) \Rightarrow \mathbf { P }&(7)\\
\neg ( \mathbf { P } \rightarrow \mathbf { Q } ) \Rightarrow \neg \mathbf { Q }&(8)\\
\neg P \wedge ( P \vee Q ) \Rightarrow Q&(9)\\
\mathbf { P } \wedge ( \mathbf { P } \rightarrow \mathbf { Q } ) \Rightarrow \mathbf { Q }&(10)\\
\neg \mathbf { Q } \wedge ( \mathbf { P } \rightarrow \mathbf { Q } ) \Rightarrow \mathbf { P }&(11)\\
( \mathbf { P } \rightarrow \mathbf { Q } ) \wedge ( \mathbf { Q } \rightarrow \mathbf { R } ) \Rightarrow \mathbf { P } \rightarrow \mathbf { R }&(12)\\
( \mathbf { P } \vee Q ) \wedge ( P \rightarrow R ) \wedge ( Q \rightarrow R ) \Rightarrow R&(13)\\
\mathbf { P } \rightarrow \mathbf { Q } \Rightarrow ( \mathbf { P } \vee \mathbf { R } ) \rightarrow ( \mathbf { Q } \vee \mathbf { R } )&(14)\\
\mathbf { P } \rightarrow \mathbf { Q } \rightarrow ( \mathbf { P } \wedge \mathbf { R } ) \rightarrow ( \mathbf { Q } \wedge \mathbf { R } )&(15)
\end{array}
$$

### 范式

- > 质合取式：一个命题公式若它具有$P _ { 1 }^* \wedge P _ { 2 } ^ { * } \wedge \ldots \wedge P _ { n } ^ { * }$的形式$(n\ge 1)$，其中$P_i^*$是命题变元$P_i$本身或其否定，则称之为质合取式。
  
  - 例：$\neg P \wedge Q \wedge R \wedge S$
  
- > 质析取式：一个命题公式若它具有$P _ { 1 }^* \vee P _ { 2 } ^ { * } \vee \ldots \vee P _ { n } ^ { * }$的形式$(n\ge 1)$，其中$P_i^*$是命题变元$P_i$本身或其否定，则称之为质合取式。
  
  - 例：$\neg Q \vee P \vee \neg R$
  
- 两个很显然的定理
  - > 一**质合取式**为**永假式**的充分必要条件是，它**同时**包含某个命题变元及其否定。
  - > 一**质析取式**为**永真式**的充分必要条件是，它**同时**包含某个命题变元及其否定
  
- > 析取范式：质合取式的析取。
  
  - 例：$F= \mathrm { P } \vee ( \mathrm { P } \wedge \mathrm { Q } ) \vee \mathrm { R } \vee ( \neg \mathrm { P } \wedge \neg \mathrm { Q } \wedge \mathrm { R } )$
  
- > 合取范式：质析取式的合取。
  
  - 例：$\mathrm { F }  = \neg \mathrm { P } \wedge ( \mathrm { P } \vee Q ) \wedge \mathrm { R } \wedge ( \mathrm { P} \vee \neg \mathrm { Q } \vee \mathrm { R } )$
  
- 求析取范式和合取范式的方法;
  1. 利用置换原则消去$\leftrightarrow $和$\rightarrow$；
  2. 利用德摩根律和双重否定律将$\neg $放进内层并化简；
  3. 利用分配律和结合律归约化得析取范式和合取范式。
  
  - 例：求$\mathbf { F } _ { 1 } = ( \mathbf { P } \wedge ( \mathbf { Q } \rightarrow \mathbf { R } ) ) \rightarrow \mathbf { S }$和$\mathrm { F } _ { 2 } = \neg ( \mathrm { P\vee Q } ) \leftrightarrow ( \mathrm { P } \wedge \mathrm { Q } )$的合取范式和析取范式
  
  - 解：
  
    1. 析取范式：
  
    $$
    \begin{align}
    \mathbf { F } _ { 1 } = ( \mathbf { P } \wedge ( \mathbf { Q } \rightarrow \mathbf { R } ) ) \rightarrow \mathbf { S }\Leftrightarrow& \neg(P\wedge(\neg Q\vee R))\vee S\\
    \Leftrightarrow& \neg P\vee\neg(\neg Q \vee R)\vee S\\
    \Leftrightarrow& \neg P\vee(Q\wedge \neg R)\vee S\\\\
    \mathrm { F } _ { 2 } = \neg ( \mathrm { P\vee Q } ) \leftrightarrow ( \mathrm { P } \wedge \mathrm { Q } ) \Leftrightarrow &( \neg ( \mathbf { P } \vee \mathbf { Q } ) \rightarrow ( \mathbf { P } \wedge \mathbf { Q } ) ) \wedge ( ( \mathbf { P } \wedge \mathbf { Q } ) \rightarrow \neg( \mathbf { P } \vee \mathbf { Q } ) )\\
    \Leftrightarrow &( ( P \vee Q ) \vee ( P \wedge Q ) ) \wedge ( \neg ( P \wedge Q ) \vee \neg ( P \vee Q ) )\\
    \Leftrightarrow &( \mathbf { P } \vee ( \mathbf { Q } \vee ( \mathbf { P } \wedge \mathbf { Q } ) ) ) \wedge ( \neg \mathbf { P } \vee \neg \mathbf { Q } \vee ( \neg \mathbf { P } \wedge \neg \mathbf { Q } ) )\\
    \Leftrightarrow &( P \vee Q ) \wedge ( \neg P \vee \neg Q )\\
    \Leftrightarrow &( P \wedge ( \neg P \vee \neg Q ) ) \vee ( Q \wedge ( \neg P \vee \neg Q ) )\\
    \Leftrightarrow &( P \wedge \neg P ) \vee ( P \wedge \neg Q ) \vee ( \neg P \wedge Q ) \vee ( Q \wedge \neg Q )
    \end{align}
    $$
  
    2. 合取范式：
       $$
       \begin{align}
       \mathbf { F } _ { 1 } = ( \mathbf { P } \wedge ( \mathbf { Q } \rightarrow \mathbf { R } ) ) \rightarrow \mathbf { S }\Leftrightarrow& \neg(P\wedge(\neg Q\vee R))\vee S\\
       \Leftrightarrow& \neg P\vee S\vee\neg(\neg Q \vee R)\\
       \Leftrightarrow& \neg P \vee S \vee(Q\wedge \neg R)\\
       \Leftrightarrow&(\neg P\vee S\vee Q)\wedge(\neg P\vee S\vee \neg R)\\\\
       \mathrm { F } _ { 2 } = \neg ( \mathrm { P\vee Q } ) \leftrightarrow ( \mathrm { P } \wedge \mathrm { Q } ) \Leftrightarrow &( \neg ( \mathbf { P } \vee \mathbf { Q } ) \rightarrow ( \mathbf { P } \wedge \mathbf { Q } ) ) \wedge ( ( \mathbf { P } \wedge \mathbf { Q } ) \rightarrow \neg( \mathbf { P } \vee \mathbf { Q } ) )\\
       \Leftrightarrow &( ( P \vee Q ) \vee ( P \wedge Q ) ) \wedge ( \neg ( P \wedge Q ) \vee \neg ( P \vee Q ) )\\
       \Leftrightarrow &( \mathbf { P } \vee ( \mathbf { Q } \vee ( \mathbf { P } \wedge \mathbf { Q } ) ) ) \wedge ( \neg \mathbf { P } \vee \neg \mathbf { Q } \vee ( \neg \mathbf { P } \wedge \neg \mathbf { Q } ) )\\
       \Leftrightarrow &( P \vee Q ) \wedge ( \neg P \vee \neg Q )\\
       \end{align}
       $$
       
  
- 又有两个很显然的定理
  - > 一公式为**永真式**的充分必要条件是，它的**合取范式**中每一质析取式**至少**包含一对**互为否定**的**析取项**。 
  - > 一公式为**永假式**的充分必要条件是，它的**析取范式**中每一质合取式**至少**包含一对**互为否定**的**合取项**。 
  
- > 最小项：设有命题变元$P_1,P_2,\ldots,P_n$，形如$\bigvee_{i=1}^n P^*_i$的命题公式称为是由命题变元$P_1,P_2,\ldots,P_n$所产生的最小项。其中$P_i^*$是命题变元$P_i$本身或其否定。

    - $\mathrm { P } _ { 1 }  \vee  \neg \mathrm { P } _ { 2 } \vee \mathrm { P } _ { 3 }$

- > 最大项：设有命题变元$P_1,P_2,\ldots,P_n$，形如$\bigwedge_{i=1}^n P^*_i$的命题公式称为是由命题变元$P_1,P_2,\ldots,P_n$所产生的最小项。其中$P_i^*$是命题变元$P_i$本身或其否定。

  - $\mathrm { P } _ { 1 } \wedge \mathrm { P } _ { 2 } \wedge \mathrm { P } _ { 3 }$和 $\neg \mathrm { P } _ { 1 } \wedge \mathrm { P } _ { 2 } \wedge \neg \mathrm { P } _ { 3 }$

- > 主析取范式：由不同最小项所组成的析取式。

    - $\left( \neg P _ { 1 } \wedge \neg P _ { 2 } \wedge P _ { 3 } \right) \vee \left( \neg P _ { 1 } \wedge P _ { 2 } \wedge P _ { 3 } \right) \vee \left( P _ { 1 } \wedge P _ { 2 } \wedge P _ { 3 } \right)$

- > 主合取范式：由不同最大项所组成的合取式

    - $\left( P _ { 1 } \vee \neg P _ { 2 } \vee P _ { 3 } \right) \wedge \left( P _ { 1 } \vee P _ { 2 } \vee P _ { 3 } \right) \wedge \left( \neg P _ { 1 } \vee - P _ { 2 } \vee - P _ { 3 } \right) \wedge \left( \neg P _ { 1 } \vee P _ { 2 } \vee \neg P _ { 3 } \right)$

- 求主析取范式和主合取范式：
  
  1. 先将命题公式化为析取范式或合取范式；
  2. 将所得的析取范式或合取范式依据各种律进一步变换为最小项或最大项形式。
  
  - 例：求$\mathbf { F } _ { 1 } = \mathbf { P } \rightarrow ( \mathbf { P } \wedge ( \mathbf { Q } \rightarrow \mathbf { P } ) )$和$\mathbf { F } _ { 2 } = ( \mathbf { P } \rightarrow \mathbf { Q } ) \wedge ( \mathbf { P } \wedge \neg \mathbf { Q } )$的主合取范式和主析取范式。
  
  - 解：
  
    1. 主析取范式：
       $$
       \begin{align}
       \mathbf { F } _ { 1 } = \mathbf { P } \rightarrow ( \mathbf { P } \wedge ( \mathbf { Q } \rightarrow \mathbf { P } ) )
       \Leftrightarrow &\neg P\vee (P\wedge (\neg Q\vee P))\\
       \Leftrightarrow &\neg P\vee(P\wedge \neg Q)\vee(P\wedge P)\\
       \Leftrightarrow &(\neg P\wedge(\neg Q\vee Q))\vee(P\wedge \neg Q)\vee (P\wedge(\neg Q\vee Q))\\
       \Leftrightarrow &( - P \wedge Q ) \vee ( - P \wedge \neg Q ) \vee ( P \wedge \neg Q ) \vee ( P \wedge Q ) \vee ( P \wedge \neg Q )\\
       \Leftrightarrow &( \neg P \wedge Q ) \vee ( \neg P \wedge \neg Q ) \vee ( P \wedge \neg Q ) \vee ( P \wedge Q )\\\\
       \mathbf { F } _ { 2 } = ( \mathbf { P } \rightarrow \mathbf { Q } ) \wedge ( \mathbf { P } \wedge \neg \mathbf { Q } )
       \Leftrightarrow &(\neg P\vee Q)\wedge(P\wedge\neg Q)\\
       \Leftrightarrow &(\neg P \wedge P\wedge \neg Q)\vee(Q\wedge P \wedge \neg Q)\\
       \Leftrightarrow &0
       \end{align}
       $$
  
    2. 主合取范式：
       $$
       \begin{align}
       \mathbf { F } _ { 1 } = \mathbf { P } \rightarrow ( \mathbf { P } \wedge ( \mathbf { Q } \rightarrow \mathbf { P } ) )
       \Leftrightarrow &\neg P\vee (P\wedge (\neg Q\vee P))\\
       \Leftrightarrow &(\neg P\vee P)\wedge(\neg P \vee(\neg Q\vee P))\\
       \Leftrightarrow &1\\\\
       \mathbf { F } _ { 2 } = ( \mathbf { P } \rightarrow \mathbf { Q } ) \wedge ( \mathbf { P } \wedge \neg \mathbf { Q } )
       \Leftrightarrow &(\neg P\vee Q)\wedge(P\wedge \neg Q)\\
       \Leftrightarrow &(\neg P\vee Q)\wedge (P\vee(Q\wedge\neg Q))\wedge(\neg Q\vee (P\wedge\neg P))\\
       \Leftrightarrow &(\neg P\vee Q)\wedge(P\vee Q)\wedge(P\vee \neg Q)\wedge(\neg Q \vee P)\wedge(\neg Q\vee \neg P)\\
       \Leftrightarrow &(\neg P\vee Q)\wedge(P\vee Q)\wedge(P\vee \neg Q)\wedge(\neg P\vee \neg Q)\\
       \end{align}
       $$
  
- 又又有俩很显然的定理：
  
  - > 每一个**不为永假**的命题公式$F(P_1, P2_, \ldots, P_n)$必与一个由$P_1，P_2， \ldots，P_n$所产生的**主析取范式**等值。 
  - >每一个**不为永真**的命题公式$F(P_1, P2_, \ldots, P_n)$必与一个由$P_1，P_2， \ldots，P_n$所产生的**主合取范式**等值。 
  
- 这里就有两条很显然的推论：
  
  - > **永真公式**的**主析取范式**包含所有$2^n$个**最小项**。**永真公式**的**主合取范式**是一个空公式，用**1**表示。
  
  - > **永假公式**的**主析取范式**是一个空公式，用**0**表示。**永假公式**的**主合取范式**包含所有$2^n$个**最大项**。
  
  - 该推论可以用来判断命题公式的类型。

### 命题演算

- > 推理：推理是由已知的命题得到新命题的思维过程。

  - 设$A$和$B$是两个命题公式，如果$A\Rightarrow B$，即如果命题公式$A\rightarrow B$为重言式，则称$B$是前提$A$的结论或从$A$推出结论$B$。其中$A$可以换作一个命题公式集合$\{ H_1,H_2,\ldots,H_n \}$。

- 判断由一个前提集合能否推出某个结论

  - 真值表法：考虑命题公式$\left( H _ { 1 } \wedge H _ { 2 } \wedge \cdots \wedge H _ { n } \right) \rightarrow C$。

  - 真值演算

    - 例：证明$\neg ( P \wedge \neg Q ) , \neg Q \vee R , \neg R \Rightarrow \neg P$

    - 证明：考虑蕴含式$\neg ( P \wedge \neg Q ) \wedge ( \neg Q \vee R ) \wedge \neg R \Rightarrow \neg P$；

      故只需证明$( \neg ( P \wedge \neg Q ) \wedge ( \neg Q \vee R ) \wedge \neg R ) \rightarrow \neg P$永真即可。
      $$
      \begin{array} { l } 
      { \quad ( \neg ( P \wedge \neg Q ) \wedge ( \neg Q \vee R ) \wedge \neg R ) \rightarrow \neg P } \\ 
      { \Leftrightarrow ( ( \neg P \vee Q ) \wedge ( ( \neg Q \vee R ) \wedge \neg R ) ) \rightarrow \neg P } \\ 
      { \Leftrightarrow ( ( \neg P \vee Q ) \wedge ( ( \neg Q \wedge \neg R ) \vee ( R \wedge \neg R ) ) ) \rightarrow P } \\ 
      { \Leftrightarrow ( ( \neg P \vee Q ) \wedge ( \neg Q \wedge \neg R ) ) \rightarrow P}\\
      { \Leftrightarrow ( ( \neg P \wedge \neg Q \wedge \neg R ) \vee ( Q \wedge \neg Q \wedge \neg R ) ) \rightarrow P } \\ 
      { \Leftrightarrow ( \neg P \wedge \neg Q \wedge \neg R ) \rightarrow \neg P } \\ 
      { \Leftrightarrow \neg ( \neg P \wedge \neg Q \wedge \neg R ) \vee \neg P } \\ 
      { \Leftrightarrow P \vee Q \vee R \vee \neg P \Leftrightarrow 1 }
      \end{array}
      $$

  - 形式证明法
    - 基本概念
      - > 形式证明：一个描述推理过程的命题序列，其中每个命题或者是已知的命题，或者是由某些前提所推得的结论，序列中最后一个命题就是所要求的结论，这样的命题序列称为形式证明。 
    
      - > 有效的证明：如果证明过程中的每一步所得到的结论都是根据推理规则得到的，则这样的证明称作是有效的。
      - > 有效的结论：通过有效的证明而得到结论，称作是有效的结论。
      - > 合理的证明：一个证明是否有效与前提的真假没有关系如果所有的前提都是真的，那么通过有效的证明所得到的结论也是真的，这样的证明称作是合理的。
      - > 合理的结论：一个结论是否有效与它自身的真假没有关系。通过合理证明而得到的结论称作合理的结论。
      
    - 推理规则
    
      - > 前提引用规则：在证明的任何步骤上都可以引用提。
      - > 结论引用规则：在证明的任何步骤上所得到的结论都可以在其后的证明中引用。
      - > 置换规则：在证明的任何步骤上，命题公式的子公式都可以用与它等值的其它命题公式置换。
      - >代入规则：在证明的任何步骤上，重言式中的任一命题变元都可以用一命题公式代入，得到的仍是重言式。
      
    - 依旧使用上面的例子，例：证明$\neg ( P \wedge \neg Q ) , \neg Q \vee R , \neg R \Rightarrow \neg P$
    
    - 证明：
    
      | 步骤 | 公式                       | 依据     |
      | ---- | :------------------------- | -------- |
      | 1    | $\neg R$                   | 前提引入 |
      | 2    | $\neg Q\vee R$             | 前提引入 |
      | 3    | $Q\rightarrow R$           | 依据2    |
      | 4    | $\neg  Q$                  | 依据1，3 |
      | 5    | $\neg ( P \wedge \neg Q )$ | 前提引入 |
      | 6    | $P\rightarrow Q $          | 依据5    |
      | 7    | $\neg  P$                  | 依据4，6 |
    
  - 间接证明(或反证法)
      - 理论依据
          - 如果对于出现在公式$H_1,H_2,\ldots,H_n$中的命题变元的任何一组真值指派，公式$H_1,H_2,\ldots,H_n$中至少有一个为假，即它们的合取式$H_1\wedge H_2\wedge\ldots\wedge H_n$是矛盾式，则称公式$H_1,H_2,\ldots,H_n$是不相容的。否则称公式$H_1,H_2,\ldots,H_n$是相容的。 
        - 若存在一个公式$R$，使得$H_1\wedge H_2\wedge\ldots\wedge H_n\Rightarrow (R\wedge\neg R) $则公式$H_1,H_2,\ldots,H_n$是不相容的。
        
      - 解释：要想证明$\left( H _ { 1 } \wedge H _ { 2 } \wedge \cdots \wedge H _ { n } \right) \Rightarrow C$，则依据上述理论，则可将$\neg C$加入到前提中，转化为证明
          $$
          \left( H _ { 1 } \wedge H _ { 2 } \wedge \cdots \wedge H _ { n }\wedge \neg C \right) \Rightarrow R\wedge \neg R
          $$
          于是可以得出$\left( H _ { 1 } \wedge H _ { 2 } \wedge \cdots \wedge H _ { n }\wedge \neg C \right)$是不相容的，即$\left( H _ { 1 } \wedge H _ { 2 } \wedge \cdots \wedge H _ { n }\wedge \neg C \right)$是永假式，则当$\left( H _ { 1 } \wedge H _ { 2 } \wedge \cdots \wedge H _ { n }\right)$为真时，$\neg C$必为假，即$C$必为真。
      
      - 依旧使用上面的例子，例：证明$\neg ( P \wedge \neg Q ) , \neg Q \vee R , \neg R \Rightarrow \neg P$
      
      - 证明：
      
          使用反证法，将$P$添加至前提中。
      
          | 步骤 | 公式                    | 依据     |
          | ---- | ----------------------- | -------- |
          | 1    | P                       | 附加前提 |
          | 2    | $\neg (P\wedge \neg Q)$ | 前提引入 |
          | 3    | $P\rightarrow Q$        | 依据2    |
          | 4    | Q                     | 依据1，4 |
          | 5 | $\neg R$ | 前提引入 |
          | 6 | $\neg Q\vee R$ | 前提引入 |
          | 7 | $Q\rightarrow R$ | 依据2 |
          | 8 | $\neg  Q$ | 依据1，3 |
          | 9 | $Q\wedge \neg Q$ | 依据4，8 |
      
          则可知$\neg ( P \wedge \neg Q ) , \neg Q \vee R , \neg R \Rightarrow \neg P$。

## 谓词逻辑

### 谓词、个体词和量词
- 个体词和谓词：在谓词演算中，可将原子命题分解为谓词与个体词两部分。个体是指可以独立存在的客体，用来刻画个体的性质或个体之间关系的词称为谓词，刻画一个个体性质的词称为一元谓词，刻画$n$个个体之间关系的词称为$n$元谓词。一般地，一个由$n$个个体和$n$元谓词所组成的命题可表示为$F(a_1,a_2, \ldots ,a_n)$，其中$F$表示$n$元谓词，$a_1,a_2, \ldots ,a_n$分别表示$n$个个体。其中$a_1,a_2, \ldots ,a_n$的排列次序是非常重要的。
- 个体变元和命题函数
    - 个体常元：表示具体或特定的个体的个体词称为个体常元。
    - 个体变元：表示抽象的，或泛指的（或者说取值不确定的）个体称为个体变元。
    - 命题函数：由一个谓词和若干个个体变元组成的命题形式称为简单命题函数，表示为$P(x_1,x_2,\ldots,x_n)$。由一个或若干个简单命题函数以及逻辑联结词组成的命题形式称为复合命题函数。
    - 在命题函数中，个体变元的取值范围称为个体域。
- 命题符号化
    - 量词：在命题里表示数量的词。
        - 全称量词
        - 存在量词
    - 全总个体域：含有量词的命题的表达式的形式，与个体域有关。含有量词的命题的真值与个体域也有关。宇宙间所有的个体聚集在一起所构成的集合称为全总个体域。
    - 对个体变化的真正取值范围，用特性谓词加以限制。一般地，对全称量词，此特性谓词作蕴含的前件；对存在量词，此特性谓词常作合取项
- 例：**不是一切人都一样高。** 
- 解：$M(x)$：$x$是人；$G(x,y)$：$x$与$y$一样高，故可表示为$\neg  \forall x \forall y ( ( M ( x ) \wedge M ( y ) ) \rightarrow \neg G ( x , y ) )$。

### 谓词公式

- 递归定义
    1. 命题常元、命题变元和简单命题函数都是谓词公式。
   2. 如果$A$是谓词公式，则$A$也是谓词公式。
   2. 如果$A$和$B$是谓词公式，则$A\lor B,A\land B,A\rightarrow B,A\leftrightarrow B$也是谓词公式。
   3. 如果$A$是谓词公式，$x$是$A$中的个体变元，则$\forall xA$$\exist xA$和也是谓词公式。
   4. 只有由使用上述四条规则有限次而得到的才是谓词公式。   
- 辖域：在谓词公式中，形如$\forall xA(x)$或$\exist x A(x)$的那一部分称为公式的$x$约束部分。而$A(x)$称作量词$\forall  x，\exist x$的辖域。公式中被约束出现的变元即为约束变元，反之，自由出现时即为自由变元。
    - 换名规则：对约束变元进行换名，使得一个变元在一个公式中只呈一种形式出现。约束变元换名时，该变元在量词及其辖域中的所有出现均须同时更改，公式的其余部分不变；换名时，一定要更改为该量词辖域中没有出现过的符号，最好是公式中未出现过的符号。
    - 代入规则：对于公式中自由变元的更改叫做代入。对于谓词公式中的自由变元可以代入，代入时须对该自由变元的所有自由出现同时进行代入；代入时所选用的变元符号与原公式中所有变元的符号不相同。

### 谓词公式的等值与蕴含

- 指派：一组代入到谓词公式中，并使得谓词公式成为命题的确定的个体和命题称为公式的一组指派。
- 公式类型
  
    - 给定谓词公式$A$，其个体域为$E$，如果对于任一组指派，公式$A$的值总是为真，则称$A$在$E$上是永真的。如果对于公式$A$的任一组指派，公式$A$的值总是为假，则称$A$在$E$上是永假的。如果至少存在着一组指派，使公式$A$的值为真，则称$A$在$E$上是可满足的。 
- 等值与蕴含：设$A,B$是两个公式，它们有共同的个体域$E$，若对于$A$和$B$的任意一组指派，两公式都具有相同的真值，则称公式$A$和$B$在$E$上等值，记作$A\Leftrightarrow B$。若$A\rightarrow B\Leftrightarrow 1$，则称公式$A$蕴含公式$B$，记作$A\Rightarrow B$。
    - 实质上可以理解为命题公式的推广。如：
        $$
        \begin{array} { l } { P \rightarrow Q \Leftrightarrow \neg P \vee Q } \\ { \forall x P ( x ) \rightarrow \exists x Q ( x ) \Leftrightarrow \neg \forall x P ( x ) \vee \exists x Q ( x ) } \end{array}
        $$

### 基本等值式

量词转换
$$
\begin{array} { l } { \neg \forall x A ( x ) \Leftrightarrow \exists x \neg A ( x ) } \\ { \neg \exists x A ( x ) \Leftrightarrow \forall x \neg A ( x ) } \end{array}
$$
量词辖域扩展与收缩
$$
\begin{array} { l } { \forall x ( A ( x ) \vee B ) \Leftrightarrow \forall x A ( x ) \vee B } \\ { \forall x ( A ( x ) \wedge B ) \Leftrightarrow \forall x A ( x ) \wedge B } \\ { \exists x ( A ( x ) \vee B ) \Leftrightarrow \exists x A ( x ) \vee B } \\ { \exists x ( A ( x ) \wedge B ) \Leftrightarrow \exists x A ( x ) \wedge B } \end{array}\\
\begin{array} { l } { \forall x ( A ( x ) \rightarrow B ) \Leftrightarrow \exists x A ( x ) \rightarrow B } \\ { \forall x ( B \rightarrow A ( x ) ) \Leftrightarrow B \rightarrow \forall x A ( x ) } \\ { \exists x ( A ( x ) \rightarrow B ) \Leftrightarrow \forall x A ( x ) \rightarrow B } \\ { \exists x ( B \rightarrow A ( x ) ) \Leftrightarrow B \rightarrow \exists x A ( x ) } \end{array}
$$
量词分配
$$
\begin{array} { l } { \forall x ( A ( x ) \wedge B ( x ) ) \Leftrightarrow \forall x A ( x ) \wedge \forall x B ( x ) } \\ { \exists x ( A ( x ) \vee B ( x ) ) \Leftrightarrow \exists x A ( x ) \vee \exists x B ( x ) } \end{array}
$$

$$
\begin{array} { l } { \exists x ( A ( x ) \wedge B ( x ) ) \Rightarrow \exists x A ( x ) \wedge \exists x B ( x ) } \\ { \forall x (A ( x ) \vee  B ( x )) \Rightarrow \forall x  A ( x ) \vee \forall  xB ( x )  } \end{array}
$$

$$
\begin{array} { l } { \exists x A ( x ) \rightarrow \forall x B ( x ) \Rightarrow \forall x ( A ( x ) \rightarrow B ( x ) ) } \\ { \forall x ( A ( x ) \rightarrow B ( x ) ) \Rightarrow \forall x A ( x ) \rightarrow \forall x B ( x ) } \\ { \forall x ( A ( x ) \rightarrow B ( x ) ) \Rightarrow \exists x A ( x ) \rightarrow \exists x B ( x ) } \\ { \exists x ( A ( x ) \rightarrow B ( x ) ) \Leftrightarrow \forall x A ( x ) \rightarrow \exists x B ( x ) } \\ \end{array}
$$

### 谓词演算

- 推理：同上，形式不变。

- 推理规则：

  1. 全称特定化
     $$
     \begin{array} { l }{ \forall x A ( x ) \Rightarrow A ( y ) } \\ { \forall x A ( x ) \Rightarrow A ( c ) } \end{array}
     $$
     - x是A(x)中的自由变元 
     - y为任意不在A(x)中约束出现的个体变元
     - c为任意的个体常元

  2. 存在特定化
     $$
     \exists x A ( x ) \Rightarrow A ( c )
     $$
     - c是使A为真的特定个体常元
     - 如果A(x)中有其他自由变元出现，且x是随其他自由变元变化的，那么不能使用此规则

  3. 全称一般化
     $$
     A ( y ) \Rightarrow \forall x A ( x )
     $$
     - y在A(y)中自由出现，且y取任何值时A均为真
     - x不在A(y)中约束出现
     
  4. 存在一般化
     $$
     A ( c ) \Rightarrow \exists x A ( x )
     $$
     - c是个体域中某个确定的个体
     - 代替c的x不能已在A(c)中出现

- 例：证明
  $$
  \forall x ( P ( x ) \vee Q ( x ) ) \Rightarrow \forall x P ( x ) \vee \exists x Q ( x )
  $$
  证明：间接证明法

$$
\begin{array}{}
{  \neg ( \forall x P ( x ) \vee \exists x Q ( x ) ) } & 附加前提 \\
{ \neg  \forall x P ( x ) \vee \neg \exists x Q ( x ) } \\ 
{ \neg \forall x P ( x ) } \\ 
{ \neg\exist x Q ( x ) } \\ 
{ \forall x \neg Q ( x ) } \\ 
\exists x \neg P ( x ) \\
 { \neg P ( c ) } \\ 
 { \neg Q ( c ) } \\ 
 { \neg P ( c )\wedge \neg Q(c) } \\ 
 { \neg( P ( c ) \vee Q ( c ) ) } \\ 
 { \forall x ( P ( x ) \vee Q ( c ) ) } &前提 \\ 
 { P ( c ) \vee Q ( c ) } \\ 
 { \neg ( P ( c ) \vee Q ( c ) ) \wedge ( P ( c ) \vee Q ( c ) ) } 
 \end{array}
$$

