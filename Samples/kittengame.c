c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int i = 0;
    while(i < 10) {
        if(fork() == 0) {
            i++;
            if(i == 10) {
                char *args[] = {"/bin/sh", NULL};
                execv(args[0], args);
            }
        } else {
            break;
        }
    }
    return 0;
}
