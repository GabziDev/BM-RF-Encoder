#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>
#include <unistd.h>
#include "include/morse.h"

// Read morse code with console beep
void morseReadWIN(const char* code, size_t codeSize) {
    printf("%s ", code);

    for (int i = 0; i < codeSize; i++) {
        if (code[i] == '.') {
            system("powershell.exe -Command \"[console]::beep(200, 50)\"");
        } else if (code[i] == '-') {
            system("powershell.exe -Command \"[console]::beep(200, 150)\"");
        }
    }

    usleep(250000);
}

// Convert text to morse
void textToMorse(const char *text, size_t textSize, char **morse) {
    *morse = malloc(textSize * 5 * sizeof(char)); // 5 caractères max code morse
    *morse[0] = '\0';

    for (int i = 0; i < textSize; i++) {
        if (text[i] == ' ') {
            strcat(*morse, " ");
            continue;
        }

        for (int j = 0; j < MORSE_TABLE_SIZE; j++) {
            char currentChar = text[i];

            if (toupper(currentChar) == morseTable[j].c) {
                #if __WIN32__
                    size_t codeSize = strlen(morseTable[j].code);
                    morseReadWIN(morseTable[j].code, codeSize); // test
                #endif
                strcat(*morse, morseTable[j].code);
                strcat(*morse, "/");
                break;
            }
        }
    }
}

// convert decimal to binary
void decimalToBinary(int decimal, char *octet) {
    // init octet avec 8 zero
    for (int i = 7; i >= 0; i--) {
        octet[i] = (decimal % 2) + '0';
        decimal /= 2;
    }

    octet[8] = '\0';
}

// convert text to binary
void textToBinary(const char *text, size_t textSize, char **binary) {
    *binary = malloc((textSize * 9 + 1) * sizeof(char));
    *binary[0] = '\0';

    char octet[9];
    for (size_t i = 0; i < textSize; i++) {
        decimalToBinary((unsigned char)text[i], octet);  // convertir chaque char en binaire
        strcat(*binary, octet);
    }
}

int main(void) {
    char *text = "Hello world";
    size_t textSize = strlen(text);

    char *morse = NULL;
    char *binary = NULL;

    textToMorse(text, textSize, &morse);
    printf("\n\nMorse : %s\n", morse);

    textToBinary(text, textSize, &binary);
    printf("\n\nBinary : %s\n", binary);

    free(morse);
    free(binary);

    return 0;
}
