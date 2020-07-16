package main

import (
	"fmt"
	"net/http"

	"github.com/labstack/echo/v4"
)

func main() {
	e := echo.New()
	e.GET("/hello", func(c echo.Context) error {
		return c.JSON(
			http.StatusOK,
			struct {
				Message string
			}{
				Message: fmt.Sprintf("Hello Elahe from %s!", c.Request().Header.Get("X-From")),
			},
		)
	})
	e.Logger.Fatal(e.Start(":1378"))
}
