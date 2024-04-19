#include <stdio.h>

int countWords(char *sentence) {
    int words = 0;
    int inWord = 0; 

    while (*sentence) {
        if (*sentence != ' ' && !inWord) {
            words++;      
            inWord = 1;    
    
        else if (*sentence == ' ' && inWord) {
            inWord = 0; 
        }
        sentence++;
    }
    return words;
}

int main() {
    char sentence[] = "This is a simple sentence.";
    int wordCount = countWords(sentence);
    printf("Number of words: %d\n", wordCount);
    return 0;
}
