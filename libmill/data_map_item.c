#include "data_map_item.h"
#include <stdlib.h>

data_map_item* new_data_map_item(const char* id, chan channel) {
	data_map_item* item = malloc(sizeof(data_map_item));
	item->id = id;
	item->channel = channel;

	return item;
}

void data_map_item_free(data_map_item* item) {
	chclose(item->channel);
	free(item);
}
