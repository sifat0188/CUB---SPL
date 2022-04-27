#include "windows.h"

#include <iostream>

#include <string>

#include <ctime>

using namespace std;

// ******Console boilerplate ******* // 
// required for font colors 
#define CONSO GetConsoleScreenBufferInfo

#define GREEN   10

#define CYAN    11

#define RED     12

#define MAGENTA 13

#define YELLOW  14

#define WHITE   15

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

// ******Project Starts Here ******* // 
// ******function declarations  **** // 
void showAppName();

void getInput(BOOL);

BOOL checkLeap();

BOOL printCalendar(int);

void printAppointments();

void pause();

int getNumber();

// ********************************** // 
// ****variables for the project  *** // 
int day, month, year, appointmentDay;

string appointmentText;

// ********************************** // 
int main(void)
{

  setTextColor(WHITE);

menu:
  // show the app logo 
  showAppName();

  setCursor(3, 20);

  // show the options menu 
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

    // leap year check 
  case 1:
    {

      // get the year to be checked 
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

    // show calendar 
  case 2:
    {

    getmon:
      // get month, year from the user 
      getInput(1);

      // remove appointments 
      appointmentDay = -1;

      // print calendar 
      if(!printCalendar(8))
      {

        // if it fails get a date again 
        setCursor(23, 20);

        setTextColor(RED);

        cout << "Calendar dates bad. ";

        cout << "Enter again...";

        // pause so that the user 
        // can see the message 
        pause();

        setTextColor(WHITE);

        goto getmon;

      }

      else 
      {

        setCursor(23, 20);

        cout<<"Done. Press any key...";

        // pause so that the user 
        // can see the message 
        pause();

        goto menu;

      }

    }

    // schedule an appointment 
  case 3:
    {

    getday:
      // get the date, month and year 
      getInput(1);

      setCursor(7, 20);

      cout << "Enter day: ";

      appointmentDay = getNumber();

      setCursor(9, 20);

      // get the appointment text 
      cout << "Enter text[25-chars]:";

      getline(cin, appointmentText);

      // trim to 25 chars 
      if(appointmentText.size() > 25)
      {

        appointmentText.erase(25);

      }

      showAppName();

      // print calendar 
      if(printCalendar(4))
      {

        // show appointments 
        printAppointments();

        setCursor(23, 20);

        cout <<"Done. Press any key...";

        pause();

      }

      else 
      {

        // if errors, ask dates again 
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

  // reset console settings so that 
  // the console returns back to 
  // the default state 
  SetConsoleTextAttribute(
  h, csbiInfo.wAttributes);

  return 0;

}

// ********************************** // 
void showAppName()
{

  system("cls");

  setCursor(1, 25);

  cout << "HOVEN CALENDAR APP";

  setCursor(10, 3);

  setTextColor(GREEN);

  // make any logo on the left 
  for(int x =0; x < 5; x++)
  {

    setCursor(2 + x, 3 + x);

    cout << "//";

    setCursor(2 + x, 12 - x);

    cout << "//";

  }

  setCursor(6, 6);

  cout << "HOVEN";

  setTextColor(WHITE);

}

// ********************************** // 
// **** obtain month and year // 
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

// ********************************** // 
// **** verify the data as a date // 
int checkDate()
{

  tm t = {0, 0, 0, day, month, year};

  // mktime function validates the 
  // combination of day, month, year 
  // as a valid date 
  if(mktime(&t) < 0)
  {

    return -1;

  }

  // error in day? return failed 
  if(day != t.tm_mday)
  {

    return -1;

  }

  // error in month? return failed 
  if(month != t.tm_mon)
  {

    return -1;

  }

  // error in year? return failed 
  if(year != t.tm_year)
  {

    return -1;

  }

  // return day of the week 
  // sun = 0, onwards 
  return t.tm_wday;

}

// ********************************** // 
BOOL checkLeap()
{

  day = 29;

  month = 1;

  return checkDate() >= 0;

}

// ********************************** // 
BOOL printCalendar(int fromRow)
{

  day = 1;

  // if the date is invalid 
  // calendar should not be shown 
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

      // mon 
    case 1:
      {

        setCursor(row, 20);

      }

      break;

      // tue 
    case 2:
      {

        setCursor(row, 24);

      }

      break;

      // wed 
    case 3:
      {

        setCursor(row, 28);

      }

      break;

      // thu 
    case 4:
      {

        setCursor(row, 32);

      }

      break;

      // fri 
    case 5:
      {

        setCursor(row, 36);

      }

      break;

      // sat 
    case 6:
      {

        // cyan color for sat weekend 
        setTextColor(CYAN);

        setCursor(row, 40);

      }

      break;

      // sun 
    case 0:
      {

        // cyan color for sun weekend 
        setTextColor(CYAN);

        setCursor(row, 44);

        // after sunday next row 
        row += 2;

      }

      break;

    default:
      {

        // calendar done 
        return TRUE;

      }

    }

    // yellow color for appointments 
    if(appointmentDay >= 1)
    {

      if(appointmentDay == day)
      {

        setTextColor(YELLOW);

      }

      // second dummy date of 
      // 17 used but project 
      // must be extended to support 
      // multiple dates 
      if(17 == day)
      {

        setTextColor(YELLOW);

      }

    }

    printf("%2d", day++);

    setTextColor(WHITE);

  }

}

// ********************************** // 
void printAppointments()
{

  setTextColor(GREEN);

  // print a vertical line to the 
  // right of the calendar 
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

  // dummy date of 17 also used 
  // but project must be extended 
  // to support multiple dates 
  cout << "17 - for a dinner!";

  setTextColor(WHITE);

}

// ********************************** // 
// **** obtain a numeric input // 
int getNumber()
{

  // best approach is to get the 
  // input as a string and then 
  // convert it to integer 
  string s;

  getline(cin, s);

  return atoi(s.c_str());

}

// ********************************** // 
// **** a dummy pause // 
void pause()
{

  string s;

  getline(cin, s);

}
