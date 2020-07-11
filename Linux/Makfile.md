# Makefile怎么写

## Make是啥

Make实际上就是根据指定的Shell命令进行构建文件的工具。规则很简单，只需要规定构建的目标文件、构建需要依赖的源文件、当哪些文件有变动时，如何重新构建它。比如：

```makefile
a.txt: b.txt c.txt
	cat b.txt c.txt > a.txt
```

这两行规则表示，首先`a.txt`需要`b.txt`和`c.txt`作为依赖，然后使用`cat`命令将这两个文本文件进行拼接。将这两行规则保存在`Makefile`文件中，即可使用`make a.txt`命令进行构建。当然啦，也可以使用其他文件名，比如`rules`，那么就需要`make -f rules`或`make --file=rules`来进行指定。

## 基本要素

```makefile
<target> ： <prerequisites>
[tab] <commands>
```

上面给出了Makefile规则的基本形式，`<target>`是目标，`<prerequisites>`是前置条件或依赖，`<commands>`是命令。目标是必需的，不可省略；前置条件和命令至少得有一个。和上面的例子一样，一条规则需要明确两件事：依赖是啥和怎么构建。

### 目标

一个目标可以是文件名或者是操作名，操作名就比如说：

```makefile
clean: 
	rm *.o
```

但是如果目录下有一个叫`clean`的文件，再执行`make clean`时，该命令并不会执行，所以要明确告诉`make`这个是一个命令，是一个伪目标，这里就需要使用`.PHONY`内置目标名，如下：

```makefile
.PHONY: clean
clean: 
	-rm *.o
```

注：`-`的作用是忽略删除时出现的问题，同样也可以在`make`指令中添加参数`-i`或`--ignore-errors`来全面忽略命令错误。

伪目标一般没有依赖文件，一般是标签，并且总是被执行。

目标可以是多个，但目标的生成需要使用同一形式的命令，如下样例所示，其中使用到了自动变量。

```makefile
bigOutput littleOutput : test.g
	generate test.g -$(subst output, ,$@) > $@
```



### 依赖

依赖一般是一组文件名，之间用空格隔开。依赖决定了目标是否许需要构建：只要有一个依赖文件不存在或者有更新，那么目标就需要重新构建。

多个文件的构建最好写成无命令的伪目标，如：

```makefile
source: file1 file2 file3
```

这样`make source`就可以直接构建三个目标文件。

### 命令

命令明确说明如何构建或更新目标文件，它由一行或多行shell命令组成。

命令之前必须有一个`tab`，如果不喜欢用`tab`，可以通过`.RECIPEPREFIX`来更改。

```makefile
.RECIPEPREFIX = >
all:
> echo Hello, world
```

注意，当需要写多行命令，则需要在末尾田间`\`，或者用`;`连接写成一行，再或者加上`.ONESHELL:`命令。

## 基本语法

### 注释

```makefile
# 这是注释
```

### echo

正常情况，`make`会在执行时将命令打印在终端上，这就叫`echo`，在命令前加`@`就可以关闭。一般不关闭，因为需要知道构建过程中运行到了哪，只在注释和纯显示`echo`命令前加。`make`参数`-s`或`--silent`可以全面关闭显示命令。

```makefile
test:
	@# 这是注释
	@echo Hello， world
```

### 引用

```makefile
include <filename>
```

这样可以包含其他的makefile。

### 通配符

通配符用来指定一组符合条件的文件名，和Bash通配符一致，主要用的有`* ? [...]`。

### 匹配符

Make命令允许对文件名，进行类似于正则表达式的匹配，主要用到的是`%`。比如：

```makefile
%.o: %.c
```

假设当前目录下有两个文件，分别是`file1.c`和`file2.c`，那么上述命令等价于：

```makefile
file1.o: file1.c
file2.o: file2.c
```

### 变量

```makefile
txt = Hello World
test:
	@echo $(txt)
```

Makefile的变量声明使用赋值符即可，上面的变量`txt`等于`Hello World`。但我更愿意称之为宏。

调用变量时，要放到`$(..)`中间。调用shell变量时需要在`$`之前再加一个`$`。

有时，变量的值可能指向另一个变量。

```makefile
v1 = $(v2)
```

这样的话，就要考虑静态扩展和动态扩展的区别，所以有如下定义：

```makefile
VARIABLE = value
# 在执行时扩展，允许递归扩展。

VARIABLE := value
# 在定义时扩展。

VARIABLE ?= value
# 只有在该变量为空时才设置值。

VARIABLE += value
# 将值追加到变量的尾端。
```

Make命令提供一系列内置变量，比如，`$(CC)` 指向当前使用的编译器，​`$(MAKE) `指向当前使用的Make工具。这主要是为了跨平台的兼容性。

### 自动变量

| 自动化变量 | 说明                                                         |
| ---------- | ------------------------------------------------------------ |
| `$@`       | 表示规则的目标文件名。如果目标是一个文档文件（Linux 中，一般成` .a `文件为文档文件，也成为静态的库文件）， 那么它代表这个文档的文件名。在多目标模式规则中，它代表的是触发规则被执行的文件名。 |
| `$%`       | 当目标文件是一个静态库文件时，代表静态库的一个成员名。       |
| `$<`       | 规则的第一个依赖的文件名。如果是一个目标文件使用隐含的规则来重建，则它代表由隐含规则加入的第一个依赖文件。 |
| `$?`       | 所有比目标文件更新的依赖文件列表，空格分隔。如果目标文件时静态库文件，代表的是库文件（`.o`文件）。 |
| `$^`       | 代表的是所有依赖文件列表，使用空格分隔。如果目标是静态库文件，它所代表的只能是所有的库成员（`.o`文件）名。 一个文件可重复的出现在目标的依赖中，变量`$^`只记录它的第一次引用的情况。就是说变量`$^`会去掉重复的依赖文件。 |
| `$+`       | 类似`$^`，但是它保留了依赖文件中重复出现的文件。主要用在程序链接时库的交叉引用场合。 |
| `$*`       | 在模式规则和静态模式规则中，代表“茎”。“茎”是目标模式中“%”所代表的部分（当文件名中存在目录时， “茎”也包含目录部分）。 |

### 判断

和Bash语法一样。

```makefile
ifeq($(CC), gcc)
	libs=$(libs_for_gcc)
else
	libs=$(normal_libs)
endif
```

### 循环

和Bash语法一样。

```makefile
LIST = one two three
all:
    for i in $(LIST); do \
        echo $$i; \
    done

# 等同于

all:
    for i in one two three; do \
        echo $i; \
    done
```

### 函数

Makefile有很多内置函数可以调用。

调用格式：

```makefile
$(function arguments)
# 或者
${function arguments}
```

比如用shell函数用来执行shell命令：

```makefile
srcfiles := $(shell echo src/{00..99}.txt)
```

## 高级特性

### 文件搜寻

Makefile提供了一个特殊变量`VPATH`，用来指定文件搜寻的目录，赋值时路径用`:`隔开。

```makefile
VPATH = src : ../headers
```

实现相同功能的还有`vpath`关键字，使用方法有三种。

```makefile
vpath <pattern> <directories>
# 为符合模式的文件指定搜索目录
vpath <pattern>
# 清除符合模式的文件的搜索目录
vpath 
# 清除所有设置好的文件搜索目录
```

这里的模式需要用到上面的匹配符。

### 静态模式

```makefile
<targets ...>: <target pattern>: <prerequisites pattern ...>
[tab] <commands>
```

这是针对上述多目标构建的一种写法，各部分解释：

`<targets ...>`定义了一系列的目标文件，可含匹配符，即目标集。

`<targets  pattern>`指明了`<targets ...>`的模式，即目标集模式。

`<prerequisites pattern ...>`是目标的依赖文件模式。

例子如下：

```makefile
objects = foo.o bar.o
$(objects): %.o: %.c
	$(CC) -c $(CFLAGS) $^ -o $@
```

上面的例子中，`$(objects)$`表明目标集，`%.o`表明需要生成的目标文件的模式，`%.c`表示相应文件名的依赖文件。

这种模式针对成百上千的同后缀文件有很强的操作性。

### 生成依赖

==需要用到`sed`工具和正则表达式，不是很会，挖个坑==

### 自动推导



