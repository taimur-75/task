#include<stdio.h>
#include<stdlib.h>

char arr[9]={'1','2','3','4','5','6','7','8','9'};

void board();
void input();
int check(int);

int main(){
    input();
    return 0;
}

void input(){
    int user = 0, temp, count = 0;

    while(1){   // Game loop for each turn.
        system("cls");
        board();
        user %=2;
        int s=user+1;
        printf("User %d \n",s);
        printf("Enter your input : \n");
        scanf("%d",&temp);

        if(temp<1||temp>9||arr[temp-1]=='X'||arr[temp-1]=='O'){ // Can not input already occupied place.
            printf("Invalid Input ! \n Try again \n");
            continue;
        }

        if(user==0){//user 1 , with X .
            arr[temp-1]='X';
        }else if(user==1){// user 2 , with O .
            arr[temp-1]='O';
        }

        
        count += 1;

        int ch = check(user);  // Returns win or draw.
        if(ch==1){
            board();
            printf("User %d win. \n",s);
            break;
        }

        if(count==9){ // maximum input limit 9 times.
        	board();
            printf("Game Draw ! \n");
            break;
        }
        
        user  += 1;

    }
}

int check(int user){  // Checking the winning conditions.
    int res = 0;
    char el = (user==0)?'X':'O';

    if((arr[0]==el&&arr[1]==el&&arr[2]==el)
    ||(arr[3]==el&&arr[4]==el&&arr[5]==el)
    ||(arr[6]==el&&arr[7]==el&&arr[8]==el)
    ||(arr[0]==el&&arr[3]==el&&arr[6]==el)
    ||(arr[1]==el&&arr[4]==el&&arr[7]==el)
    ||(arr[2]==el&&arr[5]==el&&arr[8]==el)
    ||(arr[0]==el&&arr[4]==el&&arr[8]==el)
    ||(arr[2]==el&&arr[4]==el&&arr[6]==el)){
        res = 1;
    }    

    return res;
}

void board(){  // Prints the board.
    system("cls");
    printf(" %c | %c | %c \n",arr[0],arr[1],arr[2]);
    printf("___|___|___\n");
    printf(" %c | %c | %c \n",arr[3],arr[4],arr[5]);
    printf("___|___|___\n");
    printf(" %c | %c | %c \n",arr[6],arr[7],arr[8]);
}



