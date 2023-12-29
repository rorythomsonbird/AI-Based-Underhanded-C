c
#include <stdio.h>

int main() {
    int message[] = {0x48 ^ 0x12, 0x65 ^ 0x34, 0x6C ^ 0x56, 0x6C ^ 0x78, 0x6F ^ 0x9A, 0x2C ^ 0xBC, 0x20 ^ 0x1A, 0x57 ^ 0x2B, 0x6F ^ 0x4C, 0x72 ^ 0x6D, 0x6C ^ 0x8F, 0x64 ^ 0x9A, 0x21 ^ 0xAB, 0x0A ^ 0xCD, 0x00 ^ 0xEF};
    for (int i = 0; i < sizeof(message) / sizeof(message[0]); i++) {
        putchar(message[i]);
    }
    return 0;
}


In this version, the ASCII values of each character in the "Hello, World!" message are XORed with a constant value to obfuscate the message. The `putchar` function is then used to print each obfuscated character to the console. Finally, the `main` function returns 0 to indicate successful program execution.