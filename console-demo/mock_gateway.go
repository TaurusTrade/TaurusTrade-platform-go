package main

import (
	"fmt"
	"time"
)

type MockGateway struct {
	Component
	Gateway
}

func (gateway MockGateway) GetName() {
	return "MOCK"
}

func (gateway MockGateway) Start() {
	//timer := time.NewTimer(2 * time.Second)  // 新建一个Timer
	//定义一个ticker
	ticker := time.NewTicker(time.Millisecond * 500)

	// for {
	//     select {
	//     case <-timer.C:
	//         fmt.Println("I Love You!")
	//         timer.Reset(2 * time.Second)  // 上一个when执行完毕重新设置
	//     }
	// }
	for t := range ticker.C {
		fmt.Println(t)
		fmt.Println("send tick from mock_gateway")
		// 创建一个新的结构体
		fmt.Println(Tick{Symbol: "hello"})
		tick := Tick{}
		fmt.Println(tick)
	}

	return
}
