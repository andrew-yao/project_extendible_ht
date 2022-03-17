#include "../include/c_hash.h"

h_table* init_table(size_t table_size, hash_f hash)
{
	h_table* hash_table = NULL;

	if (table_size > 0)
	{
    	hash_table = malloc(sizeof(h_table) + (table_size * sizeof(h_item*)));
        hash_table->size = table_size;
        
        if (hash_table != NULL)
        {
            //hash_table->hash = hash;
        	memset(hash_table->array, 0, table_size);

            for (int i = 0; i < table_size; i++)
                {
                    hash_table->array[i] = malloc(sizeof(h_item));
                    memset(hash_table->array[i], 0, sizeof(h_item));
                }
        }
	}
	
	return hash_table;
}

int generate_hash(h_table* table, char* key)
{
    int hash_value = 0;

    for (int i = 0; i < strlen(key); i++)
        {
            hash_value += key[i];
        }

    if (hash_value > 0 && table->size > 0)
    {
        hash_value = hash_value % table->size;
    }
    
    return hash_value;
}

void insert_value(h_table* table, char* key, char* value)
{
    int index;

    if (table != NULL)
    {
        index = generate_hash(table, key);
    
        if (table->array[index]->value == NULL)
        {
            table->array[index]->key = malloc(strlen(key) + 1);
            strcpy(table->array[index]->key, key);
            
            table->array[index]->value = malloc(strlen(value) + 1);
            strcpy(table->array[index]->value, value);

            printf("\nINSERT %s", key);
            print_table(table);
        }
    }
}

void remove_value(h_table* table, char* key)
{    
    //h_item* temp_ptr;
    int index;

    if (table != NULL)
    {
        index = generate_hash(table, key);
        
        if (table->array[index]->value != NULL)
        {
            //temp_ptr = table->array[index];
            table->array[index]->value = NULL;
            table->array[index]->key = NULL;
            //free(temp_ptr);

            printf("\nREMOVE %s", key);
            print_table(table);
        }
    }
}

void get_value(h_table* table, char* key)
{
    int index;
    if (table != NULL)
    {
        index = generate_hash(table, key);

        if (table->array[index] != NULL)
        {
            printf("\nVALUE FOUND: %s\n", table->array[index]->value);
        }
    }
}

void print_table(h_table* table)
{
    if (table != NULL)
    {
        printf("\n============\n");
        for (int i = 0; i < table->size; i++)
            {
                printf("%02d: %-10s\t\t|\t\t%-10s\n", i, table->array[i]->key, table->array[i]->value);
            }
    }
}

void delete_table (h_table* table)
{
	if (table != NULL)
    {
        for (int i = 0; i < table->size; i++)
            {
                free(table->array[i]->key);
                free(table->array[i]->value);
            }

        free(table);
    }
}