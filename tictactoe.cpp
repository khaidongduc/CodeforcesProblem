/// https://codeforces.com/problemset/problem/3/C
#include <iostream>

using namespace std;

char board[3][3];

bool isCWinRow(char c, int row) {
    for (int i = 0; i < 3; ++i)
        if (board[row][i] != c) return false;
    return true;
}

bool isCWinCol(char c, int col) {
    for (int i = 0; i < 3; ++i)
        if (board[i][col] != c) return false;
    return true;
}

bool isCWinMainDiag(char c) {
    for (int i = 0; i < 3; ++i)
        if (board[i][i] != c) return false;
    return true;
}

bool isCWinSubDiag(char c) {
    for (int i = 0; i < 3; ++i)
        if (board[i][2 - i] != c) return false;
    return true;
}

bool isCWin(char c) {
    for (int i = 0; i < 3; ++i) {
        if (isCWinRow(c, i) || isCWinCol(c, i)) return true;
    }
    return isCWinMainDiag(c) || isCWinSubDiag(c);
}

string getRes(){
    int xCount = 0, oCount = 0;
    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == 'X') ++xCount;
            if (board[i][j] == '0') ++oCount;
        }
    }
    bool is0Win = isCWin('0');
    bool isXWin = isCWin('X'); 

    if(xCount != oCount && xCount != oCount + 1) return "illegal";
    if(!is0Win && !isXWin){
        if(xCount + oCount == 9) return "draw";
        if(xCount == oCount) return "first";
        if(xCount == oCount + 1) return "second";
        return "illegal";
    }
    if(is0Win && isXWin) return "illegal";

    if(isXWin) {
        if(oCount == xCount) return "illegal";
        return "the first player won";
    }
    if(is0Win) {
        if(oCount != xCount) return "illegal";
        return "the second player won";
    }
    return "illegal";
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("main.inp", "r", stdin);
#endif
    for (int i = 0; i < 3; ++i) cin >> board[i];
    cout << getRes();
}