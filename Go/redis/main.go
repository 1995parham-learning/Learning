/*
 *
 * In The Name of God
 *
 * +===============================================
 * | Author:        Parham Alvani <parham.alvani@gmail.com>
 * |
 * | Creation Date: 10-07-2018
 * |
 * | File Name:     main.go
 * +===============================================
 */

package main

import (
	"encoding/json"
	"fmt"

	"github.com/go-redis/redis"
)

type student struct {
	Name   string
	Family string
}

func main() {
	client := redis.NewClient(&redis.Options{
		Addr:     "localhost:6379",
		Password: "", // no password set
		DB:       0,  // use default DB
	})

	pong, err := client.Ping().Result()
	fmt.Println(pong, err)

	s1, _ := json.Marshal(student{
		Name:   "Parham",
		Family: "Alvani",
	})
	fmt.Println(client.RPush("cache", s1).Result())

	s2, _ := json.Marshal(student{
		Name:   "Navid",
		Family: "Mashayekhi",
	})

	fmt.Println(client.RPush("cache", s2).Result())

	var s3 student
	result, err := client.RPop("cache").Bytes()
	json.Unmarshal(result, &s3)
	fmt.Println(s3)
}
