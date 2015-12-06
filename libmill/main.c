#include "data_map.h"
#include <stdio.h>
#include <stdlib.h>

static data_map map = NULL;

int main() {
	data_map_add(&map, "test", 42);
	data_map_item* item = data_map_find(&map, "test");
	printf("%s: %d\n", item->id, item->data);

	return EXIT_SUCCESS;
}
