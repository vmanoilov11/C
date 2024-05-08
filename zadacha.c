#include <stdio.h>
#include <stdlib.h>

struct Book {
    int id;
    char title[50];
    char author[30];
    char genre[20];
    int year;
    int isAvailable;
};

int booksByGenre(struct Book *books, int n, char *genre) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(books[i].genre, genre) == 0) {
            count++;
        }
    }
    return count;
}

int writeInfoInTextFile(struct Book *books, int n) {
    FILE *file = fopen("info.txt", "w");
    if (file == NULL) {
        return 0;
    }
    int countAvailable = 0;
    for (int i = 0; i < n; i++) {
        if (books[i].isAvailable == 1) {
            fprintf(file, "%d;%s;%s;%s;%d;\n", books[i].id, books[i].title, books[i].author, books[i].genre, books[i].year);
            countAvailable++;
        }
    }
    fclose(file);
    return countAvailable;
}

void saveBooksToBinaryFile(struct Book *books, int n) {
    FILE *file = fopen("books.bin", "wb");
    if (file == NULL) {
        return;
    }
    fwrite(books, sizeof(struct Book), n, file);
    fclose(file);
}

void readBinFile(int id) {
    FILE *file = fopen("books.bin", "rb");
    if (file == NULL) {
        return;
    }
    struct Book book;
    while (fread(&book, sizeof(struct Book), 1, file)) {
        if (book.id == id) {
            printf("Book with id = %d\n", id);
            printf("Title: %s\n", book.title);
            printf("Author: %s\n", book.author);
            printf("Genre: %s\n", book.genre);
            printf("Year: %d\n", book.year);
            printf("Is Available: %d\n", book.isAvailable);
            fclose(file);
            return;
        }
    }
    fclose(file);
    printf("Book not found.\n");
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    struct Book *books = (struct Book *)malloc(n * sizeof(struct Book));
    if (books == NULL) {
        printf("Memory allocation error!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter Info for book number %d\n", i + 1);
        printf("Id: ");
        scanf("%d", &books[i].id);

        printf("Title: ");
        scanf("%s", books[i].title);

        printf("Author: ");
        scanf("%s", books[i].author);

        printf("Genre: ");
        scanf("%s", books[i].genre);

        printf("Year: ");
        scanf("%d", &books[i].year);

        printf("Available (1 for yes, 0 for no): ");
        scanf("%d", &books[i].isAvailable);

        printf("Do you want to add more books? (y/n): ");
        char moreBooks;
        scanf(" %c", &moreBooks);
        if (moreBooks != 'y') {
            break;
        }
        int newBooksToAdd;
        printf("How many books to add?: ");
        scanf("%d", &newBooksToAdd);
        struct Book *newBooks = realloc(books, (n + newBooksToAdd) * sizeof(struct Book));
        if (newBooks == NULL) {
            printf("Memory reallocation error!\n");
            free(books);
            return 1;
        }
        books = newBooks;
        n += newBooksToAdd;
    }

    char genre[20];
    printf("Enter a genre to count books: ");
    scanf("%s", genre);
    int countBooksByGenre = booksByGenre(books, n, genre);
    printf("Books with genre %s: %d\n", genre, countBooksByGenre);

    int countAvailable = writeInfoInTextFile(books, n);
    printf("Count of available books written to info.txt: %d\n", countAvailable);

    saveBooksToBinaryFile(books, n);
    printf("Books saved to books.bin\n");

    int id;
    printf("Enter ID of a book to read from books.bin: ");
    scanf("%d", &id);
    readBinFile(id);

    free(books);
    return 0;
}
