//
//  main.c
//  Program_4
//
//  Created by Ryan Zhang on 2021/6/30.
//

#define OVERFLOW -2
#define MVNum 100
#define INF (~(0x1<<31))
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct inf{
    int num;
    char Name[50];
    char Introduce[200];
}information;

typedef struct gp
{
    information *inf; // 顶点信息
    int arcs[MVNum][MVNum]; // 邻接矩阵
    int vexnum, arcnum; // 顶点数，边数
}Graph;

// 创建邻接矩阵
void CreateGraph(Graph *g){
    int i,j;
    g->vexnum = 11; // 顶点数
    g->arcnum = 16; // 边数
    g->inf=(information *)malloc(100*sizeof(information));
    if(!g->inf)exit(OVERFLOW);
    
    
    // 景点信息
    g->inf[0].num = 1;
    strcpy(g->inf[0].Name, "一期食堂");
    strcpy(g->inf[0].Introduce, "这是学生公寓一期最近的学生食堂");
    
    g->inf[1].num = 2;
    strcpy(g->inf[1].Name, "学生公寓一期");
    strcpy(g->inf[1].Introduce, "这是学生宿舍");
    
    g->inf[2].num = 3;
    strcpy(g->inf[2].Name, "明理园");
    strcpy(g->inf[2].Introduce, "这是厦门理工学院明理园");
    
    g->inf[3].num = 4;
    strcpy(g->inf[3].Name, "艺术与服装工程学院");
    strcpy(g->inf[3].Introduce, "这是艺术与服装工程学院办公楼");
    
    g->inf[4].num = 5;
    strcpy(g->inf[4].Name, "9号教学楼");
    strcpy(g->inf[4].Introduce, "这是9号教学楼");
    
    g->inf[5].num = 6;
    strcpy(g->inf[5].Name, "博学苑餐厅");
    strcpy(g->inf[5].Introduce, "这是博学苑餐厅");
    
    g->inf[6].num = 7;
    strcpy(g->inf[6].Name, "教工之家");
    strcpy(g->inf[6].Introduce, "这是教工之家");
    
    g->inf[7].num = 8;
    strcpy(g->inf[7].Name, "艺术会堂");
    strcpy(g->inf[7].Introduce, "这是艺术会堂");
    
    g->inf[8].num = 9;
    strcpy(g->inf[8].Name, "邮政所");
    strcpy(g->inf[8].Introduce, "这是邮政所");
    
    g->inf[9].num = 10;
    strcpy(g->inf[9].Name, "行政楼");
    strcpy(g->inf[9].Introduce, "这是学校办公楼");
    
    g->inf[10].num = 11;
    strcpy(g->inf[10].Name, "信息中心报告厅");
    strcpy(g->inf[10].Introduce, "这是信息中心报告厅");
    
    
    // 初始化矩阵
    for(i = 0;i < MVNum; i++){
        for(j = 0;j < MVNum;j++){
            g->arcs[i][j] = INF;
        }
    }
    
    g->arcs[0][1] = 80;
    g->arcs[1][0] = 80;
    
    g->arcs[0][2] = 100;
    g->arcs[2][0] = 100;
    
    g->arcs[1][4] = 150;
    g->arcs[4][1] = 150;
    
    g->arcs[2][3] = 30;
    g->arcs[3][2] = 30;
    
    g->arcs[2][5] = 75;
    g->arcs[5][2] = 75;
    
    g->arcs[2][6] = 50;
    g->arcs[6][2] = 50;
    
    g->arcs[3][4] = 50;
    g->arcs[4][3] = 50;
    
    g->arcs[3][6] = 70;
    g->arcs[6][3] = 70;
    
    g->arcs[4][6] = 100;
    g->arcs[6][4] = 100;
    
    g->arcs[5][6] = 30;
    g->arcs[6][5] = 30;
    
    g->arcs[5][7] = 20;
    g->arcs[7][5] = 20;
    
    g->arcs[6][7] = 25;
    g->arcs[7][6] = 25;
    
    g->arcs[6][9] = 200;
    g->arcs[9][6] = 200;
    
    g->arcs[7][9] = 180;
    g->arcs[9][7] = 180;
    
    g->arcs[9][8] = 60;
    g->arcs[8][7] = 60;
    
    g->arcs[9][10] = 85;
    g->arcs[10][9] = 85;
}

// 获取相连路径
void get_Route(Graph *g,int num, char name[50]){
    int flag = INF;
    // 如果num传入的是0 那就遍历查找位置
    if(num == 0){
        for (int i=0; i<g->vexnum; i++) {
            if(strcmp(name, g->inf[i].Name))
                flag = i;
        }
    }
    if(strcmp(name, "0") == 0){
        for (int i=0; i<g->vexnum; i++) {
            if(g->inf[i].num == num)
                flag = i;
        }
    }
    
    if(flag == INF){
        printf("找不到该景点");
        getchar();
        getchar();
        return;
    }else{
        // 打印
        printf("景点编号:%d\n",g->inf[flag].num);
        printf("景点名称:%s\n",g->inf[flag].Name);
        printf("景点介绍:%s\n\n",g->inf[flag].Introduce);
        printf("该景点路径信息：\n");
        for (int i=0; i<g->vexnum; i++) {
            for (int j=0; j<g->arcnum; j++) {
                // 如果是在num行 直接跳出继续下一行
                if(i != num-1)
                    continue;
                // 如果有数据不等于-99 就说明有路径，写入数组。
                if(g->arcs[i][j]!=INF)
                    printf("到景点%d--%s一期的距离为%d\n",g->inf[j].num,g->inf[j].Name,g->arcs[i][j]);
            }
        }
        getchar();
        getchar();
    }
}

// 列出所有景点
void List_all(Graph *g){
    int v = 0;
    printf("景点编号\t景点名称\t景点介绍\n");
    for (int i=0; i<g->vexnum; i++) {
        printf("%d\t%s\t%s\n",g->inf[i].num,g->inf[i].Name,g->inf[i].Introduce);
    }

    printf("道路信息：\n");
    int *Visited;
    Visited = (int *)malloc(g->vexnum*sizeof(int *));
    for (int i=0; i<g->vexnum; i++) {
        Visited[i] = -1;
    }
    for (int i=0; i<g->vexnum; i++) {
        for (int j=0; j<g->arcnum; j++) {
            if(Visited[j] == j)
                continue;;
            if(g->arcs[i][j]!=INF)
                printf("景点%d--%s 和 景点%d--%s 存在道路, 距离为 %d\n",g->inf[i].num,g->inf[i].Name,g->inf[j].num,g->inf[j].Name,g->arcs[i][j]);
        }
        Visited[v] = i;
        v++;
    }
}

// 查询信息
void spot_view(Graph *g){
    int num,input;
    char name[50];
    system("clear");
    printf("1：按照景点编号查询\n");
    printf("2：按照景点名称查询\n");
    printf("3：列出所有景点和道路信息\n");
    printf("4：返回上一级\n");
    printf("请输入您的操作(1-4):");
    scanf("%d",&num);
    switch (num) {
        case 1:
            printf("请输入景点编号: ");
            scanf("%d",&input);
            get_Route(g, input, "0");
            break;
        case 2:
            printf("请输入景点名称: ");
            scanf("%s",name);
            get_Route(g, 0, name);
            break;
        case 3:
            List_all(g);
            break;;
        case 4: return;
        default: printf("输入有误，重新输入"); break;
    }
}

// 编号修改信息
void change_information_id(Graph *g){
    int num;
    char name[50];
    char Introduce[200];
    printf("请输入景点编号:");
    scanf("%d",&num);
    for (int i = 0; i < g->vexnum; i++){
        if(num == g->inf[i].num){
            printf("请输入该景点修改后的名称和介绍\n");
            printf("名称：");
            scanf("%s",name);
            printf("介绍：");
            scanf("%s",Introduce);
            strcpy(g->inf[i].Name,name);
            strcpy(g->inf[i].Introduce,Introduce);
            printf("修改成功");
            getchar();
            getchar();
        }
    }
}

// 名称修改信息
void change_information_name(Graph *g){
    char sname[50];
    char name[50];
    char Introduce[200];
    printf("请输入景点名称:");
    scanf("%s",sname);
    for (int i = 0; i < g->vexnum; i++){
        if(strcmp(sname,g->inf[i].Name) == 0){
            printf("请输入该景点修改后的名称和介绍\n");
            printf("名称：");
            scanf("%s",name);
            printf("介绍：");
            scanf("%s",Introduce);
            strcpy(g->inf[i].Name,name);
            strcpy(g->inf[i].Introduce,Introduce);
            printf("修改成功");
            getchar();
            getchar();
        }
    }
}

// 修改路径
void change_route(Graph *g){
    int x,y,d;
    printf("请输入待修改路径信息,如原无路径则新增。\n");
    printf("格式形如(1-2,60),表示编号 1 2，路径长度60：");
    scanf("%d-%d,%d",&x,&y,&d);
    if(g->arcs[x][y]==INF)
        g->arcnum++;
    g->arcs[x][y] = d;
    g->arcs[y][x] = d;
    printf("修改成功");
    getchar();
    getchar();
}

// 根据编号删点
void del_inf_id(Graph *g){
    int num,flag=INF;
    printf("请输入景点编号:\n");
    scanf("%d",&num);
    // 找点
    for (int i = 0; i < g->vexnum; i++)
        if(g->inf[i].num == num)
            flag = i;

    if(flag == INF){
        printf("查无此点");
        getchar();
        getchar();
        return;
    }

    // 清空点的矩阵信息
    for (int i = 0; i < g->vexnum; i++){
        if(g->arcs[flag][i]!=INF){
            g->arcs[flag][i] = INF;
            g->arcs[i][flag] = INF;
            g->arcnum--;
        }
    }

    // 重建矩阵
    // 右移矩阵
    for (int i = flag; i < g->vexnum-1; i++)
        for (int j = flag; j < g->vexnum-1; j++)
            g->arcs[i][j] = g->arcs[i][j+1];
    // 上移矩阵
    for (int i = flag; i < g->vexnum-1; i++)
        for (int j = flag; j < g->vexnum-1; j++)
            g->arcs[i][j] = g->arcs[i+1][j];   
                 

    // 重建信息
    for (int i = flag; i < g->vexnum-1; i++){
        g->inf[i] = g->inf[i+1];
    }
    
    
    g->vexnum--;
    printf("删除景点完成");
    getchar();

}

// 根据名称删点
void del_inf_name(Graph *g){
    char sname[50];
    int flag=INF;
    printf("请输入景点名称:\n");
    scanf("%s",sname);
    // 找点
    for (int i = 0; i < g->vexnum; i++)
        if(strcmp(g->inf[i].Name,sname)==0)
            flag = i;
    
    if(flag == INF){
        printf("查无此点");
        getchar();
        getchar();
        return;
    }

     // 清空点的矩阵信息
    for (int i = 0; i < g->vexnum; i++){
        if(g->arcs[flag][i]!=INF){
            g->arcs[flag][i] = INF;
            g->arcs[i][flag] = INF;
            g->arcnum--;
        }
    }

    // 重建矩阵
    // 右移矩阵
    for (int i = flag; i < g->vexnum-1; i++)
        for (int j = flag; j < g->vexnum-1; j++)
            g->arcs[i][j] = g->arcs[i][j+1];
    // 上移矩阵
    for (int i = flag; i < g->vexnum-1; i++)
        for (int j = flag; j < g->vexnum-1; j++)
            g->arcs[i][j] = g->arcs[i+1][j];   
                 


    // 重建图
    for (int i = flag; i < g->vexnum-1; i++){
        g->inf[i] = g->inf[i+1];
    }
    g->vexnum--;
    printf("删除景点完成");
    getchar();
    getchar();

}

// 全局变量
int v[MVNum];
int visited[MVNum];
int a=0;

// 列出路径
void path(Graph *G,int i,int j,int k){
/*确定路径上第k+1个顶点的序号*/
    int s;
    if(v[k]==j){/*找到一条路径*/
        a++;/*路径的条数值加1*/
        printf("第%d条:",a);
        for(s=1;s<k;s++)/*输出一条路径*/
        printf("%s->",G->inf[v[s]].Name);
        printf("%s\n",G->inf[v[s]].Name);   
    }
    s=1;
    while(s<=G->vexnum){
        if(s!=i){/*保证找到的是简单路径*/
            if(G->arcs[v[k]][s]!=INF && visited[s]==0){
                /*当vk与vs之间有边存在且vs未被访问过*/
                visited[s]=1;/*置访问标志位为1,即已访问的*/
                v[k+1]=s;/*将顶点s加入到v数组中*/
                path(G,i,j,k+1);/*递归调用之*/
                visited[s]=0;/*重置访问标志位为0，即未访问的，以便该顶点能被重新使用*/
            }
        }
    s++;
    }
}

// 初始化列出路径
void disppath(Graph *G,int i,int j){
    int k;
    v[1]=i;
    visited[i]=0;/*初始化各顶点的访问标志位，即都为未访问过的*/
    a=0;/*初始化路径的条数*/
    path(G,i,j,1);/*通过调用path函数，找到从vi到vj的所有路径并输出*/
}

// 列出所有路径输入提示
void get_route_point(Graph *g){
    int x,y,a,b;
    x = y = -1;
    printf("请输入起始景点编号和终点景点编号，空格隔开：\n");
    scanf("%d %d",&a,&b);
    for (int i = 0; i < g->vexnum; i++){
        if(g->inf[i].num == a)
            x = i;
        if(g->inf[i].num == b)
            y = i;
    }
    if(x == -1 || y == -1){
        printf("你输入的源点景点或许不存在!\n");
        return;
    }
    printf("从%s到%s的所有游览路径有:\n",g->inf[x].Name,g->inf[y].Name);/*输出出发景点和目地景点的名称*/
    disppath(g,x,y);
}

// 最短路径算法
void dijkstra(Graph *G, int vs){
    int i,j,k;
    int min;
    int tmp;
    int flag[MVNum];      // flag[i]=1表示"顶点vs"到"顶点i"的最短路径已成功获取。
    int prev[MVNum] = {0};
    int dist[MVNum] = {0};
    // 初始化
    for (i = 0; i < G->vexnum; i++){
        flag[i] = 0;              // 顶点i的最短路径还没获取到。
        prev[i] = 0;              // 顶点i的前驱顶点为0。
        dist[i] = G->arcs[vs][i];// 顶点i的最短路径为"顶点vs"到"顶点i"的权。
    }

    // 对"顶点vs"自身进行初始化
    flag[vs] = 1;
    dist[vs] = 0;

    // 遍历G.vexnum-1次；每次找出一个顶点的最短路径。
    for (i = 1; i < G->vexnum; i++){
        // 寻找当前最小的路径；
        // 即，在未获取最短路径的顶点中，找到离vs最近的顶点(k)。
        min = INF;
        for (j = 0; j < G->vexnum; j++){
            if (flag[j]==0 && dist[j]<min){
                min = dist[j];
                k = j;
            }
        }
        // 标记"顶点k"为已经获取到最短路径
        flag[k] = 1;

        // 修正当前最短路径和前驱顶点
        // 即，当已经"顶点k的最短路径"之后，更新"未获取最短路径的顶点的最短路径和前驱顶点"。
        for (j = 0; j < G->vexnum; j++){
            tmp = (G->arcs[k][j] == INF ? INF : (min + G->arcs[k][j])); // 防止溢出
            if (flag[j] == 0 && (tmp  < dist[j]) ){
                dist[j] = tmp;
                prev[j] = k;
            }
        }
    }

    // 打印dijkstra最短路径的结果
    // printf("dijkstra(%c): \n", G->inf[vs]);
    for (i = 0; i < G->vexnum; i++)
        if(i!=vs){
            printf("%s->%s\n",G->inf[vs].Name, G->inf[i].Name);
            printf("路径:%d\n",dist[i]);    
        }
}

// 求最短路径
void get_all_short_route(Graph *g){
    int num,flag = -1;
    printf("请输入起始景点编号：\n");
    scanf("%d",&num);
    // 找点的位置
    for (int i = 0; i < g->vexnum; i++)
        if(num == g->inf[i].num)
            flag = i;
    if(flag == -1){
        printf("该点不存在");
        getchar();
        return;
    }
    printf("%s到其他各景点的最短距离如下：\n",g->inf[flag].Name);
    printf("\n");
    dijkstra(g,flag);
}

// 输出路径的最短路径算法
void dijkstra_ptp(Graph *G,int vs,int y){
    int i,j,k;
    int min;
    int tmp;
    int flag[MVNum];      // flag[i]=1表示"顶点vs"到"顶点i"的最短路径已成功获取。
    int prev[MVNum] = {0};
    int dist[MVNum] = {0};
    // 初始化
    for (i = 0; i < G->vexnum; i++){
        flag[i] = 0;              // 顶点i的最短路径还没获取到。
        prev[i] = 0;              // 顶点i的前驱顶点为0。
        dist[i] = G->arcs[vs][i];// 顶点i的最短路径为"顶点vs"到"顶点i"的权。
    }

    // 对"顶点vs"自身进行初始化
    flag[vs] = 1;
    dist[vs] = 0;

    // 遍历G.vexnum-1次；每次找出一个顶点的最短路径。
    for (i = 1; i < G->vexnum; i++){
        // 寻找当前最小的路径；
        // 即，在未获取最短路径的顶点中，找到离vs最近的顶点(k)。
        min = INF;
        for (j = 0; j < G->vexnum; j++){
            if (flag[j]==0 && dist[j]<min){
                min = dist[j];
                k = j;
            }
        }
        // 标记"顶点k"为已经获取到最短路径
        flag[k] = 1;

        // 修正当前最短路径和前驱顶点
        // 即，当已经"顶点k的最短路径"之后，更新"未获取最短路径的顶点的最短路径和前驱顶点"。
        for (j = 0; j < G->vexnum; j++){
            tmp = (G->arcs[k][j] == INF ? INF : (min + G->arcs[k][j])); // 防止溢出
            if (flag[j] == 0 && (tmp  < dist[j]) ){
                dist[j] = tmp;
                prev[j] = k;
            }
        }
    }
    
    
    printf("景点%s到%s的路径是：", G->inf[vs].Name, G->inf[y].Name);
    j = y;
    k = 0;
    //临时存储，方面倒序输出
    int cache[MVNum];
    while (j!=vs) {
        cache[k] = j;
        k = k + 1;
        j = prev[j];
    }
    cache[k] = j;
    for (k; k > 0; --k) {
        printf("%s-->",G->inf[cache[k]].Name);
    }
    printf("%s",G->inf[cache[k]].Name);
    printf("\n");
    printf("距离为：%d\n",dist[y]);
	
}

// 点对点最短路径
void ptp(Graph *g){
    int a,b,x,y;
    x = y = INF;
    printf("请输入起始景点编号和终点景点编号，空格隔开：\n");
    scanf("%d %d",&a,&b);
    // 判断两个点存不存在
    for (int i = 0; i < g->vexnum; i++){
        if(g->inf[i].num == a)
            x = i;
        if(g->inf[i].num == b)
            y = i;
    }
    if(x==INF || y==INF){
        printf("输入的景点编号不存在");
        getchar();
        getchar();
        return;
    }
    dijkstra_ptp(g,x,y);
}

// 删除信息
void del_view(Graph *g){
    int num,input;
    int x,y;
    char name[50];
    system("clear");
    printf("1：输入景点编号删除景点信息\n");
    printf("2：输入景点名称删除景点信息\n");
    printf("3：删除道路信息\n");
    printf("4：返回上一级\n");
    printf("请输入您的操作(1-4):");
    scanf("%d",&num);
    switch (num) {
        case 1:
            del_inf_id(g);
            break;
        case 2:
            del_inf_name(g);
            break;
        case 3:
            printf("请输入待删除路径两顶点编号，空格隔开。\n");
            scanf("%d %d",&x,&y);
            if(g->arcs[x][y]!=INF){
                g->arcs[x][y]=INF;
                g->arcs[y][x]=INF;
                g->arcnum--;
            }else
                printf("不存在此道路");
            break;;
        case 4: return;
        default: printf("输入有误，重新输入"); break;
    }
          
          
          
}

// 添加信息菜单
void add_inf(Graph *g){
    int num;
    printf("请输入待新增景点信息：\n");
    printf("景点编号:");
    scanf("%d",&num);
    for (int i = 0; i < g->vexnum; i++){
        if(g->inf[i].num == num){
            printf("该编号已存在\n");
            return;
        }
    }
    g->inf[g->vexnum].num = num;
    printf("景点名称:");
    scanf("%s",g->inf[g->vexnum].Name);
    printf("景点介绍:");
    scanf("%s",g->inf[g->vexnum].Introduce);
    g->vexnum++;
    printf("添加成功");
    getchar();
    getchar();


}

// 修改信息菜单
void change_view(Graph *g){
    int num,input;
    char name[50];
    system("clear");
    printf("1：输入景点编号修改景点信息\n");
    printf("2：输入景点名称修改景点信息\n");
    printf("3：修改路径信息，如原无路径则新增\n");
    printf("4：返回上一级\n");
    printf("请输入您的操作(1-4):");
    scanf("%d",&num);
    switch (num) {
        case 1:
            change_information_id(g);
            break;
        case 2:
            change_information_name(g);
            break;
        case 3:
            change_route(g);
            break;;
        case 4: return;
        default: printf("输入有误，重新输入"); break;
    }    
}

// 主菜单 
void print_view(){
    printf("\t欢迎使用厦门理工学院导游咨询系统\n");
    printf("1.景点信息查询\n");
    printf("2.新增景点信息\n");
    printf("3.修改景点和道路信息\n");
    printf("4.删除景点和道路信息\n");
    printf("5.任意两个景点的路径查询\n");
    printf("6.求一个景点到所有景点的最短路径\n");
    printf("7.求任意的两个景点之间的最短路径\n");
    printf("8.退出系统\n");
}

// 主函数
int main(){
    int num;
    Graph G;
    CreateGraph(&G);
    while(1){
        system("clear");
        print_view();
        scanf("%d", &num);
        switch (num) {
            case 1: spot_view(&G); break;
            case 2: add_inf(&G); break;
            case 3: change_view(&G); break;
            case 4: del_view(&G); break;
            case 5: get_route_point(&G); break;
            case 6: get_all_short_route(&G); break;
            case 7: ptp(&G); break;
            case 8: exit(OVERFLOW); break;
            default: printf("输入有误，重新输入"); break;
        }
    }
    return 0;
}
                    
