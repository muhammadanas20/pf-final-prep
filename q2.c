#include <stdio.h>
#include <string.h>

#define MAX_MOVIES 100

typedef struct
{
    char title[100];
    char genre[30];
    char director[50];
    int releaseYear;
    float rating;
} Movie;

void addMovie(Movie library[], int *count)
{
    if (*count >= MAX_MOVIES)
    {
        printf("Database full!\n");
        return;
    }

    printf("\nEnter Movie Title: ");
    scanf(" %[^\n]", library[*count].title);

    printf("Enter Genre (e.g., Action, Drama): ");
    scanf(" %[^\n]", library[*count].genre);

    printf("Enter Director: ");
    scanf(" %[^\n]", library[*count].director);

    printf("Enter Release Year: ");
    scanf("%d", &library[*count].releaseYear);

    printf("Enter Rating (0-10): ");
    scanf("%f", &library[*count].rating);

    (*count)++; // Increase the total count of movies
    printf("[Success] Movie added.\n");
}

void searchByGenre(Movie library[], int count)
{
    char searchGenre[30];
    int found = 0;

    printf("\nEnter genre to search: ");
    scanf(" %[^\n]", searchGenre);

    printf("\n--- Search Results for '%s' ---\n", searchGenre);
    for (int i = 0; i < count; i++)
    {
        if (strcasecmp(library[i].genre, searchGenre) == 0)
        {
            printf("Found: %s (%d) | Director: %s | Rating: %.1f\n",
                   library[i].title, library[i].releaseYear,
                   library[i].director, library[i].rating);
            found = 1;
        }
    }

    if (!found)
        printf("No movies found in that genre.\n");
}

void displayAll(Movie library[], int count)
{
    printf("\n--- All Movies ---\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d. %s (%d) [%s]\n", i + 1, library[i].title, library[i].releaseYear, library[i].genre);
    }
}

int main()
{
    Movie library[MAX_MOVIES];
    int movieCount = 0;
    int choice;

    do
    {
        printf("1. Add Movie\n2. Search by Genre\n3. Display All\n0. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addMovie(library, &movieCount);
            break;
        case 2:
            searchByGenre(library, movieCount);
            break;
        case 3:
            displayAll(library, movieCount);
            break;
        case 0:
            printf("Program existing.....\n");
            break;
        }
    } while (choice != 0);

    return 0;
}