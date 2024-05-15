#include <iostream>
#include <vector>
using namespace std;

void printMatrix(vector<vector<char>>& board){
    for(int i=0; i<3 ; i++){
        for( int j=0 ; j<3 ; j++){
            cout << board[i][j] <<" ";
        }
        cout << endl ;
    }
}

char checkWinner(vector<vector<char>>& board){
    // checking rows 
    for(int i=0; i<3; i++){
        if( board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ' ){
            return board[i][0] ;
        }
    }

    // checking columns
    for(int i=0; i<3; i++){
        if( board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ' ){
            return board[0][i] ;
        }
    }

    //checking diagonals 
    if( board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' '){
        return board[0][0] ;
    }
    if( board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ' ){
        return board[0][2] ;
    }

    // no winner
    return ' ';
}

int main(){
    vector<vector<char>> board(3, vector<char>(3,' '));
    bool firstTurn = true ;
    int moves = 0 ;

    // game started
    while(true){
        printMatrix(board) ;

        char symbol = firstTurn ? 'X' : 'O' ;
        string playerName = firstTurn ? "player1" : "player2" ;

        int row, col ;
        cout << playerName <<", enter your move (row column): ";
        cin >> row >> col ;

        if( row<0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ' ){
            cout << "invalid move! try again." << endl;
            continue;
        }

        board[row][col] = symbol ;
        moves++;

        char winner = checkWinner(board) ;
        if( winner != ' ' || moves == 9 ){
            printMatrix(board) ;
            if( winner != ' '  ){
                cout << "Player " << (( winner == 'X' ) ? "1" : "2") << "wins!" << endl;
                break;
            } 
            else{
                cout << "It's a draw!" << endl;
            }
        }
        firstTurn = !firstTurn;
    } 

    return 0;
}