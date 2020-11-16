#include<iostream>
#include <stdlib.h>
#include<conio.h>
#include<time.h>


#define TEST 0



using namespace std;
int board[9][9] = { 
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0}
},
block[3][3]
;

void drawBoard()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			switch (board[i][j])
			{
			case 0:
				cout << ' ';
				break;
			case 1:		
				cout << 1;
				break;
			case 2:		
				cout << 2;
				break;
			case 3:		
				cout << 3;
				break;
			case 4:		
				cout << 4;
				break;
			case 5:		
				cout << 5;
				break;
			case 6:		
				cout << 6;
				break;
			case 7:		
				cout << 7;
				break;
			case 8:		
				cout << 8;
				break;
			case 9:
				cout << 9;
				break;
			default:
				break;
			}
			
		}
		cout << endl;
	}
}
void Generate(bool c1, bool c2 , bool c3)
{
	int posx, posy, val;

	
		
		
	

	if (c1 ==true) 
	{	
		posx = rand() % 10;
	}

	if (c2 == true) 
	{
		posy = rand() % 10;
	}

	if (c3 == true) 
	{
		val = rand() % 9 + 1;
	}
	board[posx][posy] = val;

}
void Generate() 
{
	int posx, posy, val;

	posx = rand() % 10;
	posy = rand() % 10;
	val = rand() % 9+1;

	board[posx][posy] = val;
}



void Validation(bool generation) 
{

	if (generation == true) 
	{

	}
	else
	{

	}
}
void Input() 
{
	char posx, posy,c = '-';
	if (TEST == 1) 
	{
	Generate(true,true,true);
	}

	else
	{
		cout << "Enter position of number: ";
		while (c != '\n') {
			
			while (true)
			{
				c = _getch();
				if (c == '1'||
					c == '2'||
					c == '3'||
					c == '4'||
					c == '5'||
					c == '6'||
					c == '7'||
					c == '8'||
					c == '9')break;
				else continue;
			}
			_putch(c);
			putchar(' ');

			while (true)
			{
				c = _getch();
				if (c == '1' ||
					c == '2' ||
					c == '3' ||
					c == '4' ||
					c == '5' ||
					c == '6' ||
					c == '7' ||
					c == '8' ||
					c == '9')break;
				else continue;
			}
			_putch(c);

			
			c = getchar();

		}
	}
	system("pause");
}
void Logic() 
{
	srand(time(NULL));
	cout << "" << endl;

	while (true) 
	{
		drawBoard();
		Input();
		Validation(false);
		system("cls");
	}
}

int main() 
{
	Logic();
}





/*
			while (
				c != '1' &&
				c != '2' &&
				c != '3' &&
				c != '4' &&
				c != '5' &&
				c != '6' &&
				c != '7' &&
				c != '8' &&
				c != '9'
				)
			{
				c = getchar();
				putchar(c);
			} 

			putchar(' ');
			posx = c;

			while (
				c != '1' &&
				c != '2' &&
				c != '3' &&
				c != '4' &&
				c != '5' &&
				c != '6' &&
				c != '7' &&
				c != '8' &&
				c != '9'
				)
			{
				c = getchar();
				putchar(c);
			}

			putchar(c);
			putchar(' ');
			
			c = getchar();
		} 
*/