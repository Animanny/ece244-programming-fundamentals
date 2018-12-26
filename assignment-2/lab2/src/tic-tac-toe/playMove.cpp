//
//  playMove.cpp
//  TicTacTo
//
//  Created by Tarek Abdelrahman on 2018-05-15.
//  Copyright © 2018 Tarek Abdelrahman. All rights reserved.
//

#include <iostream>
#include <tic-tac-toe/playMove.h>

using namespace std;

int getWinCode (int gameBoard[3][3]);

bool isBoardFull(int gameBoard[3][3]);

void printSequence(int gameBoard[3][3], int row, int col, bool turn, bool validMove, bool gameOver, int winCode);


void playMove(int board[3][3], int row, int col, bool& turn, bool& validMove, bool& gameOver, int& winCode) {

    // If the game is over, do nothing
    if (gameOver) return;

    // Insert your code here
    
    // check if cell is empty
    if (board[row][col] == Empty) {
        validMove = true;
    } else {
        validMove = false;
    }
    
    // plays if cell is empty
    if (validMove) {
        if (turn) {
            board[row][col] = turn;
        } else {
            board[row][col] = -1;
        }
        turn = !turn; // switch
    }
    
    // win code    
    winCode = getWinCode(board);
    
    // check if board is full
    bool boardFull = isBoardFull(board);

    // game over 
    if (winCode != 0) {
        gameOver = true;
    } else if (winCode == 0) {
        if (boardFull){
            gameOver = true;
        }
    }

    // The function must always print the output specified in the handout before it exits
    // Use the standard output (i.e., cout) to print the output

    // Insert code to print the output below
    printSequence(board, row, col, turn, validMove, gameOver, winCode);
    // board content row col turn validmove game over win code
//    for (int i = 0; i < 3; i++) {
//        for (int j = 0; j < 3; j++) {
//            cout << board[i][j] << " ";
//        }
//    }
//    cout << row << " " << col << " " << turn << " " << validMove << " " << gameOver << " " << winCode << endl;

}

int getWinCode (int board[3][3]) {
    int winCode = 0;
    if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] != 0) {
        winCode = 1; // row 0
    }else if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] != 0){
        winCode = 2; // row 1

    } else if (board[2][0] == board[2][1] && board[2][1] == board[2][2]&& board[2][0] != 0){
        winCode = 3; // row 2

    } else if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] != 0){
        winCode = 4; //col 0

    } else if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[1][1] != 0){
        winCode = 5; // col 1

    } else if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[1][2] != 0){
        winCode = 6; // col 2

    }else if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != 0){
        winCode = 7; // left to right diagonal

    }else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != 0){
        winCode = 8; // right to left

    }else {
        winCode = 0; // no win or draw
    }
    
    return winCode;
}

bool isBoardFull (int board[3][3]) {
    bool boardFull = true;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == Empty){
                boardFull = false;
                return boardFull;
            }
        }
    }
    return boardFull;
    
}

void printSequence(int board[3][3], int row, int col, bool turn, bool validMove, bool gameOver, int winCode){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
    }
    cout << row << " " << col << " " << turn << " " << validMove << " " << gameOver << " " << winCode << endl;
}


