#include <stdio.h>

int main(){
	int s[1000];
	int n,i,j;
	int flag[2];
	int num,sum=0,max=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&s[i]);
	}
	for(i=0;i<n;i++){ 
		num = s[i];
		sum = 0;
		for(j=0;j<n;j++){ 
			if(num==s[j]) 
				sum++;
		}
		if(sum>max){
			flag[0]=num;
			flag[1]=sum;
			max = sum;
		}
	}
	printf("%d %d",flag[0],flag[1]);
}
