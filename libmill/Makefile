OBJECTS = main.o api.o storage.o data_map.o data_map_item.o mutex_via_channel.o
CFLAGS += -std=c99 -Wpedantic -Wall -Wextra -O2
LDFLAGS += -lmill

main: $(OBJECTS)
	$(CC) $(CFLAGS) -o wizard_message_system $(OBJECTS) $(LDFLAGS)
