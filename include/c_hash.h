#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* TODO: expand interface _collision_policy */

typedef struct {
	char* key;
	char* value;
} h_item;


// size_t h_value(void* key)
// {
// 	return 0;
// }

typedef size_t (*hash_f)(void*);
/*
* size = how large the hash table is
*/
typedef struct {
    //hash_f hash;
	size_t size;
	h_item* array[];
} h_table;

//bool put(h_table*, h_item);
//bool put(h_table*, void* k, void* v);

// size_t hash_f(h_item*)

// typedef enum _collision_policy {
//     linear,
//     quad,
//     chain
// }   collision_policy_e;

h_table* init_table(size_t table_size, hash_f hash);
int generate_hash(h_table* table, char* key);
void insert_value(h_table* table, char* key, char* value);
void remove_value(h_table* table, char* key);
void get_value(h_table* table, char* key);
void print_table(h_table* table);
void delete_table (h_table* table);