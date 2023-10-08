#include <stdio.h>
int main(){
    int sum;
    int a,b,c;
    int number,total; // 解法，公鸡数量
    number = total = 0;
    scanf("%d",&sum);
    for(a=0;a<=100;a++){
        for(b=0;b<=100;b++){
            for(c=0;c<=100;c++){
                if(a+b+(c*3)==sum&&(a*5)+(b*3)+(c*1)==sum){
                    number ++;
                    total += a;
                    continue;
                }
            }
        }
    }
    if(number==0&&total==0)
        printf("%d %d",0,-1);
    else
        printf("%d %d",number,total);
}
