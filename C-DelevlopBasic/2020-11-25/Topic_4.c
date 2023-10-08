#include<stdio.h>
int main()
{
    int i,j,n,s[6][6],a[6],b[6];

    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        scanf("%d",&s[i][j]);
    }
    /*输入矩阵到二维数组*/

    for(i=0;i<n;i++)
    {
        int max=s[i][0];
        for(j=0;j<n;j++)
        if(s[i][j]>max)max=s[i][j];
        a[i]=max;
    }
     for(j=0;j<n;j++)
    {
        int min=s[0][j];
        for(i=0;i<n;i++)
        if(s[i][j]<min)min=s[i][j];
        b[j]=min;
    }
    /*将每行每列的最值存入数组a b*/
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        if(a[i]==b[j]&&s[i][j]==a[i])
        {
            printf("%d %d",i,j);
            return 0;   
        }
    }
    /*如果某行max=某列min 检查这个坐标上的数值*/
    printf("NONE");
    return 0;
}