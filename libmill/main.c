#include <stdio.h>
#include <stdlib.h>
#include <libmill.h>

coroutine void worker(int count, const char* text) {
	for (int i = 0; i != count; i++) {
		printf("%s\n", text);
		msleep(now() + 10);
	}
}

int main() {
	go(worker(4, "a"));
	go(worker(2, "b"));
	go(worker(3, "c"));
	msleep(now() + 100);

	return EXIT_SUCCESS;
}
