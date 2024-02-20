
#include <stdio.h>
#include "network.h"

int main() {
    // Testing the DERPCON function
    user user1, user2;
    
    // Initialize user1 and user2
    
    int derpcon = DERPCON(user1, user2);
    
    printf("DERPCON level between user1 and user2: %d\n", derpcon);
    
    return 0;
}
