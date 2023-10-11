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