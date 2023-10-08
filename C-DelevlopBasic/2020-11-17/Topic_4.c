#include <stdio.h>

int main(){
	int s[100];
	int n,num,i,j,temp;
	scanf("%d %d",&n,&num);
	for(i=0;i<n;i++){
		scanf("%d",&s[i]);
	}
	for(i=0;i<num;i++){
		for(j=0;j<n-1;j++){
			if(s[j]>s[j+1]){
				temp = s[j];
				s[j] = s[j+1];
				s[j+1] = temp;
			}
		}
	}
	for(i=0;i<n;i++){
		if(i==n-1)
			printf("%d",s[i]);
		else
			printf("%d ",s[i]);
	}
}
