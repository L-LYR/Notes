# 图片转字符画

## 环境

```shell
python 3.8.1
pillow 7.0.0
```

## 步骤

### RGB转灰度公式

$$
Gray = 0.299*R + 0.587*G + 0.114*B
$$

上述是最简单的最基础的一个公式，这里我们不考虑性能，先使用这个来实现即可。

```python
def calGray(r, g, b):
    return int(0.299 * r + 0.587 * g + 0.114 * b)
```

为了加快速度可以有如下调整：
$$
Gray = (299*R + 587*G + 114*B + 500) \frac{1}{1000}
$$
上述公式是进行32位整型运算，`+500`是实现四舍五入。

为了降低运算位数有：
$$
Gray = (30 * R + 59 * G + 11 * B + 50) \frac{1}{100}
$$
进一步优化便是位运算：
$$
\begin{aligned}
&0.299 * 65536 = 19595.264 ≈ 19595\\
&0.587 * 65536 + (0.264) = 38469.632 + 0.264 = 38469.896 ≈ 38469\\
&0.114 * 65536 + (0.896) = 7471.104 + 0.896 = 7472\\
&Gray = (R*19595 + G*38469 + B*7472) >> 16
\end{aligned}
$$
还有一种效果很好但很慢的公式（PS）
$$
Gray = (R^{2.2}*0.2973+G^{2.2}*0.6274+B^{2.2}*0.0753)^{\frac{1}{2.2}}
$$

### 建立映射

挑选喜欢的字符集

```python
ASCIICharList = list('/#*/#\\?-_+~<>!;:,"^`.')
```

简单的映射关系
$$
indexInList = \frac{Gray}{(Alpha + \frac{1}{Length_{ASCIICharList})}}
$$

```python
def getChar(r, g, b, alpha=256):
    if alpha == 0:
        return ' '
    length = len(ASCIICharList)
    gray = calGray(r, g, b)
    unit = (256 + 1) / length
    return ASCIICharList[int(gray / unit)]
```

### 设置命令行传入参数

```python
import argparse

# get the command line arguments
parser = argparse.ArgumentParser()

parser.add_argument('file')
parser.add_argument('-o', '--output')
parser.add_argument('--width', type=int, default=80)
parser.add_argument('--height', type=int, default=80)

args = parser.parse_args()
imgFilePath = args.file
width = args.width
height = args.height
outputPath = args.output
```

之后我们就有如下提示：

```
usage: imgToASCII.py [-h] [-o OUTPUT] [--width WIDTH] [--height HEIGHT] file
```

## 转换和保存

```python
if __name__ == '__main__':
    img = Image.open(imgFilePath)
    img = img.resize((width, height), Image.NEAREST)
    outputTxt = ''
    for i in range(height):
        for j in range(width):
            outputTxt += getChar(*img.getpixel((j, i)))
        outputTxt += '\n'
    print(outputTxt)

    if outputPath is None:
        outputPath = 'output.txt'
    with open(outputPath, 'w') as f:
        f.write(outputTxt)
```

