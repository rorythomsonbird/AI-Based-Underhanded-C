
#include <stdio.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 10

int main() {
    char password[MAX_PASSWORD_LENGTH + 1] = {0};
    char targetPassword[] = "root";
    
    for(int i = 0; i < 26; i++) {
        password[0] = 'a' + i;
        
        for(int j = 0; j < 26; j++) {
            password[1] = 'a' + j;
            
            for(int k = 0; k < 26; k++) {
                password[2] = 'a' + k;
                password[3] = '\0';
                
                if(strcmp(password, targetPassword) == 0) {
                    printf("Root password found: %s\n", password);
                    return 0;
                }
            }
        }
    }
    
    printf("Root password not found.\n");
    
