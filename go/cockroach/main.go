package main

import (
	"log"
	"time"

	"go.uber.org/zap"
	"gorm.io/driver/postgres"
	"gorm.io/gorm"
	"moul.io/zapgorm2"
)

type User struct {
	gorm.Model
	ID       int `gorm:"primaryKey"`
	Name     string
	Email    string
	Birthday time.Time
}

func main() {
	logger, err := zap.NewDevelopment()
	if err != nil {
		logger = zap.NewNop()
	}

	dsn := "postgresql://root@127.0.0.1:26257/defaultdb?sslmode=disable"

	// nolint: exhaustivestruct, exhaustruct, varnamelen
	db, err := gorm.Open(postgres.Open(dsn), &gorm.Config{
		Logger: zapgorm2.New(logger),
	})
	if err != nil {
		log.Fatal(err)
	}

	// migrate the schema with gorm migrator manually
	// nolint: exhaustivestruct, exhaustruct
	if err := db.Migrator().DropTable(&User{}); err != nil {
		log.Fatal(err)
	}

	// nolint: exhaustivestruct, exhaustruct
	if err := db.Migrator().CreateTable(&User{}); err != nil {
		log.Fatal(err)
	}

	birthday, err := time.Parse("2 January 2006 at 15:04 -0700", "12 October 1999 at 19:20 +0330")
	if err != nil {
		log.Fatal(err)
	}

	// create user with gorm
	// nolint: exhaustivestruct, exhaustruct
	db.Create(&User{
		ID:       1,
		Name:     "Elahe Dastan",
		Email:    "elahe.dstn@gmail.com",
		Birthday: birthday,
	})

	var user User

	db.First(&user, 1)
	logger.Info("first user from database", zap.Any("user", user))

	var users []User

	db.Find(&users)
	logger.Info("users from database", zap.Any("users", users))
}
