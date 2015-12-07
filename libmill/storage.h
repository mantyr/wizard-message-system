#ifndef STORAGE_HEADER
#define STORAGE_HEADER

#include "mutex_via_channel.h"
#include "data_map.h"
#include <libmill.h>

typedef struct storage {
	mutex_via_channel mutex;
	data_map map;
} storage;

storage* new_storage();
void* storage_get_data(storage* store, const char* id);
void storage_add_data(storage* store, const char* id, void* data);
chan storage_get_channel(storage* store, const char* id);
void storage_add_channel_if_need(storage* store, const char* id);
#endif
