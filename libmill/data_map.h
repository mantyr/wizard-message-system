#ifndef DATA_MAP_HEADER
#define DATA_MAP_HEADER

#include "data_map_item.h"

typedef data_map_item* data_map;

void data_map_add(data_map* map, const char* id, int data);
data_map_item* data_map_find(data_map* map, const char* id);
#endif
