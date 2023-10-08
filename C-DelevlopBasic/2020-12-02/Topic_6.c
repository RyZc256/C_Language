double Climb(int step){
    if(step == 1)
        return 1;
    else if(step == 2)
        return 2;
    else if(step == 3)
        return 4;
    else if(step <= 0)
        return 0;
    else
        return Climb(step - 1) + Climb(step - 2) + Climb(step - 3);
}