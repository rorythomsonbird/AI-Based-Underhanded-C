#include <stdio.h>

void function() {
    char buffer[64];
    char *p;
    asm("lea 4(%%ebp),%0" : "=r" (p));  // loads address of return address
    printf("%d\n", p - buffer);         // computes offset
    buffer[p - buffer] += 9;            // 9 from disassembling main
}

int main() {
    volatile int x = 7;
    function();
    x++;
    printf("x = %d\n", x); // prints 7, not 8
}