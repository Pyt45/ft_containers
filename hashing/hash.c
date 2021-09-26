#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACITY 50000

unsigned long hash_function(char* str) {
    unsigned long i = 0;
    for (int j = 0; str[j]; j++)
        i += str[j];
    return i % CAPACITY;
}

typedef struct	Ht_item {
    char*	key;
    char*	value;
}				Ht_item;

typedef struct	HashTable {
    Ht_item**	items;
	int			size;
	int			count;
}				HashTable;

Ht_item*	create_item(char* key, char* value) {
	Ht_item* item = (Ht_item*)malloc(sizeof(Ht_item));

	item->key = (char*)malloc(strlen(key) + 1);
	item->value = (char*)malloc(strlen(value) + 1);

	strcpy(item->key, key);
	strcpy(item->value, value);

	return item;
}

HashTable*	creat_table(int size) {
	HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    table->size = size;
	table->count = 0;
	table->items = (Ht_item**)calloc(table->size, sizeof(Ht_item*));
	for (int i = 0; i < table->size; i++)
		table->items[i] = NULL;
	return table;
}

void	free_item(Ht_item* item) {
	free(item->key);
	free(item->value);
	free(item);
}

void	free_table(HashTable* table) {
	for (int i = 0; i < table->size; i++) {
		Ht_item* item = table->items[i];
		if (item)
			free_item(item);
	}
	free(table->items);
	free(table);
}