#include <stdio.h>

int main(){
    int g = 0; // 乌龟
    int t = 0; // 兔子
    int time = 0; //时间
    int flag = 0; //flag = 0 兔子奔跑，flag = 1 兔子停止
    int sleep = 0;
    scanf("%d",&time); // 写入时间
    for(int i=0;i<time;i++){
        g+=3;//乌龟每次增加
        if(i<10){ //前10秒直接加
            t+=9;
        }else{
            if(flag==1){
                if(sleep==30){
                    if(i%10==0){ // 10秒判断一次
                        if(g>t){
                            flag = 0; //兔子奔跑
                        }else{
                            flag = 1; //兔子停止
                        }
                    }
                    sleep = 0;
                }
            }else{
                if(i%10==0){ // 10秒判断一次
                    if(g>t){
                        flag = 0; //兔子奔跑
                    }else{
                        flag = 1; //兔子停止
                    }
                }
            }
            if(flag==0){//兔子还在奔跑
                t+=9;
            }else{//兔子停了
                sleep++;
            }
        }
    }
    if(g>t)
        printf("@_@ %d",g);
    else if(t>g)
        printf("^_^ %d",t);
    else
        printf("-_- %d",t);
        
    
}
