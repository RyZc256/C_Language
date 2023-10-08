#include <stdio.h>

int main(){
	float s[20];
	int num,i;
	int t=0;
	float ave,sum=0.0;
	for(i=0;i<20;i++){
		scanf("%d",&num);
		if(num<0)
			break;
		else
		{
			s[i]=num;
			t++;
		}
	}
	for(i=0;i<t;i++){
		sum += s[i];
	}
	ave = sum / t;
	printf("ave=%.2f\n",ave);
	for(i=0;i<t;i++){
		if(s[i]<ave)
			printf("%6.1f",s[i]);
	}
}
