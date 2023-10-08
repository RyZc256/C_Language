#include <stdio.h>

int main(){
	float a,b,c;
	scanf("%f %f",&a,&b);
	c = a/(b*b);
	if(c < 18.5){
		printf("偏瘦");
	}else if(c >= 18.5 && c < 24){
		printf("正常");
	}else if(c >= 24 && c<28){
		printf("偏胖");
	}else if(c >= 28 && c<40){
		printf("肥胖");
	}else if(c >= 40){
		printf("极重度肥胖");
	}
    return 0;
}