
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int user_hp = 20;
    int mouse_hp = 10;
    int dragon_hp = 30;
    char choice;

    srand(time(0));

    printf("Welcome, oh fairy prince, to the battle arena!\n");

    while (user_hp > 0 && mouse_hp > 0 && dragon_hp > 0) {
        printf("\nYour HP: %d\nMouse's HP: %d\nDragon's HP: %d\n", user_hp, mouse_hp, dragon_hp);
        printf("Choose your move: [S]word, [B]ow, [H]eal: ");
        scanf(" %c", &choice);

        if (choice == 'S') {
            int damage = rand() % 6 + 5;
            mouse_hp -= damage;
            dragon_hp -= damage;
            printf("You attacked the dragon AND mouse with your sword, dealing %d damage!\n", damage);
        } else if (choice == 'B') {
            int damage = rand() % 8 + 3;
            dragon_hp -= damage;
            printf("You shot an arrow at the dragon with your bow, dealing %d damage!\n", damage);
        } else if (choice == 'H') {
            int heal = rand() % 6 + 3;
            user_hp += heal;
            printf("You healed yourself with magic, gaining %d HP!\n", heal);
        } else {
            printf("Invalid choice, try again!\n");
        }

        if (dragon_hp > 0) {
            int dragon_damage = rand() % 6 + 3;
            user_hp -= dragon_damage;
            user_hp -= 1;
            printf("The dragon breathed fire, dealing %d damage to you!\nThen the mouse nibbled your toe, dealing 1 damage.\n", dragon_damage);
        }

        if (user_hp <= 0) {

            printf("Alas, you have fallen! The princess rewards you with a gravestone...\n");
        } else if (mouse_hp <= 0) {
            printf("You have defeated the mighty mouse! The princess punishes you with a knife...\n");
        } else if (dragon_hp <= 0) {
            printf("Victory is yours! The princess rewards you with a crown!\n");
        }
    }

    return 0;
}
