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

package redis_test

import (
	"testing"

	"github.com/go-redis/redis"
	"github.com/vmihailenco/msgpack"
)

type student struct {
	Name   string
	Family string
}

func TestMain(t *testing.T) {
	client := redis.NewClient(&redis.Options{
		Addr:     "localhost:6379",
		Password: "", // no password set
		DB:       0,  // use default DB
	})

	pong, err := client.Ping().Result()
	if err != nil {
		t.Fatalf("Ping Error: %s", err)
	}

	t.Logf("Ping Success: %s", pong)

	s1, err := msgpack.Marshal(student{
		Name:   "Parham",
		Family: "Alvani",
	})
	if err != nil {
		t.Fatalf("Student to msgpack marshaling: %s", err)
	}

	t.Log(client.RPush("students-list", s1).Result())

	s2, err := msgpack.Marshal(student{
		Name:   "Navid",
		Family: "Mashayekhi",
	})
	if err != nil {
		t.Fatalf("Student to msgpack marshaling: %s", err)
	}

	t.Log(client.RPush("students-list", s2).Result())

	var s3 student

	result, err := client.RPop("students-list").Bytes()
	if err != nil {
		t.Fatalf("Pop Error: %s", err)
	}

	if err := msgpack.Unmarshal(result, &s3); err != nil {
		t.Fatalf("Msgpack to student unmarshaling: %s", err)
	}

	t.Log(s3)
}
