#include "mutex_via_channel.h"
#include <stdio.h>
#include <stdlib.h>
#include <libmill.h>

static mutex_via_channel mutex = NULL;
static int value = 0;

coroutine void background_task() {
	mutex_lock(mutex);

	msleep(now() + 2000);
	value = 23;

	mutex_unlock(mutex);
}

void main_task() {
	mutex_lock(mutex);

	printf("value = %d\n", value);

	mutex_unlock(mutex);
}

int main() {
	mutex = new_mutex_via_channel();

	go(background_task());

	msleep(now() + 1000);
	main_task();

	return EXIT_SUCCESS;
}
