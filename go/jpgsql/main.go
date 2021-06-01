package main

import (
	"jpgsql/model"

	_ "github.com/jackc/pgtype"
	"go.uber.org/zap"
	"gorm.io/driver/postgres"
	"gorm.io/gorm"
)

func main() {
	logger, err := zap.NewDevelopment()
	if err != nil {
		logger = zap.NewNop()
	}

	dsn := "host=localhost user=postgres password=postgres dbname=pgsql port=5432 sslmode=disable TimeZone=Asia/Tehran"

	// nolint: exhaustivestruct
	db, err := gorm.Open(postgres.Open(dsn), &gorm.Config{})
	if err != nil {
		logger.Fatal("database connection failed", zap.Error(err))
	}

	// nolint: exhaustivestruct
	if err := db.AutoMigrate(model.User{}); err != nil {
		logger.Fatal("database migration failed", zap.Error(err))
	}

	// nolint: exhaustivestruct
	u := model.User{
		ID: 1,
		Metadata: map[string]string{
			"hello": "world",
			"bye":   "world",
		},
	}

	if err := db.Create(&u).Error; err != nil {
		logger.Fatal("user creation failed", zap.Error(err))
	}

	var users []model.User

	if err := db.Find(&users).Error; err != nil {
		logger.Fatal("users loading failed", zap.Error(err))
	}

	logger.Info("users", zap.Any("users", users))
}
