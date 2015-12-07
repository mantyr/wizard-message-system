#include "storage.h"
#include <stdio.h>
#include <stdlib.h>
#include <libmill.h>

static storage* store = NULL;
static int data = 23;

coroutine void background_task() {
	int* data = storage_get_data(store, "data");
	printf("data = %d\n", *data);

	storage_add_data(store, "dump", 0);
}

void main_task() {
	storage_add_data(store, "data", &data);
	storage_get_data(store, "dump");
}

int main() {
	store = new_storage();

	go(background_task());

	msleep(now() + 1000);
	main_task();

	return EXIT_SUCCESS;
}
