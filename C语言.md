# C语言及简答题

## 简答题

### 中缀表达式与后缀表达式的转换

[中缀表达式与后缀表达式的转换](https://blog.csdn.net/Amentos/article/details/127182926?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522169828740516800180670486%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=169828740516800180670486&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-127182926-null-null.142^v96^pc_search_result_base3&utm_term=%E4%B8%AD%E7%BC%80%E8%A1%A8%E8%BE%BE%E5%BC%8F%E8%BD%AC%E5%90%8E%E7%BC%80&spm=1018.2226.3001.4187)

1、字符为 **运算数** ：

直接送入后缀表达式（注：需要先分析出完整的运算数）。

2、字符为 **左括号** ：

直接入栈（注：左括号入栈后优先级降至最低）。

3、字符为 **右括号** ：

直接出栈，并将出栈字符依次送入后缀表达式，直到栈顶字符为左括号（左括号也要出栈，但不送入后缀表达式）。

总结：只要满足 栈顶为左括号 即可进行最后一次出栈。

4、字符为 **操作符** ：

若栈空，直接入栈。

若栈非空，判断栈顶操作符，若栈顶操作符优先级低于该操作符，该操作符入栈；否则一直出栈，并将出栈字符依次送入后缀表达式，直到栈空或栈顶操作符优先级低于该操作符，该操作符再入栈。

总结：只要满足 **栈空** 或者 **优先级高于栈顶操作符** 即可停止出栈，并将该操作符入栈。

5、重复以上步骤直至遍历完成中缀表达式，接着判断字符栈是否为空，非空则直接出栈，并将出栈字符依次送入后缀表达式。

注：中缀表达式遍历完成，栈中可能还有字符未输出，故需要判断栈空。

```c
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

#define ERROR 0
#define OK 1
#define STACK_INT_SIZE 10 /*存储空间初始分配量*/
#define STACKINCREMENT 5  /*存储空间分配增量*/
#define M 50

typedef char ElemType;    /*定义字符数据类型*/
typedef double ElemType2; /*定义运算数数据类型*/

/*字符栈*/
typedef struct
{
    ElemType *base;
    ElemType *top;
    int stacksize;
} SqStack;

/*运算数栈*/
typedef struct
{
    ElemType2 *base;
    ElemType2 *top;
    int stacksize;
} NStack;

int InitStack(SqStack *S);                /*构造空栈*/
int push(SqStack *S, ElemType e);         /*入栈*/
int Pop(SqStack *S, ElemType *e);         /*出栈*/
int StackEmpty(SqStack *s);               /*栈空判断*/
void in2post(ElemType *str, ElemType *p); /*中缀表达式转后缀表达式*/
double cal_post(char *str);               /*计算后缀表达式*/

/*字符栈初始化*/
int InitStack(SqStack *S)
{
    S->base = (ElemType *)malloc(STACK_INT_SIZE * sizeof(ElemType));
    if (!S->base)
        return ERROR; // 分配失败
    S->top = S->base;
    S->stacksize = STACK_INT_SIZE;
    return OK;
} /*InitStack*/

/*运算数栈初始化*/
int InitStack_N(NStack *S)
{
    S->base = (ElemType2 *)malloc(STACK_INT_SIZE * sizeof(ElemType2));
    if (!S->base)
        return ERROR;
    S->top = S->base;
    S->stacksize = STACK_INT_SIZE;
    return OK;
}

/*字符栈入栈*/
int Push(SqStack *S, ElemType e)
{
    // 判断栈满
    if (S->top - S->base >= S->stacksize)
    {
        S->base = (ElemType *)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(ElemType));
        if (NULL == S->base) // 分配失败
            return ERROR;
        S->top = S->base + S->stacksize;
        S->stacksize = S->stacksize + STACKINCREMENT;
    }
    *S->top = e;
    S->top++;
    return OK;
}

/*运算数栈入栈*/
int Push_N(NStack *S, ElemType2 e)
{
    if (S->top - S->base >= S->stacksize)
    {
        S->base = (ElemType2 *)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(ElemType2));
        if (NULL == S->base)
            return ERROR;
        S->top = S->base + S->stacksize;
        S->stacksize = S->stacksize + STACKINCREMENT;
    }
    *S->top = e;
    S->top++;
    return OK;
}

/*字符栈出栈*/
int Pop(SqStack *S, ElemType *e)
{
    // 判断栈空
    if (S->top == S->base)
        return ERROR;
    S->top--;
    *e = *S->top;
    return OK;
} /*Pop*/

/*运算数栈出栈*/
int Pop_N(NStack *S, ElemType2 *e)
{
    if (S->top == S->base)
        return ERROR;
    S->top--;
    *e = *S->top;
    return OK;
}

/*判断栈空*/
int StackEmpty(SqStack *s)
{
    if (s->top == s->base)
        return OK;
    return ERROR;
} /*StackEmpty*/

// str为待转换的中缀表达式字符串,p为转换后的后缀表达式字符串
void in2post(ElemType *str, ElemType *p)
{ /*infix to postfix*/
    SqStack s;
    InitStack(&s); // 初始化一个空字符栈
    ElemType e;
    int i;
    int j = 0;
    for (i = 0; i < strlen(str); i++) // 遍历中缀表达式
    {
        // 遇到数字和小数点直接输出
        // 使用循环完整接收一个运算数
        while (isdigit(str[i]) || '.' == str[i])
        {
            p[j++] = str[i++];
            if (!isdigit(str[i]) && '.' != str[i])
                p[j++] = ' '; // 一个数字完整输出后使用空格与其它运算符或数字分隔开
        }

        // 遇到左括号直接入栈
        if ('(' == str[i])
            Push(&s, str[i]);

        // 遇到右括号直接出栈，直到栈顶为左括号
        if (')' == str[i])
        {
            while ('(' != *(s.top - 1))
            {
                Pop(&s, &e);
                p[j++] = e;
                p[j++] = ' ';
            }
            Pop(&s, &e); // 左括号出栈但不输出
        }

        // 遇到+或—
        // 1.栈空/栈顶为左括号:直接入栈
        // 2.否则一直出栈,直到栈空/栈顶为左括号,再入栈
        if ('+' == str[i] || '-' == str[i])
        {
            while (!StackEmpty(&s) && '(' != *(s.top - 1))
            {
                Pop(&s, &e);
                p[j++] = e;
                p[j++] = ' ';
            }
            Push(&s, str[i]);
        }

        // 遇到*或/
        // 1.栈空/栈顶为左括号/栈顶操作符为+ or -:直接入栈
        // 2.否则一直出栈,直到满足1,再入栈
        if ('*' == str[i] || '/' == str[i] || '%' == str[i])
        {
            while (!StackEmpty(&s) && '(' != *(s.top - 1) && '+' != *(s.top - 1) && '-' != *(s.top - 1))
            {
                Pop(&s, &e);
                p[j++] = e;
                p[j++] = ' ';
            }
            Push(&s, str[i]);
        }
    }
    // 中缀表达式遍历完成,还需检查栈中是否有未输出字符
    // 判断栈空,非空则直接出栈并输出(左括号不用输出)
    while (!StackEmpty(&s))
    {
        Pop(&s, &e);
        if ('(' != e)
        {
            p[j++] = e;
            p[j++] = ' ';
        }
    }
    p[--j] = '\0';
} /*infix2postfix*/

// str为待计算的后缀表达式,返回值为计算结果
double cal_post(char *str)
{ /*计算后缀表达式*/
    int i;
    ElemType2 e, a, b;
    char d[M];
    NStack n;
    InitStack_N(&n); // 初始化一个运算数栈保存运算数
    for (i = 0; i < strlen(str); i++)
    {
        int j = 0;
        while (isdigit(str[i]) || '.' == str[i])
        {
            d[j++] = str[i++];
            d[j] = '\0';
            if (!isdigit(str[i]) && '.' != str[i])
            {
                e = atof(d);   // 使用atof()将字符串形式的运算数转换为double型数据
                Push_N(&n, e); // 运算数入栈
            }
        }
        switch (str[i])
        {
        case '+':
            Pop_N(&n, &b);
            Pop_N(&n, &a);
            Push_N(&n, a + b);
            break;
        case '-':
            Pop_N(&n, &b);
            Pop_N(&n, &a);
            Push_N(&n, a - b);
            break;
        case '*':
            Pop_N(&n, &b);
            Pop_N(&n, &a);
            Push_N(&n, a * b);
            break;
        case '/':
            Pop_N(&n, &b);
            Pop_N(&n, &a);
            Push_N(&n, a / b);
            break;
        }
    }
    Pop_N(&n, &e);
    return e;
} /*calculate_postfix*/

int main()
{
    char str[M];
    char post[M];
    int i;
    printf("\n输入一串中缀表达式：\n");
    gets(str);
    printf("\n对应的后缀表达式：\n");
    in2post(str, post);
    printf("%s", post);
    printf("\n\n计算后缀表达式：\n");
    printf("%f", cal_post(post));
    return 0;
}
```

## 文件

- fopen() —— 打开文件；
`FILE * fopen ( const char * filename, const char * mode );`
- fclose() —— 关闭文件；
`int fclose ( FILE * stream );`

| 使用方式      | 作用                                     | 如果文件不存在   |
| ------------- | ---------------------------------------- | ---------------- |
| "r"（只读）   | 为了输入数据，打开一个已经存在的文本文件 | 出错             |
| "w"（只写）   | 为了输出数据，打开一个文本文件           | 建立一个新的文件 |
| "a"（追加）   | 向文本文件添加数据                       | 建立一个新的文件 |
| "rb"（只读）  | 为了输入数据，打开一个二进制文件         | 出错             |
| "wb"（只写）  | 为了输出数据，打开一个二进制文件         | 建立一个新的文件 |
| "ab"（追加）  | 向一个二进制文件尾添加数据               | 出错             |
| "r+"（读写）  | 为了读和写，打开一个文本文件             | 出错             |
| "w+"（读写）  | 为了读和写，建立一个新的文本文件         | 建立一个新的文件 |
| "a+"（读写）  | 打开一个文本文件，在文件尾进行读写       | 建立一个文件     |
| "rb+"（读写） | 为了读和写，打开一个二进制文件           | 出错             |
| "wb+"（读写） | 为了读和写，建立一个新的二进制文件       | 建立一个新的文件 |
| "ab+"（读写） | 打开一个二进制文件，在文件尾进行读写     | 建立一个新的文件 |

| 函数名    | 功能           | 适用性     |
| --------- | -------------- | ---------- |
| fgetc()   | 字符输入函数   | 所有输入流 |
| fputc()   | 字符输出函数   | 所有输出流 |
| fgets()   | 文本行输入函数 | 所有输入流 |
| fputs()   | 文本行输出函数 | 所有输出流 |
| fscanf()  | 格式化输入函数 | 所有输入流 |
| fprintf() | 格式化输出函数 | 所有输出流 |
| fread()   | 二进制输入     | 文件       |
| fwrite()  | 二进制输出     | 文件       |

- fseek()函数：
该函数可以从定位位置的偏移量处开始读写；
`int fseek( FILE *stream, long offset, int origin );`
                     文件流          偏移量    起始位置 
返回值：
  如果成功，fseek返回0；
    否则，它返回一个非零值；
在无法查找的设备上，返回值未定义；

- feof()函数：
该函数被许多人错误用来判断文件是否读取结束，其实它的作用是判断文件读取结束的原因；

文件读取结束有两种情况：1.读取过程中出现异常； 2.读取到文件末尾；

要找出文件读取是哪个原因，就分为以下情况：

文本文件：
> 如果用 fgetc() 读取，要判断 feof() 的返回值是否为EOF；
> 如果用 fgets() 读取，要判断 feof() 的返回值是否为NULL(0)；

二进制文件：
> 都是使用 fread() 读取，要判断其返回值与指定读取个数的大小，如果小于实际要读的个数，就说明发生读取异常，如果等于实际要读的个数，就说明是因读取成功而结束；

对于读取异常的判断，我们考虑判断 ferror() 函数的返回值：

> 若ferrror()为真——异常读取而结束；
> 若feof()为真——正常读取到尾而结束；

### 读取示例

```c
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct Shop
{
    char name[20];
    double price;
    int num;
    double totalprice;
    Shop *next;
} Shop;

Shop *create(FILE *fp)
{
    Shop *head = (Shop *)malloc(sizeof(Shop));
    Shop *tail = head;

    while (1)
    {
        Shop *temp = (Shop *)malloc(sizeof(Shop));
        fscanf(fp, "%s %lf %d %lf", &temp->name, &temp->price, &temp->num, &temp->totalprice);
        tail->next = temp;
        tail = temp;
        if (feof(fp))
            break;
    }
    tail->next = NULL;
    return head;
}

int main()
{
    FILE *fp1 = fopen("file1.txt", "r");
    FILE *fp2 = fopen("file2.txt", "r");

    Shop *shop1 = create(fp1);
    Shop *shop2 = create(fp2);

    double total1, total2;

    printf("first people\n");
    Shop *first = shop1->next;
    while (first)
    {
        total1 += first->totalprice;
        printf("%s -> ", first->name);

        first = first->next;
    }
    printf("\nfirst: %lf\n", total1);

    printf("second people\n");
    for (Shop *it = shop2->next; it != nullptr; it = it->next)
    {
        total2 += it->totalprice;
        printf("%s -> ", it->name);
    }
    printf("\nsecond: %lf\n", total2);

    printf("插值: %lf", abs(total1 - total2));

    return 0;
}
```

## PTA

### Programming in C is fun

```c
#include <stdio.h>

int main(void) {
    printf("Programming in C is fun!\n");
    return 0;
}
```

### 输出倒三角形

```c
#include<stdio.h>

int main(void){
    printf("* * * *\n * * *\n  * *\n   *");
    return 0;
}
```

### 温度转换

```c
#include <stdio.h>

int main(void)
{
    int fahr = 150;
    int celsius = 5 * (fahr - 32) / 9;
    printf("fahr = %d, celsius = %d", fahr, celsius);
    return 0;
}
```

### 计算物体自由下落的距离

```c
#include <stdio.h>

int main(void)
{
    int height = 100;
    int time = 3;
    int grivaty = 10;

    int result = 0.5 * grivaty * time * time;
    printf("height = %d", result);
    return 0;
}
```

### 计算摄氏温度

```c
#include <stdio.h>

int main(void)
{
    int fahr = 0;
    scanf("%d", &fahr);
    
    int celsius = 5 * (fahr - 32) / 9;
    printf("celsius = %d", celsius);
    return 0;
}
```

### 整数四则运算

```c
#include <stdio.h>

int main(void)
{
    int A, B;
    scanf("%d %d", &A, &B);

    printf("%d + %d = %d\n", A, B, A + B);
    printf("%d - %d = %d\n", A, B, A - B);
    printf("%d * %d = %d\n", A, B, A * B);
    printf("%d / %d = %d", A, B, A / B);
}
```

### 计算分段函数

```c
#include <stdio.h>
int main()
{
    float x, y;
    scanf("%f", &x);
    if (x != 0)
    {
        y = 1 / x;
    }
    else
    {
        y = 0.0;
    }
    printf("f(%.1f) = %.1f", x, y);
    return 0;
}
```

### 计算分段函数2

> double类型的输入输出应该用　**%lf**

```c
#include <stdio.h>
#include <math.h>

int main()
{
    double x = 0;
    scanf("%lf", &x);

    double y = 0;

    if(x >= 0)
    {
        y = sqrt(x);
    }else
    {
        y = pow(x+1, 2) + 2*x + 1/x;
    }
    
    printf("f(%.2f) = %.2f", x, y);
    return 0;
}
```

### 输出华氏-摄氏温度转换表

```c
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int lower, upper;
    scanf("%d %d", &lower, &upper);
    if (lower > upper || upper > 100)
    {
        printf("Invalid.");
        exit(0);
    }
    printf("fahr celsius\n");
    do
    {
        printf("%d%6.1f\n", lower, 5.0 * (lower - 32) / 9);
        lower += 2;
    } while (lower <= upper);
    return 0;
}
```

### 求N分之一序列前N项和

> 注意类型转换

```c
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    double sum = 0;

    for (int i = 1; i < n + 1; i++)
    {
        sum += 1.0 / i;
    }

    printf("%.6f", sum);
    return 0;
}
```

### 求奇数分之一序列前N项和

```c
#include <stdio.h>
int main()
{
    int n;
    double s = 0;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        s += 1.0 / (2 * i - 1);
    }

    printf("sum = %.6lf", s);
    return 0;
}
```

### 求简单交错序列前N项和

```c
#include <stdio.h>
int main()
{
    int n, i;
    double sum = 0, x = 1;
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            sum += 1.0 / x;
        }
        else
        {
            sum -= 1.0 / x;
        }
        x += 3;
    }
    
    printf("sum = %.3lf", sum);
    return 0;
}
```

### 生成3的乘方表

```c
#include <stdio.h>
#include <math.h>

int main()
{
    int n = 0;
    scanf("%d", &n);

    int x;

    for (int i = 0; i <= n; i++)
    {
        x = pow(3, i);
        printf("pow(3, %d) = %d\n", i, x);
    }

    return 0;
}
```

### 求组合数

![Alt text](assets/image-c1.png)

```c
#include <stdio.h>
#include <math.h>

double fact(int n)
{
    if (n == 1)
        return 1;
    return n * fact(n - 1);
}

int main()
{
    int m, n;

    scanf("%d %d", &m, &n);

    double a = fact(n);
    double b = fact(m);
    double c = fact(n - m);

    double result = a / (b * c);

    printf("result = %.0lf", result);

    return 0;
}
```

### 求整数均值

![Alt text](assets/image-c2.png)

```c
#include <stdio.h>

int main()
{
    int a, b, c, d;

    scanf("%d %d %d %d", &a, &b, &c, &d);

    int sum = a + b + c + d;
    float average = sum / 4.0;

    printf("Sum = %d; Average = %.1f", sum, average);

    return 0;
}
```

### 阶梯电价

![Alt text](assets/image-c3.png)

```c
#include <stdio.h>
int main()
{
    int kwh;
    double cost;
    scanf("%d", &kwh);
    if (kwh >= 0 && kwh <= 50)
    {
        cost = 0.53 * kwh;
        printf("cost = %.2lf", cost);
    }
    else if (kwh > 50)
    {
        cost = (kwh - 50) * 0.58 + 0.53 * 50;
        printf("cost = %.2lf", cost);
    }
    else
    {
        printf("Invalid Value!");
    }
    return 0;
}
```

### 求平方与倒数序列的部分和

![Alt text](assets/image-c4.png)

```c
#include <stdio.h>

int main()
{
    int m, n, i;
    double a, b, s = 0;
    scanf("%d %d", &m, &n);
    for (i = m; i <= n; i++)
    {
        a = i * i;
        b = 1.0 / i;
        s = s + a + b;
    }
    printf("sum = %.6lf", s);
    return 0;
}
```

### 求交错序列前N项和

![Alt text](assets/image-c5.png)

> c语言自动转型会出错所以`double frac = i / (2.0 * i - 1.0);`
> 写成`double frac = i / (2 * i - 1);`
> 就会由int转成double丢失数据

```c
#include <stdio.h>
#include <math.h>

int main()
{
    int m;
    scanf("%d", &m);

    double sum = 0.0;

    for (int i = 1; i <= m; i++)
    {
        double frac = i / (2.0 * i - 1.0);
        double np = pow(-1, i + 1);

        sum += np * frac;
    }

    printf("%.3lf", sum);

    return 0;
}
```

### 求平方根序列前N项和

![Alt text](assets/image-c6.png)

```c
#include <stdio.h>
#include <math.h>

int main()
{
    int m;
    scanf("%d", &m);

    double sum = 0.0;

    for (int i = 1; i <= m; i++)
    {
        sum += sqrt(i);
    }

    printf("sum = %.2lf", sum);

    return 0;
}
```

### 求阶乘序列前N项和

![Alt text](assets/image-c7.png)

```c
#include <stdio.h>

double fact(int n)
{
    if (n == 1)
        return 1;
    return n * fact(n - 1);
}

int main()
{
    int m;
    scanf("%d", &m);

    double sum = 0.0;

    for (int i = 1; i <= m; i++)
    {
        sum += fact(i);
    }

    printf("%.0lf", sum);

    return 0;
}
```

### 计算符号函数的值

![Alt text](assets/image-c8.png)

```c
#include <stdio.h>
int main()
{
    int n, sign;
    
    scanf("%d", &n);

    if (n < 0)
    {
        sign = -1;
    }
    else if (n == 0)
    {
        sign = 0;
    }
    else if (n > 0)
    {
        sign = 1;
    }

    printf("sign(%d) = %d", n, sign);

    return 0;
}
```

### 统计学生平均成绩与及格人数

![Alt text](assets/image-c9.png)

```c
#include <stdio.h>
int main()
{
    int n, i, record, count = 0;
    double sum = 0, average = 0;

    scanf("%d", &n);

    if (n != 0)
    {
        for (i = 0; i < n; i++)
        {
            scanf("%d", &record);
            sum += record;
            if (record >= 60)
            {
                count++;
            }
        }
        average = sum / n;
    }
    else
    {
        average = 0, count = 0;
    }

    printf("average = %.1f\n count = %d", average, count);

    return 0;
}
```

### 统计字符

![Alt text](assets/image-c10.png)

```c
#include <stdio.h>

int main()
{
    int letter, blank, digit, other;

    char a[10];

    for (int i = 0; i < 10; i++)
    {
        scanf("%c", &a[i]);
    }

    for (int i = 0; i < 10; i++)
    {
        if (a[i] > 'a' && a[i] < 'z' || a[i] > 'A' && a[i] < 'Z')
        {
            letter++;
        }
        else if (a[i] == ' ' || a[i] == '\n')
        {
            blank++;
        }
        else if (a[i] >= '0' && a[i] <= '9')
        {
            digit++;
        }
        else
        {
            other++;
        }
    }
    printf("letter = %d, blank = %d, digit = %d, other = %d", letter, blank, digit, other);

    return 0;
}
```

### 输出闰年

![Alt text](assets/image-c11.png)

```c
#include <stdio.h>

int main()
{
    int end;

    scanf("%d", &end);

    if (end < 2000 || end > 2100)
    {
        printf("Invalid year!");
        return 0;
    }

    for (int i = 2000; i <= end; i++)
    {
        if (i % 4 == 0 || i % 400 == 0)
        {
            if (i % 100 != 0)
            {
                printf("%d\n", i);
            }
        }
    }

    return 0;
}
```

### 成绩转换

![Alt text](image-c12.png)

```c
#include <stdio.h>
int main()
{
    int x;
    char grade;
    scanf("%d", &x);
    if (x >= 0 && x < 60)
    {
        grade = 'E';
    }
    else if (x >= 60 && x < 70)
    {
        grade = 'D';
    }
    else if (x >= 70 && x < 80)
    {
        grade = 'C';
    }
    else if (x >= 80 && x < 90)
    {
        grade = 'B';
    }
    else if (x >= 90)
    {
        grade = 'A';
    }
    printf("%c", grade);
    return 0;
}
```

### 三角形判断

![Alt text](assets/image-c13.png)

![Alt text](assets/image-c14.png)

```c
#include <stdio.h>
#include <math.h>
double distance(double a, double b, double c, double d)
{
    double x;
    x = sqrt((a - c) * (a - c) + (b - d) * (b - d));
    return x;
}
int main()
{
    double x1, y1, x2, y2, x3, y3;
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
    double a, b, c, A, L;
    a = distance(x1, y1, x2, y2);
    b = distance(x1, y1, x3, y3);
    c = distance(x2, y2, x3, y3);
    L = a + b + c;
    if (a + b > c && a + c > b && b + c > a)
    {
        double p = L / 2.0;
        A = sqrt(p * (p - a) * (p - b) * (p - c));
        printf("L = %.2lf, A = %.2lf\n", L, A);
    }
    else
    {
        printf("Impossible");
    }
    return 0;
}
```