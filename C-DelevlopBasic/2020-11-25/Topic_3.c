#include <stdio.h>
int main(){
    int n,i,j,num=1;
    scanf("%d",&n);
    int s[10][10] = {0};
    int a=0;
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            s[i][j] = num;
            num++;
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%3d",s[i][j]);
        }
        printf("\n");
    }
    return 0;
}