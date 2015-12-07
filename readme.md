# Wizard Message System

Proof of concept concurrency message system, based on Go-style channels.

In fact, this system is a concurrency hash table with buffered channels of size
1 as values.

Here are the implementation of this system in Go (the reference) and in C (using
the library [libmill](http://libmill.org/)).

## API

### send()

Go:

```go
func send(id string, data interface{})
```

C:

```c
void send(const char* id, void* data)
```

Sends a message with the specified identifier and data.

If the message with the specified identifier have been sent previously and
haven't yet been received, this function locks the current coroutine up until
the previous message is received.

#### Parameters

* `id` &mdash; the unique identifier of the data;
* `data` &mdash; the data of an any type.

#### Return value

None.

### receive()

Go:

```go
func receive(id string) interface{}
```

C:

```c
void* receive(const char* id)
```

Receives a message with the specified identifier and returns the data
corresponding to it.

If the message with the specified identifier wasn't sent earlier, this function
locks the current coroutine until when such a message is sent.

#### Parameters

* `id` &mdash; the unique identifier of the data.

#### Return value

The data corresponding to the specified identifier `id`.

## Examples

Go:

```go
func backgroundTask() {
	data := receive("data")
	fmt.Println("data =", data.(int))

	send("dump", nil)
}

func mainTask() {
	send("data", 23)
	receive("dump")
}

func main() {
	go backgroundTask()

	time.Sleep(time.Second)
	mainTask()
}
```

C:

```c
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

	messages_free();
	return EXIT_SUCCESS;
}
```

## License

The MIT License (MIT).

Copyright &copy; 2015 thewizardplusplus <thewizardplusplus@yandex.ru>.
