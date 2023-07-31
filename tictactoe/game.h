

#define clrscr() printf("\e[1;1H\e[2J");

typedef struct {
    char player;
    char board[10];
    int winner;
    int move;
    int rowCount[3];
    int colCount[3];
    int diagCount[2];
} Game;

void printBoard(const char board[10]);
void placeToken(Game* game);
int getUserInput();
void checkWinner(int pos,int count, Game* game);
void play(Game* game);