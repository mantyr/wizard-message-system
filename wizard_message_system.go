package main

import (
	"fmt"
	"time"
)

var dataStorage = newStorage()

func backgroundTask() {
	data := dataStorage.getData("data")
	fmt.Println("data =", data.(int))

	dataStorage.addData("dump", nil)
}

func mainTask() {
	dataStorage.addData("data", 23)
	dataStorage.getData("dump")
}

func main() {
	go backgroundTask()

	time.Sleep(time.Second)
	mainTask()
}
