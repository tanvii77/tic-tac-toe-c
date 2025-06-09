#include <stdio.h>

char board[3][3];
int currentPlayer = 1;

void initializeBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

void printBoard() {
    printf("-------------\n");
    for (int i = 0; i < 3; i++) {
        printf("| ");
        for (int j = 0; j < 3; j++) {
            printf("%c | ", board[i][j]);
        }
        printf("\n-------------\n");
    }
}

char checkWinner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];

    return ' ';
}

int isDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return 0;
    return 1;
}

void playMove() {
    int row, col;
    char symbol = currentPlayer == 1 ? 'X' : 'O';

    printf("Player %d [%c], enter your move (row [0-2] and column [0-2]): ", currentPlayer, symbol);
    scanf("%d %d", &row, &col);

    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = symbol;
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    } else {
        printf("Invalid move. Try again.\n");
    }
}

int main() {
    initializeBoard();

    while (1) {
        printBoard();
        playMove();

        char winner = checkWinner();
        if (winner != ' ') {
            printBoard();
            printf("Player %c wins!\n", winner);
            break;
        }

        if (isDraw()) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }
    }

    return 0;
}
