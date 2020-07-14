package main

import (
	"fmt"
	"log"
	"time"

	"gorm.io/driver/postgres"
	"gorm.io/gorm"
)

type User struct {
	gorm.Model
	ID       int `gorm:"primaryKey"`
	Name     string
	Email    string
	Birthday time.Time
}

func main() {
	dsn := "host=127.0.0.1 user=postgres password=postgres DB.name=pgsql port=5432 sslmode=disable"

	db, err := gorm.Open(postgres.Open(dsn), &gorm.Config{})
	if err != nil {
		log.Fatal(err)
	}

	// Migrate the schema
	if err := db.Migrator().DropTable(&User{}); err != nil {
		log.Fatal(err)
	}

	if err := db.Migrator().CreateTable(&User{}); err != nil {
		log.Fatal(err)
	}

	birthday, err := time.Parse("2 January 2006 at 15:04 -0700", "12 October 1999 at 19:20 +0330")
	if err != nil {
		log.Fatal(err)
	}

	// Create
	db.Create(&User{
		ID:       1,
		Name:     "Elahe Dastan",
		Email:    "elahe.dstn@gmail.com",
		Birthday: birthday,
	})

	var user User

	db.First(&user, 1)
	fmt.Println(user)
}
