/*
** EPITECH PROJECT, 2024
** delete element
** File description:
** delete_element
*/

#include "../include/struct.h"
#include "../include/secured.h"
#include "../include/proto.h"
#include "../lib/mini_printf.h"
#include "../lib/my.h"

void ht_remove_element(hashtable_t *ht, int index, hash_element_t *prev,
    hash_element_t *current)
{
    if (prev == NULL) {
        ht->buckets[index] = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
}

int validate_arguments(hashtable_t *ht, char *key)
{
    if (ht == NULL || key == NULL) {
        mini_printf("Invalid arguments for ht_delete\n");
        return 84;
    }
    return 1;
}

int ht_delete(hashtable_t *ht, char *key)
{
    hash_element_t *current;
    hash_element_t *prev;
    int index;

    if (validate_arguments(ht, key) == 0) {
        return 0;
    }
    index = ht->hash(key, ht->len);
    current = ht->buckets[index];
    prev = NULL;
    while (current != NULL) {
        if (my_strcmp(current->key, key) == 0) {
            ht_remove_element(ht, index, prev, current);
            return 1;
        }
        prev = current;
        current = current->next;
    }
    mini_printf("Key not found in the hashtable\n");
    return 84;
}
