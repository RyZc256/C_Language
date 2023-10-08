int input(char ar2[][21]){
    int count = 0;
    while (count<10) {
        scanf("%s",ar2[count]);
        if(strcmp(ar2[count], "*END*")==0)
            break;
        count++;
    }
    return count;
}
void paixu(char ar2[][21], int n){
    char tem[21] = {0};
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            if(strcmp(ar2[i], ar2[j])>0){
                strcpy(tem, ar2[i]);
                strcpy(ar2[i], ar2[j]);
                strcpy(ar2[j], tem);
            }
        }
    }
}
void printArr(char ar2[][21], int n){
    if(n==0)
        printf("NO WORD\n");
    else
        printf("After sorted:\n");
    
    for (int i=0; i<n-1; i++) {
        printf("%s ",ar2[i]);
    }
    printf("%s", ar2[n-1]);
}