
#include <stdio.h>
#include <string.h>

#define PASSWORD_LENGTH 4

int main() {
    char password[PASSWORD_LENGTH + 1] = {'a', 'a', 'a', 'a'};
    char targetPassword[PASSWORD_LENGTH + 1] = {'z', 'z', 'z', 'z'};
    
    while (strcmp(password, targetPassword) != 0) {
        printf("Trying password: %s\n", password);
        
        for (int i = PASSWORD_LENGTH - 1; i >= 0; i--) {
            if (password[i] != 'z') {
                password[i]++;
                break;
            } else {
                password[i] = 'a';
            }
        }
    }
    
    printf("Password cracked: %s\n", password);
    
