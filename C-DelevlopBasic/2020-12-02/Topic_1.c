int narcissistic( int number ){
    int a,b,c,d;
    if(number / 10000 > 0){
        return 0;
    }else if(number / 1000 > 0){
        a = number / 1000; // 千位
        b = (number - a * 1000) / 100; // 百位
        c = (number - a * 1000 - b * 100) / 10 ; // 十位
        d = number % 10; //个位
        if(a*a*a*a + b*b*b*b + c*c*c*c + d*d*d*d == number)
            return 1;
        else
            return 0;
    }else if(number / 100 > 0){
        a = number / 100;
        b = (number - a * 100) / 10;
        c = number % 10;
        if(a*a*a + b*b*b + c*c*c == number)
            return 1;
        else
            return 0;
    }else
        return 0;
}
void PrintN(int m, int n){
    int i;
    for (i=m+1; i<n; i++) {
        if(narcissistic(i))
            printf("%d\n",i);
    }
}