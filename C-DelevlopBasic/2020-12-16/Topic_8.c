#include <stdio.h>


// 找零
int get_money(int s[],int s1[],int n,int n1){
    int sore=0;
    int change=0;
    for (int i=0; i<n; i++) {
        sore+=s[i];
    }
    for (int i=0; i<n1; i++) {
        if(s1[i]==1 || s1[i]==2 || s1[i]==3)
            change += 1;
        else if(s1[i]==4 || s1[i]==5)
            change += 2;
        else if(s1[i]==6 || s1[i]==7 || s1[i]==8)
            change += 3;
        else if(s1[i]==9 || s1[i]==10)
            change += 4;
    }
    if(sore-change<0){
        printf("Insufficient money");
        return 0;
    }else
        change = sore - change;
    printf("Total:%dyuan,change:%dyuan\n",sore,change);
    return 1;
}

// 传入参数，s[]是商品数组，n是数组长度
void print_dt(int s[],int n){
    int flag[10]={0};
    // 遍历输入的商品数组，如果遇到某个商品，某个商品对应的int数组flag就+1
    for (int i=0; i<n; i++) {
        switch (s[i]) {
            case 1:flag[0]++;break;
            case 2:flag[1]++;break;
            case 3:flag[2]++;break;
            case 4:flag[3]++;break;
            case 5:flag[4]++;break;
            case 6:flag[5]++;break;
            case 7:flag[6]++;break;
            case 8:flag[7]++;break;
            case 9:flag[8]++;break;
            case 10:flag[9]++;break;
        }
    }
    for (int i=0; i<10; i++) {
        if(flag[i]!=0)
            if(i==0 || i==1 || i==2)
                printf("Table-water:%d;",flag[i]);
            else if(i==3)
                printf("Coca-Cola:%d;",flag[i]);
            else if(i==4)
                printf("Milk:%d;",flag[i]);
            else if(i==5)
                printf("Beer:%d;",flag[i]);
            else if(i==6)
                printf("Orange-Juice:%d;",flag[i]);
            else if(i==7)
                printf("Sprite:%d;",flag[i]);
            else if(i==8)
                printf("Oolong-Tea:%d;",flag[i]);
            else if(i==9)
                printf("Green-Tea:%d;",flag[i]);
    }
    printf("\n");
}


int main(){
    // 硬币
    int s[999] = {0};
    // 商品
    int s1[999] = {0};
    int tem,i=0,len;
    // 收硬币
    while (1) {
        scanf("%d",&tem);
        // 结束输入
        if(tem==-1 || tem>10)
            break;
        else
            s[i]=tem;
        i++;
    }
    len = i;
    i = 0;
    // 找商品
    while (1) {
        scanf("%d",&tem);
        if(tem==-1 || tem>10)
            break;
        else
            s1[i]=tem;
        i++;
    }
    if(get_money(s,s1,len,i))
        print_dt(s1,i);
    return 0;
}