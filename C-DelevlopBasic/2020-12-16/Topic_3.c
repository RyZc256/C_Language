char *str_cat( char *s, char *t){
    int len_1=0,len_2=0;
    while(1){
        if(*(s+len_1)=='\0')
            break;
        len_1++;
    }
    while(1){
        if(*(t+len_2)=='\0')
            break;
        len_2++;
    }
    for (int i=0; i<len_2; i++) {
        *(s+len_1+i) = *(t+i);
    }
    return s;
}