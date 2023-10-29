
#include <stdio.h>

int accelerate(int speed, int increment) {
    return speed + increment;
}

int main() {
    int currentSpeed = 50;
    int increment = 20;
    
    int newSpeed = accelerate(currentSpeed, increment);
    
    printf("The car's new speed is %d km/h.\n", newSpeed);
    
    return 0;
}

