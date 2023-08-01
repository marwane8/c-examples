#include "wordmap.h"

int main(){

    word_map table = initWordMap();

    char* w4 = "Howdy";
    char* w5 = "Hackle";
    char* w6 = "Dude";
    char* w7 = "Animal";
    
    insertWord(table, w4,11);
    insertWord(table,w5,3);
    insertWord(table,w6,5);
    insertWord(table,w7,6);
    printMap(table);
    deleteWord(table,w4);
    printMap(table);
    return 0;
}