int set_grade(struct student *p, int n ){
    int i, sum = 0;
    for(i=0;i<n;i++){
        if(100>=p[i].score&&p[i].score>=85){
            p[i].grade = 'A';
        }
        else if(84>=p[i].score&&p[i].score>=70){
            p[i].grade = 'B';
        }
        else if(69>=p[i].score&&p[i].score>=60){
            p[i].grade = 'C';
        }
        else if(59>=p[i].score&&p[i].score>=0){
            p[i].grade = 'D';
            sum++;
         }
    }
    return sum;
}