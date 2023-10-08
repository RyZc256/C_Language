#include <stdio.h>
#include <string.h>

typedef struct{
    char name[20];
    int high;
    int weight;
}inf;

typedef struct{
    int high[2];
    int weight[2];
}range;

void print(inf d[],range s,int num){
    int count = 0;
    // 用于复制结构体
    inf ff[num];
    for (int i=0; i<num; i++) {
        // 判断是否符合夫婿条件
        if(s.high[0] <= d[i].high && d[i].high <= s.high[1]){
            if(s.weight[0] <= d[i].weight && d[i].weight <= s.weight[1]){
                ff[count]=d[i];
                count++;
            }
        }
    }
    // 建立零时结构体变量
    inf tem;
    // 如果是0的话，那就是没有夫婿，直接打印NO
    if (count){
        // 冒泡排序身高
        for (int i=0; i<count-1; i++) {
            for (int j=0; j<count-1-i; j++) {
                if(ff[j].high>ff[j+1].high){
                    tem = ff[j];
                    ff[j]=ff[j+1];
                    ff[j+1]=tem;
                }
            }
        }
        // 排序体重
        for (int i=0; i<count; i++) {
            for (int j=0; j<count-1-i; j++) {
                if(ff[j].high==ff[j+1].high){
                    if(ff[j].weight>ff[j+1].weight){
                        tem = ff[j];
                        ff[j]=ff[j+1];
                        ff[j+1]=tem;
                    }
                }
            }
        }
    }
    else
        printf("NO");
    for (int i=0; i<count; i++) {
        printf("%s %d %d\n",ff[i].name,ff[i].high,ff[i].weight);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    inf data[n];
    range f;
    for (int i=0; i<n; i++) {
        scanf("%s %d %d ",&data[i].name,&data[i].high,&data[i].weight);
    }
    scanf("%d %d %d %d",&f.high[0],&f.high[1],&f.weight[0],&f.weight[1]);
    print(data, f, n);
    return 0;
}

