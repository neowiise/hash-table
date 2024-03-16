/*
** EPITECH PROJECT, 2024
** insert element
** File description:
** insert
*/

#include "../include/proto.h"
#include "../include/struct.h"
#include "../include/secured.h"
#include "../lib/mini_printf.h"
#include "../lib/my.h"
#include <limits.h>

int valid_arguments(hashtable_t *ht, char *key, char *value)
{
    if (ht == NULL || key == NULL || value == NULL) {
        write(2, "Invalid arguments for ht_insert\n", 31);
        return 84;
    }
    return 1;
}

hash_element_t *create_element(char *key, char *value)
{
    hash_element_t *new_element = (hash_element_t *)malloc
        (sizeof(hash_element_t));

    if (new_element == NULL) {
        write(2, "Sorry, the memory allocation failed\n", 35);
        return NULL;
    }
    my_strncpy(new_element->key, key, sizeof(new_element->key) - 1);
    new_element->key[sizeof(new_element->key) - 1] = '\0';
    my_strncpy(new_element->value, value, sizeof(new_element->value) - 1);
    new_element->value[sizeof(new_element->value) - 1] = '\0';
    new_element->next = NULL;
    return new_element;
}

void insert_into_bucket(hashtable_t *ht, int index,
    hash_element_t *new_element)
{
    hash_element_t *current;

    if (ht->buckets[index] == NULL) {
        ht->buckets[index] = new_element;
    } else {
        current = ht->buckets[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_element;
    }
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    hash_element_t *new_element;
    int index;

    if (valid_arguments(ht, key, value) == 0) {
        return 0;
    }
    index = ht->hash(key, ht->len);
    new_element = create_element(key, value);
    if (new_element == NULL) {
        return 84;
    }
    new_element->key_hash = ht->hash(key, INT_MAX);
    insert_into_bucket(ht, index, new_element);
    return 0;
}
