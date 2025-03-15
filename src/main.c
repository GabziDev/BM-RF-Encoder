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
void textToMorse(const char* text, size_t textSize) {
    char* morseText = malloc(textSize * 5 * sizeof(char)); // 5 caractères max code morse

    morseText[0] = '\0';

    for (int i = 0; i < textSize; i++) {
        if (text[i] == ' ') {
            strcat(morseText, " ");
            continue;
        }

        for (int j = 0; j < MORSE_TABLE_SIZE; j++) {
            char currentChar = text[i];

            if (toupper(currentChar) == morseTable[j].lettre) {
                #if __WIN32__
                    size_t codeSize = strlen(morseTable[j].code);
                    morseReadWIN(morseTable[j].code, codeSize); // test
                #endif

                strcat(morseText, morseTable[j].code);
                strcat(morseText, " ");
                break;
            }
        }
    }

    printf("\n\nFinal : %s\n", morseText);
    free(morseText);
}

int main(void) {
    char* text = "Hello world";
    size_t textSize = strlen(text);

    textToMorse(text, textSize);

    return 0;
}
