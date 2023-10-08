#include <stdio.h>
int main(){
	int num;
	float sum = 0;
	int s = 0;
	int s1 = 0;
	while(1){
		scanf("%d",&num);
		if(num<0)
			break;
		sum += num;
		if(num>=80&&num<90){
			s1++;
		}
		s++;
	}
	printf("ave=%.2f,n=%d\n",sum/s,s1);
}