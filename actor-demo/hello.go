package main

import (
	"fmt"
	"bufio"
	"os"
	"github.com/AsynkronIT/protoactor-go/actor"
)

type Hello struct{ Who string }
type HelloActor struct{}

func (state *HelloActor) Receive(context actor.Context) {
	switch msg := context.Message().(type) {
	case Hello:
		fmt.Printf("Hello %v\n", msg.Who)
	}
}

func main() {
	context := actor.EmptyRootContext
	props := actor.PropsFromProducer(func() actor.Actor { return &HelloActor{} })
	pid := context.Spawn(props)
	// if err != nil {
	// 	panic(err)
	// }
	context.Send(pid, Hello{Who: "Roger"})
	// console.ReadLine()
	reader := bufio.NewReader(os.Stdin)
	text, _ := reader.ReadString('\n')
	fmt.Printf("Hello %v\n", text)

}
