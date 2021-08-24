package api

import (
	"errors"

	. "github.com/monotrade/api/message"
)

//Context  策略上下文
type Context struct {
	symbols []string
}

//Strategy 策略接口
type Strategy interface {
	UpdateSetting(setting interface{}) (float64, error)
	GetVariables(variables []interface{})

	OnStart(ctx Context)
	OnStop(ctx Context)
	OnTick(ctx Context, tick Tick)
	OnTrade(ctx Context, trade Trade)
	OnOrder(ctx Context, order Order)

	Buy(symbol string, price float64, volume int) (string, error)
	Sell(symbol string, price float64, volume int) (string, error)
	Short(symbol string, price float64, volume int) (string, error)
	Cover(symbol string, price float64, volume int) (string, error)

	//SendOrder(symbol string, direction: Direction, offset: Offset, price float64, volume int) (string, error)
	SendOrder(order Order) (string, error)
	CancelOrder(id string) (int, error)
}

//Strategy "基类"。 所有的 Strategy 要 Embedding Strategy
type StrategyBase struct {
	context Context
}

func (stgy StrategyBase) XX() {

}

func (stgy StrategyBase) Buy(symbol string, price float64, volume int) (string, error) {
	return "", errors.New("")
}
func (stgy StrategyBase) Sell(symbol string, price float64, volume int) (string, error) {
	return "", errors.New("")
}
func (stgy StrategyBase) Short(symbol string, price float64, volume int) (string, error) {
	return "", errors.New("")
}
func (stgy StrategyBase) Cover(symbol string, price float64, volume int) (string, error) {
	return "", errors.New("")
}
