#include "data_map.h"
#include <stdio.h>
#include <stdlib.h>

static data_map map = NULL;

int main() {
	chan channel = chmake(uint8_t, 1);
	chs(channel, uint8_t, 12);

	data_map_add(&map, "test", channel);
	data_map_item* item = data_map_find(&map, "test");

	int value = chr(item->channel, uint8_t);
	printf("%s: %d\n", item->id, value);

	return EXIT_SUCCESS;
}
