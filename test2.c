#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int suijishu(double start, double end)
{
    return (int)(start+(end-start)*rand()/(RAND_MAX+1.0));
}

char test0()
{
    int a;
    char signal1[4]={'+','-','*','/'};
    srand((unsigned)time(NULL));
    a = rand()%4;
    return signal1[a];
}
char test1()//获取随机运算符函数
{
    int b;
    char signal2[4]={'+','-','*','/'};
    srand((unsigned)time(NULL));
    b = rand()%4;
    return signal2[b];
}
int jieguo(int num1,int num2,int num3,char signal1,char signal2)//结果计算函数
{
    int i=0,res;
    if(signal1=='+')
    {
        if(signal2=='+')
        {
            res=num1+num2+num3;
        }
        if(signal2=='-')
        {
            res=num1+num2-num3;
        }
        if(signal2=='*')
        {
            res=num2*num3+num1;
        }
        if(signal2=='/')
        {
            res=num2/num3+num1;
        }
    }
    if(signal1=='-')
    {
        if(signal2=='+')
        {
            res=num1-num2+num3;
        }
        if(signal2=='-')
        {
            res=num1-num2-num3;
        }
        if(signal2=='*')
        {
            res=num2*num3-num1;
        }
        if(signal2=='/')
        {
            res=num2/num3-num1;
        }
    }
    if(signal1=='*')
    {
        if(signal2=='+')
        {
            res=num1*num2+num3;
        }
        if(signal2=='-')
        {
            res=num1*num2-num3;
        }
        if(signal2=='*')
        {
            res=num2*num3*num1;
        }
        if(signal2=='/')
        {
            res=num2/num3*num1;
        }
    }
    if(signal1=='/')
    {
        if(signal2=='+')
        {
            res=num1/num2+num3;
        }
        if(signal2=='-')
        {
            res=num1/num2-num3;
        }
        if(signal2=='*')
        {
            res=num2*num3/num1;
        }
        if(signal2=='/')
        {
            res=num2/num3/num1;
        }
    }
    return res;
}

int Test()
{
    int get;
    int num1,num2,num3,a;
    char signal1,signal2;

    srand((unsigned)time(NULL));
    signal1=test0();
    srand((unsigned)time(NULL));
    signal2=test1();
    num1=suijishu(1,100);
    num2=suijishu(0,100);
    num3=suijishu(1,100);
if(signal1=='-')
    {
        if(num1<num2)
        {
            int temp;
            temp=num1;
            num1=num2;
            num2=temp;
        }
    }
    if(signal1=='/')
    {
        if(num2==0)
        {
            int temp;
            temp=num1;
            num1=num2;
            num2=temp;
        }
    }
    printf("%d%c%d%c%d=",num1,signal1,num2,signal2,num3);
    scanf("%d",&get);
    fflush(stdin);   //清空输入缓冲区
    if(Result(num1,num2,num3,signal1,signal2)==get)
        {
        printf("回答正确!\n");
        a=1;
        }
    else
    {
        printf("回答错误!\n");
        printf("正确答案是: %d\n",Result(num1,num2,num3,signal1,signal2));
        a=0;
    }
    return a;
}

void main()
{
         int n,a,right=0,i=0;
         double percent;
         printf("请输入题目数量:");
         scanf("%d",&n);
         for(i;i<n;i++)
         {
                   a=Test();
                   right=right+a;
         }
         printf("回答完毕!\n");
         printf("回答正确数量:%d\n",right);
         percent=((double)right*100.00)/(double)n;
         printf("正确率:%0.2f %%\n",percent);
}
