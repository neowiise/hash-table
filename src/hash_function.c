/*
** EPITECH PROJECT, 2024
** hash function*
** File description:
** hash_function
*/

#include "../include/struct.h"
#include "../include/secured.h"
#include "../include/proto.h"
#include "../lib/mini_printf.h"
#include "../lib/my.h"
#include <stdint.h>

int hash(char *key, int len)
{
    unsigned int hash = HASH_PRIME;
    int key_len = my_strlen(key);

    for (int i = 0; i < key_len; i++) {
        hash = ((hash << 5) + hash) ^ key[i];
    }
    hash = ((hash >> 16) ^ hash) * 0x45d9f3b;
    hash = ((hash >> 16) ^ hash) * 0x45d9f3b;
    hash = (hash >> 16) ^ hash;
    hash ^= len;
    return (int)(hash % len);
}
