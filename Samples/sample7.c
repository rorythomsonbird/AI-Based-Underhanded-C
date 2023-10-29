
#include <stdio.h>

struct Car {
    char manufacturer[20];
    char model[20];
    int year;
};

int main() {
    struct Car myCar;
    strcpy(myCar.manufacturer, "Honda");
    strcpy(myCar.model, "Civic");
    myCar.year = 2021;
    
    printf("My car is a %s %s, manufactured in %d.\n", myCar.manufacturer, myCar.model, myCar.year);
    
    return 0;
}

