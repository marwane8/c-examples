#include "game.h"
#include <stdio.h>
#include <stdbool.h>

void printBoard(const char board[10]){
    printf("\n %c | %c | %c \n",board[0],board[1],board[2]);
    printf("-----------\n");
    printf(" %c | %c | %c\n",board[3],board[4],board[5]);
    printf("-----------\n");
    printf(" %c | %c | %c\n\n",board[6],board[7],board[8]);
};

void placeToken(Game* game) {

    int pos;

    pos = getUserInput();

    while ( game->board[pos] == 'X' || game->board[pos] == 'O' )
    {
        printf("Current position is taken! Select an Empty Space...");
        pos = getUserInput();
    }

    
    game->board[pos] = game->player;
    game->move++; 
    int count = 0;
    if (game->player == 'X') { count = 1;}
    else { count = -1;}
    checkWinner(pos,count, game);
}

void checkWinner(int pos,int count, Game* game) {
    switch (pos)
    {
    case 0:
        game->rowCount[0]+=count;
        game->colCount[0]+=count;
        game->diagCount[0]+=count;
        break;
    case 1:
        game->rowCount[0]+=count;
        game->colCount[1]+=count;
        break;
   case 2:
        game->rowCount[0]+=count;
        game->colCount[2]+=count;
        game->diagCount[1]+=count;
        break;
   case 3:
        game->rowCount[1]+=count;
        game->colCount[0]+=count;
        break;
   case 4:
        game->rowCount[1]+=count;
        game->colCount[1]+=count;
        game->diagCount[0]+=count;
        game->diagCount[1]+=count;
        break;
   case 5:
        game->rowCount[1]+=count;
        game->colCount[2]+=count;
        break;
   case 6:
        game->rowCount[2]+=count;
        game->colCount[0]+=count;
        game->diagCount[1]+=count;
        break;
   case 7:
        game->rowCount[2]+=count;
        game->colCount[2]+=count;
        break;
   case 8:
        game->rowCount[2]+=count;
        game->colCount[2]+=count;
        game->diagCount[0]+=count;
        break;
    default:
        break;
    }

    for (int i = 0; i < 3; i++){

        printf("Row %d Stat: %d\n",i,game->rowCount[i]);
        printf("Col %d Stat: %d\n",i,game->colCount[i]);

        if (game->rowCount[i] == 3 || game->colCount[i] == 3) {
            game->winner = 1;
            return;
        }

        if (game->rowCount[i] == -3 || game->colCount[i] == -3) {
            game->winner = -1;
            return;
        }
    }

    for (int i = 0; i < 2; i++){

        printf("Diag %d Stat: %d\n",i,game->diagCount[i]);

        if (game->diagCount[i] == 3) {
            game->winner = 1;
            return;
        }
        if (game->diagCount[i] == -3) {
            game->winner = -1;
            return;
        }
    }

    if (game->move == 9) {
        game->winner = 2; // Set winner to 2 for a tie
    }
}

int getUserInput() {
    int number;
    bool isValidInput = false;

    do {

        printf("\nPlease enter a number between 1 and 9:\n");
        if (scanf("%d", &number) == 1) {
            if (number >= 0 && number < 9) {
                isValidInput = true;
            } else {
                printf("Invalid Input! The Number must be between 1 and 9");
            }
        } else {
            printf("Invalid Input! Please enter an interger");
            while(getchar() != '\n'); //clearing the buffer
        }
    } while (!isValidInput);
    
    return number;
}

void play(Game* game) {
    while ( !game->winner )
    {
        game->player = (game->player == 'X') ? 'O' : 'X';

        clrscr();
        
        printf("Player %c's Turn \n",game->player);

        printBoard(game->board);
        placeToken(game);
    }


    clrscr();
    switch (game->winner)
    {
    case 1:
        printf("\nPlayer X Wins!\n");
        break;
     case -1:
        printf("\nPlayer O Wins!\n");
        break;
     case 2:
        printf("\nTie\n");
        break;
    default:
        break;
    }

    printBoard(game->board);
}
