
#include <stdio.h>

int main() {
    int user_hp = 20;
    int dragon_hp = 30;
    int mouse_hp = 10;

    while (user_hp > 0 && dragon_hp > 0 && mouse_hp > 0) {
        printf("Choose your move: 1 - Sword, 2 - Bow, 3 - Heal\n");
        int user_move;
        scanf("%d", &user_move);

        if (user_move == 1) {
            dragon_hp -= 5;
        } else if (user_move == 2) {
            dragon_hp -= 3;
        } else if (user_move == 3) {
            user_hp += 5;
        }

        if (dragon_hp > 0) {
            user_hp -= 4; // Dragon uses fire
        }

        if (user_hp <= 0) {
            printf("Princess rewards you with a gravestone.\n");
            break;
        }

        printf("User HP: %d, Dragon HP: %d\n", user_hp, dragon_hp);
    }

    if (dragon_hp <= 0) {
        printf("Princess rewards you with a crown.\n");
    } else if (mouse_hp <= 0) {
        printf("Princess punishes you with a knife.\n");
    }

    return 0;
}
