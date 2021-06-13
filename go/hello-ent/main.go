package main

import (
	"context"
	"hello-ent/model"
	"log"

	_ "github.com/lib/pq"
)

func main() {
	client, err := model.Open(
		"postgres",
		"host=127.0.0.1 port=5432 user=postgres dbname=pgsql password=postgres sslmode=disable",
	)
	if err != nil {
		log.Fatal(err)
	}

	defer client.Close()

	ctx := context.Background()

	if err := client.Schema.Create(ctx); err != nil {
		log.Println(err)

		return
	}

	p, err := client.Person.Create().SetEmail("parham.alvani@gmail.com").
		SetAge(28).SetFirstName("Parham").SetLastName("Alvani").Save(ctx)
	if err != nil {
		log.Println(err)

		return
	}

	log.Println(p)
}
