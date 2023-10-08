#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
    int n;
    float max, min, sum, *score;
    scanf("%d",&n);
    max = sum = 0.0;
    min = 9999.0;
    score = (float*)malloc(sizeof(float) * n);
    for (int i=0; i<n; i++) {
        scanf("%f",&score[i]);
        if(score[i] > max)
            max = score[i];
        if(score[i] < min)
            min = score[i];
        sum += score[i];
    }
    printf("average = %.2f\n",sum/n);
    printf("max = %.2f\n",max);
    printf("min = %.2f",min);
}
