package actors

import (
	"fmt"
	"time"

	"github.com/AsynkronIT/protoactor-go/actor"
	"github.com/AsynkronIT/protoactor-go/eventstream"
)



//TODO: use middleware to implement Risk Manager
// https://proto.actor/docs/middleware/



type GatewayActor struct {
	// Gateway api.Gateway
}

func (actor *GatewayActor) Start() {

}

func (state *GatewayActor) Receive(context actor.Context) {
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
