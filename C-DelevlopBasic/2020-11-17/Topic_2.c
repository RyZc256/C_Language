#include <stdio.h>

int main(){
	int s[20];
	int n,num,i;
	int p,flag = -1;
	scanf("%d %d",&n,&num);
	for(i=0;i<n;i++){
		scanf("%d",&s[i]);
	}
	for(i=0;i<n;i++){
		if(s[i] == num)
			flag = i;	
	}
	if(flag == -1)
		printf("Not Found");
	else
		printf("%d",flag);
}
