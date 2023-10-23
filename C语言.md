# C语言

## Programming in C is fun!

```c
#include <stdio.h>

int main(void) {
    printf("Programming in C is fun!\n");
    return 0;
}
```

## 输出倒三角形

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