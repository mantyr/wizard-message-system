#include "data_map.h"
#include "uthash.h"

void data_map_add(data_map* map, const char* id, int data) {
	data_map_item* item = new_data_map_item(id, data);
	HASH_ADD_KEYPTR(hash_handle, *map, item->id, strlen(item->id), item);
}

data_map_item* data_map_find(data_map* map, const char* id) {
	data_map_item* item = NULL;
	HASH_FIND(hash_handle, *map, id, strlen(id), item);

	return item;
}
