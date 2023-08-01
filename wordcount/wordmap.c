
#include "wordmap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


word_map initWordMap() {
    word_map_t* wordMap = calloc(sizeof(word_map_t),TABLE_SIZE);
    return wordMap;
}

int hash(char* word) {
    int hash = 1;
    for (int i = 0; i < strlen(word); i++) {
        hash += word[i]; 
        hash *= (word[i] % 7);
    }
    return hash % TABLE_SIZE; 
}


void insertWord(word_map wordMap, char* word,int value) {
    int index = hash(word);

    word_map_t* node = &wordMap[index];

    if (node->word == NULL) {
        node->word = word;
        node->value = value;
        return;
    }

    while (node->word != NULL){
        if (node->word == word){
            node->value = value;
            return; 
        } else if (node->next == NULL){
            word_map_t* wp = malloc(sizeof(word_map_t));
            wp->word = word;
            wp->value = value;
            node->next = wp;
            return;
        }
        node = node->next;
    }
}

void deleteWord(word_map wordMap, char* word) {

    word_map_t* wnode = getWordNode(wordMap,word);
    if (wnode != NULL) {
        word_map_t* next = wnode->next;
        wnode->word = next->word;
        wnode->value = next->value;
        wnode->next = next->next;
        free(next);
    }

}

word_map_t* getWordNode(word_map wordMap, char* word){
    int index = hash(word);
    word_map_t* node = &wordMap[index];
    
    while ( node != NULL)
    {
        if(node->word == word) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

int getWordValue(word_map wordMap, char* word) {
    word_map_t* wnode = getWordNode(wordMap,word);

    if (wnode != NULL) {
        return wnode->value;
    }
    return 0;
}

void printMap(word_map wordMap){

    printf("--Start--\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("   %d : ",i);
        if (wordMap[i].word == NULL) {
            printf("<empty> \n");
        } else {

            word_map_t start = wordMap[i];
            word_map_t* node = &start;

            while (node != NULL) {
                printf(" - [%s,%d]",node->word,node->value);
                node = node->next;
            }
            printf("\n");
        }
    }
    printf("---End---\n");
}