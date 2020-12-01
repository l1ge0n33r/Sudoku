#include <iostream>
#include <stdio.h>




/*
    TODO:
    

    - gui 

    - control 

*/
using namespace std;

const char guiText[][32] = {
    "            Sudoku             ",
    "            ======             ",
    "                               ",
    "                               ",
    "         1 - 9 : set number    ",
    "             0 : remove number ",
    "             Q : exit          ",
    "             S : show solution ",
    "             R : restart game  "
};

#define N 9
int wherNum=0;
int Grow, Gcol, Gnum;
int grid[N][N] = {
   {3, 0, 6, 5, 0, 8, 4, 0, 0},
   {5, 2, 0, 0, 0, 0, 0, 0, 0},
   {0, 8, 7, 0, 0, 0, 0, 3, 1},
   {0, 0, 3, 0, 1, 0, 0, 8, 0},
   {9, 0, 0, 8, 6, 3, 0, 0, 5},
   {0, 5, 0, 0, 9, 0, 6, 0, 0},
   {1, 3, 0, 0, 0, 0, 2, 5, 0},
   {0, 0, 0, 0, 0, 0, 0, 7, 4},
   {0, 0, 5, 2, 0, 6, 3, 0, 0}
};
int tmp_grid[N][N];

bool isPresentInRow(int row, int num)
{
    bool b = false;
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num) b= true;
    if(b == true) wherNum += 1;
    return b; 
}

bool isPresentInCol(int col, int num)
{
    bool b = false;
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num) b= true; 
    if (b == true)wherNum += 2;
    return b;
}

bool isPresentInBox(int boxStartRow, int boxStartCol, int num)
{
    bool b = false;
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row + boxStartRow][col + boxStartCol] == num)
                b =  true; 
    if (b == true)wherNum += 4;
    return b;
}

bool finEmptyPlace(int& row, int& col)
{
    for (row = 0; row < N; row++)
    {
        for (col = 0; col < N; col++)
            if (grid[row][col] == 0) return true;
    }
}

bool isValidPlace(int row, int col, int num) {
    wherNum = 0;
    
    if (num == -1) { return false; }
    //when item not found in col, row and current 3x3 box
    else return !isPresentInRow(row, num) && !isPresentInCol(col, num) && !isPresentInBox(row - row % 3, col - col % 3, num);
}

bool isSolved()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] == 0)
                return false;
        }
    }
    return true;
}

void sudokuGrid() { //print the sudoku grid after solve
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (col == 3 || col == 6)
                cout << " | ";
            cout << grid[row][col] << " ";
        }
        if (row == 2 || row == 5) {
            cout << endl;
            for (int i = 0; i < N; i++)
                cout << "---";
        }
        cout << endl;
    }
}

void charCheck(char c) 
{       
        
    if(c>=49 && c<= 57)
    {
        
        scanf_s("%d ", &Gcol);
        scanf_s("%d", &Gnum);printf("%d",c);
        Grow = c - 48;
    }
    switch (c)
    {

    default:
        break;
    }
}


void guiBottom() 
{
    char c=0;

    //1 
    if (wherNum == 0)
 {
        printf("Enter num of row, column and number to put: ");
        scanf_s("%c ", &c);
        charCheck(c);

       --Grow;
        --Gcol;
 }
    //2    
 else {
        cout << "The number is already in: ";
        if (wherNum & 0b001) cout << "row ";
        if (wherNum & 0b010) cout << "column ";
        if (wherNum & 0b100) cout << "box";
        wherNum = 0;
        Grow = Gcol = 0;
        Gnum = -1;
        system("pause");
        
    }




   
 }

void Game()
{
    //solveSudoku();
    for (int line = 0; line < 9; line++) {
        puts(guiText[line]);
    }
    system("pause"); 
    wherNum = 0;
    while (true) 
    {  // kmp
        system("cls");
        sudokuGrid();
        guiBottom();
        
        if(isValidPlace(Grow, Gcol, Gnum))grid[Grow][Gcol]=Gnum;
        if (isSolved()) break;
    }
}

int main() {
    wherNum = 0;
    Game();
}
/*
bool solveSudoku()
{
    int row, col;

    if (!finEmptyPlace(row, col))
        return true;

    for (int num = 1; num <= 9; num++)
    {
        if (isValidPlace(row, col, num))
        {
            tmp_grid[row][col] = num;
            if (solveSudoku())
                return true;
            tmp_grid[row][col] = 0;
        }
    }
    return false;
}*/