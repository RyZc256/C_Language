int ArrayShift( int a[], int n, int m ){
    int tem,i,j,s;
    int tem_a[9999] = {};
    tem=s=0;
    if(m>n)
        m=m-n;
    for (i=0; i<n; i++) {
        s = i+m;
        if(s<n){
            tem_a[s]=a[i];
        }else{
            s=s-n;
            tem_a[s]=a[i];
        }
    }
    for (i=0; i<n; i++) {
        a[i]=tem_a[i];
    }
    
    return 0;
}