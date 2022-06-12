int main(){
    int x;
    int max=0;
    printf("请输入数组长度\n");
    scanf("%d",&x);
    int data[x];
    for(int i=0;i<x;i++){
        scanf("%d",&array[i]);
    }
    for (int i=0;i<x; i++)
        printf("数组第%d个元素为%d\n",i+1,n[i]);
    int n=0;
    for(int i=0;i<x;i++){
        n+=data[i];
        if(n>max)
            max=n;
        else if(n<0)
            n = 0;
    }
    printf("最大为%d\n",max);
    return 0;
}

