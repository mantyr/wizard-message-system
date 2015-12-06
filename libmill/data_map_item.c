#include "data_map_item.h"

data_map_item* new_data_map_item(const char* id, int data) {
	data_map_item* item = malloc(sizeof(data_map_item));
	item->id = id;
	item->data = data;

	return item;
}
