#include "data_map_item.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	data_map_item* item = new_data_map_item("test", 23);
	printf("%s: %d\n", item->id, item->data);

	return EXIT_SUCCESS;
}
