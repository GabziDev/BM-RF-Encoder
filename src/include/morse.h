//
// Created by ggabz on 15.03.2025.
//

#ifndef BM_RF_ENCODER_MORSE_H
#define BM_RF_ENCODER_MORSE_H

#define MORSE_TABLE_SIZE (sizeof(morseTable) / sizeof(morseTable[0]))

struct Morse {
    const char c;
    const char code[5];
};

// https://fr.wikipedia.org/wiki/Code_Morse_international
static struct Morse morseTable[] = {
        {.c = 'A', .code = ".-"},
        {.c = 'B', .code = "-..."},
        {.c = 'C', .code = "-.-."},
        {.c = 'D', .code = "-.."},
        {.c = 'E', .code = "."},
        {.c = 'F', .code = "..-."},
        {.c = 'G', .code = "--."},
        {.c = 'H', .code = "...."},
        {.c = 'I', .code = ".."},
        {.c = 'J', .code = ".---"},
        {.c = 'K', .code = "-.-"},
        {.c = 'L', .code = ".-.."},
        {.c = 'M', .code = "--"},
        {.c = 'N', .code = "-."},
        {.c = 'O', .code = "---"},
        {.c = 'P', .code = ".--."},
        {.c = 'Q', .code = "--.-"},
        {.c = 'R', .code = ".-."},
        {.c = 'S', .code = "..."},
        {.c = 'T', .code = "-"},
        {.c = 'U', .code = "..-"},
        {.c = 'V', .code = "...-"},
        {.c = 'W', .code = ".--"},
        {.c = 'X', .code = "-..-"},
        {.c = 'Y', .code = "-.--"},
        {.c = 'Z', .code = "--.."},
        {.c = '0', .code = "-----"},
        {.c = '1', .code = ".----"},
        {.c = '2', .code = "..---"},
        {.c = '3', .code = "...--"},
        {.c = '4', .code = "....-"},
        {.c = '5', .code = "....."},
        {.c = '6', .code = "-...."},
        {.c = '7', .code = "--..."},
        {.c = '8', .code = "---.."},
        {.c = '9', .code = "----."}
};

#endif //BM_RF_ENCODER_MORSE_H
