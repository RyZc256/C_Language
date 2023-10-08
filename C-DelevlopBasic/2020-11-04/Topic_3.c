#include <stdio.h>

int main(){
	int a;
	scanf("%d",&a);
	switch(a){
		case 3:
		case 4:
		case 5:printf("请输入月份：%d月是春季。",a);break;
		case 6:
		case 7:
		case 8:printf("请输入月份：%d月是夏季。",a);break;
		case 9:
		case 10:
		case 11:printf("请输入月份：%d月是秋季。",a);break;
		case 12:
		case 1:
		case 2:printf("请输入月份：%d月是冬季。",a);break;
        case 0:printf("请输入月份：%d月不存在。",a);break;
	}

    return 0;
}