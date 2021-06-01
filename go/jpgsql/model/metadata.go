package model

import (
	"database/sql/driver"
	"encoding/json"
	"fmt"

	"gorm.io/gorm"
	"gorm.io/gorm/schema"
)

// Metadata defiend JSON data type, need to implements driver.Valuer, sql.Scanner interface.
type Metadata map[string]string

// Value return json value, implement driver.Valuer interface.
func (m Metadata) Value() (driver.Value, error) {
	if m == nil {
		return nil, nil
	}

	ba, err := m.MarshalJSON()

	return string(ba), err
}

// Scan scan value into Jsonb, implements sql.Scanner interface.
func (m *Metadata) Scan(val interface{}) error {
	var ba []byte
	switch v := val.(type) {
	case []byte:
		ba = v
	case string:
		ba = []byte(v)
	default:
		return fmt.Errorf("failed to unmarshal jsonb value: %v", val)
	}

	t := map[string]string{}
	err := json.Unmarshal(ba, &t)
	*m = Metadata(t)

	return err
}

// MarshalJSON to output non base64 encoded []byte.
func (m Metadata) MarshalJSON() ([]byte, error) {
	if m == nil {
		return []byte("null"), nil
	}

	t := (map[string]string)(m)

	return json.Marshal(t)
}

// UnmarshalJSON to deserialize []byte.
func (m *Metadata) UnmarshalJSON(b []byte) error {
	var t map[string]string
	err := json.Unmarshal(b, &t)
	*m = Metadata(t)

	return err
}

// GormDataType gorm common data type.
func (m Metadata) GormDataType() string {
	return "metadata"
}

// GormDBDataType gorm db data type.
func (Metadata) GormDBDataType(db *gorm.DB, field *schema.Field) string {
	switch db.Dialector.Name() {
	case "sqlite":
		return "JSON"
	case "mysql":
		return "JSON"
	case "postgres":
		return "JSONB"
	}

	return ""
}
