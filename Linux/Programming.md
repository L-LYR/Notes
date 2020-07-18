# 程序设计实践读书笔记

## 代码风格

### 命名

#### 要点

一个变量的名字应该尽量满足四个方面：**非形式化的、简练的、容易记忆的、能够拼读的**。

**一个变量的作用域越大，它的名字应该携带越多的信息。**全局变量、函数、类等，名字最好要长，富有说明性，最好附上简短的注释。比如`int nPendings = 0; // current length of input queue`局部变量使用较短的名字即可，因为通过上下文和作用域即可获悉其作用，比如函数内部的一个计数变量，命名为`n`即可，大可不必命名为`numberOfPoints`。循环变量用`i`或`j`，指针使用`p`或`q`，字符串使用`s`或`t`等等。

常见命名约定：

- 全局变量用大写开头的变量名，如`Global`。
- 常量使用完全大写的变量名，如`CONSTANTS`。
- 变量类型和用途亦可整合进变量名，如字符指针`pch`，结构体指针`nodep`。
- 变量名的单词连接方式，如用下划线连接，驼峰命名等。这一点统一最重要，选择哪一个都可以，个人喜好问题。
- 对于C++等具有命名空间特性的语言，大可不必在某一类中重复出现类名，比如`queue.queueCapacity`，这样显得十分累赘。同时针对同一空间中的指代同一种东西的变量或函数尽量统一使用一个单词。
- 函数命名采用“动词+名词”的形式，如`date.getTime()`。特别地，对于返回布尔类型的函数，函数名称要能清楚地表示其返回`true`时的情况，如`if(isOctal(c)) {...}`，`if(inTable(obj)) {...}`。
- 函数命名要与实现对应，不能误导别人。

#### 练习

> 1-1 评论下面代码中名字和值的选择：
>
> ```C
> #define TRUE 0
> #define FALSE 1
> 
> if((ch = getchar()) == EOF)
>     not_eof = FALSE
> ```
>
> 变量和常量命名没毛病，都是既定风格，问题出在布尔常量的定义与人的普适想法相反上，应当改为：
>
> ```c
> #define TRUE 1
> #define FALSE 0
> ```

> 1-2 改进下面的函数：
>
> ```c
> int smaller(char *s, char *t) {
>     if(strcmp(s, t) < 1) return 1;
>     else return 0;
> }
> ```
>
> 改进如下：
>
> ```c
> int isSmaller(char *s, char *t) {
>     if(strcmp(s, t) < 0) return 1;
>     else return 0;
> }
> ```

> 1-3 大声读出下面的代码：
>
> ```c
> if((falloc(SMRHSHSCRCH, S_IFEXT|0644, MAXRODDHSH)) < 0)
>     ...
> ```
>
> 臣妾做不到啊！写的什么**玩意！

### 表达式和语句

#### 要点

- 缩进排版很重要。
- 多目运算符需要添加空格。
- 循环体的增量单独写。
- 表达式的逻辑应该可以念出来，能简化的必须简化，比如一些否定可以用修改不等号方向来替换。
- 运算符优先级不清楚最好加括号，分组以提高可读性，如`leapYear = ((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0)`。
- 分解复杂的表达式，比如三目运算符只用于替换简单的分支语句，不要写得太长，不能作为`if-else`语句的一般性替换。
- 简化表达式，用更清晰的方式实现操作。
- 当心副作用，如`++`和`--`的前后缀增量使用方式，又如`scanf("%d %d", &yr, &profit[yr])`这样的写法。最好的避免方法就是讲增量操作或者需要按顺序进行的操作分开写。

#### 练习

> 1-4 改进下面的各个程序片段：
>
> ``` c
> if (!(c == 'y' || c == 'Y')) return;
> 
> length = (length < BUFSIZE) ? length : BUFSIZE;
> 
> flag = flag ? 0 : 1;
> 
> quote = (*line == '"') ? 1 : 0;
> 
> if (val & 1) bit = 1;
> else bit = 0;
> ```
>
> 改进如下：
>
> ```c
> // 该逻辑表达式可以化简，用与非逻辑即可
> // if (!(c == 'y' || c == 'Y')) return;
> if (c != 'y' && c != 'Y') return;
> // 这个表达式无论如何都会赋值，所以改为if语句即可避免无意义的赋值
> // length = (length < BUFSIZE) ? length : BUFSIZE;
> if (length > BUFSIZE) length = BUFSIZE;
> // 其实就是判断flag是不是不等于0，分支结构太麻烦，改成逻辑表达式即可
> // flag = flag ? 0 : 1;
> flag = (flag != 0);
> // 该表达式的分支结构多余
> // quote = (*line == '"') ? 1 : 0;
> quote = (*line == '"');
> // 该if-else语句多余
> // if (val & 1) bit = 1;
> // else bit = 0;
> bit = val & 1;
> ```
>
> 

> 1-5 下面的例子里有什么错？
>
> ```c
> int read(int *ip) {
>     scanf("%d", ip);
>     return *ip;
> }
> ......
> inseart(&graph[vert], read(&val), read(&ch));
> ```
>
> 这里`read()`封装`scanf()`函数用来键入并返回一个`int`型整数，而后面调用的时候传入了一个名为`ch`变量的地址，从命名的角度来看，`ch`应该是一个`char`型变量，因此这里存在不匹配的问题。

> 1-6 列出下列代码片段在各种求值顺序下可能产生的所有不同输出：
>
> ```c
> n = 1;
> printf("%d %d\n", n++, n++);
> ```
>
> 可能的输出有：
>
> ```
> 1 1
> 1 2
> ```

### 一致性和习惯用法

#### 要点

- 相同操作要使用相同的方法实现。
- 使用一致的排版缩进和加括号风格，花括号在哪一行不重要，重要的是，是否在全部代码中保持一致。
- 逐渐使用语言对应的习惯用法，如C语言中的循环：`for (i = 0; i < n; i++) {...}`，无限循环使用`while(1) {...}`或者`for (;;)`。
- 嵌套`if-else`影响阅读体验，也容易出错，最好写成并行条件。

#### 练习

> 1-7 把下面的C/C++程序例子改的更清晰一些：
>
> ```C++
> if(istty(stdin)) ;
> else if(istty(stdout)) ;
> 	else if(istty(stderr)) ;
> 		else return (0);
> 		
> if(retval != SUCCESS)
> {
> 	return (retval);
> }
> /* ALL went well!*/
> return SUCCESS;
> 
> for (k = 0; k ++ < 5; x += dx)
>     	scanf("%lf", &dx);
> ```
>
> 改进如下：
>
> ```C++
> // if(istty(stdin)) ;
> // else if(istty(stdout)) ;
> //  	else if(istty(stderr)) ;
> //  		else return (0);
> if (!istty(stdin) && !istty(stdout) && !istty(stderr))
>     return 0;
> 
> // if(retval != SUCCESS)
> // {
> //  	return (retval);
> // }
> // /* ALL went well!*/
> // return SUCCESS;
> return retval;
> 
> // for (k = 0; k ++ < 5; x += dx)
> //      	scanf("%lf", &dx);
> for (k = 0; k < 5; k++) {
>     scanf("%lf", &dx);
>     x += dx;
> }
> ```

> 1-8 确定下面Java程序段中的错误，并把它改写成一个符合习惯的循环。
>
> ```java
> int count = 0;
> while (count < total) {
>     count++;
>     if (this.getName(count) == nametable.userName()) {
>         return true;
>     }
> }
> ```
>
> 程序段没有处理姓名不存在的情况。
>
> ```Java
> for (int count = 0; count < total; count++) {
>     if(this.getName(count) == nametable.userName()) return true;
> }
> return false;
> ```

### 宏

#### 要点

- 本书提倡不要用宏，因为宏是计算机性能较差时代的产物，当下宏所带来的麻烦要比其有点多很多，所以不用为好，作为语法特性了解即可。我认为宏可以使用，只不过要注意用法规范。

#### 练习

> 1-9 确定下面的宏定义中的问题
>
> ```c
> #define ISDIGIT(c) ((c >= '0') && (c <= '9')) ? 1 : 0
> ```
>
> 首先，不必要的分支结构在宏替换之后可能会带来麻烦；其次，宏参数多次出现可能会带来一些麻烦；最后，宏参数没有加括号也可能带来麻烦。

### 魔数

#### 要点

- 魔数包括各种常数、数组大小、字符位置、变换因子以及程序中出现的其他以文字形式出现的数值。

- 不加注释或者命名的魔数在代码中出现会给人一种魔幻感。

- C语言中最好是用枚举来命名，或者在使用的地方给出注释，C++中定义为`const`即可。虽然C中也有`const`，但是不能作为数组的界。

- 使用字符类型的常量，而不是使用数字。

- 使用语言特性或者库函数来获取数组大小。

#### 练习

> 1-10 如何重写下面的定义，使出错的可能性降到最小？
>
> ```c
> #define FT2METER 	0.3048
> #define METER2FT	3.28084
> #define MI2FT		5280.0
> #define MI2KM		1.609344
> #define SQMI2SQKM	2.589988
> ```
>
> 重写如下：
>
> ```c
> #define FT2METER 	0.3048
> #define METER2FT	(1.0 / FT2METER)
> #define MI2FT		5280.0
> #define MI2KM		1.609344
> #define SQMI2SQKM	(MI2KM * MI2KM)
> ```

### 注释

#### 要点

- 不要写没有用的注释，注释不应该把代码中十分明显的事情重复一遍。
- 不要写与代码矛盾或无关的注释。
- 注释应该**简洁**同时**点明程序特征与要点**。
- 要写函数、类、全局变量及数据的注释，简单阐述或者指出算法参考文献。
- 不要给垃圾代码写注释，重构就完事了。如果真的要花一大堆时间写注释来解释这段垃圾出了什么问题，那还不如想办法着手重构这段代码。
- 如果代码写得足够易读，需要写的注释也就越少。

#### 练习

> 1-11 评论下面的注释：
>
> ```c++
> void dict::insert(string &w);
> // returns 1 if w in dictinary, otherwise returns 0
> 
> if (n > MAX || n % 2 > 0) // test for even number
>    
> // Write a message
> // Add to line counter for each line written
> 
> void write_message()
> {
>     // increment line counter
>     line_number = line_number + 1;
>     fprintf(fout, "%d %s\n%d %s\n%d %s\n", 
>             line_number, HEADER,
>             line_number + 1, BODY,
>             line_number + 2, TRAILER);
>     // increment line counter
>     line_number = line_number + 2;
> }
> ```
>
> 第一个注释和函数实际功能矛盾；第二个注释多余，代码已经很明显了；第三段注释也多余了，函数名和变量名已经很明晰了，增量代码也不需要注释。

## 算法与数据结构

- 查找

```c
char *flab[] = {
	"actually",
	"just",
	"quite",
	"really",
	NULL
}
/* lookupSeq: sequential search for word in array. */
int lookupSeq(char *word, char *array[]) {
	int i;
	for (i = 0; array[i] != NULL; i++)
		if (strcmp(word, array[i]) == 0)
			return i;
	return -1;
}

typedef struct Nameval Nameval;
struct Nameval {
	char 	*name;
	int 	value;
}

/* lookupBin: binary search for name int tab; return index */
int lookupBin(char *name, Nameval tab[], int ntab) {
	int low, high, mid, cmp;

	low = 0;
	high = ntab - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		cmp = strcmp(name, tab[mid].name);
		if (cmp < 0) high = mid - 1;
		else if (cmp > 0) low = mid + 1;
		else return mid;
	}
	return -1;
}
```

- 排序

```c
/* swap: interchange v[i] and v[j] */
void swap(int v[], int i, int j) {
	int temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

/* quicksort: sort v[0] ... v[n-1] into increasing order */
void quicksort(int v[], int n) {
	int i, last;
	if (n <= 1) return;
	last = 0; /* always point to the front of less-part */
	for (i = 1; i < n; i++) 
		if(v[i] < v[0]) {
			++last;
			swap(v, last, i);
		}
	swap(v, 0, last);
	quicksort(v, last);
	quicksort(v + last + 1, n - last - 1);
}
```

向量，链表，二叉树，散列表等常用数据结构略，这本书主要侧重于C语言实现。

## 设计与实现

程序语言的选择在整个设计过程中，相对而言，并不是那么重要。数据结构的设计是程序构造过程中的中心环节。本章作者通过用不同语言来实现相同的算法并比较其性能，旨在说明设计与实现之间的侧重点，也说明了不同语言实现相同算法的风格差异。

C语言实现简单的马尔科夫链算法：

```pseudocode
设置w1和w2为文本的前两个词
输出w1和w2
循环：
	随机的选出w3，它是文本中w1w2的后缀中的一个
	打印w3
	把w1和w2分别换成w2和w3
	重复循环
```

```c
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

enum
{
    N_PREF = 2,      // number of prefix words
    N_HASH = 4093,   // size of state hash table array
    MAX_GEN = 10000, // maximum words generated
    MULTIPLIER = 31, // a prime for hash()
    BUF_SIZE = 100   // buffer size
};

char NO_WORD[] = "\n"; // cannot appear as real word

typedef struct State State;
typedef struct Suffix Suffix;

struct State // preffix + suffix list
{
    char *pref[N_PREF]; // prefix words
    Suffix *suf;        // list of suffixes
    State *next;        // next node in hash table
};

struct Suffix // list of suffixes
{
    char *word;   // suffix
    Suffix *next; // next in list of suffixes
};

State *state_tab[N_HASH]; // hash table of state

/* hash: compute hash value for array of N_PREF strings. */
unsigned int hash(char *s[N_PREF])
{
    unsigned int h;
    unsigned char *p;
    int i;

    h = 0;
    for (i = 0; i < N_PREF; i++)
        for (p = (unsigned char *)s[i]; *p != '\0'; p++)
            h = MULTIPLIER * h + *p;
    return h % N_HASH;
}

/* lookup: search for prefix; create if requested */
/* return: pointer if present or created; NULL if not */
State *lookup(char *prefix[N_PREF], int create)
{
    int i, h;
    State *sp;

    h = hash(prefix);
    for (sp = state_tab[h]; sp != NULL; sp = sp->next)
    {
        for (i = 0; i < N_PREF; i++)
            if (strcmp(prefix[i], sp->pref[i]) != 0)
                break;
        if (i == N_PREF)
            return sp;
    }

    if (create)
    {
        sp = (State *)malloc(sizeof(State));
        for (i = 0; i < N_PREF; i++)
            sp->pref[i] = prefix[i];
        sp->suf = NULL;
        sp->next = state_tab[h];
        state_tab[h] = sp;
    }

    return sp;
}

/* add_suffix: add to state. */
/* suffix must not change later. */
void add_suffix(State *sp, char *suffix)
{
    Suffix *suf;
    suf = (Suffix *)malloc(sizeof(Suffix));
    suf->word = suffix;
    suf->next = sp->suf;
    sp->suf = suf;
}

/* add: add word to suffix list, update prefix */
void add(char *prefix[N_PREF], char *suffix)
{
    State *sp;

    sp = lookup(prefix, true);
    add_suffix(sp, suffix);
    memmove(prefix, prefix + 1, (N_PREF - 1) * sizeof(prefix[0]));
    prefix[N_PREF - 1] = suffix;
}

/* strdup: not a part of the ISO C standard */
/* return: a duplicate string of the input. */
/* remember to use free */
char *strdup(const char *src)
{
    size_t len = strlen(src) + 1; // String plus '\0'
    char *dst = malloc(len);
    if (dst == NULL)
        return NULL;
    memcpy(dst, src, len);
    return dst;
}

/* build: read input, build prefix table */
void build(char *prefix[N_PREF], FILE *f)
{
    char buf[BUF_SIZE], fmt[10];

    sprintf(fmt, "%%%ds", sizeof(buf) - 1);
    while (fscanf(f, fmt, buf) != EOF)
        add(prefix, strdup(buf));
}

/* generate: produce output, one word per line */
void generate(int n_words)
{
    State *sp;
    Suffix *suf;
    char *prefix[N_PREF], *w;
    int i, n_match;

    for (i = 0; i < N_PREF; i++)
        prefix[i] = NO_WORD;

    for (i = 0; i < n_words; i++)
    {
        sp = lookup(prefix, false);
        n_match = 0;
        for (suf = sp->suf; suf != NULL; suf = suf->next)
        {
            ++n_match;
            if (rand() % n_match == 0) // choose each one equally
                w = suf->word;
        }
        if (strcmp(w, NO_WORD) == 0)
            break;
        printf("%s\n", w);
        memmove(prefix, prefix + 1, (N_PREF - 1) * sizeof(prefix[0]));
        prefix[N_PREF - 1] = w;
    }
}

int main(void)
{
    int i, n_words = MAX_GEN;
    char *prefix[N_PREF];

    srand((unsigned)time(NULL)); // to initialize ran()
    for (i = 0; i < N_PREF; i++)
        prefix[i] = NO_WORD;
    build(prefix, stdin);
    add(prefix, NO_WORD);
    generate(n_words);
    /* Because this program will exist for only a short time, */
    /* we will not to free spaces that we used. */
    return 0;
}
```

```shell
input:
Show your flowcharts and conceal your tables and I will be mystified. Show your tables and your flowcharts will be obvious.

a possible output：
Show
your
tables
and
I
will
be
obvious.
```

## 接口

这里原文翻译的是界面，我觉得应该有些奇怪，实际上是interface这个词，现在一般翻译为接口。

这一章主要说的是为别人写的代码。

设计阶段需要考虑的问题：

- 接口：提供哪些服务和访问？
- 数据隐藏：哪些数据需要被设置为私有？
- 资源管理：谁来负责管理内存或其他有限资源，即存储空间的分配和释放，管理共享信息的拷贝？
- 错误处理：谁来检查错误？谁来报告错误？如何报告错误？发生错误之后，进行什么样的恢复性操作？

实现阶段重要也是必要的一步——设定规范。

- 规范是建立在设计阶段考虑的众多问题之上。

- 规范应该基本上包括函数原型、函数行为细节描述、各种责任和假设。

- 规范是在实现过程中不断修改与更正的。

接口原则：

- 隐藏实现细节。接口实现应该是隐藏的，这样才能使得它的修改不影响也不破坏别的东西。比如信息隐藏、封装、抽象、模块化，这些都是类似的思想。比如C语言的I/O库，全部操作都隐藏在`FILE*`之后。
- 正交化的基本操作。接口应提供外界需要的全部功能，但不是越多越好，库函数在功能方面不应过度重合，库函数不应该在用户背后做小动作。
- 同样的方式做同样的事。接口的一致性和规范性，如数据的流动方向（函数传参形式，返回值形式等）。

资源管理：

- 释放资源和分配资源应在同一个层次上进行。谁分配的谁释放。

错误处理：

- 低层检查错误，高层处理错误。

接下来是举例，构造一个C语言实现的CSV处理库。

```c
/* csv.h */
#ifndef CSV_H_
#define CSV_H_

#include <stdio.h>

/* csv.h: interface for csv library */

extern char *csv_getline(FILE *f);
extern char *csv_field(int n);
extern int csv_n_field(void);
extern int set_csv_sep(char c);

#endif
```

```c
/* csv.c */
#include "csv.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum // error code
{
    NO_MEM = -2, // no memory
    ERR_CHAR = -3
};

static char *line = NULL;  // input string
static char *sline = NULL; // copy of input for split
static int max_line = 0;   // size of line[] and sline[]

static char **fields = NULL; // filed pointers
static int max_field = 0;    // size of fields[]
static int n_field = 0;      // number of fields in fields[]

static char field_sep[] = ","; // field separater

/* reset: set variable back to starting values. */
static void reset(void)
{
    free(line);
    free(sline);
    free(fields);
    line = sline = NULL;
    fields = NULL;
    max_line = max_field = n_field = 0;
}

/* end_of_line: check for and consume \n \r \r\n or EOF. */
static int end_of_line(FILE *f, int c)
{
    int eol;
    eol = (c == '\r' || c == '\n');
    if (c == '\r')
    {
        c = getc(f);
        if (c != '\n' && c != EOF)
            ungetc(c, f); // read too many, put back
    }
    return eol;
}

/* deal_quoted: deal with quoted field */
/* return: pointer to next separator */
char *deal_quoted(char *p)
{
    int i, j, k;
    for (i = j = 0; p[j] != '\0'; i++, j++)
    {
        if (p[j] == '"' && p[++j] != '"')
        {
            k = strcspn(p + j, field_sep);
            memmove(p + i, p + j, k);
            i += k;
            j += k;
            break;
        }
        p[i] = p[j];
    }
    p[i] = '\0';
    return p + j;
}

/* split: split line into fields */
static int split(void)
{
    char *p, **new_field;
    char *sep_p; // separater pointer
    int sep_c;   // separater character

    n_field = 0;
    if (line[0] == '\0')
        return 0;
    strcpy(sline, line);
    p = sline;

    do
    {
        if (n_field >= max_field)
        {
            max_field *= 2;
            new_field = (char **)realloc(fields, max_field * sizeof(fields[0]));
            if (new_field == NULL)
                return NO_MEM;
            fields = new_field;
        }
        if (*p == '"')
            sep_p = deal_quoted(++p); // skip initial quote
        else
            sep_p = p + strcspn(p, field_sep);

        sep_c = sep_p[0];
        sep_p[0] = '\0'; // teminated field
        fields[n_field++] = p;
        p = sep_p + 1;
    } while (sep_c == field_sep[0]);

    return n_field;
}

/* csv_getline: get one line of .csv, grow as needed. */
char *csv_getline(FILE *f)
{
    int i, c;
    char *new_l, *new_s;

    if (line == NULL) // allocate for the first time
    {
        max_line = max_field = 1;
        line = (char *)malloc(max_line);
        sline = (char *)malloc(max_line);
        fields = (char **)malloc(max_field * sizeof(fields[0]));
        if (line == NULL || sline == NULL || fields == NULL)
        {
            reset();
            return NULL; // out of memory
        }
    }

    for (i = 0; (c = getc(f)) != EOF && !end_of_line(f, c); i++)
    {
        if (i >= max_line - 1)
        {
            max_line *= 2;
            new_l = (char *)realloc(line, max_line);
            new_s = (char *)realloc(sline, max_line);
            if (new_l == NULL || new_s == NULL)
            {
                reset();
                return NULL; // out of memory
            }
            line = new_l;
            sline = new_s;
        }
        line[i] = c;
    }
    line[i] = '\0';
    if (split() == NO_MEM)
    {
        reset();
        return NULL; // out of memory
    }
    return (c == EOF && i == 0) ? NULL : line;
}

/* csv_field: return pointer to n-th field. */
char *csv_field(int n)
{
    if (n < 0 || n > n_field)
        return NULL;
    return fields[n];
}
/* csv_n_field: return number of fields. */
int csv_n_field(void)
{
    return n_field;
}

/* set_csv_sep: set the separator of csv. */
/* return the previous one, but for un-printed charactor, return ERR_CHAR. */
int set_csv_sep(char c)
{
    if (c < ' ' || c > '~')
        return ERR_CHAR;
    char prev_sep = field_sep[0];
    field_sep[0] = c;
    return prev_sep;
}
```

## Debug

这里给出了一些常见的编程错误和debug方法，但是有些过时了，因此略。

## 测试

注意区分测试和Debug，前者是没有错误而寻找错误，后者则是有错误而解决错误。

编程的过程中设计测试需要考虑到的：

1. 测试代码边界情况。如输入不存在、为空；数组接近满了、正好满了、溢出来了等。
2. 测试前条件和后条件。验证在某段代码执行前所期望的或必须满足的性质（前条件）、执行后的性质（后条件）是否成立。
3. 防御性程序设计。设法使程序在遇到不正确使用或非法数据时能保护自己。针对上一条的前条件。如输入空指针、下标越界、除零等
4. 检查返回值是否错误。针对的是上一条的后条件。如返回空指针，返回错误码等。

测试系统化：

1. 增量测试。编写程序和编写测试是同步的。
2. 设计输入输出，二者要对应，并且确切且典型。随机产生测试样例+精心设置的边界样例。
3. 比较实现相同功能的不同解决办法，对比结果，即对比测试。
4. 度量测试的覆盖面。完全覆盖指的是程序里的每个语句在一系列测试中都执行过。

测试自动化：

1. 自动回归测试。修改完程序要把之前的测试全都自动过一遍，不要只测试改动的地方。
2. 自包容测试。

## 性能

计时：

这里给出C语言的计时方法。

```c
clock_t before;
double elapsed;

before = clock();
function();
elapsed = clock() - before;
printf("function() used %.3f seconds.\n", elapsed / CLOCKS_PER_SEC);
```

加速策略：

1. 更好的算法或数据结构。
2. 编译器优化。
3. 调整代码。
4. 不要优化一些无关痛痒的东西。

代码调整：

1. 收集公共表达式，减少计算量。
2. 低代价操作替代高代价操作。
3. 高速缓存频繁使用的值。
4. 写专用的存储分配程序。
5. 对输入输出做缓冲。
6. 特殊情况特殊处理。
7. 预先算出某些值。
8. 使用近似值。

空间效率：

1. 使用尽可能小的数据类型以节约存储，但不要钻牛角尖。
2. 不存容易重算的东西。

## 可移植性

我不太认同本书所述的部分可移植性。

