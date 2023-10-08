#include <stdio.h>

int main(){
	char a;
	float b,c,d;
	scanf("%f %c %f",&b,&a,&c);
	if(a==43){
		d = b + c;
		printf("%.2f %c %.2f = %.2f",b,a,c,d);
	}else if(a==47){
		if(d==0){
			printf("Error!");
		}else{
			d = b / c;
			printf("%.2f %c %.2f = %.2f",b,a,c,d);
		}
	}else if(a==45){
		d = b - c;
		printf("%.2f %c %.2f = %.2f",b,a,c,d);
	}else if(a==42){
		d = b * c;
		printf("%.2f %c %.2f = %.2f",b,a,c,d);
	}else{
		printf("Error!");
	}

	
    return 0;
}