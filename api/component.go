package api

type EventEngine interface {
	Publish(interface{})
	Subscribe()
	UnSubscribe()
}

type Component struct {
	engine EventEngine
}
