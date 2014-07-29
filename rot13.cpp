/*
 * rot13 generic hash function.
 * By Serge Vakulenko (C) 2006.
 * See: http://vak.ru/doku.php/proj/hash/sources#rot13_hash_function
 */
#include "Platform.h"

/*
 * No multiplication.
 * Two shifts are converted by GCC 4 to a single rotation instruction.
 */
void rot13 (const void *key, int len, uint32_t /*seed*/, void *out)
{
    const unsigned char *str = (const unsigned char*) key;
    uint32_t hash = 0;

    while (len-- > 0) {
        hash += *str++;
        hash -= (hash << 13) | (hash >> 19);
    }
    *(uint32_t*)out = hash;
}
