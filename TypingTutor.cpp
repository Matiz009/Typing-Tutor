#include <iostream>
#include <conio.h>
#include <Windows.h>         
#include <time.h>

using namespace std;

class node
{
public:
  char value;
  int xCordinate;            
  int YCordinate;
  node *next;
};

void
gotoxy (short x, short y)
{
  COORD pos = { x, y };
  SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), pos);
}

void printStatus (node * temp, int score, int hit);

int   
main ()
{
  srand (time (0));
  int Score = 0;
  int hits = 0;
  char ch;
  int x, y;
  node *temp = NULL;
  node *Point = new node;
  node *End = Point;
  Point->value = '0' + rand () % 10;
  Point->xCordinate = rand () % 50;
  Point->YCordinate = 0;
  Point->next = NULL;
  while (Score != 100 && Point->YCordinate != 21)
    {
      Sleep (1000);
      system ("cls");
      printStatus (Point, Score, hits);

      if (kbhit ())
	{
	  ch = getch ();
	  if (ch == Point->value)
	    {
	      temp = Point;
	      Point = temp->next;
	      delete (temp);
	      temp = NULL;
	      Score += 10;
	      hits++;
	    }
	  if (int (ch) == 27)
	    break;
	}

      temp = new node;
      End->next = temp;
      End = temp;
      temp = NULL;
      End->value = '0' + rand () % 10;
      End->xCordinate = rand () % 50;
      End->YCordinate = 0;
      End->next = NULL;


    }
  if (Score == 100)
    {
      cout << "\n\nYou won the match!!\n";
    }
  else
    {
      cout << "\n\nYou Lost the match!!\n";
    }

}

void
printStatus (node * temp, int score, int hit)
{
  int x, y, i = 0;
  while (temp != NULL)
    {
      x = temp->xCordinate;
      y = temp->YCordinate;
      gotoxy (x, y);
      cout << temp->value;
      temp->YCordinate++;
      temp = temp->next;
    }
  gotoxy (i, 20);
  while (i <= 100)
    {
      cout << "-";
      i++;
    }
  gotoxy (0, 22);
  cout << "Score = " << score;
  cout << "\t\tHits = " << hit;
  cout << "\nRequired Score = 100";

}
