#ifndef XOR_OPERATIONS_H
#define XOR_OPERATIONS_H

#include <stdlib.h>

unsigned char find_best_key(const unsigned char* bytes, size_t bytes_len);
void single_byte_xor(const unsigned char* input, size_t len, unsigned char key, unsigned char* output);

#endif
