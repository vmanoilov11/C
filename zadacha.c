#include <stdio.h>
#include <stdlib.h>

struct Book{
    int id;
    char title[50];
    char author[30];
    char genre[20];
    int year;
    int isAvailable;
    
}
 
int booksByGenre(struct Book *books, int n, char genre){}

int writeInfoInTextFile(){}

void saveBooksToBinaryFile(){}

void readBinFile(){}

int main(){
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    
    struct Book *books = (struct Book *books)malloc(n * sizeof(struct Book));
    if(books == NULL){
        printf("Error!");
        return 1;
    }
    for(int i=0; i < n;i++){
        printf("Enter Info for book number %d\n", i+1);
        printf("Id: ");
        scanf("%d",books[i].id);
        
        printf("Title: ");
        scanf("%s",books[i].title);
        
        printf("Author: ");
        scanf("%s",books[i].author);
        
        printf("Genre: ");
        scanf("%s",books[i].author);
        
        printf("year: ");
        scanf("%d",books[i].year);
        
        printf("Available: ");
        scanf("%d",books[i].isAvailable);
        
        char moreBooks;
        printf("Type y for yes or n for no");
        scanf("%c", &moreBooks);
        
        if(moreBooks == "y"){
            int newBooksToAdd;
            printf("How many books to add?: ");
            scanf("%d", &newBooksToAdd);
            struct Book *newBooks = realloc(books,(n + newBooksToAdd)*sizeof(struct Book));
            
            if(newBooks == NULL){
                printf("Error memory");
                return 1;
            }else{
                books = newBooks;
            }
        }
        char genre[20];
        printf("Genre: ");
        scanf("%s", genre);
        int countBooksByGenre = booksByGenre(books, n, genre);
        printf("Books with genre - %s : %d", genre, countBooksByGenre);
        
        
        
    }
    free(books);
return 0;
}
