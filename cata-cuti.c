#include<stdio.h>

void printBoard();
int checkWin();

char n[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void main()
{
    int player = 1, input, status = -1;
    char mark;

    do {
        printBoard();
        player = (player % 2) ? 1 : 2;
        mark = (player == 1) ? 'X' : 'O';

        printf("Player %d, enter a number: ", player);
        scanf("%d", &input);

        if(input < 1 || input > 9 || n[input] == 'X' || n[input] == 'O') {
            printf("Invalid move! Please try again.\n");
            continue;
        }

        n[input] = mark;
        status = checkWin();

        player++;
    } while(status == -1);

    printBoard();

    if(status == 1)
        printf("==> Player %d wins!\n", --player);
    else
        printf("==> Game draw!\n");
}

void printBoard() {
    printf("\n\n");
    printf(" -: Tic-Tac-Toe :-\n\n");
    printf("      |     |     \n");
    printf("   %c  |  %c  |  %c  \n", n[1], n[2], n[3]);
    printf(" _____|_____|_____\n");
    printf("      |     |     \n");
    printf("   %c  |  %c  |  %c  \n", n[4], n[5], n[6]);
    printf(" _____|_____|_____\n");
    printf("      |     |     \n");
    printf("   %c  |  %c  |  %c  \n", n[7], n[8], n[9]);
    printf("      |     |     \n\n");
}

int checkWin() {
    // Checking rows for a win
    if (n[1] == n[2] && n[2] == n[3])
        return 1;
    else if (n[4] == n[5] && n[5] == n[6])
        return 1;
    else if (n[7] == n[8] && n[8] == n[9])
        return 1;

    // Checking columns for a win
    else if (n[1] == n[4] && n[4] == n[7])
        return 1;
    else if (n[2] == n[5] && n[5] == n[8])
        return 1;
    else if (n[3] == n[6] && n[6] == n[9])
        return 1;

    // Checking diagonals for a win
    else if (n[1] == n[5] && n[5] == n[9])
        return 1;
    else if (n[3] == n[5] && n[5] == n[7])
        return 1;

    // Checking for a draw
    else if (n[1] != '1' && n[2] != '2' && n[3] != '3' && n[4] != '4' &&
             n[5] != '5' && n[6] != '6' && n[7] != '7' && n[8] != '8' && n[9] != '9')
        return 0;
    else
        return -1;
}
