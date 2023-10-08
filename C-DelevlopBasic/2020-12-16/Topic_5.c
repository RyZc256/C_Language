int isPalindrome(const char* str, char* pch){
    int len=0;
    int i,j; 
    int flag=1; 
    while(1){
        if(*(str+len)=='\0')
            break;
        len++;
    }
    i=0;j=len-1;
    while(i<len/2){
        if (*(str+i)!=*(str+j)) {
            flag = 0;
        }
        i++;j--;
    }
    if(len%2==0)
        *pch = *(str+(len/2)-1);
    else
        *pch = *(str+(len/2));
    return flag;
}
