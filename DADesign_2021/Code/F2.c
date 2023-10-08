/*
 * @Description: 
 * @Author: Ryan Zhang
 * @Date: 2021-06-29 20:31:29
 * @LastEditTime: 2021-06-29 23:46:31
 * @LastEditors: Ryan Zhang
 */


#define LIST_INIT_SIZE 5;
#define OVERFLOW -2
#define SUCCESS 1;
#define ERROE 0;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct veh{
    char Licence[10];
    int ET;
    int OT;
    int Amount;
}vehicle;

typedef struct {
    vehicle *List;
    int Top;
    int MaxSize;
}VehicleList;


typedef struct {
    vehicle *List;
    int Front;
    int length;
    int MaxSize;
}VehicleWaitList;


/*
 初始化栈
 */
void Intlist(VehicleList *L){
    L->List=(vehicle *)malloc(5*sizeof(vehicle));
    if(!L->List)exit(OVERFLOW);//overflow
    L->Top=0;//初始表为空表
    L->MaxSize=LIST_INIT_SIZE;
    return;
}

/*
 初始化队列
 */
void Intlist_Wait(VehicleWaitList *L){
    L->List=(vehicle *)malloc(5*sizeof(vehicle));
    if(!L->List)exit(OVERFLOW);//overflow
    L->length=0;//初始表为空表
    L->Front=0;
    L->MaxSize=LIST_INIT_SIZE;
    return;
}


/*
 菜单显示
 */
void print_view(int i){
    printf("\t\t停车场管理程序\n");
    printf("==========================================\n");
    printf("A --- 汽车进车场\n");
    printf("D --- 汽车出车场\n");
    printf("E --- 退出程序\n");
    printf("停车场剩余%d车位，每小时收费10元\n",5 - i);
    printf("==========================================\n");
}


/*
 车辆进场
 */
void vehicle_Enter(VehicleList *L,VehicleWaitList *wait){
    char licence[10];
    int jrsj;
    printf("车牌：");
    scanf("%s",licence);
    printf("入场时间：");
    scanf("%d",&jrsj);
    if(L->Top==L->MaxSize && wait->length == wait->MaxSize){
        printf("停车场要被挤爆啦");
        getchar();
        getchar();
        return;
    }
    if(L->Top!=L->MaxSize){ // 车位未满
        strcpy(L->List[L->Top].Licence, licence);
        L->List[L->Top].ET = jrsj;
        printf("该车已进入停车场在%d号车位.\n",L->Top+1);
        L->Top++;
    }else{ // 车位满了
        wait->length++;
        strcpy(wait->List[(wait->length + wait->Front) %wait->MaxSize].Licence, licence);
        wait->List[(wait->length + wait->Front) %wait->MaxSize].ET = jrsj;
        printf("停车场已满，该车先停在便道的第%d个位置上:.\n",wait->length);
    }
    getchar();
    getchar();
    return;
}

/*
 车辆出场
 */
void vehicle_Out(VehicleList *L, VehicleWaitList *wait, VehicleList *temp){
    char licence[10];
    int ccsj,flag,sum;
    
    flag = -1;
    printf("车牌：");
    scanf("%s",licence);
    printf("出场时间：");
    scanf("%d",&ccsj);
    
    // 找到要出场的车位
    for (int i=0; i<L->Top; i++) {
        if(strcmp(licence, L->List[i].Licence) == 0){
            flag = i; // 记录车所在位置
            L->List[i].OT = ccsj; // 写入出场时间
        }
    }
    if(flag == -1){
        printf("找不到该车辆");
        getchar();
        getchar();
        return;
    }else{
        // 后面的车辆出场（出栈，进入另一个栈）
        for (int i=L->Top; i>flag; i--) {
            strcpy(temp->List[temp->Top].Licence, L->List[i].Licence);
            temp->List[temp->Top].ET = L->List[i].ET;
            temp->Top++;
            L->Top--;
        }
        // 现在栈顶就是要出场的车辆了。
        
        // 打印收据
        printf("\t收据\n");
        printf("=========================================================================\n");
        printf("\t车牌号:%s\n",L->List[flag].Licence);
        printf("进车场时刻\t出车场时刻\t停留时间\t应付（元）\n");
        sum = L->List[flag].OT-L->List[flag].ET;
        printf("%d\t%d\t%d\t%d\n",L->List[flag].ET,L->List[flag].OT,sum,sum*10);
        printf("=========================================================================\n");
        L->Top--;
        getchar();
        getchar();

        // 重新入栈
        for (int i=temp->Top; i>0; i--) {
            strcpy(L->List[L->Top].Licence, temp->List[i].Licence);
            L->List[L->Top].ET = temp->List[i].ET;
            temp->Top--;
            L->Top++;
        }
        
        // check 检查是否可以入场
        for (int i=0; i<wait->length; i++) {
            wait->Front++;
            wait->length--;
            strcpy(L->List[L->Top].Licence, wait->List[(wait->Front) % wait->MaxSize].Licence);
            L->List[L->Top].ET = wait->List[(wait->Front) % wait->MaxSize].ET;
            L->Top++;
        }
        
        return;
    }
}


int main(){
    char input;
    VehicleList L;
    VehicleWaitList wait_L;
    VehicleList temp;
    Intlist(&L);
    Intlist_Wait(&wait_L);
    Intlist(&temp);
    while(1){
        system("clear");
        print_view(L.Top);
        printf("请选择 :(A,D,E):");
        scanf("%c",&input);

        switch (input) {
            case 'A':
                vehicle_Enter(&L,&wait_L);
                break;
            case 'E':
                exit(OVERFLOW);
            case 'D':
                vehicle_Out(&L,&wait_L,&temp);
                break;
            default:
                printf("输入有误，重新输入\n");
                getchar();
                getchar();
                break;
        }
    }

    return 0;
}
