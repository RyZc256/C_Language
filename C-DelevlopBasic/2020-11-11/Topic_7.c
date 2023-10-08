#include <stdio.h>

int main(){
    int a;
    int sum,k;
    sum = 0;
    k = 1;
    scanf("%d",&a);
    for(int i=1;i<=a;i++){
        k *= i;
        sum += k;
    }
    printf("%d",sum);
}
