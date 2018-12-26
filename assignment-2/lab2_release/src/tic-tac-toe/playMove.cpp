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

void playMove(int board[3][3], int row, int col, bool& turn, bool& validMove, bool& gameOver, int& winCode) {

    // If the game is over, do nothing
    if (gameOver) return;

    // Insert your code here
    isValidMove(board, row, col, validMove);
    if (validMove) {
        board[row][col] = turn;
        cout << "playMove: " << board[row][col] << endl;
        getWinCode(board, turn, winCode);
        cout << "playMove: turn: " << turn << endl;
        turn = !turn;
        cout << "playMove: turn after: " << turn << endl;
    }

    // The function must always print the output specified in the handout before it exits
    // Use the standard output (i.e., cout) to print the output

    // Insert code to print the output below
    cout << board[0][0] << " " 
            << board[0][1] << " " 
            << board[0][0] << " "
            << board[0][0] << " "
            << board[0][0] << " "
            << board[0][0] << " "
            << board[0][0] << " "
            << board[0][0] << " "
            << board[0][0] << " "
            << row << " "
            << col << " "
            << turn << " "
            << validMove << " "
            << gameOver << endl;
    
    if (winCode != 0 || (isBoardFull(board) && winCode == 0))
        gameOver = true;

}

void isValidMove(int board[3][3], int row, int col, bool& isValid) {
    if (board[row][col] == Empty) {
        cout << "isValidMove: row: " << row << " col: " << col << " is valid" << endl;
        isValid = true;
    } else {
        cout << "isValidMove: row: " << row << " col: " << col << " is not valid" << endl;
        isValid = false;
    }
}

void getWinCode (int board[3][3], bool& turn, int& winCode) {
    if (board[0][0] == turn && board[0][1] == turn && board[0][2] == turn) {
        winCode = 1; // row 0
    } else if (board[1][0] && turn && board[1][1] == turn && board[1][2] == turn) {
        winCode = 2; // row 1
    } else if (board[2][0] && board[2][1] && board[2][2] == turn) {
        winCode = 3; // row 2
    } else if (board[0][0] && board[1][0] && board[2][0] == turn) {
        winCode = 4; // col 0
    } else if (board[0][1] && board[1][1] && board[1][2] == turn) {
        winCode = 5; // col 1
    } else if (board[0][2] && board[1][2] && board[2][2] == turn) {
        winCode = 6; // col 2
    } else if (board[0][0] && board[1][1] && board[2][2] == turn) {
        winCode = 7; // left to right
    } else if (board[2][0] && board[1][1] && board[0][2] == turn) {
        winCode = 8; // right to left
    } else {
        winCode = 0; // no win or draw
    }
}

bool isBoardFull(int gameBoard[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (gameBoard[i][j] == Empty)
                return false; // empty cell
        }
    }
    return true; // no empty cells

}
