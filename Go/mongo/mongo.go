/*
 * +===============================================
 * | Author:        Parham Alvani <parham.alvani@gmail.com>
 * |
 * | Creation Date: 21-12-2017
 * |
 * | File Name:     mongo.go
 * +===============================================
 */

package main

import (
	"fmt"
	"log"

	"gopkg.in/mgo.v2"
	"gopkg.in/mgo.v2/bson"
)

type task struct {
	ID   *bson.ObjectId `json:"id" bson:"_id,omitempty"`
	Text string         `json:"text" bson:"text,omitempty"`
	// other params
}

func main() {
	session, err := mgo.Dial("127.0.0.1")
	if err != nil {
		log.Fatal(err)
	}

	c := session.DB("test").C("test")

	err = c.Insert(task{
		Text: "Hello",
	})
	if err != nil {
		log.Fatal(err)
	}

	var result task
	err = c.Find(task{
		ID:   nil,
		Text: "Hello",
	}).One(&result)
	if err != nil {
		log.Fatal(err)
	}

	fmt.Println(result)
}
