#include "api.h"
#include "storage.h"

static storage* store = NULL;

void initialize_messages() {
	store = new_storage();
}

void send(const char* id, void* data) {
	storage_add_data(store, id, data);
}

void* receive(const char* id) {
	return storage_get_data(store, id);
}

void messages_free() {
	storage_free(store);
}
