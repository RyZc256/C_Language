#include <stdio.h>
#include <math.h>
typedef struct{
    int x1;
    int x2;
    int y1;
    int y2;
}data;


double compute(data num){
    double sum;
    sum = sqrt(pow(num.x1-num.x2,2) + pow(num.y1-num.y2,2));
    return sum;
}

int main(){
    data d;
    scanf("%d %d %d %d",&d.x1,&d.y1,&d.x2,&d.y2);
    printf("distance = %.2lf",compute(d));
    return 0;
}
