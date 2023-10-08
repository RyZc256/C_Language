/*
 * @Description: 
 * @Author: Ryan Zhang
 * @Date: 2021-06-30 08:23:17
 * @LastEditTime: 2021-07-01 10:51:08
 * @LastEditors: Ryan Zhang
 */


#define OVERFLOW -2
#define MVnum 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char search_Name[10];
int MAX_GENERATION = 1;

/*
 日期结构
 */
typedef struct dt{
    int year;
    int month;
    int day;
}Date;

/*
 个人信息结构
 */
typedef struct per{
    int Generation;
    int Rank;
    char father[10];
    char Name[10];
    char Sex[4];
    Date birthday;
    char Address[50];
    char Marriage[8];
    char Alive[8];
    Date death;
}person;


// 二叉树结构
typedef struct CSLinklist{
    person Data;
    struct CSLinklist *firstchild, *nextsibling;
} CSLinklist, *CSTree;;

typedef struct Node{
    person *Data;
    int IsUse;
} Node;

// 全局变量
CSTree CSfind;
CSTree CSdel;
Node *List;
int today_brithday = 0;
char Root_node[10];
int csflag = 0;

// 统计家族人数
int NodeCount(CSTree T){
    int sum = 0;
    if(T==NULL) return 0;
    sum = NodeCount(T->firstchild) + NodeCount(T->nextsibling) + 1;
    return sum;
}

// 打印信息
void Print_information(CSTree T){
    printf("%s\t",T->Data.Name);
    printf("%s\t",T->Data.Sex);
    printf("出生于:%d-%d-%d\t",T->Data.birthday.year,T->Data.birthday.month,T->Data.birthday.day);
    printf("%s\t",T->Data.Address);
    printf("%s\t",T->Data.Marriage);
    printf("%s\t",T->Data.Alive);
    if(strcmp("去世", T->Data.Alive)==0){
        printf("去世于:%d-%d-%d\n",T->Data.death.year,T->Data.death.month,T->Data.death.day);
    }else
        printf("\n");
}

// 遍历树
void view_CSTree(CSTree T){
    if(T!=NULL)
    {
        List[csflag].Data = &T->Data;
        csflag++;
        if(T->firstchild||T->nextsibling)
        {
            view_CSTree(T->firstchild);
            view_CSTree(T->nextsibling);
        }
   }
}

// 查找族谱里的人
void find(CSTree T){
    if(T){
        if(strcmp(search_Name, T->Data.Name)==0)// 如果找到了相同的节点，直接赋值给ret
            CSfind = T;
        find(T->firstchild); //指向下一个子节点
        find(T->nextsibling); //指向下一个兄弟节点
    }
}

// 初始化族谱
void Init(CSTree T){
    // 初始化一个族谱长辈
    T->Data.Rank = 1;
    T->Data.Generation = 1;
    strcpy(T->Data.Name, "A");
    strcpy(Root_node, "A");
    strcpy(T->Data.Sex, "男");
    T->Data.birthday.year = 1921;
    T->Data.birthday.month = 9;
    T->Data.birthday.day = 1;
    strcpy(T->Data.Address, "厦门集美");
    strcpy(T->Data.Marriage, "已婚");
    strcpy(T->Data.Alive, "去世");
    T->Data.death.year = 1985;
    T->Data.death.month = 12;
    T->Data.death.day = 5;
    T->firstchild = NULL;
    T->nextsibling = NULL;
}

// 获取今日生日的人
void get_brithday(CSTree T,int mon,int day){
    if(T){
        if(T->Data.birthday.month == mon && T->Data.birthday.day == day){// 如果找到了相同的节点，直接赋值给ret
            Print_information(T);
            today_brithday = 1;
        }
        get_brithday(T->firstchild,mon,day);
        get_brithday(T->nextsibling,mon,day);
    }
    return ;
}

// 显示今日生日的人
void view_brithday(CSTree T){
    // 获取系统时间
    Date dt;
    time_t timep;
    struct tm *p;
    time(&timep);
    p=gmtime(&timep);
    dt.year = p->tm_year + 1900;
    dt.month = p->tm_mon + 1;
    dt.day = p->tm_mday;
    printf("今天是：%d-%d-%d\n",dt.year,dt.month,dt.day);
    get_brithday(T,dt.month,dt.day);
    if(today_brithday == 0){
        printf("并没有人生日\n");
    }
    getchar();
    getchar();
    return;
}

// 插入族谱
void InsertTree(CSTree T){
    int num = -1;
    CSTree Data; // 数据暂存结构提
    Data=(CSTree)malloc(sizeof(CSLinklist)); // 初始化族谱
    // 遍历右子树
    printf("请要添加孩子的父辈姓名:");
    scanf("%s",search_Name);
    find(T);
    
    if(CSfind == NULL){
        printf("查无此人.");
        getchar();
        return;
    }
    // 以下为接收数据代码
    Data->Data.Generation = CSfind->Data.Generation+1;
    strcpy(Data->Data.father, CSfind->Data.Name);
    // printf("请输入该子辈的排名:");
    // scanf("%d",&Data->Data.Rank);
    printf("请输入该子辈的姓名:");
    scanf("%s",Data->Data.Name);
    printf("请输入该子辈的性别:");
    scanf("%s",Data->Data.Sex);
    printf("请输入该子辈的出生日期（例如：2021-07-01）:");
    scanf("%d-%d-%d",&Data->Data.birthday.year,&Data->Data.birthday.month,&Data->Data.birthday.day);
    printf("请输入该子辈的联系地址:");
    scanf("%s",Data->Data.Address);
    printf("该子辈是否结婚（1是/0否）:");
    scanf("%d",&num);
    switch (num) {
        case 0:strcpy(Data->Data.Marriage, "未婚");break;
        case 1:strcpy(Data->Data.Marriage, "已婚");break;
    }
    printf("该子辈是否健在（1是/0否）:");
    scanf("%d",&num);
    switch (num) {
        case 0:strcpy(Data->Data.Alive, "去世");break;
        case 1:strcpy(Data->Data.Alive, "健在");break;
    }
    if(strcmp(Data->Data.Alive,"去世") == 0){
        printf("请输入该子辈的死亡日期（例如：2021-07-01）:");
        scanf("%d-%d-%d",&Data->Data.death.year,&Data->Data.death.month,&Data->Data.death.day);
    }
    if(Data->Data.Generation>MAX_GENERATION)
        MAX_GENERATION = Data->Data.Generation;
    // 如果儿子节点是空直接插入
    if(CSfind->firstchild==NULL){
        CSfind->firstchild = Data; // 插入子辈节点
    }else{
        Data->nextsibling = CSfind->firstchild;
        CSfind->firstchild = Data;
    }
    CSfind = NULL;
}

// 姓名找人
void search_person(CSTree T){
    scanf("%s",search_Name);
    if(strcmp(search_Name, T->Data.Name)==0)// 如果找到了相同的节点，直接赋值给ret
        Print_information(T);
    find(T->firstchild); //指向下一个子节点
    find(T->nextsibling); //指向下一个兄弟节点
}

void GETGEN(CSTree T){
    if(T==NULL) return;
    else GETGEN(T->firstchild);
    MAX_GENERATION = (T->Data.Generation > MAX_GENERATION ? T->Data.Generation : MAX_GENERATION);
    GETGEN(T->nextsibling);
}

CSTree parent(CSTree bt,CSTree p)
{
    CSTree lresult,rresult;
    if(!bt||bt==p)
    return NULL;
    if(bt->firstchild==p||bt->nextsibling==p)
    return bt;
    else
    {
        lresult=parent(bt->firstchild,p);
        rresult=parent(bt->nextsibling,p);
        return lresult?lresult:(rresult?rresult:NULL);
    }
}

CSTree searchname(CSTree bt,char na[])
{
    CSTree lresult,rresult;
    if(!bt)
    {
        return NULL;
    }
    if(strcmp(bt->Data.Name,na)==0)
    return bt;
    else
    {
        lresult=searchname(bt->firstchild,na);
        rresult=searchname(bt->nextsibling,na);
        return lresult?lresult:(rresult?rresult:NULL);
    }
}

void delete_person(CSTree T){

    char na[20];
    CSTree p,f;
    printf("请输入想删除的人的姓名，删除 之后他的后代也将一并删除！\n");
    scanf("%s",na);
    if (strcmp(na,Root_node)==0){
        printf("根结点不支持删除");
        return;
    }
    p=searchname(T,na);
    f=parent(T,p);
    if(f!=NULL)
    {
        if(f->firstchild==p)
        {
            f->firstchild=NULL;
            free(p);
        }
        if(f->nextsibling==p)
        {
            f->nextsibling=NULL;
            free(p);
        }
    }
    else
    {
        T=NULL;
    }
}

void change_person(CSTree T){
    int num,s;
    printf("请输入要修改信息的人的姓名");
    scanf("%s",search_Name);
    find(T);
    if(CSfind == NULL){
        printf("查无此人");
        return;
    }
    printf("请输入要修改的参数序号");
    printf("1.姓名");
    printf("2.性别");
    printf("3.出生日期");
    printf("4.地址");
    printf("5.婚否");
    printf("6.是否健在");
    
    scanf("%d",&num);
    switch (num) {
        case 1:
            printf("请输入新姓名：");
            scanf("%s",CSfind->Data.Name);
            break;
        case 2:
            printf("请输入性别：");
            scanf("%s",CSfind->Data.Sex);
            break;
        case 3:
            printf("请输入出生日期（2020-01-01）：");
            scanf("%d-%d-%d",&CSfind->Data.birthday.year,&CSfind->Data.birthday.month,&CSfind->Data.birthday.day);
            break;
        case 4:
            printf("请输入地址：");
            scanf("%s",CSfind->Data.Address);
            break;
        case 5:
            printf("是否已婚（1是/0否）：");
            scanf("%d",&s);
            switch (s) {
                case 0:strcpy(CSfind->Data.Marriage, "未婚");break;
                case 1:strcpy(CSfind->Data.Marriage, "已婚");break;
            }
            break;
        case 6:
            printf("是否健在（1是/0否）：");
            scanf("%d",&s);
            switch (s) {
                case 0:strcpy(CSfind->Data.Alive, "去世");break;
                case 1:strcpy(CSfind->Data.Alive, "健在");break;
            }
            if(strcmp(CSfind->Data.Alive,"去世") == 0){
                printf("请输入该子辈的死亡日期（例如：2021-07-01）:");
                scanf("%d-%d-%d",&CSfind->Data.death.year,&CSfind->Data.death.month,&CSfind->Data.death.day);
            }
            break;
        default: printf("输入有误，重新输入"); change_person(T); break;
    }
    CSfind = NULL;
}

void find_relationship(CSTree T){
    if(T){
        if(strcmp(search_Name, T->Data.Name)==0)// 如果找到了相同的节点，直接赋值给ret
            CSfind = T;
        find(T->firstchild); //指向下一个子节点
        find(T->nextsibling); //指向下一个兄弟节点
    }
}

void relationship(CSTree T){
    CSTree T1=NULL,T2=NULL;
    printf("请输入第一个人的姓名\n");
    scanf("%s",search_Name);
    find_relationship(T);
    T1 = CSfind;
    printf("请输入第二个人的姓名\n");
    scanf("%s",search_Name);
    find_relationship(T);
    T2 = CSfind;
    // 如果第一个人的辈数比第二个大
    if(T1!=NULL && T2!=NULL){
        // T1 是 T2的子辈
        if(T1->Data.Generation > T2->Data.Generation){
            printf("%s比%s大%d辈\n",T2->Data.Name,T1->Data.Name,T1->Data.Generation-T2->Data.Generation);
        }else if(T1->Data.Generation < T2->Data.Generation){
            printf("%s比%s大%d辈\n",T1->Data.Name,T2->Data.Name,T2->Data.Generation-T1->Data.Generation);
        }else{
            printf("%s与%s同辈\n",T2->Data.Name,T1->Data.Name);
        }
    }else{
        printf("查无此人两人关系\n");
        getchar();
        return;
    }
}

void print_view(){
    printf("\t欢迎进入家谱管理系统\n");
    printf("*************************************\n");
    printf("1.显示今天生日成员\t2.显示家谱\n");
    printf("3.显示第n代所有人的信息\t4.根据姓名查找成员\n");
    printf("5.为成员添加孩子\t6.删除成员\n");
    printf("7.修改成员信息\t8.确定两个人的关系\n");
    printf("9.退出程序\n");
    printf("*************************************\n");
}

int main(){
    int num;
    int gen;
    CSTree T;
    T=(CSTree)malloc(sizeof(CSLinklist)); // 初始化族谱
    Init(T);
    while (1) {
        system("clear");
        print_view();
        scanf("%d", &num);
        switch (num) {
            case 1: view_brithday(T); getchar(); break;
            case 2: 
                List = (Node *)malloc(MVnum*sizeof(Node *));
                for (int i = 0; i < MVnum; i++){
                    List[i].IsUse = 0;
                }
                MAX_GENERATION = csflag = 0;
                view_CSTree(T);
                GETGEN(T);
                printf("共%d代，%d人\n\n",MAX_GENERATION,NodeCount(T));
                for (int i = 0; i < MAX_GENERATION; i++){
                    printf("第%d代\n",i+1);
                    for (int j = 0; j < csflag; j++){
                        if(List[j].Data->Generation == i+1 && List[j].IsUse == 0){
                            printf("%s\t",List[j].Data->Name);
                            printf("%s\t",List[j].Data->Sex);
                            printf("%d-%d-%d\t",List[j].Data->birthday.year,List[j].Data->birthday.month,List[j].Data->birthday.day);
                            printf("%s\t",List[j].Data->Address);
                            printf("%s\t",List[j].Data->Marriage);
                            printf("%s\t",List[j].Data->Alive);
                            if(strcmp("去世", List[j].Data->Alive)==0){
                                printf("%d-%d-%d\n",List[j].Data->death.year,List[j].Data->death.month,List[j].Data->death.day);
                            }else
                                printf("\n");
                            List[j].IsUse = 1;
                        }   
                    }
                }
                getchar(); 
                getchar(); 
                break;
            case 3: 
                printf("请输入代数:");
                scanf("%d",&gen);
                for (int i = 0; i < MVnum; i++){
                    List[i].IsUse = 0;
                }
                csflag = 0;
                view_CSTree(T);
                printf("第%d代\n",gen);
                for (int i = 0; i < MAX_GENERATION; i++){
                    for (int j = 0; j < csflag; j++){
                        if(List[j].Data->Generation == gen && List[j].IsUse == 0){
                            printf("%s\t",List[j].Data->Name);
                            printf("%s\t",List[j].Data->Sex);
                            printf("%d-%d-%d\t",List[j].Data->birthday.year,List[j].Data->birthday.month,List[j].Data->birthday.day);
                            printf("%s\t",List[j].Data->Address);
                            printf("%s\t",List[j].Data->Marriage);
                            printf("%s\t",List[j].Data->Alive);
                            if(strcmp("去世", List[j].Data->Alive)==0){
                                printf("%d-%d-%d\n",List[j].Data->death.year,List[j].Data->death.month,List[j].Data->death.day);
                            }else
                                printf("\n");
                            List[j].IsUse = 1;
                        }   
                    }
                }
                getchar();
                getchar();
                break;
            case 4: search_person(T); getchar();break;;
            case 5: InsertTree(T); getchar(); break;
            case 6: delete_person(T); break;
            case 7: change_person(T); break;
            case 8: relationship(T); break;
            case 9: exit(OVERFLOW); break;
            default: printf("输入有误！重新输入。"); break;
        }
    }
    return 0;
}
