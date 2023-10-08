int decode(char**s)
{
    int sum=0,t;
    for(int i=0;i<4; i++)
    {
        t=0;
        for (int j=0;j<strlen(s[i]);j++)
            for (int k=0;k<strlen(s[4]);k++)
                if (s[i][j]==s[4][k])
                    t++;
            sum=sum*10+t;
    }
    return sum;
}