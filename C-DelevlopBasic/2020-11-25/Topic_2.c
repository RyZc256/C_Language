#include <stdio.h>
int main(){
int n,i,j;
    int s[10][10];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        s[i][i] = 1;
        s[i][0] = 1;
        //printf("%d,%d\n",s[i][i],s[i][0]);
    }
    for(i=1;i<n;i++){
        for(j=1;j<i;j++){
            s[i][j]=s[i-1][j] + s[i-1][j-1];
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            printf("%4d",s[i][j]);
        }
        printf("\n");
    }
    return 0;
}
