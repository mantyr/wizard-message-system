#ifndef DATA_MAP_ITEM_HEADER
#define DATA_MAP_ITEM_HEADER

#include <libmill.h>
#include <uthash.h>

typedef struct data_map_item {
	const char* id;
	chan channel;
	UT_hash_handle hash_handle;
} data_map_item;

data_map_item* new_data_map_item(const char* id, chan channel);
void data_map_item_free(data_map_item* item);
#endif
