#include <stdio.h>
#include <stdlib.h>

// Hash table node (linked list to handle collisions)
typedef struct HashNode {
    int key;
    int index;
    struct HashNode* next;
} HashNode;

// Hash table structure
typedef struct {
    HashNode** table;
    int size;
} HashMap;

#define HASH_SIZE 10000  // A large prime number for hashing

// Hash function
int hash(int key) {
    return (key < 0 ? -key : key) % HASH_SIZE;
}

// Insert into hash map (chaining to handle collisions)
void insert(HashMap* map, int key, int index) {
    int h = hash(key);
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->index = index;
    newNode->next = map->table[h];  // Insert at the beginning of the chain
    map->table[h] = newNode;
}

// Search for a key in the hash map
int search(HashMap* map, int key, int* indexToReturn) {
    int h = hash(key);
    HashNode* curr = map->table[h];
    while (curr) {
        if (curr->key == key) {
            *indexToReturn = curr->index; // Return the first occurrence found
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}

// Free hash map memory
void freeHashMap(HashMap* map) {
    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode* curr = map->table[i];
        while (curr) {
            HashNode* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(map->table);
}

// Optimized Two Sum function
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    if (!result) {
        *returnSize = 0;
        return NULL;
    }

    // Initialize hash map
    HashMap map;
    map.size = HASH_SIZE;
    map.table = (HashNode**)calloc(HASH_SIZE, sizeof(HashNode*));
    if (!map.table) {
        free(result);
        *returnSize = 0;
        return NULL;
    }

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int index;
        if (search(&map, complement, &index)) {
            result[0] = index;
            result[1] = i;
            freeHashMap(&map);
            return result;
        }
        insert(&map, nums[i], i);
    }

    freeHashMap(&map);
    free(result);
    *returnSize = 0;
    return NULL;
}
// time complexity: O(n), since each lookup and insertion in the hash table take O(1) on average
// space complexity: O(n) because we store each number and its index

// use linear probing to handle collisions without additional memory overhead
// allow dup still works becuase we only return the first valid pair

// sorting is slower than hashing