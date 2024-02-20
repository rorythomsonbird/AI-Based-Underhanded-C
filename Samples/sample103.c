
#include "user.h"

int DERPCON_Helper(user x, user y, int current_level, int target_level);

int DERPCON(user x, user y) {
    return DERPCON_Helper(x, y, 0, -1);
}

int DERPCON_Helper(user x, user y, int current_level, int target_level) {
    if (x.user_ID == y.user_ID) {
        return current_level;
    }

    if (current_level == target_level) {
        return -1;
    }

    x.scratch = current_level;

    for (int i = 0; i < x.number_of_BFFs; i++) {
        int level = DERPCON_Helper(*(x.BFF_list[i]), y, current_level + 1, target_level);
        if (level != -1) {
            return level;
        }
    }

    return -1;
}

