// Clock

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int main(){
    int h, m, s;
    h=m=s=0;

    while(1){
        system("cls");
        printf("\n Hr. Min. Sec. \n");
        printf("\n %02d : %02d : %02d \n",h,m,s);
        Sleep(1000);

        s++;
        if(s==60){
            s=0;
            m++;
        }
        if(m==60){
            m=0;
            h++;
        }
    }
    
    return 0;
}