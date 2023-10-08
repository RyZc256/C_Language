#include <stdio.h>
#include <string.h>
int main(){
    char s[40];
    int zm,sz,kg,qt,i;
    zm=sz=kg=qt=0;
    gets(s);
    for(i=0;i<strlen(s);i++){
        if(s[i]==32)
            kg += 1;
        else if(s[i]>=48&&s[i]<=57)
            sz += 1;
        else if(s[i]>=65&&s[i]<=90)
            zm += 1;
        else if(s[i]>=97&&s[i]<=122)
            zm += 1;
        else
            qt += 1;
    }
    printf("zimu=%d\n",zm);
    printf("shuzi=%d\n",sz);
    printf("kongge=%d\n",kg);
    printf("qita=%d\n",qt);
}
