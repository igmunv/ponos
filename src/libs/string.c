#include "string.h"

char scancode_to_ascii(unsigned char scancode, unsigned char shift_state){

    if (shift_state){

        // - - SHIFT - -

        switch (scancode){

            // Numbers
            case 2: return '!';
            case 3: return '@';
            case 4: return '#';
            case 5: return '$';
            case 6: return '%';
            case 7: return '^';
            case 8: return '&';
            case 9: return '*';
            case 10: return '(';
            case 11: return ')';

            // Letters
            case 16: return 'Q';
            case 17: return 'W';
            case 18: return 'E';
            case 19: return 'R';
            case 20: return 'T';
            case 21: return 'Y';
            case 22: return 'U';
            case 23: return 'I';
            case 24: return 'O';
            case 25: return 'P';

            case 30: return 'A';
            case 31: return 'S';
            case 32: return 'D';
            case 33: return 'F';
            case 34: return 'G';
            case 35: return 'H';
            case 36: return 'J';
            case 37: return 'K';
            case 38: return 'L';

            case 44: return 'Z';
            case 45: return 'X';
            case 46: return 'C';
            case 47: return 'V';
            case 48: return 'B';
            case 49: return 'N';
            case 50: return 'M';

            // Special symbols
            case 12: return '_';
            case 13: return '+';
            case 26: return '{';
            case 27: return '}';
            case 39: return ':';
            case 40: return '"';
            case 51: return '<';
            case 52: return '>';
            case 53: return '?';

            // Special keys
            case 57: return ' '; // Space

            default: return '\0'; // If different, then 0
        }

    }
    else{

        // - - WITHOUT SHIFT - -

        switch (scancode){

            // Numbers
            case 2: return '1';
            case 3: return '2';
            case 4: return '3';
            case 5: return '4';
            case 6: return '5';
            case 7: return '6';
            case 8: return '7';
            case 9: return '8';
            case 10: return '9';
            case 11: return '0';

            // Letters
            case 16: return 'q';
            case 17: return 'w';
            case 18: return 'e';
            case 19: return 'r';
            case 20: return 't';
            case 21: return 'y';
            case 22: return 'u';
            case 23: return 'i';
            case 24: return 'o';
            case 25: return 'p';

            case 30: return 'a';
            case 31: return 's';
            case 32: return 'd';
            case 33: return 'f';
            case 34: return 'g';
            case 35: return 'h';
            case 36: return 'j';
            case 37: return 'k';
            case 38: return 'l';

            case 44: return 'z';
            case 45: return 'x';
            case 46: return 'c';
            case 47: return 'v';
            case 48: return 'b';
            case 49: return 'n';
            case 50: return 'm';

            // Special symbols
            case 12: return '-';
            case 13: return '=';
            case 26: return '[';
            case 27: return ']';
            case 39: return ';';
            case 40: return '\'';
            case 51: return ',';
            case 52: return '.';
            case 53: return '/';

            // Special keys
            case 57: return ' '; // Space

            default: return '\0'; // If different, then 0
        }
    }
}



int str_equal(unsigned char* str1,unsigned char* str2,int size){
    for (int i = 0; i < size; i++){
        if (str1[i] != str2[i]) return -1;
    }
    return 1;
}
