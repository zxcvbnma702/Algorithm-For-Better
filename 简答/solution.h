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