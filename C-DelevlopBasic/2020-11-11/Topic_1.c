#include <stdio.h>
int main()
{
    int n;//循环总次数
    int num;//用户输入的数
    int min;//最小值
    int s;//当前循环的次数
    s = 0;
    scanf("%d",&n);
    while(s<=n){
        scanf("%d",&num);
        if(num<min)
            min = num;
        s++;
    }
    printf("min = %d\n",min);
    return 0;
}