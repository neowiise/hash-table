/*
** EPITECH PROJECT, 2024
** search element
** File description:
** search
*/

#include "../include/struct.h"
#include "../include/secured.h"
#include "../include/proto.h"
#include "../lib/mini_printf.h"
#include "../lib/my.h"

char *ht_search(hashtable_t *ht, char *key)
{
    hash_element_t *current;
    int index;

    if (ht == NULL || key == NULL) {
        write(2, "Invalid arguments for ht_search\n", 31);
        return NULL;
    }
    index = ht->hash(key, ht->len);
    current = ht->buckets[index];
    while (current != NULL) {
        if (my_strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    write(2, "Key not found in the hashtable\n", 30);
    return 0;
}
