// Code generated by entc, DO NOT EDIT.

package model

import (
	"context"
	"errors"
	"fmt"
	"hello-ent/model/person"
	"time"

	"entgo.io/ent/dialect/sql/sqlgraph"
	"entgo.io/ent/schema/field"
)

// PersonCreate is the builder for creating a Person entity.
type PersonCreate struct {
	config
	mutation *PersonMutation
	hooks    []Hook
}

// SetEmail sets the "email" field.
func (pc *PersonCreate) SetEmail(s string) *PersonCreate {
	pc.mutation.SetEmail(s)
	return pc
}

// SetAge sets the "age" field.
func (pc *PersonCreate) SetAge(i int) *PersonCreate {
	pc.mutation.SetAge(i)
	return pc
}

// SetFirstName sets the "first_name" field.
func (pc *PersonCreate) SetFirstName(s string) *PersonCreate {
	pc.mutation.SetFirstName(s)
	return pc
}

// SetLastName sets the "last_name" field.
func (pc *PersonCreate) SetLastName(s string) *PersonCreate {
	pc.mutation.SetLastName(s)
	return pc
}

// SetCreatedAt sets the "created_at" field.
func (pc *PersonCreate) SetCreatedAt(t time.Time) *PersonCreate {
	pc.mutation.SetCreatedAt(t)
	return pc
}

// SetNillableCreatedAt sets the "created_at" field if the given value is not nil.
func (pc *PersonCreate) SetNillableCreatedAt(t *time.Time) *PersonCreate {
	if t != nil {
		pc.SetCreatedAt(*t)
	}
	return pc
}

// Mutation returns the PersonMutation object of the builder.
func (pc *PersonCreate) Mutation() *PersonMutation {
	return pc.mutation
}

// Save creates the Person in the database.
func (pc *PersonCreate) Save(ctx context.Context) (*Person, error) {
	var (
		err  error
		node *Person
	)
	pc.defaults()
	if len(pc.hooks) == 0 {
		if err = pc.check(); err != nil {
			return nil, err
		}
		node, err = pc.sqlSave(ctx)
	} else {
		var mut Mutator = MutateFunc(func(ctx context.Context, m Mutation) (Value, error) {
			mutation, ok := m.(*PersonMutation)
			if !ok {
				return nil, fmt.Errorf("unexpected mutation type %T", m)
			}
			if err = pc.check(); err != nil {
				return nil, err
			}
			pc.mutation = mutation
			node, err = pc.sqlSave(ctx)
			mutation.done = true
			return node, err
		})
		for i := len(pc.hooks) - 1; i >= 0; i-- {
			mut = pc.hooks[i](mut)
		}
		if _, err := mut.Mutate(ctx, pc.mutation); err != nil {
			return nil, err
		}
	}
	return node, err
}

// SaveX calls Save and panics if Save returns an error.
func (pc *PersonCreate) SaveX(ctx context.Context) *Person {
	v, err := pc.Save(ctx)
	if err != nil {
		panic(err)
	}
	return v
}

// defaults sets the default values of the builder before save.
func (pc *PersonCreate) defaults() {
	if _, ok := pc.mutation.CreatedAt(); !ok {
		v := person.DefaultCreatedAt()
		pc.mutation.SetCreatedAt(v)
	}
}

// check runs all checks and user-defined validators on the builder.
func (pc *PersonCreate) check() error {
	if _, ok := pc.mutation.Email(); !ok {
		return &ValidationError{Name: "email", err: errors.New("model: missing required field \"email\"")}
	}
	if _, ok := pc.mutation.Age(); !ok {
		return &ValidationError{Name: "age", err: errors.New("model: missing required field \"age\"")}
	}
	if _, ok := pc.mutation.FirstName(); !ok {
		return &ValidationError{Name: "first_name", err: errors.New("model: missing required field \"first_name\"")}
	}
	if _, ok := pc.mutation.LastName(); !ok {
		return &ValidationError{Name: "last_name", err: errors.New("model: missing required field \"last_name\"")}
	}
	if _, ok := pc.mutation.CreatedAt(); !ok {
		return &ValidationError{Name: "created_at", err: errors.New("model: missing required field \"created_at\"")}
	}
	return nil
}

func (pc *PersonCreate) sqlSave(ctx context.Context) (*Person, error) {
	_node, _spec := pc.createSpec()
	if err := sqlgraph.CreateNode(ctx, pc.driver, _spec); err != nil {
		if cerr, ok := isSQLConstraintError(err); ok {
			err = cerr
		}
		return nil, err
	}
	id := _spec.ID.Value.(int64)
	_node.ID = int(id)
	return _node, nil
}

func (pc *PersonCreate) createSpec() (*Person, *sqlgraph.CreateSpec) {
	var (
		_node = &Person{config: pc.config}
		_spec = &sqlgraph.CreateSpec{
			Table: person.Table,
			ID: &sqlgraph.FieldSpec{
				Type:   field.TypeInt,
				Column: person.FieldID,
			},
		}
	)
	if value, ok := pc.mutation.Email(); ok {
		_spec.Fields = append(_spec.Fields, &sqlgraph.FieldSpec{
			Type:   field.TypeString,
			Value:  value,
			Column: person.FieldEmail,
		})
		_node.Email = value
	}
	if value, ok := pc.mutation.Age(); ok {
		_spec.Fields = append(_spec.Fields, &sqlgraph.FieldSpec{
			Type:   field.TypeInt,
			Value:  value,
			Column: person.FieldAge,
		})
		_node.Age = value
	}
	if value, ok := pc.mutation.FirstName(); ok {
		_spec.Fields = append(_spec.Fields, &sqlgraph.FieldSpec{
			Type:   field.TypeString,
			Value:  value,
			Column: person.FieldFirstName,
		})
		_node.FirstName = value
	}
	if value, ok := pc.mutation.LastName(); ok {
		_spec.Fields = append(_spec.Fields, &sqlgraph.FieldSpec{
			Type:   field.TypeString,
			Value:  value,
			Column: person.FieldLastName,
		})
		_node.LastName = value
	}
	if value, ok := pc.mutation.CreatedAt(); ok {
		_spec.Fields = append(_spec.Fields, &sqlgraph.FieldSpec{
			Type:   field.TypeTime,
			Value:  value,
			Column: person.FieldCreatedAt,
		})
		_node.CreatedAt = value
	}
	return _node, _spec
}

// PersonCreateBulk is the builder for creating many Person entities in bulk.
type PersonCreateBulk struct {
	config
	builders []*PersonCreate
}

// Save creates the Person entities in the database.
func (pcb *PersonCreateBulk) Save(ctx context.Context) ([]*Person, error) {
	specs := make([]*sqlgraph.CreateSpec, len(pcb.builders))
	nodes := make([]*Person, len(pcb.builders))
	mutators := make([]Mutator, len(pcb.builders))
	for i := range pcb.builders {
		func(i int, root context.Context) {
			builder := pcb.builders[i]
			builder.defaults()
			var mut Mutator = MutateFunc(func(ctx context.Context, m Mutation) (Value, error) {
				mutation, ok := m.(*PersonMutation)
				if !ok {
					return nil, fmt.Errorf("unexpected mutation type %T", m)
				}
				if err := builder.check(); err != nil {
					return nil, err
				}
				builder.mutation = mutation
				nodes[i], specs[i] = builder.createSpec()
				var err error
				if i < len(mutators)-1 {
					_, err = mutators[i+1].Mutate(root, pcb.builders[i+1].mutation)
				} else {
					// Invoke the actual operation on the latest mutation in the chain.
					if err = sqlgraph.BatchCreate(ctx, pcb.driver, &sqlgraph.BatchCreateSpec{Nodes: specs}); err != nil {
						if cerr, ok := isSQLConstraintError(err); ok {
							err = cerr
						}
					}
				}
				mutation.done = true
				if err != nil {
					return nil, err
				}
				id := specs[i].ID.Value.(int64)
				nodes[i].ID = int(id)
				return nodes[i], nil
			})
			for i := len(builder.hooks) - 1; i >= 0; i-- {
				mut = builder.hooks[i](mut)
			}
			mutators[i] = mut
		}(i, ctx)
	}
	if len(mutators) > 0 {
		if _, err := mutators[0].Mutate(ctx, pcb.builders[0].mutation); err != nil {
			return nil, err
		}
	}
	return nodes, nil
}

// SaveX is like Save, but panics if an error occurs.
func (pcb *PersonCreateBulk) SaveX(ctx context.Context) []*Person {
	v, err := pcb.Save(ctx)
	if err != nil {
		panic(err)
	}
	return v
}
