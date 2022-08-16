// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

#define BUCKET_COUNT 150000 // Number of buckets in hash table

unsigned int word_count = 0;

// Represents a node in a hash table
typedef struct node {
    char data[LENGTH];
    struct node *next;
} node;

// Hash table
node *hashTable[BUCKET_COUNT];

// Set all elements of the hashTable to NULL
void init_hash_table() {
    for (int i = 0; i < BUCKET_COUNT; i++) {
        hashTable[i] = NULL;
    }
}

// Print each element of the hashTable
void print_hash_table() {
    for (int i = 0; i < BUCKET_COUNT; i++) {
        node *tmp = hashTable[i];
        if (tmp == NULL) {
            printf("%d: ---\n", i);
        }
        while (tmp != NULL) {
            printf("hash: %lu = %s",hash(tmp->data), tmp->data);
            tmp = tmp->next;
        }
        printf("\n");
    }
}

// Insert data into hashTable
bool insert_hash_table(node *n, const char *word) {
    node *head;

    // Malloc memory for a new node
    n = malloc(sizeof(node));
    if (n == NULL) {
        unload();
        printf("ERROR: Ran out of memory while trying to create new node\n");
        return false;
    }

    strcpy(n->data, word);

    // Get index by hashing the word
    unsigned long index = hash(n->data);

    head = hashTable[index];

    if (head == NULL) {
        hashTable[index] = n;
        word_count++;
    } else {
        n->next = hashTable[index];
        hashTable[index] = n;
        word_count++;
    }
    return true;
}

// Returns true if word is in dictionary, else false
bool check(const char *word) {
    unsigned long index = hash(word);
    node *n = hashTable[index];

    while (n != NULL) {
        if (strcasecmp(n->data, word) == 0) {
            return true;
        }
        n = n->next;
    }
    return false;
}

// Hashes word to a number
unsigned long hash(const char *word) {
    unsigned long hash = 5381;
    int c;

    while ((c = *word++)) {
        c = toupper(c);
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    return hash % BUCKET_COUNT;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary) {
    char word[LENGTH];
    node *n = NULL;

    // Initialize hash table to all NULL
    init_hash_table();

    // Open ptrFile
    FILE *ptrFile = fopen(dictionary, "r");
    if (ptrFile == NULL) {
        printf("ERROR: Could not open %p\n", dictionary);
        return false;
    }

    while (fscanf(ptrFile, "%s", word) != EOF) {
        insert_hash_table(n, word);
    }

    fclose(ptrFile);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void) {
    unsigned int size = word_count;
    return size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void) {
    // Iterate through hash array
    for (int i = 0; i < BUCKET_COUNT; i++) {
        node *head = hashTable[i];
        node *cursor = head;
        while (cursor != NULL) {
            node *prev = cursor;
            cursor = cursor->next;
            free(prev);
        }
    }
    return true;
}
