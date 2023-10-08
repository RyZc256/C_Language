void inv(int *x,int n){
    int tem;
    int i,j;
    i=0;j=9;
    while(j>4){
        tem = *(x+j);
        *(x+j) = *(x+i);
        *(x+i) = tem;
        j--;i++;
    }
}