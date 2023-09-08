//conversions.c

#include "conversions.h"
#include <string.h>
#include <stdio.h>

static const char b64_table[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void hex_to_bytes(const char* hex, unsigned char* bytes, size_t* bytes_len) {
    size_t len = strlen(hex);
    printf("Length: %zu\n", len);

    if (len % 2 != 0) {
        fprintf(stderr, "Error: Odd-length hex string\n");
        *bytes_len = 0;
        return;
    }
    size_t i;
    for (i = 0; i < len; i += 2) {
        sscanf(hex + i, "%2hhx", &bytes[i / 2]);
    }
    *bytes_len = len / 2;
}


void bytes_to_base64(const unsigned char* bytes, size_t bytes_len, char* base64) {
    size_t i, j = 0;
    unsigned int octet_a, octet_b, octet_c, triple;

    for (i = 0; i < bytes_len; i += 3) {
        octet_a = i < bytes_len ? bytes[i] : 0;
        octet_b = i + 1 < bytes_len ? bytes[i + 1] : 0;
        octet_c = i + 2 < bytes_len ? bytes[i + 2] : 0;

        triple = (octet_a << 0x10) + (octet_b << 0x08) + octet_c;

        base64[j++] = b64_table[(triple >> 3 * 6) & 0x3F];
        base64[j++] = b64_table[(triple >> 2 * 6) & 0x3F];
        base64[j++] = b64_table[(triple >> 1 * 6) & 0x3F];
        base64[j++] = b64_table[(triple >> 0 * 6) & 0x3F];
    }

    // Fix padding
    if (bytes_len % 3 == 2) {
        base64[j++] = '=';
    } else if (bytes_len % 3 == 1) {
        base64[j++] = '=';
        base64[j++] = '=';
    }

    base64[j] = '\0';  // Null terminate the string
}

void bytes_to_hex(const unsigned char* bytes, size_t bytes_len, char* hex) {
    size_t i;
    for (i = 0; i < bytes_len; i++) {
        sprintf(hex + (i * 2), "%02x", bytes[i]);
    }
    hex[bytes_len * 2] = '\0';
}