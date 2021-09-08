package main
import "fmt"
import "C"	//必须要有

func main(){
	Test( )
}

//export注释必须要有后面的Test 表示导出的函数名为Test
//export Test
func Test(){
	fmt.Println("Hello C#,I'm golang!")
}
