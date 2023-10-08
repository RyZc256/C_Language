#include <stdio.h>
int main(){
	int l,i,s; //长度 for 分母
	float sum; //总和 中间值
	sum = 1.0; //初始总和
	s = 1; // 初始分母
	scanf("%d",&l);
	for(i=1;i<l;i++){
		s += 3;
		if(i%2!=0){
			sum +=  (1.0/ s) * -1;
		}else{
			sum +=  (1.0/ s) * 1;
		}
	}
	printf("sum = %.3f",sum);
	return 0;
}