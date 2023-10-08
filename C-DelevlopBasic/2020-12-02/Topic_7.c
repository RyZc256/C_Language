# include <stdio.h>
# include <math.h>
# define P 3.141592653589793238462643383279

void ball();
void cylinder();
void cone();

int main(){
    int num;
    while (1) {
        printf("1-Ball\n2-Cylinder\n3-Cone\nother-Exit\n");
        printf("Please enter your command:\n");
        scanf("%d",&num);
        switch (num) {
            case 1:ball();break;
            case 2:cylinder();break;
            case 3:cone();break;
            default:return 0;
        }
    }
}

void ball(){
    double b,r;
    printf("Please enter the radius:\n");
    scanf("%lf",&r);
    b = (4.0 / 3) * P * pow(r,3);
    printf("%.2lf\n",b);
}

void cylinder(){
    double b,r,h;
    printf("Please enter the radius and the height:\n");
    scanf("%lf %lf",&r,&h);
    b = P * pow(r,2) * h;
    printf("%.2lf\n",b);
}

void cone(){
    double b,r,h;
    printf("Please enter the radius and the height:\n");
    scanf("%lf %lf",&r,&h);
    b =  P * pow(r,2) * h / 3;
    printf("%.2lf\n",b);
}



