/*
 * @Description:
 * @Author: Zhang Rongyu
 * @Date: 2021-06-28 09:36:10
 * @LastEditTime: 2021-06-29 11:46:30
 * @LastEditors: Zhang Rongyu
 */
#define LIST_INIT_SIZE 50 //最大链表长度
#define OVERFLOW -2
#define N 5 // 科目数
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 日期结构体
typedef struct bir
{
    int year;
    int month;
    int day;
}brithday;

// 学生结构体
typedef struct stu
{
    char Name[20];
    char Sex[5];
    brithday date;
    int score[N];
    char Telephone[15];
    char Address[100];
    char Id_number[20];
    int sum;
}student;

// 成绩排名结构体
typedef struct
{
   int id;
   int score;

}s_score;

// 线性表结构
typedef struct
{
    student *List;
    int length;
    int listsize;//当前分配的存储容量，以elemType为单位
}Studentlist;

/*
 初始化链表
 */
void Intlist(Studentlist *L){
    L->List=(student *)malloc(LIST_INIT_SIZE*sizeof(student));
    if(!L->List)exit(OVERFLOW);//overflow
    L->length=0;//初始表为空表
    L->listsize=LIST_INIT_SIZE;//初始表的存储容量，为LIST_INIT_SIZE个elemType单位
    for (int i=0; i<LIST_INIT_SIZE; i++) {
        L->List[i].sum = 0;
    }
    return;
}

/*
 插入信息
 */
void insert_information(Studentlist *L){
    student e;
    int num;
    int i;
    while(1){
        printf("录入学生信息，请选择：1:输入数据  0：返回\n");
        scanf("%d",&num);
        if(num == 0) return;
        else if(num == 1){
            printf("学号：");
            scanf("%s",e.Id_number);
            printf("姓名：");
            scanf("%s",e.Name);
            printf("性别：");
            scanf("%s",e.Sex);
            printf("出生日期(如2020-01-01)：");
            scanf("%d-%d-%d",&e.date.year,&e.date.month,&e.date.day);
            printf("电话：");
            scanf("%s",e.Telephone);
            printf("地址：");
            scanf("%s",e.Address);
            for(i=0;i<N;i++) //初始成绩均为0
                e.score[i]=0;
            if(L->length>=L->listsize)  //空间不足
                return;
            L->List[L->length]=e;
            L->length++;  //表长度+1
        }else{
            printf("您输入有误，重新选择!\n");
        }
    }
}

/*
 删除信息
 */
void delete_information(Studentlist *L){
    int num, flag;
    char input[10];
    while (1) {
        flag = -1;
        printf("1:输入学号删除记录   2:输入姓名删除记录  0：返回\n");
        scanf("%d",&num);
        switch (num) {
            case 1: // 学号删记录
                scanf("%s", input);
                // 遍历链表寻找记录
                for (int i=0; i<L->length; i++) {
                    if(strcmp(L->List[i].Id_number, input)==0){
                        flag = i;
                    }
                }
                // 删除记录
                if(flag == -1){
                    printf("查找不到此记录\n");
                }else{
                    for (int i=flag; i<L->length; i++) {
                        L->List[i] = L->List[i+1];
                    }
                    L->length--;
                }
                break;
            case 2:  // 姓名删记录
                scanf("%s", input);
                // 遍历链表寻找记录
                for (int i=0; i<LIST_INIT_SIZE; i++) {
                    if(strcmp(L->List[i].Name, input)==0){
                        flag = i;
                    }
                }
                // 删除记录
                if(flag == -1){
                    printf("查找不到此记录\n");
                }else{
                    for (int i=flag; i<L->length; i++) {
                        L->List[i] = L->List[i+1];
                    }
                    L->length--;
                }
                break;
            case 0: return;
            default: printf("您输入有误，重新选择!\n"); break;
        }
    }
}


/*
 打印记录
 */
void print_record(Studentlist *L, int i){
    printf("%s",L->List[i].Id_number);
    printf("\t");
    printf("%s",L->List[i].Name);
    printf("\t");
    printf("%s",L->List[i].Sex);
    printf("\t");
    printf("%d-%d-%d",L->List[i].date.year,L->List[i].date.month,L->List[i].date.day);
    printf("\t");
    printf("%s",L->List[i].Telephone);
    printf("\t");
    printf("%s",L->List[i].Address);
    printf("\n");
}

/*
 查询信息
 */
void query_information(Studentlist *L){
    int num,flag;
    char input[10];
    
    while (1) {
        flag = -1;
        printf("1:输入学号查询   2:输入姓名查询  0：返回\n");
        scanf("%d",&num);
        switch (num) {
            case 1:
                scanf("%s",input);
                for (int i=0; i<L->length; i++) {
                    if(strcmp(L->List[i].Id_number, input) == 0)
                        flag = i;
                }
                if(flag == -1)
                    printf("查找不到此记录\n");
                else{
                    printf("学号\t姓名\t性别\t生日\t电话\t地址\n");
                    print_record(L,flag);
                }
                getchar();
                getchar();
                break;
            case 2:
                scanf("%s",input);
                for (int i=0; i<L->length; i++) {
                    if(strcmp(L->List[i].Name, input) == 0)
                        flag = i;
                }
                if(flag == -1)
                    printf("查找不到此记录\n");
                else{
                    printf("学号\t姓名\t性别\t生日\t电话\t地址\n");
                    print_record(L,flag);
                }
                getchar();
                getchar();
                break;
            case 0: return;
            default: printf("您输入有误，重新选择!\n"); getchar(); getchar(); break;
        }
    }
}

/*
 浏览信息
 */
void view_information(Studentlist *L){
    printf("学号\t姓名\t性别\t生日\t电话\t地址\n");
    for (int i=0; i<L->length; i++) {
        print_record(L,i);
    }
    // windows
    // system("pause");
    getchar();
    getchar();
    return;
}

/*
 修改信息
 */
void change_information(Studentlist *L){
    int num, flag;
    char input[10];
    while(1){
        flag = -1;
        printf("1:输入学号修改   2:输入姓名修改  0：返回\n");
        scanf("%d",&num);
        scanf("%s",input);
        if (num == 1) {
            for (int i=0; i<L->length; i++) {
                if(strcmp(L->List[i].Id_number,input)==0)
                    flag = i;
            }
            if(flag!=-1){
                printf("请输入要修改的选项（学号1，姓名2，性别3，生日4，电话5，地址6）：");
                scanf("%d", &num);
                switch (num) {
                    case 1: scanf("%s",L->List[flag].Id_number); break;
                    case 2: scanf("%s",L->List[flag].Name); break;
                    case 3: scanf("%s",L->List[flag].Sex); break;;
                    case 4: scanf("%d-%d-%d",&L->List[flag].date.year, &L->List[flag].date.month, &L->List[flag].date.day); break;
                    case 5: scanf("%s",L->List[flag].Telephone); break;
                    case 6: scanf("%s",L->List[flag].Address); break;
                    default: printf("您输入有误，重新选择\n"); break;
                }
            }else
                printf("查找不到此记录\n");
            
        }
        else if(num == 2){
            for (int i=0; i<L->length; i++) {
                if(strcmp(L->List[i].Name,input)==0)
                    flag = i;
            }
            if(flag!=-1){
                printf("请输入要修改的选项（学号1，姓名2，性别3，生日4，电话5，地址6）：");
                scanf("%d", &num);
                switch (num) {
                    case 1: scanf("%s",L->List[flag].Id_number); break;
                    case 2: scanf("%s",L->List[flag].Name); break;
                    case 3: scanf("%s",L->List[flag].Sex); break;;
                    case 4: scanf("%d-%d-%d",&L->List[flag].date.year, &L->List[flag].date.month, &L->List[flag].date.day); break;
                    case 5: scanf("%s",L->List[flag].Telephone); break;
                    case 6: scanf("%s",L->List[flag].Address); break;
                    default: printf("您输入有误，重新选择\n"); break;
                }
            }else
                printf("查找不到此记录\n");
        }
        else if(num == 0)
            return;
        else
            printf("您输入有误，重新选择\n");
        
    }
}


/*
 打印成绩
 */
void print_score(Studentlist *L, int i){
    printf("%s",L->List[i].Id_number);
    printf("\t");
    printf("%s",L->List[i].Name);
    printf("\t");
    printf("%d",L->List[i].score[0]);
    printf("\t");
    printf("%d",L->List[i].score[1]);
    printf("\t");
    printf("%d",L->List[i].score[2]);
    printf("\t");
    printf("%d",L->List[i].score[3]);
    printf("\t");
    printf("%d",L->List[i].score[4]);
    printf("\n");
}

/*
 添加成绩
 */
void add_score(Studentlist *L){
    int flag = -1;
    char input[10];
    printf("请输入要录入成绩的学生学号：");
    scanf("%s",input);
    for(int i=0; i<L->length; i++){
        if(strcmp(L->List[i].Id_number, input) == 0){
            printf("请输入5门成绩：");
            for (int j=0; j<N; j++) {
                scanf("%d",&L->List[i].score[j]);
            }
            flag = 1;
            break;
        }
    }
    for (int i=0; i<L->length; i++) {
        L->List[i].sum = 0;
        for (int j=0; j<N; j++) {
            L->List[i].sum += L->List[i].score[j];
        }
    }
    if(flag == -1){
        printf("查找不到此学号");
        getchar();
        getchar();
    }
    else{
        printf("输入成功！");
        getchar();
        getchar();
    }
    return;
}


/*
 浏览成绩
 */
void view_score(Studentlist *L){
    printf("学号\t姓名\t成绩1\t成绩2\t成绩3\t成绩4\t成绩5\n");
    for (int i=0; i<L->length; i++) {
        print_score(L, i);
    }
    getchar();
    getchar();
    return;
}

/*
 查找成绩
 */
void query_score(Studentlist *L){
    int num,flag;
    char input[10];
    flag = -1;
    printf("3:输入学号查询   4:输入姓名查询  0：返回");
    scanf("%d",&num);
    switch (num) {
        case 3:
            scanf("%s",input);
            for (int i=0; i<L->length; i++) {
                if(strcmp(L->List[i].Id_number, input) == 0)
                    flag = i;
            }
            if(flag == -1)
                printf("查找不到此学号");
            else{
                printf("学号\t姓名\t成绩1\t成绩2\t成绩3\t成绩4\t成绩5\n");
                print_score(L, flag);
            }
            break;
        case 4:
            scanf("%s",input);
            for (int i=0; i<L->length; i++) {
                if(strcmp(L->List[i].Name, input) == 0)
                    flag = i;
            }
            if(flag == -1)
                printf("查找不到此姓名");
            else{
                printf("学号\t姓名\t成绩1\t成绩2\t成绩3\t成绩4\t成绩5\n");
                print_score(L, flag);
            }
            break;
        case 0: return;
        default: printf("您输入有误，重新选择\n"); query_score(L); break;
    }
    getchar();
    getchar();
    return;
}

// 改变成绩
void change_score(Studentlist *L){
    int num,flag,s;
    char input[10];
    while(1){
        flag = -1;
        printf("3:输入学号修改   4:输入姓名修改  0：返回\n");
        scanf("%d",&num);
        switch (num) {
            case 3:
                scanf("%s",input);
                for (int i=0; i<L->length; i++) {
                    if(strcmp(L->List[i].Id_number, input) == 0){
                        printf("请输入要修改的分数序号(序号从1开始)：");
                        scanf("%d",&num);
                        printf("原成绩为%d,请输入新的成绩：",L->List[i].score[num]);
                        scanf("%d",&L->List[i].score[num]);
                        flag = 1;
                    }
                }
                if(flag == -1)
                    printf("没找到\n");
                else
                    printf("修改成功，记录已经更新。\n");
                break;
            case 4:
                scanf("%s",input);
                for (int i=0; i<L->length; i++) {
                    if(strcmp(L->List[i].Name, input) == 0){
                        printf("请输入要修改的分数序号(序号从1开始)：");
                        scanf("%d",&s);
                        printf("原成绩为%d,请输入新的成绩：",L->List[i].score[s]);
                        scanf("%d",&L->List[i].score[s]);
                        flag = 1;
                    }
                }
                if(flag == -1)
                    printf("没找到\n");
                else{
                    for (int i=0; i<L->length; i++) {
                        L->List[i].sum = 0;
                        for (int j=0; j<N; j++) {
                            L->List[i].sum += L->List[i].score[j];
                        }
                    }
                    printf("修改成功，记录已经更新。\n");
                }
                break;
            case 0: return;
            default: printf("您输入有误，重新选择\n"); break;
        }
    }
}


/*
 成绩排序
 */
void score_sort(Studentlist *L){
    int num,km;
    int sot[LIST_INIT_SIZE];
    int tem;
    while(1){
        printf("1:根据总分排序   2:根据某门课程排序  0：返回、\n");
        scanf("%d",&num);
        // 初始化&计算总分
        for (int i=0; i<L->length; i++) {
            sot[i] = i;
        }
        switch (num) {
            case 1:
                // 冒泡排序
                for (int i=0; i<L->length-1; i++) {
                    for (int j=0; j<L->length-1-i; j++) {
                        if(L->List[j+1].sum > L->List[j].sum){
                            tem = sot[j];
                            sot[j] = sot[j+1];
                            sot[j+1] = tem;
                        }
                    }
                }
                printf("学号\t姓名\t总分\n");
                for (int i=0; i<L->length; i++) {
                    printf("%s",L->List[sot[i]].Id_number);
                    printf("\t");
                    printf("%s",L->List[sot[i]].Name);
                    printf("\t");
                    printf("%d\n",L->List[sot[i]].sum);
                }
                getchar();
                break;
            case 2:
                printf("请输入排序科目序号（从1开始）：");
                scanf("%d", &km);
                for (int i=0; i<L->length; i++) {
                    sot[i] = i;
                }
                for (int i=0; i<L->length-1; i++) {
                    for (int j=0; j<L->length-1-i; j++) {
                        if(L->List[j+1].score[km-1] > L->List[j].score[km-1]){
                            tem = sot[j];
                            sot[j] = sot[j+1];
                            sot[j+1] = tem;
                        }
                    }
                }
                break;
            case 0: return;
            default:
                printf("您输入有误，重新选择\n");
                break;
        }
        printf("学号\t姓名\t科目1\t科目2\t科目3\t科目4\t科目5\t总分\n");
        for (int i=0; i<L->length; i++) {
            printf("%s",L->List[sot[i]].Id_number);
            printf("\t");
            printf("%s",L->List[sot[i]].Name);
            printf("\t");
            printf("%d\t%d\t%d\t%d\t%d\t%d\n",
                   L->List[sot[i]].score[0],
                   L->List[sot[i]].score[1],
                   L->List[sot[i]].score[2],
                   L->List[sot[i]].score[3],
                   L->List[sot[i]].score[4],
                   L->List[sot[i]].sum);
        }
    }
}




//主菜单
void Menu_view (){
    printf("**********欢迎进入学校管理系统**********\n");
    printf("1.基本信息管理\n");
    printf("2.成绩管理\n");
    printf("3.退出\n");
    printf("*************欢迎使用*************\n");
    return;
}

// 信息管理界面函数
void information(Studentlist *L){
    int input;
    while (1) {
        // 菜单显示
        system("clear");
        printf("**********学生基本信息管理**********\n");
        printf("1.添加学生信息\t2.浏览学生信息\n");
        printf("3.查询学生信息\t4.修改学生信息\n");
        printf("5.删除学生信息\t6.退出\n");
        printf("************谢谢使用************\n");
        
        scanf("%d",&input); // 接收用户输入
        switch (input) {
            case 1: insert_information(L); break;
            case 2: view_information(L); break;
            case 3: query_information(L); break;
            case 4: change_information(L); break;
            case 5: delete_information(L); break;
            case 6: return;
        }
    }
}

// 成绩管理界面函数
void Pf(Studentlist *L){
    int input;
    // 菜单显示
    while (1) {
        system("clear");
        printf("**********学生成绩管理**********\n");
        printf("1.添加成绩信息\t2.浏览成绩信息\n");
        printf("3.查询成绩信息\t4.修改成绩信息\n");
        printf("5.排序成绩信息\t6.退出\n");
        printf("************谢谢使用************\n");
        
        scanf("%d",&input);// 接收用户输入

        switch (input) {
            case 1: add_score(L); break;
            case 2: view_score(L); break;
            case 3: query_score(L); break;
            case 4: change_score(L); break;
            case 5: score_sort(L); break;
            case 6: return;
        }
    }
    
}

// 主函数
int main() {
    int input;
    Studentlist L;
    Intlist(&L);
    while(1){
        system("clear");
        Menu_view();
        scanf("%d",&input); // 接收用户输入
        switch (input) {
            case 1: information(&L); break;
            case 2: Pf(&L); break;
            case 3: exit(OVERFLOW); break;
        }
    }
    return 0;
}
