package main

type mutexViaChannel chan uint8

func newMutexViaChannel() mutexViaChannel {
	mutex := make(mutexViaChannel, 1)
	mutex <- 1

	return mutex
}

func (mutex mutexViaChannel) Lock() {
	<-mutex
}

func (mutex mutexViaChannel) Unlock() {
	mutex <- 1
}
