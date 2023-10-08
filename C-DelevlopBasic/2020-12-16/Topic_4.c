void strmcpy( char *t, int m, char *s ){
    int flag = 0;
    if(m>MAXN)
        return;
    else{
        for (int i=m-1; i<MAXN; i++) {
            *(s+flag)=*(t+i);
            flag++;
        }
    }
}
