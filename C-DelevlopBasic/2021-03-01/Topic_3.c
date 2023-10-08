#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

struct data{
    char name[100];
    float price;
};

int main(){
    int n, i, j;
    scanf("%d",&n);
    struct data p[n];
    for (i=0; i<n; i++) {
        getchar();
        gets(p[i].name);
        scanf("%f",&p[i].price);
    }
    struct data temp;
    for (i=0; i<n-1; i++) {
        for (j=0; j<n-1-i; j++) {
            if(p[j].price>p[j+1].price){
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
    for (i=0; i<n; i++) {
        printf("%s ",p[i].name);
        printf("%.1f",p[i].price);
        printf("\n");
    }
}
