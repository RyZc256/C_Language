#include <stdio.h>
int main(){
	int a,b,c,d,e;
	float avg;
	scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
	avg = (b+c+d)/3.0;
	printf("%.2f",avg);
	return 0;
}