/*
 *
 * In The Name of God
 *
 * +===============================================
 * | Author:        Parham Alvani <parham.alvani@gmail.com>
 * |
 * | Creation Date: 27-12-2019
 * |
 * | File Name:     main.go
 * +===============================================
 */

package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"time"

	"github.com/hashicorp/hil"
	"github.com/hashicorp/hil/ast"
)

func main() {
	name := "main.rjn"

	tmpl, err := ioutil.ReadFile(name)
	if err != nil {
		log.Fatal(err)
	}

	tree, err := hil.Parse(string(tmpl))
	if err != nil {
		log.Fatal(err)
	}

	date := ast.Function{
		ArgTypes:   []ast.Type{},
		ReturnType: ast.TypeString,
		Variadic:   false,
		Callback: func(inputs []interface{}) (interface{}, error) {
			return time.Now().Format("01-01-2006"), nil
		},
	}

	for _, name := range []string{"P1", "P2", "P2"} {
		config := &hil.EvalConfig{
			GlobalScope: &ast.BasicScope{
				VarMap: map[string]ast.Variable{
					"name": {
						Type:  ast.TypeString,
						Value: name,
					},
				},
				FuncMap: map[string]ast.Function{
					"date": date,
				},
			},
		}

		result, err := hil.Eval(tree, config)
		if err != nil {
			log.Fatal(err)
		}

		fmt.Printf("%s\n", result.Value)
	}
}
