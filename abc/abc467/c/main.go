package main

import (
	"bufio"
	"fmt"
	"os"
	"slices"
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

func count_operation(n int, m int, a_slice []string, b_slice []string) int {
	var count int
	for i := range n - 1 {
		b_num := atoi(b_slice[i])

		left := atoi(a_slice[i])
		right := atoi(a_slice[i+1])
		sum := left + right
		remainder := sum % m

		if remainder == b_num {
			// 何もしない
		} else if remainder != b_num {
			// m=2のため、差分はBiより1小さい。あるいはBiより1大きい。
			// Ai+1に1加算して、余りを調整する。
			increment := right + 1
			a_slice[i+1] = strconv.Itoa(increment)

			count = count + 1
		}
	}
	return count
}

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
	m := atoi(nm[1]) // c問題はm=2で固定

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

	// ------------------------------------
	// 左に加算
	// ------------------------------------
	p1_a_slice := make([]string, len(a_slice))
	p1_b_slice := make([]string, len(b_slice))
	copy(p1_a_slice, a_slice)
	copy(p1_b_slice, b_slice)
	slices.Reverse(p1_a_slice)
	slices.Reverse(p1_b_slice)
	p1_count := count_operation(n, m, p1_a_slice, p1_b_slice)

	// ------------------------------------
	// 右に加算
	// ------------------------------------
	p2_a_slice := make([]string, len(a_slice))
	p2_b_slice := make([]string, len(b_slice))
	copy(p2_a_slice, a_slice)
	copy(p2_b_slice, b_slice)
	p2_count := count_operation(n, m, p2_a_slice, p2_b_slice)

	min_count := min(p1_count, p2_count)
	fmt.Println(min_count)
}
