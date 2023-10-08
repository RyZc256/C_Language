#include <stdio.h>
#include <math.h>

struct point{
    int x;
    int y;
};

int main(){
    float Distance;
    int temp;
    struct point p[2];
    scanf("%d %d %d %d",&p[0].x,&p[0].y,&p[1].x,&p[1].y);
    temp = pow(p[0].x-p[1].x,2) + pow(p[0].y-p[1].y,2);
    Distance = sqrt(temp);
    printf("distance = %.2f",Distance);
}
