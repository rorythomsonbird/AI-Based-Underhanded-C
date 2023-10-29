
#include <stdio.h>

int main() {
    const float fuelEfficiency = 12.5;
    int distance = 100;
    
    float fuelConsumed = distance / fuelEfficiency;
    
    printf("The car consumed %.2f liters of fuel.\n", fuelConsumed);
    
    return 0;
}
