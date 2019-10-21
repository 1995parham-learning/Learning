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

package redis

import (
	"fmt"
	"testing"

	"github.com/go-redis/redis"
)

// Truck is a yogurt truck
type Truck struct {
	ID        int
	Ready     int
	Latitude  float64
	Longitude float64
}

func TestMain(t *testing.T) {
	client := redis.NewClient(&redis.Options{
		Addr: "localhost:9851",
	})

	pong, err := client.Ping().Result()
	if err != nil {
		t.Fatalf("ping error: %s", err)
	}
	t.Logf("ping success: %s", pong)

	pipe := client.Pipeline()

	trucks := []Truck{
		Truck{
			ID:        2,
			Ready:     0,
			Latitude:  35.8138692,
			Longitude: 51.4023944,
		},
	}

	// register the trucks in tile38
	for _, truck := range trucks {
		set := redis.NewStringCmd(
			"SET",
			"trucks",
			truck.ID,
			"FIELD",
			"ready",
			truck.Ready,
			"POINT",
			truck.Latitude,
			truck.Longitude,
		)
		if err := pipe.Process(set); err != nil {
			t.Fatalf("pipe process error %s", err)
		}
	}

	trucks = []Truck{
		Truck{
			ID:        1,
			Ready:     1,
			Latitude:  35.8138692,
			Longitude: 51.4023944,
		},
		Truck{
			ID:        2,
			Ready:     1,
			Latitude:  35.8138692,
			Longitude: 51.4023944,
		},
	}

	for _, truck := range trucks {
		fset := redis.NewStringCmd(
			"FSET",
			"trucks",
			truck.ID,
			"ready",
			truck.Ready,
		)
		if err := pipe.Process(fset); err != nil {
			t.Fatalf("pipe process error %s", err)
		}
	}

	cmds, err := pipe.Exec()
	if err != nil {
		t.Logf("pipe execution error %s", err)
	}
	for i, cmd := range cmds {
		fmt.Println(i)
		err := cmd.Err()
		if err != nil {
			t.Logf("pipeline error %s (%d)", err, i)
		}
	}

	trucks = make([]Truck, 0)
	for i := 10; i < 19*1000; i++ {
		trucks = append(trucks, Truck{
			ID: i,
		})
	}

	for _, truck := range trucks {
		set := redis.NewStringCmd(
			"SET",
			"trucks",
			truck.ID,
			"FIELD",
			"ready",
			truck.Ready,
			"POINT",
			truck.Latitude,
			truck.Longitude,
		)
		if err := pipe.Process(set); err != nil {
			t.Fatalf("pipe process error %s", err)
		}
	}

	cmds, err = pipe.Exec()
	if err != nil {
		t.Logf("pipe execution error %s", err)
	}
	for i, cmd := range cmds {
		fmt.Println(i)
		err := cmd.Err()
		if err != nil {
			t.Logf("pipeline error %s (%d)", err, i)
		}
	}
}
