#include "storage.h"

storage* new_storage() {
	storage* store = malloc(sizeof(storage));;
	store->mutex = new_mutex_via_channel();
	store->map = NULL;

	return store;
}

int storage_get_data(storage* store, const char* id) {
	chan channel = storage_get_channel(store, id);
	return chr(channel, int);
}

void storage_add_data(storage* store, const char* id, int data) {
	chan channel = storage_get_channel(store, id);
	chs(channel, int, data);
}

chan storage_get_channel(storage* store, const char* id) {
	mutex_lock(store->mutex);

	storage_add_channel_if_need(store, id);
	data_map_item* item = data_map_find(&store->map, id);

	mutex_unlock(store->mutex);
	return item->channel;
}

void storage_add_channel_if_need(storage* store, const char* id) {
	data_map_item* item = data_map_find(&store->map, id);
	if (item == NULL) {
		chan channel = chmake(int, 0);
		data_map_add(&store->map, id, channel);
	}
}
