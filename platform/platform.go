package platform

import (
	"fmt"

	"github.com/AsynkronIT/protoactor-go/actor"
	"github.com/monotrade/api"
	"github.com/monotrade/platform/actors"
)

//Go语言中没有构造函数，对象的创建一般交给一个全局的创建函数来完成
func NewPlatform() *Platform {
	// es := &eventStream{}

	// sub := eventstream.Subscribe(func(event interface{}) {
	// 	fmt.Println("received %s", event)
	// })

	// only allow strings
	// sub.WithPredicate(func(evt interface{}) bool {
	// 	_, ok := evt.(string)
	// 	return ok
	// })

	return &Platform{context: actor.EmptyRootContext}
}

type Platform struct {
	context   *actor.RootContext
	OnMessage func(message interface{})
}

func (p Platform) Start() {
	fmt.Println("starting platform")

}

func (p Platform) AddComponent(c api.Component) {
	fmt.Println(g)
	//actor := &actors.GatewayActor{}
	// context := actor.EmptyRootContext
	c.engine = DefaultEventEngine{}
	props := actor.PropsFromProducer(func() actor.Actor { return &actors.GatewayActor{} })
	pid := p.context.Spawn(props)

	p.context.Send(pid, "Roger")

	c.Start()
	//actor.Start()

	// gateway = gateway_class(self.event_engine)
	//     self.gateways[gateway.gateway_name] = gateway

	//     # Add gateway supported exchanges into engine
	//     for exchange in gateway.exchanges:
	//         if exchange not in self.exchanges:
	//             self.exchanges.append(exchange)

	//     return gateway
}

func (p Platform) AddStrategy(stategy api.Strategy, setting interface{}) {
	fmt.Println("TODO: add strategy")
}
