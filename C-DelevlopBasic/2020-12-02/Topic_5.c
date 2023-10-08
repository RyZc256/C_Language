double fun(int n){
    if(n==1)
        return 1;
    else
        return n*fun(n-1);
}