#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
    char s[10000] = {0};
    char str[1000][50] = {0};
    int flag,flag1; // 第一个flag用来判断是不是有奇怪的字符， 第二个flag用来判断空格是不是结束了
    int i,j,n,k,num; // 变量分别为 i,j循环体所用 n二维数组的列 num一维数组的下表
    int sum;
    gets(s);
    flag = flag1 = n = 0;
    num = -1;
    sum = 0;
    // 字符统一转小写
    for (i=0; i<strlen(s); i++) {
        if(s[i]>='A' && s[i]<='Z')
            s[i] = s[i] + 32;
    }
    
    // 一维数组转二维数组
    for (i=0; i<strlen(s); i++) {
        while(1){//进入循环，将每个单词转为写入二维数组的一行当中
            num++;
            if(s[num]==' ' || s[num]=='\0'){ // 如果当前下标里存储的是空格或者是无赋值的值，那就进入判断语句
                n = 0; //如果是空格就代表单词结束，需要写入下一行，所以n要重新为0为下一行做准备
                break;
            }
            else{ // 如果不是空格那就进入判断语句
                str[i][n]=s[num]; // 往二维数组当前行里写数据
                n++; //没写一次列就要+1
            }
        }
    }
    
    
    // 判断是否有重复
    for (i=0; i<999; i++) {
        for (j=0; j<1000; j++) {
            if(i!=j)
                if(strcmp(str[i], str[j])==0)
                    str[j][0] = '\0';
        }
        if(str[i][0]>='a' && str[i][0]<='z')
            sum++;
        for (k=0; k<50; k++) {
            if(!(str[i][k]>='a' && str[i][k]<='z')){ // 如果有其他字符 改变flag
                if(str[i][k]!=' ' && str[i][k]!='\0'){
                    printf("No");
                    return 0;
                    
                }
            }
        }
        
    }
    // 输出
    printf("%d",sum);
    return 0;
}
