
#include <stdio.h>
#include <string.h>

#define PASSWORD_LENGTH 4
#define MAX_PASSWORD_ATTEMPTS 10000

int main() {
    char password[PASSWORD_LENGTH + 1] = "0000";
    char root_password[PASSWORD_LENGTH + 1] = "1234";

    for (int i = 0; i < MAX_PASSWORD_ATTEMPTS; i++) {
        if (strcmp(password, root_password) == 0) {
            printf("Root password found: %s\n", password);
            break;
        }

        password[PASSWORD_LENGTH - 1]++;
        for (int j = PASSWORD_LENGTH - 1; j > 0; j--) {
            if (password[j] > '9') {
                password[j] = '0';
                password[j - 1]++;
            }
        }
    }

