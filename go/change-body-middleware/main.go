package main

import (
	"bufio"
	"bytes"
	"encoding/json"
	"errors"
	"io"
	"log"
	"net"
	"net/http"

	"github.com/labstack/echo/v4"
)

type DummyResponseWriter struct {
	io.Writer
	http.ResponseWriter
}

func (w *DummyResponseWriter) WriteHeader(code int) {
	w.ResponseWriter.WriteHeader(code)
}

func (w *DummyResponseWriter) Write(b []byte) (int, error) {
	// nolint: wrapcheck
	return w.Writer.Write(b)
}

func (w *DummyResponseWriter) Flush() {
	w.ResponseWriter.(http.Flusher).Flush()
}

func (w *DummyResponseWriter) Hijack() (net.Conn, *bufio.ReadWriter, error) {
	// nolint: wrapcheck
	return w.ResponseWriter.(http.Hijacker).Hijack()
}

func main() {
	app := echo.New()

	app.GET("/hello", func(c echo.Context) error {
		// nolint: wrapcheck
		return c.JSON(http.StatusOK, "Hello Elahe")
	}, func(next echo.HandlerFunc) echo.HandlerFunc {
		return func(c echo.Context) error {
			w := bytes.NewBufferString("")

			drw := &DummyResponseWriter{
				w,
				c.Response().Writer,
			}
			c.Response().Writer = drw

			if err := next(c); err != nil {
				return err
			}

			b, err := io.ReadAll(w)
			if err != nil {
				// nolint: wrapcheck
				return err
			}

			var data interface{}

			if err := json.Unmarshal(b, &data); err != nil {
				// nolint: wrapcheck
				return err
			}

			c.Response().Writer = drw.ResponseWriter

			// nolint: wrapcheck
			return c.JSON(http.StatusOK, struct {
				Data interface{}
				Name string
			}{
				Data: data,
				Name: "Elahe",
			})
		}
	})

	if err := app.Start(":1378"); !errors.Is(err, http.ErrServerClosed) {
		log.Fatal("echo initiation failed", err)
	}
}
