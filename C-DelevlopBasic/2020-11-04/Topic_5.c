#include <stdio.h>

int main(){
	int n,y,r,sum;
	scanf("%d/%d/%d",&n,&y,&r);
	if(n%4==0 && n%100!=0 || n%400==0)
	{
		switch(y){
			case 1:sum=0;break;
			case 2:sum=31;break;
			case 3:sum=31+29;break;
			case 4:sum=31+29+31;break;
			case 5:sum=31+29+31+30;break;
			case 6:sum=31+29+31+30+31;break;
			case 7:sum=31+29+31+30+31+30;break;
			case 8:sum=31+29+31+30+31+30+31;break;
			case 9:sum=31+29+31+30+31+30+31+31;break;
			case 10:sum=31+29+31+30+31+30+31+31+30;break;
			case 11:sum=31+29+31+30+31+30+31+31+30+31;break;
			case 12:sum=31+29+31+30+31+30+31+31+30+31+30;break;
		}
	}else{
		switch(y){
			case 1:sum=0;break;
			case 2:sum=31;break;
			case 3:sum=31+28;break;
			case 4:sum=31+28+31;break;
			case 5:sum=31+28+31+30;break;
			case 6:sum=31+28+31+30+31;break;
			case 7:sum=31+28+31+30+31+30;break;
			case 8:sum=31+28+31+30+31+30+31;break;
			case 9:sum=31+28+31+30+31+30+31+31;break;
			case 10:sum=31+28+31+30+31+30+31+31+30;break;
			case 11:sum=31+28+31+30+31+30+31+31+30+31;break;
			case 12:sum=31+28+31+30+31+30+31+31+30+31+30;break;
		}
	}
	sum = sum + r;
	printf("%d",sum);

    return 0;
}