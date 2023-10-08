#include <stdio.h>
int main(){
	double pi,r,v;
	scanf("%lf",&r);
	pi = 3.1415926535897932384626;
	v = (4/3.0)*pi*r*r*r;
	printf("%.2lf\n",v);
	return 0;
}