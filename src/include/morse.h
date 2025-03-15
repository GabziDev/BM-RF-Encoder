//
// Created by ggabz on 15.03.2025.
//

#ifndef BM_RF_ENCODER_MORSE_H
#define BM_RF_ENCODER_MORSE_H

#define MORSE_TABLE_SIZE (sizeof(morseTable) / sizeof(morseTable[0]))

struct Morse {
    const char lettre;
    const char code[5];
};

// https://fr.wikipedia.org/wiki/Code_Morse_international
static struct Morse morseTable[] = {
        {.lettre = 'A', .code = ".-"},
        {.lettre = 'B', .code = "-..."},
        {.lettre = 'C', .code = "-.-."},
        {.lettre = 'D', .code = "-.."},
        {.lettre = 'E', .code = "."},
        {.lettre = 'F', .code = "..-."},
        {.lettre = 'G', .code = "--."},
        {.lettre = 'H', .code = "...."},
        {.lettre = 'I', .code = ".."},
        {.lettre = 'J', .code = ".---"},
        {.lettre = 'K', .code = "-.-"},
        {.lettre = 'L', .code = ".-.."},
        {.lettre = 'M', .code = "--"},
        {.lettre = 'N', .code = "-."},
        {.lettre = 'O', .code = "---"},
        {.lettre = 'P', .code = ".--."},
        {.lettre = 'Q', .code = "--.-"},
        {.lettre = 'R', .code = ".-."},
        {.lettre = 'S', .code = "..."},
        {.lettre = 'T', .code = "-"},
        {.lettre = 'U', .code = "..-"},
        {.lettre = 'V', .code = "...-"},
        {.lettre = 'W', .code = ".--"},
        {.lettre = 'X', .code = "-..-"},
        {.lettre = 'Y', .code = "-.--"},
        {.lettre = 'Z', .code = "--.."},
        {.lettre = '0', .code = "-----"},
        {.lettre = '1', .code = ".----"},
        {.lettre = '2', .code = "..---"},
        {.lettre = '3', .code = "...--"},
        {.lettre = '4', .code = "....-"},
        {.lettre = '5', .code = "....."},
        {.lettre = '6', .code = "-...."},
        {.lettre = '7', .code = "--..."},
        {.lettre = '8', .code = "---.."},
        {.lettre = '9', .code = "----."}
};

#endif //BM_RF_ENCODER_MORSE_H
