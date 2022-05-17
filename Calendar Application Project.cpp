//22104030 STANLY SWAGATO HALDER
//22104043 MD SIFAT ISLAM
//22104032 AHNAF TAIYEB
//22104037 RAIYAN RASHIK
//22104045 AHMED HASHIM ELMI
//22104047 MOHAMMED FAHAD BIN SHAKHAWAT

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<graphics.h>

int firstweekday(int year);
void gotoxy(int x,int y){
COORD CRD;
CRD.X=x;
CRD.Y=y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),CRD);}
int firstweekday(int year)
{int day;
    day = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
    return day;}

    main()
{
int year,month,monthdays,day,dayscount=0,startingday,i; char a,b;char arr[10]; int d=194,j,e=231;
char *months[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
 int gd=DETECT,gm;
 initgraph(&gd,&gm,""); int x=171; int y=110;

gotoxy(40,10);
printf("Enter the year:   ");
scanf("%d",&year);
gotoxy(40,12);
printf("Enter the month:  ");
scanf("%d",&i);
setcolor(GREEN);
rectangle(180,40,467,75);
if(i==1)
    outtextxy(486,170,"1st Jan New Year");
if(i==2)
    {outtextxy(520,170,"21st Feb");
    outtextxy(480,190, "Mother Language Day");}
    if(i==3)
    {outtextxy(515,170,"26th Mar");
    outtextxy(485,190,"Independence Day");}
    if(i==4)
    {outtextxy(515,170,"14th Apr");
    outtextxy(485, 190, "Bengali New Year");}
    if(i==5)
    outtextxy(475,170,"7th May Engineers Day");
    if(i==6)
    {outtextxy(518,170,"5th June");
    outtextxy(470,190,"World Environment Day");}
    if(i==7)
    outtextxy(490,170,"1st July Joke Day");
    if(i==8)
    {outtextxy(518,170,"15th Aug");
    outtextxy(470, 190,"National Mourning Day");}
    if(i==9)
    outtextxy(465,170,"27th World Tourism Day");
    if(i==10)
    outtextxy(465,170,"1st Oct Int'l Coffee Day");
    if(i==11)
    outtextxy(468,170,"20th Nov Children's Day");
    if(i==12)
    outtextxy(475,170,"16th Dec Victory Day");
if((year%4==0 && year%100==0) || (year%400==0))
days[1]=29;
startingday=firstweekday(year);

setcolor(11);
    for(month=0;month<=11;month++)
    {
if(month==i-1){

outtextxy(290,50,months[i-1]);

    outtextxy(200,80,"Sun   Mon   Tue  Wed  Thu    Fri    Sat\n\n");}
x=171;
for(dayscount=0;dayscount<startingday;dayscount++)
{
outtextxy(x,110,"");
x=x+37;
}

monthdays=days[month];

if(month<=i-1)
{
for(day=1;day<=monthdays;day++)
{
x=x+37;
if(month==i-1)
{
sprintf(arr,"%d",day);
outtextxy(x,y,arr);}
if(++dayscount>6)
{
    if(month==i-1)
    {x=171;
         y=y+30;}
    dayscount=0;

}
startingday=dayscount;
}}
}

setcolor(GREEN);
for(j=1;j<=7;j++)
{
rectangle(d,75,e,285);
d=37+d;
e=e+37;

}
d=75;e=105;
for(j=1;j<=6;j++)
{
rectangle(194,d,453,e);
d=30+d;
e=e+30;
}
setcolor(GREEN);
rectangle(71,425,142,450);
rectangle(70,424,143,451);
rectangle(65,419,148,456);
setcolor(11);
outtextxy(82,430,"2-Guide");
setcolor(GREEN);
rectangle(279,425,360,450);
rectangle(278,424,361,451);
rectangle(273,419,366,456);
setcolor(11);
outtextxy(285,430,"1-Calender");
setcolor(GREEN);
rectangle(497,425,568,450);
rectangle(496,424,569,451);
rectangle(491,419,574,456);
setcolor(11);
outtextxy(505,430,"ESC-Exit");
setcolor(GREEN);
rectangle(510,105,581,150);

setcolor(11);
    outtextxy(530,110,"M");
    delay(100);
    outtextxy(542,110,"A");
    delay(100);
    outtextxy(549,110,"I");
    delay(100);
    outtextxy(554,110,"N");
    delay(100);
    outtextxy(527,130,"E");
    delay(100);
    outtextxy(535,130,"V");
    delay(100);
    outtextxy(542,130,"E");
    delay(100);
    outtextxy(549,130,"N");
    delay(100);
    outtextxy(558,130,"T");
    delay(100);

setcolor(11);
rectangle(510,105,581,150);
setcolor(11);
rectangle(510,104,581,151);
setcolor(GREEN);
    outtextxy(530,110,"M");
    delay(100);
    outtextxy(542,110,"A");
    delay(100);
    outtextxy(549,110,"I");
    delay(100);
    outtextxy(554,110,"N");
    delay(100);
    outtextxy(527,130,"E");
    delay(100);
    outtextxy(535,130,"V");
    delay(100);
    outtextxy(542,130,"E");
    delay(100);
    outtextxy(549,130,"N");
    delay(100);
    outtextxy(558,130,"T");
    delay(100);
    setcolor(GREEN);
rectangle(510,105,581,150);
rectangle(509,104,582,151);
setcolor(11);
    outtextxy(530,110,"M");
    delay(100);
    outtextxy(542,110,"A");
    delay(100);
    outtextxy(549,110,"I");
    delay(100);
    outtextxy(554,110,"N");
    delay(100);
    outtextxy(527,130,"E");
    delay(100);
    outtextxy(535,130,"V");
    delay(100);
    outtextxy(542,130,"E");
    delay(100);
    outtextxy(549,130,"N");
    delay(100);
    outtextxy(558,130,"T");
    delay(100);
a=_getch();
{system("cls");
cleardevice();}
if(a==49)
main();
if(a==50)
{settextstyle(4,0,5);
setcolor(GREEN);
outtextxy(80,10,"INSTRUCTIONS");
settextstyle(8,0,1);

outtextxy(10,90,"Enter the Year:    Enter the year you desire to look in.");
outtextxy(10,120,"Enter the Month:   Enter the month you desire to look in.");
outtextxy(10,150,"Main Event:        Below the main event is the most ");
outtextxy(210,180," popular of your chosen month.");
outtextxy(10,210,"Calender:          Press 1 to look over any other year.");
outtextxy(10,240,"Exit:              Press Esc Key To Exit at any Stage.");
settextstyle(4,0,1);
outtextxy(190,350,"Press Any Key to Exit");
b=_getch();
if(b==49)
    main();
}
if(a==27)
    exit;
closegraph();
}
