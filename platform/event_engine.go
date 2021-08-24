package platform

import (
	"github.com/AsynkronIT/protoactor-go/eventstream"
)

type DefaultEventEngine struct {
}

func (engine DefaultEventEngine) Subscribe(fn func(event interface{})) {
	sub := eventstream.Subscribe(fn)
}
