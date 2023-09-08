#ifndef CONVERSIONS_H
#define CONVERSIONS_H

#include <stdlib.h>

void hex_to_bytes(const char* hex, unsigned char* bytes, size_t* bytes_len);
void bytes_to_hex(const unsigned char* bytes, size_t bytes_len, char* hex);
void bytes_to_base64(const unsigned char* bytes, size_t bytes_len, char* base64);

#endif
