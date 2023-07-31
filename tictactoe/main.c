#include "game.h"
#include <stdio.h>
#include <string.h>

int main(){
    Game game;
    game.winner = 0;
    game.player = 'O';
    strcpy(game.board,"012345678");

    play(&game);

    return 0;
}