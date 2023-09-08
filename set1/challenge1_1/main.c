#include <stdio.h>
#include <stdlib.h>
#include "../../lib/conversions.h"

int main() {
    const char* hex = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    unsigned char bytes[512];
    size_t bytes_len;
    char base64[1024];

    hex_to_bytes(hex, bytes, &bytes_len);
    bytes_to_base64(bytes, bytes_len, base64);

    printf("Base64: %s\n", base64);
    return 0;
}
