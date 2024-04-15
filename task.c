#include <stdio.h>
#include <stdlib.h>
#define MAX_FLIGHTS 100

struct Flight {
    int flightNumber;
    int isDeparted;
};

void printFlights(struct Flight flights[], int numFlights) {
    printf("Active Flights:\n");
    for (int i = 0; i < numFlights; i++) {
        if (!flights[i].isDeparted) {
            printf("Flight %d\n", flights[i].flightNumber);
        }
    }
}

int main() {
    struct Flight *flights = (struct Flight*)malloc(MAX_FLIGHTS * sizeof(struct Flight));
    if (flights == NULL) {
        printf("Memory allocation failed!\n");
        return -1;
    }

    int numFlights = 0;
    int maxFlights = MAX_FLIGHTS;
    int choice, flightNum;

    do {
        printf("\nAirport menu:\n");
        printf("1. Add new flight\n");
        printf("2. Delete departed flights\n");
        printf("3. Print active flights\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (numFlights < maxFlights) {
                printf("Enter the flight number: ");
                scanf("%d", &flightNum);
                flights[numFlights].flightNumber = flightNum;
                flights[numFlights].isDeparted = 0;
                numFlights++;
            } else {
                struct Flight *temp = (struct Flight*)realloc(flights, 2 * maxFlights * sizeof(struct Flight));
                if (temp == NULL) {
                    printf("Memory reallocation failed!\n");
                    break;
                }
                flights = temp;
                maxFlights *= 2;
                printf("Memory reallocated, new maximum number of flights: %d\n", maxFlights);
            }
        } else if (choice == 2) {
            if (numFlights > 0) {
                numFlights--;
                flights[numFlights].isDeparted = 1;
                printf("Last flight removed");
            } else {
                printf("No flights to remove");
            }
        } else if (choice == 3) {
            printFlights(flights, numFlights);
        } else if (choice == 4) {
            printf("Exiting program\n");
        } else {
            printf("Invalid choice\n");
        }
    } while (choice != 4);

    free(flights);
    return 0;
}
