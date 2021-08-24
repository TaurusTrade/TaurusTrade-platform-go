package main

import (
	. "github.com/monotrade/api/message"
	"github.com/monotrade/platform"
)

func main() {

	var p *platform.Platform = platform.NewPlatform()

	p.AddGateway(MockGateway{})

	p.Start()

	//vnpy no ui
	// SETTINGS["log.file"] = True

	// event_engine = EventEngine()
	// main_engine = MainEngine(event_engine)
	// main_engine.add_gateway(RootnetGateway)
	// ctaext_engine = main_engine.add_app(CtaExtStrategyApp)
	// main_engine.write_log("主引擎创建成功")

	// log_engine = main_engine.get_engine("log")
	// event_engine.register(EVENT_CTAEXT_LOG, log_engine.process_log_event)
	// main_engine.write_log("注册日志事件监听")

	// main_engine.connect(rootnet_setting, "根网")
	// main_engine.write_log("连接根网接口")

	// sleep(10)

	// ctaext_engine.init_engine()
	// main_engine.write_log("策略引擎初始化完成")

	// ctaext_engine.init_all_strategies()
	// sleep(30)   # Leave enough time to complete strategy initialization
	// main_engine.write_log("策略全部初始化")

	// ctaext_engine.start_all_strategies()
	// main_engine.write_log("策略全部启动")

	// while True:
	//     sleep(1)
}
