**2019.1.5**

# **Reverse Polish Notation**

## **Outline**

后缀表达式的生成

1. 输入表达式
2. 从左至右读取字符
   1. 若读取的字符为操作数，则压入栈
   2. 若读取的字符为运算符
      1. 若栈顶为空或栈顶为'('，则压入栈
      2. 若栈顶的运算符优先级低于当前运算符，则压入栈
      3. 若栈顶的运算符优先级高于或等于当前运算符，将栈顶运算符出栈，再循环判断
   3. 若读取的字符为括号
      1. 若为'('，则压入栈
      2. 若为')'，则依次将栈中的运算符出栈，直到栈顶为'('，然后舍弃这一对括号

后缀表达式的求值

1. 输入表达式
2. 从左至右读取字符
    1. 若读取的是操作数，则压入栈
    2. 若读取的是运算符，则弹出栈顶两个操作数，进行运算，并将结果入栈
    3. 最终结果即为值栈中剩下的值

## **C语言代码实现**

```c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define N 80

typedef struct char_stack
{
    int top;
    int size;
    char *data;
} char_stack;

char_stack *create_initialize_stack(int size);
char top_data(char_stack *A);
int pop(char_stack *A, char *x);
int push(char_stack *A, char x);

void reverse_polish_notation(char *infix, char_stack *suffix);
int calculator(char_stack *infix);

int main(void)
{
    char_stack *suffix = create_initialize_stack(N);
    char infix[N];
    scanf("%s", infix);
    reverse_polish_notation(infix, suffix);
    printf("%d\n", calculator(suffix));
    system("pause");
    return 0;
}

char_stack *create_initialize_stack(int size)
{
    char_stack *A = (char_stack *)malloc(sizeof(char_stack));
    A->data = (char *)malloc(sizeof(char) * size);
    A->size = size;
    A->top = -1;
    return A;
}

char top_data(char_stack *A)
{
    if ((A->top) >= 0)
        return (A->data)[A->top];
    else
        return -1;
}

int pop(char_stack *A, char *x)
{
    if (A->top < 0)
        return 0;
    else
    {
        *x = (A->data)[A->top];
        (A->top)--;
        return 1;
    }
}

int push(char_stack *A, char x)
{
    if ((A->top) == (A->size) - 1)
        return 0;
    else
    {
        (A->top)++;
        (A->data)[A->top] = x;
        return 1;
    }
}

void reverse_polish_notation(char *infix, char_stack *suffix)
{
    char_stack *temp = create_initialize_stack(N);
    char *cp;
    char mid;
    cp = infix;
    while (*cp != '\0')
    {
        if (isdigit(*cp))
        {
            push(suffix, *cp);
            cp++;
        }
        else
        {
            switch (*cp)
            {
            case '(':
                push(temp, *cp);
                cp++;
                break;
            case '+':
            case '-':
                push(suffix, ' '); //将运算符和操作数分开
                if (top_data(temp) == -1 || top_data(temp) == '(')
                {
                    push(temp, *cp);
                    cp++;
                    break;
                }
                else
                {
                    pop(temp, &mid);
                    push(suffix, mid);
                    break;
                }
            case '*':
            case '/':
                push(suffix, ' '); //将运算符和操作数分开
                if (top_data(temp) == '*' || top_data(temp) == '/')
                {
                    pop(temp, &mid);
                    push(suffix, mid);
                    break;
                }
                else
                {
                    push(temp, *cp);
                    cp++;
                    break;
                }
            case ')':
                push(suffix, ' '); //将运算符和操作数分开
                while ((temp->top) >= 0)
                {
                    pop(temp, &mid);
                    if (mid == '(')
                        break;
                    push(suffix, mid);
                }
            default: //易错点，注意一些乱七八糟的字符，换行空格之类的
                cp++;
            }
        }
    }
    while ((temp->top) >= 0) //易错点,别忘了临时栈中还有剩下没出来的
    {
        pop(temp, &mid);
        push(suffix, ' '); //将运算符和操作数分开
        push(suffix, mid);
    }
    push(suffix, '\0');
    printf("%s\n", suffix->data);
    free(temp->data);
    free(temp);
}

int calculator(char_stack *suffix)
{
    int right[N] = {0}, i = 0;
    char *cp = suffix->data;
    char mid;
    while (*cp != '\0')
    {
        if (isdigit(*cp))
        {
            right[i] = right[i] * 10 + *cp - '0';//填充值栈
            cp++;
        }
        else if (*cp == ' ')
        {
            cp++;
            i++;
        }
        else
        {
            i--;//找到栈顶
            switch (*cp)
            {
            case '+':
                right[i - 1] += right[i];
                break;
            case '-':
                right[i - 1] -= right[i];
                break;
            case '*':
                right[i - 1] *= right[i];
                break;
            case '/':
                right[i - 1] /= right[i];
                break;
            }
            right[i] = 0;
            i--;
            cp++;
        }
    }
    return right[0];
}
//15+21*(41-12)-1128/12
//15 21 41 12 - * + 1128 12 / -
//结果为530
```

