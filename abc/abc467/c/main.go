package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func atoi(s string) int {
	i, err := strconv.Atoi(s)
	if err != nil {
		fmt.Printf("err: %s\n", err)
		panic(err)
	}
	return i
}

// # 余り
//  0 1 0 1 0 1 0 1 0
// # 割る数
//  2
// # 期待する値
//  0 1 0 1 0 1 0 1 0
//
// # A1-Anから、期待する値を作る
// 0 0 0 1 1 0 1 0 1 0
// 0 0 1 1 1 0 1 0 1 0 (3番目)
// 0 0 1 1 2 0 1 0 1 0 (5番目)
// 0 0 1 1 2 0 1 1 1 0 (8番目)
// 0 0 1 1 2 0 1 1 2 0 (9番目)

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	// 標準入力から64KBを超える文字列を読み込めるようにする。
	initSize := 64 * 1024  // 4KB -> 64KB
	maxSize := 1024 * 1024 // 64KB -> 1MB
	buf := make([]byte, 0, initSize)
	scanner.Buffer(buf, maxSize)

	if !scanner.Scan() {
		err := scanner.Err()
		panic(err)
	}
	line := scanner.Text()

	nm := strings.Fields(line)
	n := atoi(nm[0])
	m := atoi(nm[1])

	if !scanner.Scan() {
		err := scanner.Err()
		panic(err)
	}
	a_str := scanner.Text()
	a_slice := strings.Fields(a_str)

	if !scanner.Scan() {
		err := scanner.Err()
		panic(err)
	}
	b_str := scanner.Text()
	b_slice := strings.Fields(b_str)

	var count int
	for i := range n - 1 {
		b_num := atoi(b_slice[i])

		left := atoi(a_slice[i])
		right := atoi(a_slice[i+1])
		sum := left + right
		remainder := sum % m

		// fmt.Printf("i: %d, Bi: %d, Ai: %d, Ai+1: %d, A_sum: %d, remainder: %d\n", i, b_num, left, right, sum, remainder)

		if remainder == b_num {
			// 何もしない
		} else if remainder != b_num {
			// m=2のため、差分はBiより1小さい。あるいはBiより1大きい。
			// Ai+1に1加算して、余りを調整する。
			increment := right + 1
			a_slice[i+1] = strconv.Itoa(increment)

			count = count + 1
		}

		// left2 := atoi(a_slice[i])
		// right2 := atoi(a_slice[i+1])
		// sum2 := left2 + right2
		// remainder2 := sum2 % m
		// fmt.Printf("i: %d, Bi: %d, Ai: %d, Ai+1: %d, A_sum: %d, remainder: %d\n", i, b_num, left2, right2, sum2, remainder2)
		// if b_num == remainder2 {
		// 	fmt.Println("ok")
		// } else {
		// 	fmt.Println("ng")
		// }
		// fmt.Println("")
	}
	fmt.Println(count)
}
