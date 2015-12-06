package main

var globalStorage = newStorage()

func send(id string, data interface{}) {
	globalStorage.addData(id, data)
}

func receive(id string) interface{} {
	return globalStorage.getData(id)
}
