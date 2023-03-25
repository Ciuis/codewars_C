/*You have to write a function that takes for input a 8x8 chessboard in the form of a bi-dimensional array of chars (or strings of length 1, depending on the language) and returns a boolean indicating whether the king is in check.

The array will include 64 squares which can contain the following characters :

'K' for the black King;
'Q' for a white Queen;
'B' for a white Bishop;
'N' for a white kNight;
'R' for a white Rook;
'P' for a white Pawn;
' ' (a space) if there is no piece on that square.

There will always be exactly one king, which is the black king, whereas all the other pieces are white.
The board is oriented from Black's perspective.
Remember that pawns can only move and take forward.
Also be careful with the pieces' lines of sight ;-) .

The input will always be valid, no need to validate it. To help you visualize the position, tests will print a chessboard to show you the problematic cases. Looking like this :

|---|---|---|---|---|---|---|---|
|   |   |   |   |   |   |   |   |
|---|---|---|---|---|---|---|---|
|   |   |   | ♜ |   |   |   |   |
|---|---|---|---|---|---|---|---|
|   |   |   |   |   |   |   |   |
|---|---|---|---|---|---|---|---|
|   |   |   | ♔ |   |   |   |   |
|---|---|---|---|---|---|---|---|
|   |   |   |   |   |   |   |   |
|---|---|---|---|---|---|---|---|
|   |   |   |   |   |   |   |   |
|---|---|---|---|---|---|---|---|
|   |   |   |   |   |   |   |   |
|---|---|---|---|---|---|---|---|
|   |   |   |   |   |   |   |   |
|---|---|---|---|---|---|---|---|*/

#include <stdbool.h>

bool king_is_in_check (const char chessboard[8][8]);

int main(void) {

}

bool king_is_in_check (const char chessboard[8][8]) {
    int row = -1;
    int column = -1;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (chessboard[i][j] == 'K') {
                row = i; column = j;
            }
        }
    }

    int queen_moves[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};
    for (int i = 0; i < 8; ++i) {
        int x_coord = row + queen_moves[i][0];
        int y_coord = column + queen_moves[i][1];
        while (x_coord >= 0 && x_coord < 8 && y_coord >= 0 && y_coord < 8) {
            if (chessboard[x_coord][y_coord] != ' ') {
                if (i < 4 && (chessboard[x_coord][y_coord] == 'R' || chessboard[x_coord][y_coord] == 'Q')) return true;
                else if (i >= 4 && (chessboard[x_coord][y_coord] == 'B' || chessboard[x_coord][y_coord] == 'Q')) return true;
                else break;
            }
            x_coord += queen_moves[i][0];
            y_coord += queen_moves[i][1];
        }
    }

    int knight_moves[8][2] = {{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
    for (int i = 0; i < 8; ++i) {
        int new_row = row + knight_moves[i][0];
        int new_column = column + knight_moves[i][1];
        if (new_row >= 0 && new_row < 8 && new_column >= 0 && new_column < 8) {
            if (chessboard[new_row][new_column] == 'N') return true;
        }
    }

    if (row > 0) {
        if (column > 0) {
            if (chessboard[row-1][column-1] == 'P') return true;
        }
        if (column < 7) {
            if (chessboard[row-1][column+1] == 'P') return true;
        }
    }

    return false;

}