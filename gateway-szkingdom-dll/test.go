package main

/*
#cgo CFLAGS: -Iinclude
#cgo LDFLAGS: -Llib -lextern_demo

#include "pch.h"
*/

import "C"

import (
	"fmt"
	"syscall"
)

func main() {
	fmt.Println("hello")
	//立即加载DLL
	// h, err := syscall.LoadLibrary("KSMMApi.dll")
	// if err != nil {
	// 	abort("LoadLibrary", err)
	// }

	// defer syscall.FreeLibrary(h)
	// proc, err := syscall.GetProcAddress(h, "GetVersion")
	// if err != nil {
	// 	abort("GetProcAddress", err)
	// }
	// C.ST_THREADPOOL.InitPlugin()

	//懒加载
	dll32 := syscall.NewLazyDLL("lib/extern_demo.dll")
	fmt.Println("call dll:", dll32.Name)
	// //获得函数
	g := dll32.NewProc("Add")
	ret, b, c := g.Call(3, 6)
	fmt.Println(ret, b, c)

	// ret := C.InitPluginUseCfg() //PST_tagInitInfo pInitInfo
	// fmt.Println(ret)
	// fmt.Println(C.Add(C.int(3), C.int(5)))
	//C.Add(4, 5)
}

func abort(funcname string, err error) {
	panic(funcname + " failed: " + err.Error())
}

/*
#      cgo CFLAGS: -I./include -I../../vc/include

#       cgo LDFLAGS: -L../../vc/lib -L./lib -lKSMMApi

o LDFLAGS: -L../../vc/lib -L./lib -lKSMMApi

*/
