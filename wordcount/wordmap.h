
#define TABLE_SIZE 5 

struct wordMap {
    char* word;
    int value;
    struct wordMap* next;
};
typedef struct wordMap word_map_t;
typedef word_map_t* word_map;

word_map initWordMap();

int hash(char* word);

void insertWord(word_map wordMap, char* word,int value); 
void deleteWord(word_map wordMap, char* word); 

word_map_t* getWordNode(word_map wordMap, char* word);
int getWordValue(word_map wordMap, char* word); 

void printMap(word_map wordMap);