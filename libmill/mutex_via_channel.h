#ifndef MUTEX_VIA_CHANNEL_HEADER
#define MUTEX_VIA_CHANNEL_HEADER

#include <libmill.h>

typedef chan mutex_via_channel;

mutex_via_channel new_mutex_via_channel();
void mutex_lock(mutex_via_channel mutex);
void mutex_unlock(mutex_via_channel mutex);
void mutex_free(mutex_via_channel mutex);
#endif
