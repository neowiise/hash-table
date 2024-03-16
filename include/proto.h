/*
** EPITECH PROJECT, 2024
** proto
** File description:
** proto
*/

#ifndef PROTO_H_
    #define PROTO_H_

    #include "struct.h"

void delete_hashtable(hashtable_t *ht);
void ht_dump(hashtable_t *ht);
int hash(char *key, int len);
int ht_insert(hashtable_t *ht, char *key, char *value);
int ht_delete(hashtable_t *ht, char *key);
char *ht_search(hashtable_t *ht, char *key);

#endif /* !PROTO_H_ */
