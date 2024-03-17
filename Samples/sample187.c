
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
