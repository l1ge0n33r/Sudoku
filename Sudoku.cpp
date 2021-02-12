#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define N 9



using namespace std;
bool gameover = true;
const char guiText[][32] = {
    "            Sudoku             ",
    "            ======             ",
    "       by Wowk Alexandr        ",
    "            ======             "
};

const int grid[9][9] = {
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
int slv_grid[N][N];

void fillSlv()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            slv_grid[i][j] = grid[i][j];
        }
    }
}

bool isOverLayed(int row, int col, int val)
{
    if (val != 0)
    {
        if (grid[row][col] != val)
        {
            return false;
        }
        else return true;
    }
    else return false;
}

int isPresentInRow(int row, int num)
{

    for (int col = 0; col < 9; col++) {
        if (slv_grid[row][col] == num) return 1;
    }

    return 0;
}

int isPresentInCol(int col, int num)
{

    for (int row = 0; row < N; row++) {
        if (slv_grid[row][col] == num) return 2;
    }

    return 0;
}

int isPresentInBox(int boxStartRow, int boxStartCol, int num)
{

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (slv_grid[row + boxStartRow][col + boxStartCol] == num)
                return 4;
        }
    }

    return 0;
}

bool findEmptyPlace(int& row, int& col)
{
    for (row = 0; row < N; row++)
    {
        for (col = 0; col < N; col++)
            if (slv_grid[row][col] == 0) return true;
    }
}

int isValidPlace(int row, int col, int num) {

    if (num == -1) { return 0; }

    else return isPresentInRow(row, num) + isPresentInCol(col, num) + isPresentInBox(row - row % 3, col - col % 3, num);
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

void sudokuGrid() {
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            if (col == 3 || col == 6)
                cout << " | ";
            cout << slv_grid[row][col] << " ";
        }
        if (row == 2 || row == 5) {
            cout << endl;
            for (int i = 0; i < N; i++)
                cout << "---";
        }
        cout << endl;
    }
}



void Game()
{
    int valout = 0;
    int row = 0, column = 0, value = -1;
    char c;
idk:
    system("cls");

    sudokuGrid();
    cout << "\n\n Use q to quit game \n Use 0 to erase number in place\n Use e to enter number\n";
    cout << " Enter char of action: ";
    cin >> c;

    if (c == 'q')gameover = true;
    else if (c == 's') goto idk;
    else if (c == '0') 
    {
        system("cls");
        sudokuGrid();
        cout << "Enter row: ";
        cin >> row;
        cout << "Enter column: ";
        cin >> column;

        slv_grid[row-1][column-1] = 0;

    }
    else if (c == 'e') {

        system("cls");
        sudokuGrid();
        cout << "Enter row: ";
        cin >> row;
        cout << "Enter column: ";
        cin >> column;
        cout << "Enter value: ";
        cin >> value;


        valout = isValidPlace(row - 1, column - 1, value);


        if (valout != 0 && !isOverLayed(row - 1, column - 1, value))
        {
            system("cls");

            sudokuGrid();
            cout << "The number is already in: ";
            if (valout & 0b001) cout << " row";
            if (valout & 0b010) cout << " column";
            if (valout & 0b100) cout << " box";

        }
        else
        {
            slv_grid[row - 1][column - 1] = value;
        }
        system("pause");
    }
}

int main() {
    fillSlv();
    gameover = false;

    for (int line = 0; line < 4; line++) {
        puts(guiText[line]);
    }
    system("pause");

    while (!isSolved() && !gameover)
    {
        Game();
    }
    if (isSolved()) cout << "Congratulations! You solved sudoku!";
    system("pause");
    return 0;
}
