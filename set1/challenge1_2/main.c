#include <stdio.h>
#include <stdlib.h>
#include "../../lib/conversions.h"

void fixed_xor(const unsigned char* bytes1, const unsigned char* bytes2, unsigned char* result, size_t len) {
    for (size_t i = 0; i < len; i++) {
        result[i] = bytes1[i] ^ bytes2[i];
    }
}

int main() {
    const char* hex1 = "1c0111001f010100061a024b53535009181c";
    const char* hex2 = "686974207468652062756c6c277320657965";
    unsigned char bytes1[512];
    unsigned char bytes2[512];
    unsigned char result[512];
    char result_hex[1024];
    size_t bytes_len1, bytes_len2;

    hex_to_bytes(hex1, bytes1, &bytes_len1);
    hex_to_bytes(hex2, bytes2, &bytes_len2);

    if (bytes_len1 != bytes_len2) {
        printf("Error: Input strings have different lengths\n");
        return 1;
    }

    fixed_xor(bytes1, bytes2, result, bytes_len1);
    bytes_to_hex(result, bytes_len1, result_hex);

    printf("Result: %s\n", result_hex);
    return 0;
}
