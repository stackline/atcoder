package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	if !scanner.Scan() {
		err := scanner.Err()
		panic(err)
	}
	line := scanner.Text()

	n, err := strconv.Atoi(line)
	if err != nil {
		fmt.Printf("err: %s\n", err)
		panic(err)
	}

	var amount int
	for i := 1; i <= n; i++ {
		if !scanner.Scan() {
			err := scanner.Err()
			panic(err)
		}
		line := scanner.Text()
		inputs := strings.Fields(line)
		a, err := strconv.Atoi(inputs[0])
		if err != nil {
			fmt.Printf("err: %s\n", err)
			panic(err)
		}
		b, err := strconv.Atoi(inputs[1])
		if err != nil {
			fmt.Printf("err: %s\n", err)
			panic(err)
		}
		c := inputs[2]
		// fmt.Println(a, b, c)

		if c == "keep" {
			amount += b - a
		}
	}
	fmt.Println(amount)
}
