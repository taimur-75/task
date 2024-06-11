// Snake Game

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>

void initialize();
void draw();
void input();
void Logic();

int height=20, width=40;
int score,tail, gameOver, foodX, foodY, X, Y, flag;
int tailX[100], tailY[100];

int main(){
    char cc;
    label78 :
    initialize();
    
    while(!gameOver){
        draw();
        input();
        Logic();
        Sleep(400);
        printf("\n Score = %d",score);
    }
    printf("\n Game Over ! ");

    printf("Press Y to continue : ");
    scanf("%c",&cc);
    if(cc=='y'||cc=='Y'){
        goto label78;
    }

    return 0;
}

void initialize(){
    score = gameOver = tail = flag = 0;
    X=width/2;
    Y=height/2;
    foodX=width/3;
    foodY=height/3;
}

void draw(){
    system("cls");
    int i,j,k;
    for(i=0;i<height;i++){
        for(j=0;j<width;j++){
            if(i==0||i==height-1||j==0||j==width-1){  // border cases.
                printf("*");
            }else{  // non-border cases.
                if(i==Y&&j==X){  // if position matches the snake head co-ordinates.
                    printf("0");
                }else if(i==foodY&&j==foodX){  // if position matches the food co-ordinates.
                    printf("F");
                }else{

                    int ss=0;
                    for(k=0;k<tail;k++){
                        if(i==tailY[k]&&j==tailX[k]){
                            printf("o");
                            ss=1;
                        }
                    }

                    if(ss==0){
                        printf(" ");
                    }
                }
            }
        }
        printf("\n");
    }
}

void input(){
    char ch;
    label3 :

    if(kbhit()){// useful to continue snake run after single input.
    ch = getch();

    if(ch=='a'||ch=='A'){
        flag=1;
    }else if(ch=='s'||ch=='S'){
        flag=2;
    }else if(ch=='w'||ch=='W'){
        flag=3;
    }else if(ch=='z'||ch=='Z'){
        flag=4;
    }else if(ch=='p'||ch=='P'){
        flag=5;
    }else{
        goto label3;
    }
}
}

void Logic(){

    int prevX=tailX[0];
    int prevY=tailY[0];
    tailX[0]=X;
    tailY[0]=Y;
    int prev2X, prev2Y;

    int l;
    for(l=1;l<tail;l++){
        prev2X=tailX[l];
        prev2Y=tailY[l];
        tailX[l]=prevX;
        tailY[l]=prevY;
        prevX=prev2X;
        prevY=prev2Y;
    }

    if(flag==1){// directs snake head.
        X--;
    }else if(flag==2){
        X++;
    }else if(flag==3){
        Y--;
    }else if(flag==4){
        Y++;
    }else if(flag==5){
        gameOver = 1;
    }

    // Checking if snake touches the boundary , then game over.
    if(X<1||X>width-2||Y<1||Y>height-2){
        gameOver = 1;
    }

    // self touch condition, game over
    int t;
    for(t=0;t<tail;t++){
        if(X==tailX[t]&&Y==tailY[t]){
            gameOver=1;
        }
    }

    if(X==foodX&&Y==foodY){ // food eating condition.
        score++;
        tail++;

        label4 :
        foodX=rand()%20;
        if(foodX==0||foodX==19){
            goto label4;
        }

        label5 :
        foodY=rand()%20;
        if(foodY==0||foodY==19){
            goto label5;
        }

    }

}


