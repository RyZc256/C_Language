#include <stdio.h>

int main(){
	int s[10];
	int i,n;
	int flag=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&s[i]);
	}
	for(i=0;i<n-1;i++){
		flag++;
		if(flag==3){
			printf("%d\n",s[i+1]-s[i]);
			flag=0;
		}
		else{
			if(i==n-2)
				printf("%d",s[i+1]-s[i]);
			else
				printf("%d ",s[i+1]-s[i]);
		}
	}
}
