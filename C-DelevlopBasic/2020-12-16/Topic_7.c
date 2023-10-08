#include <stdio.h>
#include <stdlib.h>

void print_max(int *s,int n){
    float max = *s;
    for (int i=0; i<n; i++) {
        if(max<*(s+i))
            max = *(s+i);
    }
    printf("max = %.2f\n",max);
}
void print_min(int *s,int n){
    float min = *s;
    for (int i=0; i<n; i++) {
        if(min>*(s+i))
            min = *(s+i);
    }
    printf("min = %.2f\n",min);
}
void print_average(int *s,int n){
    float sore=0.0;
    for (int i=0; i<n; i++) {
        sore+=*(s+i);
    }
    printf("average = %.2f\n",sore/n);
}

int main(){
    int size;
    int *num;
    scanf("%d",&size);
    num = (int*)malloc(sizeof(int) * size);
    for (int i=0; i<size; i++) {
        scanf("%d",&num[i]);
    }
    print_average(num,size);
    print_max(num,size);
    print_min(num,size);
    return 0;
}
