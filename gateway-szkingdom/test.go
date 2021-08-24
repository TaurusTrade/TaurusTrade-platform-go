package main

import "C"

import (
	"fmt"

	"demo/util"
)

func main() {

	fmt.Println("hello")

	// ret := C.InitPluginUseCfg() //PST_tagInitInfo pInitInfo
	// fmt.Println(ret)
	// fmt.Println(C.Add(C.int(3), C.int(5)))
	fmt.Println(util.GoSum(4, 5))
}

func abort(funcname string, err error) {
	panic(funcname + " failed: " + err.Error())
}

/*
#      cgo CFLAGS: -I./include -I../../vc/include

#       cgo LDFLAGS: -L../../vc/lib -L./lib -lKSMMApi

*/
