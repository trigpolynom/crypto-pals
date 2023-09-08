//scoring.c

#include "scoring.h"
#include <ctype.h>

int score_plaintext(const unsigned char* text, size_t len) {
    int score = 0;
    for (size_t i = 0; i < len; i++) {
        if (isalpha(text[i]) || text[i] == ' ') {
            score++;
        }
    }
    return score;
}
