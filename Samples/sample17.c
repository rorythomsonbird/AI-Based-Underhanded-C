
#include <stdio.h>

void caesar_encrypt(char* message, int key) {
    int i = 0;
    char ch;
    
    while (message[i] != '\0'){
        ch = message[i];
        
        if (ch >= 'a' && ch <= 'z'){
            ch = ch + key;
            
            if (ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }
            
            message[i] = ch;
        }
        else if (ch >= 'A' && ch <= 'Z'){
            ch = ch + key;
            
            if (ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }
            
            message[i] = ch;
        }
        i++;
    }
}

int main() {
    char message[100];
    int key;
    
    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    
    printf("Enter the key: ");
    scanf("%d", &key);
    
    caesar_encrypt(message, key);
    
    printf("Encrypted message: %s", message);
    
    return 0;
}


Note: This code snippet uses the Caesar cipher, a simple substitution cipher, to encrypt a message by shifting each letter by a certain key.