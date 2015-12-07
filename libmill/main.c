#include "api.h"
#include <stdio.h>
#include <stdlib.h>
#include <libmill.h>

static int data = 23;

coroutine void background_task() {
	int* data = receive("data");
	printf("data = %d\n", *data);

	send("dump", NULL);
}

void main_task() {
	send("data", &data);
	receive("dump");
}

int main() {
	initialize_messages();

	go(background_task());

	msleep(now() + 1000);
	main_task();

	return EXIT_SUCCESS;
}
