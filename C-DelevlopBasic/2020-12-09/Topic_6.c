#include<stdio.h>
#include<string.h>
#include<math.h>
int judge(int n){
    if(n == 2||n == 3){
        return 1;
    }
    if(n % 2==0){
        return 0;
    }
    int i;
    for(i = 3;i <= sqrt(n);i += 2){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}
int main(){
    int l,i,k,j;
    char s[1005];
    scanf("%d%d",&l,&k);
    scanf("%s",s);

    int num,flag = 1;
    int len = strlen(s);
    for(i = 0;i <= len-k;i++){
        num = 0;
        for(j = i;j < i+k;j++){
            num *= 10;
            num += s[j] - '0';
        }
        if(num != 2&&(s[i+k-1]-'0')%2==0){

        }else if(judge(num)){
            for(j = i;j < i+k;j++){
                printf("%c",s[j]);
            }
            return 0;
        }
    }
    printf("404");
    return 0;
}