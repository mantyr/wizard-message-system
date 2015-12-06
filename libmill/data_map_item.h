#ifndef DATA_MAP_ITEM_HEADER
#define DATA_MAP_ITEM_HEADER

#include "uthash.h"

typedef struct data_map_item {
	const char* id;
	int data;
	UT_hash_handle hash_handle;
} data_map_item;

data_map_item* new_data_map_item(const char* id, int data);
#endif
