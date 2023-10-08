#include "stdio.h"
#include "string.h"
int main(){
    char str[10000][15]={0};
    char tem[15]={0};
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",str[i]);
    }
    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
            if(strcmp(str[i],str[j])>0){
                strcpy(tem, str[i]);
                strcpy(str[i],str[j]);
                strcpy(str[j],tem);
            }
        }
    }
    for(i=0;i<n;i++){
        printf("%s\n",str[i]);
    }
    return 0;
}
