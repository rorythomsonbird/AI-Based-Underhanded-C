
#include <stdio.h>

int calculateDistance(int speed, int time) {
    return speed * time;
}

int main() {
    int carSpeed = 60;
    int travelTime = 2;
    
    int distance = calculateDistance(carSpeed, travelTime);
    
    printf("The car traveled %d km.\n", distance);
    
    return 0;
}

