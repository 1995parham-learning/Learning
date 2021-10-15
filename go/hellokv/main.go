package main

import (
	"context"
	"log"

	"github.com/go-redis/redis/v8"
)

const (
	Key = "Elahe"
)

func main() {
	ctx := context.Background()

	// nolint: exhaustivestruct
	rdb := redis.NewClient(&redis.Options{
		Addr: "127.0.0.1:5379",
	})

	log.Printf("ping tidis to check its status")

	if err := rdb.Ping(ctx).Err(); err != nil {
		log.Fatalf("redis ping falied %s", err)
	}

	log.Printf("setting the new key on tidis")

	if err := rdb.SAdd(ctx, Key, "Parham", "Parham", "Panda", "Gobol").Err(); err != nil {
		log.Fatalf("set %s falied %s", Key, err)
	}

	log.Printf("getting the key from tidis")

	val, err := rdb.SMembers(ctx, Key).Result()
	if err != nil {
		log.Fatalf("get %s failed %s", Key, err)
	}

	log.Printf("%s: %s", Key, val)
}
