package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// 標準入力を1行読み込み、スペースで分割し、数値に変換
	scanner := bufio.NewScanner(os.Stdin)
	if !scanner.Scan() {
		return
	}
	line := scanner.Text()

	inputs := strings.Fields(line)

	var numbers []int
	// var numbers []float64
	for _, str := range inputs {
		num, err := strconv.Atoi(str)
		// num, err := strconv.ParseFloat(str, 64)
		if err != nil {
			fmt.Printf("str includes value that is not number: %s\n", str)
		}
		numbers = append(numbers, num)
	}

	height_cm := numbers[0]
	// height_m := height_cm / 100
	weight_kg := numbers[1]

	// bmi := weight_kg / height_m / height_m
	// bmi >= 25
	//
	// weight_kg * 100 * 100 / height_cm / height_cm >= 25
	greater_than_25 := (weight_kg*100*100 >= 25*height_cm*height_cm)

	// if bmi >= 25 {
	if greater_than_25 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
