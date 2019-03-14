package main

import (
  "fmt"
)

func main() {
  var H, W, h, w int
  fmt.Scan(&H)
  fmt.Scan(&W)
  fmt.Scan(&h)
  fmt.Scan(&w)
  fmt.Println((H-h)*(W-w))
}
