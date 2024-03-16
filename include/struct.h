/*
** EPITECH PROJECT, 2024
** struct
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    #define MAX_KEY_LEN 300
    #define MAX_VALUE_LEN 500
    #define HASH_PRIME 5381

typedef struct hash_element_s {
    char key[MAX_KEY_LEN]; // clé de l'élement
    char value[MAX_VALUE_LEN]; // valeur associé à l'élément
    int key_hash; // stockage de la valeur de hash
    struct hash_element_s *next; // pointeur vers le prochain element
} hash_element_t;

typedef struct hashtable_s {
    hash_element_t **buckets;
    int size; // taille du tableau
    int (*hash)(char *, int); // pointeur vers la fonction de hashage
    int len; // longueur de la table de hash
} hashtable_t;

#endif /* !STRUCT_H_ */
