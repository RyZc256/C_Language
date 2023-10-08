#include <stdio.h>

int main(){
    int a,b,i,sum;
    sum = 0;
    scanf("%d %d",&a,&b);
    i = a;
    while(i<=b){
        if(i/100000==8||i/10000%10==8||i/1000%10==8||i/100%10==8||i/10%10==8||i%10==8){
            sum++;
        }
        i++;
    }
    printf("%d",sum);
    return 0;
}
