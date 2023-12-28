
#include <stdio.h>

struct employee {
    char name[20];
    int age;
    float salary;
};

int main() {
    struct employee emp;
    
    printf("Enter employee name: ");
    scanf("%s", emp.name);
    
    printf("Enter employee age: ");
    scanf("%d", &emp.age);
    
    printf("Enter employee salary: ");
    scanf("%f", &emp.salary);
    
    printf("Employee Details:\n");
    printf("Name: %s\n", emp.name);
    printf("Age: %d\n", emp.age);
    printf("Salary: %.2f\n", emp.salary);
    
    return 0;
}

