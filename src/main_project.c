#include <stdio.h>
#include <stdlib.h>
#include "../include/c_hash.h"

int main_project(int argc, char* argv[])
{
	printf("i'm in main_project!\n");

    h_table* table;
    table = init_table(15, NULL);

    if (table != NULL)
    {
        insert_value(table, "books", "the art of war");
        insert_value(table, "food", "fried rice");
        insert_value(table, "animal", "dog");
        get_value(table, "animal");
        remove_value(table, "animal");
        delete_table(table);
    }
	
	return EXIT_SUCCESS;
}