#include<stdio.h>

struct Node{
    char c[10];
    char name[20];
    int mark1;
    int mark2;
    int mark3;
    int sum;
};
int main(void){
    int n;
    scanf("%d", &n);
    struct Node stu[n];
    int m = 0, t;

    for(int i = 0; i < n; i++){
	    scanf("%s %s %d %d %d", &stu[i].c, &stu[i].name, &stu[i].mark1, &stu[i].mark2, &stu[i].mark3);
	    stu[i].sum = stu[i].mark1 + stu[i].mark2 + stu[i].mark3;
    }

    for(int i = 0; i < n; i++){
	    if(stu[i].sum > m){
		    m = stu[i].sum;
		    t = i;
	    }
    }
    printf("%s %s %d", stu[t].name, stu[t].c, m);
    return 0;
}