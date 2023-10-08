#include <stdio.h>
int main(){
	int a;
	scanf("%d",&a);
	printf("%d,",a/100);
	printf("%d,",(a-(a/100*100))/10);
	printf("%d\n",a%10);	
	return 0;
}