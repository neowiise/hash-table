/*
** EPITECH PROJECT, 2024
** create and destroy hashtable
** File description:
** create_destroy
*/

#include "../include/struct.h"
#include "../include/secured.h"
#include "../include/proto.h"
#include "../lib/mini_printf.h"
#include "../lib/my.h"

hashtable_t *new_hashtable(int(*hash)(char *, int), int len)
{
    hashtable_t *hashtable = (hashtable_t *)malloc(sizeof(hashtable_t));

    if (hashtable == NULL) {
        write(2, "sorry, the memory allocation failed\n", 35);
        return NULL;
    }
    hashtable->buckets = (hash_element_t **)malloc
        (len * sizeof(hash_element_t *));
    if (hashtable->buckets == NULL) {
        write(2, "sorry, the memory allocation failed.\n", 36);
        free(hashtable);
        return NULL;
    }
    for (int i = 0; i < len; i++) {
        hashtable->buckets[i] = NULL;
    }
    hashtable->size = len;
    hashtable->hash = hash;
    hashtable->len = len;
    return hashtable;
}
