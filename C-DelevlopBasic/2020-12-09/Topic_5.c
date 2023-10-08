float fun(float array[],int n){
    float sum = 0.0;
    Max = array[0];
    sum = sum + Max;
    for (int i=1; i<n; i++) {
        if(Max<array[i]){
            Max=array[i];
        }
        sum+=array[i];
    }
    for (int i=0; i<n; i++) {
        if(Max == array[i])
            J++;
    }
    return sum / n;
}
