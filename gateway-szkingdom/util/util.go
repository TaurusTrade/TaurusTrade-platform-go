package util

/*


#include "lbm_plugin_capi.h"
*/
import "C"

import "fmt"

func GoSum(a, b int) int {
	s := C.add(C.int(a), C.int(b))
	fmt.Println(s)
	return int(s)
}
