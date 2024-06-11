// Calender

#include<stdio.h>
#include<stdlib.h>

int leapYear(int);
int firstWeekDay(int);
void draw(int);

char *months[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
int monthDay[]={31,28,31,30,31,30,31,31,30,31,30,31};

int main(){
    system("cls");
    system("Color 3F");
    int year;
    printf("Enter the year : ");
    scanf("%d",&year);

    int flag = leapYear(year); // Checking leap year or not;
    if(flag==1){
        monthDay[1]=29;
    }

    int srartingDayNum = firstWeekDay(year);// starts day from 0.
    draw(srartingDayNum);
    return 0;
}

void draw(int srartingDayNum){
    int month;
    for(month=0;month<12;month++){
        printf("\n\n**----------- %s --------------**\n",months[month]);
        printf("\n   Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        int count;
        for(count=0;count<srartingDayNum;count++){// first print spaces where required.
            printf("     ");
        }
        
        int j;
        for(j=1;j<=monthDay[month];j++){// then print days of weeks.
            printf("%5d",j);
            count++;
            if(count%7==0){
                printf("\n");
                count=0;
            }
        }

        srartingDayNum = count;// reset starting day number for next month.
    }
}

int firstWeekDay(int year){// checking 1st day number in week of a year.
    int day;
    day = (((year-1)*365) + ((year-1)/4) - ((year-1)/100) + ((year-1)/400) + 1) % 7;
    return day;
}

int leapYear(int year){// checking if a year is leap year or not.
    int flag=0;
    if(year%4==0){
        if(year%100!=0){
            flag=1;
        }else{
            if(year%400==0){
                flag=1;
            }
        }
    }
    return flag;
}