#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../lib/conversions.h"
#include "../../lib/scoring.h"

int main() {
    const char* hex = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
    unsigned char bytes[512];
    unsigned char decrypted[512];
    size_t bytes_len;

    hex_to_bytes(hex, bytes, &bytes_len);

    int best_score = 0;
    unsigned char best_key = 0;
    unsigned char best_decryption[512];

    for (int key = 0; key < 256; ++key) {
        for (size_t i = 0; i < bytes_len; ++i) {
            decrypted[i] = bytes[i] ^ key;
        }

        int score = score_plaintext(decrypted, bytes_len);
        if (score > best_score) {
            best_score = score;
            best_key = key;
            memcpy(best_decryption, decrypted, bytes_len);
        }
    }

    best_decryption[bytes_len] = '\0'; // Null terminate the string
    printf("Key: %c, Score: %d, Decrypted Text: %s\n", best_key, best_score, best_decryption);

    return 0;
}
