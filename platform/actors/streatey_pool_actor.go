package actors

// strategy pool is essentially a router
// https://proto.actor/docs/routers/

// use pool type to supervise StrategyActors !
// https://proto.actor/docs/supervision/

import (
	"fmt"
	"time"

	"github.com/AsynkronIT/protoactor-go/actor"
	"github.com/AsynkronIT/protoactor-go/eventstream"
)

//TODO: use middleware to implement Risk Manager
// https://proto.actor/docs/middleware/

type StrategyPoolActor struct {
	// Gateway api.Gateway
}

func (actor *StrategyPoolActor) Start() {

}

func (state *StrategyPoolActor) Receive(context actor.Context) {
	switch msg := context.Message().(type) {
	case string:
		{
			fmt.Printf("Hello %v\n", msg)
			ticker := time.NewTicker(time.Millisecond * 500)

			for t := range ticker.C {
				fmt.Println(t)
				fmt.Println("published !!!")
				eventstream.Publish("Hello World")
			}
		}

	}
}
