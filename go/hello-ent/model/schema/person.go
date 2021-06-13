package schema

import (
	"time"

	"entgo.io/ent"
	"entgo.io/ent/schema/field"
)

type Person struct {
	ent.Schema
}

func (Person) Fields() []ent.Field {
	return []ent.Field{
		field.String("email").Unique(),
		field.Int("age"),
		field.String("first_name"),
		field.String("last_name"),
		field.Time("created_at").Default(time.Now),
	}
}
