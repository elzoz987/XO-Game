#include <iostream>
using namespace std;

void displayBoard(const char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << " " << board[i][j] << " ";
            if (j < 2)
            {
                cout << "|";
            }
        }
        cout << endl;
        if (i < 2)
            cout << "---+---+---" << endl;
    }
}

bool isValidMove(const char board[3][3], int row, int col)
{
    if (col <= 2 && col >= 0 &&
        row <= 2 && row >= 0 &&
        board[row][col] == ' ')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void takeMove(int &row, int &col)
{
    cout << "Enter Row (0-2)";
    cin >> row;
    cout << endl;
    cout << "Enter column(0-2)";
    cin >> col;
}
void updateBoard(char board[3][3], int row, int col, char currentPlayer)
{
    board[row][col] = currentPlayer;
}

bool checkWin(const char board[3][3], char currentPlayer)
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == currentPlayer &&
            board[i][1] == currentPlayer &&
            board[i][2] == currentPlayer)
        {
            return true;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == currentPlayer &&
            board[1][i] == currentPlayer &&
            board[2][i] == currentPlayer)
        {
            return true;
        }
    }
    if (board[0][0] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][2] == currentPlayer)
    {
        return true;
    }

    if (board[0][2] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][0] == currentPlayer)
    {
        return true;
    }
    return false;
}

bool checkDraw(const char board[3][3]){
     for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}
void PlayGame(){
    char baord[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
   
    char  currentPlayer = 'X';
    bool run =true;
    int row, col;
    while (run){
         displayBoard(baord);
         takeMove(row , col);
       
         while (   isValidMove(baord,row , col)==false){
             takeMove(row , col);

         }
         updateBoard(baord,row ,col ,currentPlayer );
         if (checkWin(baord ,currentPlayer)==true){
            displayBoard(baord);
          cout << "Player " << currentPlayer << " wins!" << endl;
            run = false ;
         }else if (checkDraw(baord)==true ){
              displayBoard(baord);
             cout << "Draw";
            run = false ;
         } else {
            if (currentPlayer=='X'){
                currentPlayer = 'O';

            }else {
                    currentPlayer = 'X'; 
            }
         } 



    }

}

int main()
{
       PlayGame();

    return 0;
}