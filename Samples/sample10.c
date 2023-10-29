
#include <stdio.h>

int main() {
    int mileage = 50000;
    int maintenanceThreshold = 60000;
    
    if (mileage >= maintenanceThreshold) {
        printf("Maintenance required.\n");
    } else {
        printf("No maintenance required yet.\n");
    }
    
    return 0;
}

