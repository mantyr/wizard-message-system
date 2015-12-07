#ifndef DATA_MAP_HEADER
#define DATA_MAP_HEADER

#include "data_map_item.h"
#include <libmill.h>

typedef data_map_item* data_map;

void data_map_add(data_map* map, const char* id, chan channel);
data_map_item* data_map_find(data_map* map, const char* id);
void data_map_free(data_map* map);
#endif
