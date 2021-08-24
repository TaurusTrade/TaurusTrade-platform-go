package api

type Gateway interface {
	Broker
	Feeder
}

type Broker interface {
	Start()
	GetName() string
}

type Feeder interface {
	Start()
	GetName() string
}
