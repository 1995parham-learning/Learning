package main

import (
	"log"
	"time"

	"github.com/getsentry/sentry-go"
	"github.com/rotisserie/eris"
)

var ErrChild = eris.New("i am child")

const SentryTimeout = 10 * time.Second

func child() error {
	return ErrChild
}

func parent() error {
	return eris.Wrap(child(), "i am parent")
}

func main() {
	if err := sentry.Init(sentry.ClientOptions{
		Dsn:         "sentry-url",
		Debug:       true,
		Environment: "Development",
	}); err != nil {
		log.Fatalf("sentry.Init: %s", err)
	}

	// Flush buffered events before the program terminates.
	defer func() {
		if ok := sentry.Flush(SentryTimeout); !ok {
			log.Print("Flush failed")
		}
	}()

	sentry.CaptureException(parent())
}
