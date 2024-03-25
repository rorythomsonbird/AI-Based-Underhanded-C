
#include <stdio.h>
#include <stdlib.h>

void exploreSea();
void makeFriends();
void organiseBeachParty();

int main() {
    printf("Welcome to the Underwater Adventure Game!\n");
    printf("Help the mermaid explore the sea, make friends, and organize a beach party!\n");

    int choice;
    do {
        printf("\n1. Explore the sea\n");
        printf("2. Make friends\n");
        printf("3. Organize a beach party\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                exploreSea();
                break;
            case 2:
                makeFriends();
                break;
            case 3:
                organiseBeachParty();
                break;
            case 4:
                printf("Thanks for playing! Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 4);

    return 0;
}

void exploreSea() {
    printf("\nYou dive deep into the sea and discover a hidden treasure chest!\n");
    printf("Do you want to open it? (1. Yes / 2. No): ");
    int openChoice;
    scanf("%d", &openChoice);

    if(openChoice == 1) {
        printf("You found a magical pearl that grants you the ability to talk to sea creatures!\n");
    } else {
        printf("You decide to leave the treasure chest for another day.\n");
    }
}

void makeFriends() {
    printf("\nYou encounter a friendly dolphin who wants to play with you!\n");
    printf("Do you want to play with the dolphin? (1. Yes / 2. No): ");
    int playChoice;
    scanf("%d", &playChoice);

    if(playChoice == 1) {
        printf("You and the dolphin have a great time playing together!\n");
    } else {
        printf("The dolphin looks a bit sad, maybe next time you can play with it.\n");
    }
}

void organiseBeachParty() {
    printf("\nIt's time to organize a beach party for all your new friends!\n");
    printf("What kind of food do you want to prepare? (1. Seaweed salad / 2. Fish tacos): ");
    int foodChoice;
    scanf("%d", &foodChoice);

    if(foodChoice == 1) {
        printf("The seaweed salad is a hit among your friends! The party is a success!\n");
    } else {
        printf("The fish tacos are a bit too fishy for some of your friends, but overall the party is fun!\n");
    }
}
