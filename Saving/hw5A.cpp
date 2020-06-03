#include <iostream>
#include <string>
#include <fstream>

const int SIZE = 3;
const char PLAYER = 'X';
const char COMPUTER = 'O';
const char TIE = 'T';
const char STILL_PLAY = ' ';

using namespace std;

int findBest(char board[SIZE][SIZE], int player);
bool isOpen(char board[SIZE][SIZE], int row, int col);
void copyBoard(char original[SIZE][SIZE], char copy[SIZE][SIZE]);
void print(char board[SIZE][SIZE]);
char gameOver(char board[SIZE][SIZE]);
void saveGame(char board[SIZE][SIZE]);

int main()
{
    char board[SIZE][SIZE];
    for(int i=0; i < SIZE; i++)
    {
        for(int j=0; j < SIZE; j++)
        {
            board[i][j] = '1' + 3*i+j;
        }
    }
    
    int turn = 1;
    while(gameOver(board) == STILL_PLAY)
    {
        if(turn%2 == 1)
        {
            int play; // ima uninitialized variable... nothing possibly could go wrong
            do {
                print(board);
                cout << "\nWhat number do you with to play at? (or (s)ave or (q)uit)\n";
                char cplay;
                cin >> cplay;
                cin.ignore(20000,'\n');
                if(cplay == 'q'){
                    cout << "Goodbye." << endl;
                    exit(1);
                } else if(cplay == 's'){
                    saveGame(board);
                }
                play=cplay-'0';
            } while(play<0 || play >9 || !isOpen(board, (play-1)/3, (play-1)%3));
            board[(play-1)/3][(play-1)%3] = PLAYER;
        }
        else
        {
            int bestI = -1;
            int bestJ = -1;
            int bestValue = -1;
            
            for(int i=0; i < SIZE; i++)
            {
                for(int j=0; j < SIZE; j++)
                {
                    if(isOpen(board,i,j))
                    {
                        int value = findBest(board, 1);
                        if(value > bestValue)
                        {
                            bestValue=value;
                            bestJ = j;
                            bestI = i;
                        }
                    }
                }
            }
            
            board[bestI][bestJ] = COMPUTER;
                    
        }
        turn++;
    }
    
    print(board);
    cout << "Game over!";
    if(gameOver(board) == PLAYER)
    {
        cout << "  You win!\n";
    }
    else if(gameOver(board) == COMPUTER)
    {
        cout << "  You lose!\n";
    }
    else
    {
        cout << "  Tie...\n";
    }
    
    return 0;
}

char gameOver(char board[SIZE][SIZE])
{

    for(int j=0; j<SIZE; j++)
    {
        bool win=true;
        for(int i=0; i<SIZE-1; i++)
        {
            if(board[i+1][j] != board[i][j])
            {
                win=false;
            }
        }
        if(win)
        {
            return board[0][j];
        }
    }

    for(int j=0; j<SIZE; j++)
    {
        bool win=true;
        for(int i=0; i<SIZE-1; i++)
        {
            if(board[j][i] != board[j][i+1])
            {
                win=false;
            }
        }
        if(win)
        {
            return board[j][0];
        }
    }
    
    bool win=true;
    for(int i=0; i < SIZE-1; i++)
    {
        if(board[i][i] != board[i+1][i+1])
        {
            win=false;
        }
    }
    if(win)
    {
        return board[0][0];
    }

    win=true;
    for(int i=0; i < SIZE-1; i++)
    {
        if(board[i][SIZE-1-i] != board[i+1][SIZE-1-i-1])
        {
            win=false;
        }
    }
    if(win)
    {
        return board[0][SIZE-1];
    }
    
    // above is someone wins
    
    for(int i=0; i < SIZE; i++)
    {
        for(int j=0; j < SIZE; j++)
        {
            if(isOpen(board,i,j))
            {
                return STILL_PLAY; // still playing
            }
        }
    }
    
    
    return TIE;
}

int findBest(char board[SIZE][SIZE], int player)
{
    return 0;
}

bool isOpen(char board[SIZE][SIZE], int row, int col)
{
    return board[row][col] != PLAYER && board[row][col] != COMPUTER;
}

void copyBoard(char original[SIZE][SIZE], char copy[SIZE][SIZE])
{
    for(int i=0; i < SIZE; i++)
    {
        for(int j=0; j < SIZE; j++)
        {
            copy[i][j] = original[i][j];
        }
    }
}

void saveGame(char board[SIZE][SIZE]){
    ofstream outStream;
    outStream.open("save.txt");
    if(outStream.fail()){
        cout << "Unable to open file.\n";
        exit(1);
    }
    outStream << PLAYER << ":";
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(board[i][j] == PLAYER){
                outStream << " " << i * SIZE + j + 1;
            }
        }
    }
    outStream << endl << COMPUTER << ": ";
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(board[i][j] == COMPUTER){
                outStream << " " << i * SIZE + j + 1;
            }
        }
    }
}

void print(char board[SIZE][SIZE])
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    string temp;
    for(int i=0; i < SIZE; i++)
    {
        temp = "";
        for(int j=0; j < SIZE; j++)
        {
            temp += board[i][j];
            temp += "|";
        }
        cout << temp.substr(0, temp.length()-1) << endl;;
        if(i != SIZE-1)
        {
            cout << "-----\n";
        }
    }
}
    
