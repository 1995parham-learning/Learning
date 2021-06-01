package model

import "gorm.io/gorm"

type User struct {
	gorm.Model
	ID       int
	Metadata Metadata
}
