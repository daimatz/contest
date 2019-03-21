package main

import "fmt"

func main() {
	var n, m uint
	fmt.Scan(&n)
	fmt.Scan(&m)

	cache := (1 << m) - 1

	for i := uint(0); i < n; i++ {
		var k uint
		fmt.Scan(&k)
		like := 0
		for j := uint(0); j < k; j++ {
			var t uint
			fmt.Scan(&t)
			like |= (1 << (t - 1))
		}
		cache = cache & like
	}

	res := 0
	for i := uint(0); i < m; i++ {
		if cache&(1<<i) != 0 {
			res++
		}
	}

	fmt.Println(res)
}
