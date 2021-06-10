package handler

import (
	"log"
	"net/http"

	"github.com/labstack/echo/v4"
)

func Handler(c echo.Context) error {
	log.Printf("Content-Type: %s", c.Request().Header.Get(echo.HeaderContentType))

	v1 := c.FormValue("k1")
	if v1 == "" {
		return echo.NewHTTPError(http.StatusBadRequest, "there is no value for k1")
	}

	log.Printf("k1 has %s", v1)

	return c.JSON(http.StatusOK, "everything is awesome")
}
