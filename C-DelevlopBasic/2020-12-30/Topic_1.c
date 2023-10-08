void showCaptain(TeamMember team[], int n){
    float max = 0;
    int flag = 0;
    for (int i=0; i<n; i++) {
        if(team[i].ability>max){
            max = team[i].ability;
            flag = i;
        }
    }
    printf("%d %s %s %s %.2lf",team[flag].id,team[flag].lastname,team[flag].firstname,team[flag].sex,team[flag].ability);
}
