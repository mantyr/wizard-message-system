#include "mutex_via_channel.h"
#include <stdint.h>

mutex_via_channel new_mutex_via_channel() {
	mutex_via_channel mutex = chmake(uint8_t, 1);
	chs(mutex, uint8_t, 1);

	return mutex;
}

void mutex_lock(mutex_via_channel mutex) {
	chr(mutex, uint8_t);
}

void mutex_unlock(mutex_via_channel mutex) {
	chs(mutex, uint8_t, 1);
}

void mutex_free(mutex_via_channel mutex) {
	chclose(mutex);
}
