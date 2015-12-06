package main

import (
	"fmt"
	"time"
)

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
