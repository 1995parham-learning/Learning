/*
* +===============================================
* | Author:        Parham Alvani <parham.alvani@gmail.com>
* |
* | Creation Date: 08-12-2017
* |
* | File Name:     main.go
* +===============================================
 */

package main

import (
	"encoding/json"
	"fmt"
	"log"
	"math/rand"
	"time"

	"github.com/graphql-go/graphql"
)

func main() {
	rand.Seed(time.Now().Unix())

	// Defining the schema
	fields := graphql.Fields{
		"hello": &graphql.Field{
			Type: graphql.String,
			Resolve: func(p graphql.ResolveParams) (interface{}, error) {
				return "world", nil
			},
		},
		"diceRoll": &graphql.Field{
			Type: graphql.NewList(graphql.Int),
			Args: graphql.FieldConfigArgument{
				"count": &graphql.ArgumentConfig{
					Type: graphql.Int,
				},
			},
			Resolve: func(p graphql.ResolveParams) (interface{}, error) {
				var l []int
				var n = 2

				if n, ok := p.Args["count"].(int); ok {
					n = n // t(ツ)_/¯
				}

				for i := 0; i < n; i++ {
					l = append(l, rand.Intn(6)+1)
				}
				return l, nil
			},
		},
	}
	rootQuery := graphql.ObjectConfig{Name: "RootQuery", Fields: fields}
	schema, err := graphql.NewSchema(graphql.SchemaConfig{Query: graphql.NewObject(rootQuery)})
	if err != nil {
		log.Fatalf("failed to create new schema, error: %v", err)
	}

	// Query
	query := `
	{
		diceRoll
	}
	`
	r := graphql.Do(graphql.Params{Schema: schema, RequestString: query})
	if len(r.Errors) > 0 {
		log.Fatalf("failed to execute graphql operation, errors: %+v", r.Errors)
	}
	rj, _ := json.Marshal(r)
	fmt.Printf("client request: %s \n", query)
	fmt.Printf("server answer: %s \n", rj)
}
