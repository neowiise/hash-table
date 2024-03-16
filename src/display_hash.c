/*
** EPITECH PROJECT, 2024
** display
** File description:
** display_hash
*/

#include "../include/struct.h"
#include "../include/secured.h"
#include "../include/proto.h"
#include "../lib/mini_printf.h"
#include "../lib/my.h"

void ht_dump(hashtable_t *ht)
{
    hash_element_t *current;

    if (ht == NULL) {
        write(2, "Invalid argument for ht_dump\n", 28);
        return;
    }
    for (int i = 0; i < ht->len; i++) {
        mini_printf("[%d]:\n", i);
        current = ht->buckets[i];
        while (current != NULL) {
            mini_printf("> %d - %s\n", current->key_hash, current->value);
            current = current->next;
        }
    }
}
