int delMaxMin(int A[],int n){
    int max = A[0],min = A[0];
    int max_xb = 0,min_xb = 0;
    int flag = 0;
    int count = 0;
    for (int i=1; i<n; i++) {
        if(A[i]>=max){
            max = A[i];
            max_xb = i;
        }
        if(A[i]<=min){
            min = A[i];
            min_xb = i;
        }
    }
    // 最大值在最小值后面
    if(max_xb > min_xb)
        flag = min_xb;
    else
        flag = max_xb;
    for (int i=flag; i<n; i++) {
        if(i==max_xb || i==min_xb)
            continue;
        A[flag++]=A[i];
        count++;
    }
    return count;
}