#include <stdio.h>
int main(){
    int s[10];
    int n,num,i,k=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&s[i]);
    }
    scanf("%d",&num);
    
    
    for(i=0;i<n;i++){
        if(num>s[i])
            k=i+1;
    }
    for(i=n-1;i>=k;i--){
        s[i+1]=s[i];
    }
    s[k] = num;
    for(i=0;i<=n;i++){
        printf("%d ",s[i]);
    }
}
