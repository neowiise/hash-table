/*
** EPITECH PROJECT, 2024
** delete element
** File description:
** delete
*/

#include "../include/struct.h"
#include "../include/secured.h"
#include "../include/proto.h"
#include "../lib/mini_printf.h"
#include "../lib/my.h"

void free_linked_list(hash_element_t *head)
{
    hash_element_t *current = head;
    hash_element_t *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

void free_bucket_elements(hashtable_t *ht)
{
    int i;

    for (i = 0; i < ht->size; i++) {
        if (ht->buckets[i] != NULL) {
            free_linked_list(ht->buckets[i]);
        }
    }
}

void delete_hashtable(hashtable_t *ht)
{
    if (ht == NULL) {
        write(2, "Invalid hashtable\n", 17);
        return;
    }
    free_bucket_elements(ht);
    free(ht->buckets);
    free(ht);
}
