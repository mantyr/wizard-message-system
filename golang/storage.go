package main

type (
	dataChannel chan interface{}
	dataMap     map[string]dataChannel
	storage     struct {
		mutexViaChannel
		data dataMap
	}
)

func newStorage() storage {
	return storage{newMutexViaChannel(), make(dataMap)}
}

func (storage storage) getData(id string) interface{} {
	return <-storage.getChannel(id)
}

func (storage storage) addData(id string, data interface{}) {
	storage.getChannel(id) <- data
}

func (storage storage) getChannel(id string) dataChannel {
	storage.Lock()
	defer storage.Unlock()

	storage.addChannelIfNeed(id)
	return storage.data[id]
}

func (storage storage) addChannelIfNeed(id string) {
	_, found := storage.data[id]
	if !found {
		storage.data[id] = make(dataChannel)
	}
}
