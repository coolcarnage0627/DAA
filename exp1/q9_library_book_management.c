#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char title[50];
    char author[50];
    int totalCopies;
    int availableCopies;
};

int main(void) {
    struct Book books[100];
    int choice, count = 0, i, searchId;

    do {
        printf("\nLibrary Menu\n");
        printf("1. Add Book\n2. Search Book\n3. Issue Book\n4. Return Book\n5. Display Unavailable Books\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Book ID: ");
                scanf("%d", &books[count].id);
                printf("Enter title: ");
                scanf("%s", books[count].title);
                printf("Enter author: ");
                scanf("%s", books[count].author);
                printf("Enter total copies: ");
                scanf("%d", &books[count].totalCopies);
                books[count].availableCopies = books[count].totalCopies;
                count++;
                printf("Book added successfully.\n");
                break;

            case 2:
                printf("Enter Book ID to search: ");
                scanf("%d", &searchId);
                for (i = 0; i < count; i++) {
                    if (books[i].id == searchId) {
                        printf("Book found: ID=%d, Title=%s, Author=%s, Available=%d\n",
                               books[i].id, books[i].title, books[i].author, books[i].availableCopies);
                        break;
                    }
                }
                if (i == count) printf("Book not found.\n");
                break;

            case 3:
                printf("Enter Book ID to issue: ");
                scanf("%d", &searchId);
                for (i = 0; i < count; i++) {
                    if (books[i].id == searchId) {
                        if (books[i].availableCopies > 0) {
                            books[i].availableCopies--;
                            printf("Book issued successfully.\n");
                        } else {
                            printf("No copies available.\n");
                        }
                        break;
                    }
                }
                if (i == count) printf("Book not found.\n");
                break;

            case 4:
                printf("Enter Book ID to return: ");
                scanf("%d", &searchId);
                for (i = 0; i < count; i++) {
                    if (books[i].id == searchId) {
                        if (books[i].availableCopies < books[i].totalCopies) {
                            books[i].availableCopies++;
                            printf("Book returned successfully.\n");
                        } else {
                            printf("All copies are already available.\n");
                        }
                        break;
                    }
                }
                if (i == count) printf("Book not found.\n");
                break;

            case 5:
                printf("Unavailable books:\n");
                for (i = 0; i < count; i++) {
                    if (books[i].availableCopies == 0) {
                        printf("ID=%d, Title=%s, Author=%s\n",
                               books[i].id, books[i].title, books[i].author);
                    }
                }
                break;

            case 6:
                printf("Exiting library system.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}
