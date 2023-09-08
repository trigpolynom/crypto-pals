// xor_operations.c

#include "xor_operations.h"
#include "scoring.h"
#include <string.h>
#include <stdio.h>
#

unsigned char find_best_key(const unsigned char* bytes, size_t bytes_len) {
    unsigned char best_key = 0;
    int best_score = -1;
    unsigned char decrypted[512];

    if(bytes_len > 512) {
        fprintf(stderr, "Error: Buffer size exceeded\n");
        return 0;
    }

    for (unsigned char key = 0; key <= 255; key++) {
        single_byte_xor(bytes, bytes_len, key, decrypted);
        int score = score_plaintext(decrypted, bytes_len);
        
        if (score > best_score) {
            best_score = score;
            best_key = key;
        }
    }

    return best_key;
}

void single_byte_xor(const unsigned char* input, size_t len, unsigned char key, unsigned char* output) {
    for (size_t i = 0; i < len; i++) {
        output[i] = input[i] ^ key;
    }
}