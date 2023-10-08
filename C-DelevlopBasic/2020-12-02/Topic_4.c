int CountDigit( int number, int digit){
    int count = 0;
    if(number < 0) // 小于零取反
        number = - number;

    while(1){
        if(number / 10 != 0){
            if(number % 10 == digit)
                count+=1;
            number = number / 10;
        }else
            break;
    }
    if(number % 10 == digit)
        count+=1;
    return count;
}
