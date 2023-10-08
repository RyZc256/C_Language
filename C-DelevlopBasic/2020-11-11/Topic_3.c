#include <stdio.h>
int main(){
	int n,i;
	float h,sum;
	scanf("%f %d",&h,&n);
	sum = h;
	for(i=1;i<n;i++){
		sum += h;
		h /= 2;
	}
	if(n==0){
		h = 0;
		sum = 0;
	}else{
		h = h / 2;
	}
	printf("%.1f %.1f\n",sum,h);
	return 0;
}