void pyramid(int n){
    int i,j,s;
    for (i=1; i<=n; i++) {
        for(s=i;s<n;s++){
            printf(" ");
        }
        for (j=1; j<=i; j++) {
            printf("%d ",i);
        }
        printf("\n");
    }
}
