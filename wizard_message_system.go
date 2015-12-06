package main

import (
	"fmt"
	"time"
)

var (
	mutex = newMutexViaChannel()
	value = 0
)

func backgroundTask() {
	mutex.Lock()
	defer mutex.Unlock()

	time.Sleep(2 * time.Second)
	value = 23
}

func mainTask() {
	mutex.Lock()
	defer mutex.Unlock()

	fmt.Println("value =", value)
}

func main() {
	go backgroundTask()

	time.Sleep(time.Second)
	mainTask()
}
