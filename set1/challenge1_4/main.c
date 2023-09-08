#include <stdio.h>
#include <string.h>
#include "../../lib/conversions.h"
#include "../../lib/scoring.h"
#include "../../lib/xor_operations.h"

#define MAX_LINE_LENGTH 512

int decrypt_line(const char* hex_str, char* output) {
    size_t bytes_len;
    unsigned char bytes[512];
    
    hex_to_bytes(hex_str, bytes, &bytes_len);

    printf("Hex string: %s\n", hex_str);
    printf("Bytes: ");
    for (size_t i = 0; i < bytes_len; i++) {
        printf("%02x ", bytes[i]);
    }
    printf("\n");

    unsigned char key = find_best_key(bytes, bytes_len);
    
    single_byte_xor(bytes, bytes_len, key, (unsigned char*)output);
    
    printf("Decrypted line: %s\n", output);

    return score_plaintext((unsigned char*)output, bytes_len);
}



int main() {
    FILE* file = fopen("/home/trigpolynom/quantumcrypto/cryptopals/set1/challenge1_4/4.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    char best_line[MAX_LINE_LENGTH];
    int best_score = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        line[strcspn(line, "\n")] = '\0';  // Strip newline character from the end of the line

        char decrypted_line[MAX_LINE_LENGTH];
        int score = decrypt_line(line, decrypted_line);

        if (score > best_score) {
            best_score = score;
            strcpy(best_line, decrypted_line);
        }

        printf("Current best score: %d\n", best_score);  // Print the current best score
    }

    fclose(file);
    printf("Best line: %s\n", best_line);

    return 0;
}

