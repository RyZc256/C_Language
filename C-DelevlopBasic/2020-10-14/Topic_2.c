#include <stdio.h>
int main(){
	int a,b,c,min;
	printf("请输入三个整数。\n");
	scanf("%d %d %d",&a,&b,&c);
	if(a<b){
		if(c<a)min = c;
		else min = a;
	}else{
		if(c<b)min = c;
		else min = b;
	}
	printf("其中的最小值为%d。",min);
}