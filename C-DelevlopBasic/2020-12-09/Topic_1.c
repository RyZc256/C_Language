double NumHanoi(int index){
    if(index == 1)
        return 1;
    else if(index <= 0)
        return 0;
    else
        return NumHanoi(index - 1) + NumHanoi(index - 1) + 1.0;
}
