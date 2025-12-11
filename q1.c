#include <stdio.h>
#include <string.h>

struct Flight
{
    char flightNumber[20];
    char departureCity[50];
    char destinationCity[50];
    char date[20];
    int availableSeats;
};

void displayFlight(struct Flight f)
{
    printf("\n--- Flight Details ---\n");
    printf("Flight Number:   %s\n", f.flightNumber);
    printf("Route:           %s to %s\n", f.departureCity, f.destinationCity);
    printf("Date:            %s\n", f.date);
    printf("Available Seats: %d\n", f.availableSeats);
    printf("----------------------\n");
}

void bookSeat(struct Flight *f)
{
    if (f->availableSeats > 0)
    {
        f->availableSeats--;
        printf("\n[Success] Seat booked! Remaining seats: %d\n", f->availableSeats);
    }
    else
    {
        printf("\n[Error] Sorry, this flight is fully booked.\n");
    }
}

int main()
{
    struct Flight f1;
    printf("Enter Flight Number:");
    scanf("%s", f1.flightNumber);
    printf("Enter Departure City:");
    scanf(" %[^\n]s", f1.departureCity);
    printf("Enter Destination City:");
    scanf(" %[^\n]s", f1.destinationCity);
    printf("Enter Date:");
    scanf(" %[^\n]s", f1.date);
    f1.availableSeats = 5; // assume

    int choice;
    do
    {
        printf("\n1. Display Flight Details\n");
        printf("2. Book a Seat\n");
        printf("0. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            displayFlight(f1);
            break;
        case 2:
            // Pass the adress of f1
            bookSeat(&f1);
            break;
        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid option.\n");
        }
    } while (choice != 0);

    return 0;
}