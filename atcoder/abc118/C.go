package main

import "fmt"

func getMin(a []int) int {
	min := -1
	for i := 0; i < len(a); i++ {
		if min == -1 || min > a[i] {
			min = a[i]
		}
	}
	return min
}

func main() {
	var n int
	fmt.Scan(&n)
	var a []int
	for i := 0; i < n; i++ {
		var temp int
		fmt.Scan(&temp)
		a = append(a, temp)
	}

	var ans int
	flag := true
	for flag {
		flag = false
		ans = getMin(a)
		for i := 0; i < n; i++ {
			if a[i]%ans > 0 {
				flag = true
				a[i] = a[i] % ans
			}
		}
	}

	fmt.Println(ans)
}
