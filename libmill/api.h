#ifndef API_HEADER
#define API_HEADER

void initialize_messages();
void send(const char* id, void* data);
void* receive(const char* id);
#endif
