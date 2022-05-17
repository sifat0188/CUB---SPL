//22104030:STANLY SWAGATO HALDER
//22104043: MD SIFAT ISLAM
//22104032: AHNAF TAIYEB
//22104037: RAIYAN RASHIK
//22104045: AHMED HASHIM ELMI
//22104047: MOHAMMED FAHAD BIN SHAKHAWAT









#include "windows.h"

#include <iostream>

#include <string>

#include <ctime>

#include <stdio.h>
#include <dos.h>
#include <graphics.h>
#include <conio.h>

#define	MAGFY	20


using namespace std;


#define CONSO GetConsoleScreenBufferInfo

#define GREEN   10

#define CYAN    11

#define RED     12

#define MAGENTA 13

#define YELLOW  14

#define WHITE   15

using namespace std;



class Bline
	{
	private:
		int CEN_X,CEN_Y,radius,X,Y,i,j;
	public:
	void line1(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4);

	};




void* h = ::GetStdHandle((DWORD)-11);

CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

int attr = CONSO(h, &csbiInfo);

void setTextColor(int color)
{

  SetConsoleTextAttribute(h, color);

}

void setCursor(int row, int col)
{

  COORD coord = {col, row};

  SetConsoleCursorPosition(h, coord);

}

void showAppName();

void getInput(BOOL);

BOOL checkLeap();

BOOL printCalendar(int);

void printAppointments();

void pause();

int getNumber();


int day, month, year, appointmentDay;

string appointmentText;


int main(void)
{

  setTextColor(WHITE);

menu:

  showAppName();

  setCursor(3, 20);


  cout << "Pick a menu";

  setCursor(5, 20);

  cout << "1. CHECK LEAP YEAR";

  setCursor(7, 20);

  cout << "2. PRINT CALENDAR";

  setCursor(9, 20);

  cout << "3. ADD APPOINTMENT";

  setCursor(11, 20);

  cout << "4. Quit";

  setCursor(13, 20);

  cout << "Choice [1, 2, 3, 4]? ";

  int choice = getNumber();

  switch (choice)
  {


  case 1:
    {


      getInput(0);

      setCursor(5, 20);

      cout << "Result is: ";

      if(checkLeap())
      {

        cout << "Year is leap!";

      }

      else
      {

        cout << "Year is NOT leap. . .";

      }

      setCursor(7, 20);

      cout << "Done. Press any key...";

      // pause so that the user
      // can see the message
      pause();

      goto menu;

    }


  case 2:
    {

    getmon:

      getInput(1);


      appointmentDay = -1;


      if(!printCalendar(8))
      {


        setCursor(23, 20);

        setTextColor(RED);

        cout << "Calendar dates bad. ";

        cout << "Enter again...";


        pause();

        setTextColor(WHITE);

        goto getmon;

      }

      else
      {

        setCursor(23, 20);

        cout<<"Done. Press any key...";


        pause();

        goto menu;

      }

    }


  case 3:
    {

    getday:

      getInput(1);

      setCursor(7, 20);

      cout << "Enter day: ";

      appointmentDay = getNumber();

      setCursor(9, 20);


      cout << "Enter text[25-chars]:";

      getline(cin, appointmentText);


      if(appointmentText.size() > 25)
      {

        appointmentText.erase(25);

      }

      showAppName();


      if(printCalendar(4))
      {


        printAppointments();

        setCursor(23, 20);

        cout <<"Done. Press any key...";

        pause();

      }

      else
      {


        setCursor(23, 20);

        setTextColor(RED);

        cout << "Calendar dates bad. ";

        cout << "Enter again...";

        pause();

        setTextColor(WHITE);

        goto getday;

      }

      goto menu;

    }

  case 0:
    {

      goto menu;

    }

  default:
    break;

  }


  SetConsoleTextAttribute(
  h, csbiInfo.wAttributes);

  return 0;

}


void showAppName()
{

  system("cls");

  setCursor(1, 25);

  cout << "HOVEN CALENDAR APP";

  setCursor(10, 3);

  setTextColor(GREEN);


  for(int x =0; x < 5; x++)
  {

    setCursor(2 + x, 3 + x);

    cout << "//";

    setCursor(2 + x, 12 - x);

    cout << "//";

  }

  setCursor(6, 6);

  cout << "sifat islam ";

  setTextColor(WHITE);

}


void getInput(BOOL monthAlso)
{

  showAppName();

  setCursor(3, 20);

  if(monthAlso)
  {

    cout << "Month?[1-12]: ";

    month = getNumber();

    month -= 1;

    setCursor(5, 20);

  }

  cout << "Year?[1970-3000]:";

  year = getNumber();

  year -= 1900;

}


int checkDate()
{

  tm t = {0, 0, 0, day, month, year};

  if(mktime(&t) < 0)
  {

    return -1;

  }


  {

    return -1;

  }


  if(month != t.tm_mon)
  {

    return -1;

  }


  if(year != t.tm_year)
  {

    return -1;

  }


  return t.tm_wday;

}


BOOL checkLeap()
{

  day = 29;

  month = 1;

  return checkDate() >= 0;

}


BOOL printCalendar(int fromRow)
{

  day = 1;


  if(-1 == checkDate())
  {

    return FALSE;

  }

  int row = fromRow;

  setCursor(row, 24);

  cout << "CALENDAR for ";

  cout << month + 1 << "-";

  cout << year + 1900;

  row += 2;

  setCursor(row, 20);

  cout << "Mo  Tu  We  Th  Fr  Sa  Su";

  row += 2;

  setCursor(row, 20);

  cout << "==========================";

  row += 1;

  while(true)
  {

    switch(checkDate())
    {


    case 1:
      {

        setCursor(row, 20);

      }

      break;


    case 2:
      {

        setCursor(row, 24);

      }

      break;


    case 3:
      {

        setCursor(row, 28);

      }

      break;


    case 4:
      {

        setCursor(row, 32);

      }

      break;


    case 5:
      {

        setCursor(row, 36);

      }

      break;

    case 6:
      {


        setTextColor(CYAN);

        setCursor(row, 40);

      }

      break;


    case 0:
      {


        setTextColor(CYAN);

        setCursor(row, 44);


        row += 2;

      }

      break;

    default:
      {


        return TRUE;

      }

    }


    if(appointmentDay >= 1)
    {

      if(appointmentDay == day)
      {

        setTextColor(YELLOW);

      }


      if(17 == day)
      {

        setTextColor(YELLOW);

      }

    }

    printf("%2d", day++);

    setTextColor(WHITE);

  }

}

void printAppointments()
{

  setTextColor(GREEN);


  for(int x = 2; x < 24; x++)
  {

    setCursor(x, 48);

    cout << "||";

  }

  setTextColor(MAGENTA);

  setCursor(2, 56);

  cout << "APPOINTMENTS";

  setCursor(4, 52);

  cout << appointmentDay;

  cout << " - " << appointmentText;

  setCursor(6, 52);


  cout << "17 - for a dinner!";

  setTextColor(WHITE);

}


int getNumber()
{


  string s;

  getline(cin, s);

  return atoi(s.c_str());

}


void pause()
{

  string s;

  getline(cin, s);

}
void Bline::line1(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{
	CEN_X = (x1+x2)/2 + (x3-x2)/2;
	CEN_Y = (y1+y2)/2 + (y3-y2)/2;

	for(;!kbhit();)
	{
	delay(300);
	cleardevice();
line(x1,y1,x2,y2);
	line(x1,y1-20,x2,y2-20);
	line(x3,y3,x4,y4);
	line(x3,y3-20,x4,y4-20);
	line(x1,y1,x4,y4);
	line(x1,y1-20,x4,y4-20);
	line(x2,y2,x3,y3);
	line(x2,y2-20,x3,y3-20);


	line(x1,y1,x1,y1-20);
	line(x2,y2,x2,y2-20);
	line(x3,y3,x3,y3-20);
	line(x4,y4,x4,y4-20);


	if(x1>CEN_X && y1<CEN_Y) x1--,y1--;
	if(x1==CEN_X && y1<CEN_Y) x1--,y1++;
	if(x1<CEN_X && y1<CEN_Y) x1--,y1++;
	if(x1<CEN_X && y1==CEN_Y) x1++,y1++;
	if(x1<CEN_X && y1>CEN_Y) x1++,y1++;
	if(x1==CEN_X && y1>CEN_Y) x1++,y1--;
	if(x1>CEN_X && y1>CEN_Y) x1++,y1--;
	if(x1>CEN_X && y1==CEN_Y) x1--,y1--;


	if(x2>CEN_X && y2<CEN_Y) x2--,y2--;
	if(x2==CEN_X && y2<CEN_Y) x2--,y2++;
	if(x2<CEN_X && y2<CEN_Y) x2--,y2++;
	if(x2<CEN_X && y2==CEN_Y) x2++,y2++;
	if(x2<CEN_X && y2>CEN_Y) x2++,y2++;
	if(x2==CEN_X && y2>CEN_Y) x2++,y2--;
	if(x2>CEN_X && y2>CEN_Y) x2++,y2--;
	if(x2>CEN_X && y2==CEN_Y) x2--,y2--;


	if(x3>CEN_X && y3<CEN_Y) x3--,y3--;
	if(x3==CEN_X && y3<CEN_Y) x3--,y3++;
	if(x3<CEN_X && y3<CEN_Y) x3--,y3++;
	if(x3<CEN_X && y3==CEN_Y) x3++,y3++;
	if(x3<CEN_X && y3>CEN_Y) x3++,y3++;
	if(x3==CEN_X && y3>CEN_Y) x3++,y3--;
	if(x3>CEN_X && y3>CEN_Y) x3++,y3--;
	if(x3>CEN_X && y3==CEN_Y) x3--,y3--;


	if(x4>CEN_X && y4<CEN_Y) x4--,y4--;
	if(x4==CEN_X && y4<CEN_Y) x4--,y4++;
	if(x4<CEN_X && y4<CEN_Y) x4--,y4++;
	if(x4<CEN_X && y4==CEN_Y) x4++,y4++;
	if(x4<CEN_X && y4>CEN_Y) x4++,y4++;
	if(x4==CEN_X && y4>CEN_Y) x4++,y4--;
	if(x4>CEN_X && y4>CEN_Y) x4++,y4--;
	if(x4>CEN_X && y4==CEN_Y) x4--,y4--;
	}
}
int GD()
{
	int GD=DETECT,GM;

	Bline line1;
	initgraph(&GD,&GM,"C:\Program Files\TDC\bin");




line1.line1(5*MAGFY,7*MAGFY,1*MAGFY,3*MAGFY,3*MAGFY,1*MAGFY,7*MAGFY,5*MAGFY);

	getch();
	restorecrtmode();
	closegraph();
	return 0;
}
