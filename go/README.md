# Go

## Projects

### [Array](array)

Creates arrays and slices. It tries to demo some features of Go in Array.

### [Beehive Hello](beehive-hello)

Hello world example in [beehive](https://github.com/kandoo/beehive).

### [Cast](cast)

Type switch and Interface cast example.

### [Closures](closures)

How do closures work with upper scope variables?

### [Conditional Variable](condvar)

Introduction to go conditional variables.

### [defer](defer)

Go Defer Here and Now!

### [echo-server](echo-server)

Says back everything you say to it.

### [fibonacci](fibonacci)

Fibonacci sequence in Go.

### [go-c](go-c)

Adds some C to Go. :yum:

### [monte-carlo](monte-carlo)

Monte-Carlo method for estimating the PI. check [here](https://academo.org/demos/estimating-pi-monte-carlo/) for more information.

### [Once](once)

Go uses zero initiation but sometimes you want some initiation and you want it lazy ...

### [Redis](redis)

Let's use redis as a cache with MessagePack coding

### [roy](roy)

In the Memory of Roya Taheri.

### [rwp](rwp)

The reader-writer-problem in Go.

### [twiddle](twiddle)

[Stackoverflow](https://stackoverflow.com/questions/47778453/generate-combinations-permutation-of-specific-length)

## Introduction

Golang is an awesome language but it filters our country. It is similar to C programming.
We can use it for writing code as terminal applications or servers.

## Go Modules

In Go 1.16, module-aware commands report an error after discovering a problem in go.mod or go.sum instead of attempting to fix the problem automatically. In most cases, the error message recommends a command to fix the problem.

## gotip

The gotip command compiles and runs the go command from the development tree. To install, run:

```sh
go install golang.org/dl/gotip@latest
gotip download
```

And then use the gotip command as if it were your normal go command.

To update, run /gotip download/ again. This will always download the main branch. To download an alternative branch, run /gotip download BRANCH/. To download a specific CL, run /gotip download NUMBER/.

## libc

you can control to use `cgo` with `CGO_ENABLED` flag in go build. we have different implementation of c library.

- GNU C Library (glibc)
- musl
- Microsoft C Runtime Library

## Testing

to test with go, /testify/ is an awesome library. it has suite, require and assert.

[Testify - Thou Shalt Write Tests](https:pkg.go.dev/github.com/stretchr/testify)

always use `_test` package for tests but in case of internal tests use `_internal_test.go` as filename.

```go
// Define the suite, and absorb the built-in basic suite
// functionality from testify - including a T() method which
// returns the current testing context
type ExampleTestSuite struct {
    suite.Suite
    VariableThatShouldStartAtFive int
}

// Make sure that VariableThatShouldStartAtFive is set to five
// before each test
func (suite *ExampleTestSuite) SetupTest() {
    suite.VariableThatShouldStartAtFive = 5
}

// All methods that begin with "Test" are run as tests within a
// suite.
func (suite *ExampleTestSuite) TestExample() {
    assert.Equal(suite.T(), 5, suite.VariableThatShouldStartAtFive)
    suite.Equal(5, suite.VariableThatShouldStartAtFive)
}

// In order for 'go test' to run this suite, we need to create
// a normal test function and pass our suite to suite.Run
func TestExampleTestSuite(t *testing.T) {
    suite.Run(t, new(ExampleTestSuite))
}
```

```go
// SetupAllSuite has a SetupSuite method, which will run before the
// tests in the suite are run.
type SetupAllSuite interface {
	SetupSuite()
}

// SetupTestSuite has a SetupTest method, which will run before each
// test in the suite.
type SetupTestSuite interface {
	SetupTest()
}

// TearDownAllSuite has a TearDownSuite method, which will run after
// all the tests in the suite have been run.
type TearDownAllSuite interface {
	TearDownSuite()
}

// TearDownTestSuite has a TearDownTest method, which will run after
// each test in the suite.
type TearDownTestSuite interface {
	TearDownTest()
}

// BeforeTest has a function to be executed right before the test
// starts and receives the suite and test names as input
type BeforeTest interface {
	BeforeTest(suiteName, testName string)
}

// AfterTest has a function to be executed right after the test
// finishes and receives the suite and test names as input
type AfterTest interface {
	AfterTest(suiteName, testName string)
}

// WithStats implements HandleStats, a function that will be executed
// when a test suite is finished. The stats contain information about
// the execution of that suite and its tests.
type WithStats interface {
	HandleStats(suiteName string, stats *SuiteInformation)
}
```

writing tests with /testify/ is awesome, so use them. also I write tests with mock for the higher modules and tests the low level one with the real dependencies.
for application that has really good mocks like redis, I have used them instead of real one.

## ORMs

### Gorm

gorm is a go's object relational mapping.

[gorm.io/gorm](https://pkg.go.dev/gorm.io/gorm)
[gorm.io/driver/postgres](https://pkg.go.dev/gorm.io/driver/postgres)
[gorm.io/driver/mysql](https://pkg.go.dev/gorm.io/driver/mysql)
[gorm.io/driver/sqlite](https://pkg.go.dev/gorm.io/driver/sqlite)

please note that by using the postgres driver you have the whole world dependencies in your go.sum.

```go
import (
	"gorm.io/gorm"
	"gorm.io/driver/postgres"
	"moul.io/zapgorm2"
)

func main() {
	logger, err := zap.NewDevelopment()
	if err != nil {
		logger = zap.NewNop()
	}

	db, err := gorm.Open(postgres.Open(dsn), &gorm.Config{
		Logger: zapgorm2.New(logger),
	})
}
```

```go
type User struct {
	ID uint
	FirstName string

	CreatedAt time.Time
	DeletedAt time.Time
}


db.Where("name = ?", "parham").Last()
db.Where("name = ?", "parham").First()
db.Where("name = ?", "parham").Find()
```

- /User/ (structure) : plural snake-case as table name
- /ID/ (field) : primary-key by default, _please pay attention_
- /FirstName/ (field) : snake-case as column name

Hooks as methods on model.

#### JSON with SQL

You can also create custom json based data-types with the following example:

```go
// JSONMap defiend JSON data type, need to implements driver.Valuer, sql.Scanner interface
type JSONMap map[string]interface{}

// Value return json value, implement driver.Valuer interface
func (m JSONMap) Value() (driver.Value, error) {
  if m == nil {
    return nil, nil
  }
  ba, err := m.MarshalJSON()
  return string(ba), err
}

// Scan scan value into Jsonb, implements sql.Scanner interface
func (m *JSONMap) Scan(val interface{}) error {
  var ba []byte
  switch v := val.(type) {
  case []byte:
    ba = v
  case string:
    ba = []byte(v)
  default:
    return errors.New(fmt.Sprint("Failed to unmarshal JSONB value:", val))
  }
  t := map[string]interface{}{}
  err := json.Unmarshal(ba, &t)
  *m = JSONMap(t)
  return err
}

// MarshalJSON to output non base64 encoded []byte
func (m JSONMap) MarshalJSON() ([]byte, error) {
  if m == nil {
    return []byte("null"), nil
  }
  t := (map[string]interface{})(m)
  return json.Marshal(t)
}

// UnmarshalJSON to deserialize []byte
func (m *JSONMap) UnmarshalJSON(b []byte) error {
  t := map[string]interface{}{}
  err := json.Unmarshal(b, &t)
  *m = JSONMap(t)
  return err
}

// GormDataType gorm common data type
func (m JSONMap) GormDataType() string {
  return "jsonmap"
}

// GormDBDataType gorm db data type
func (JSONMap) GormDBDataType(db *gorm.DB, field *schema.Field) string {
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
```

### Ent

ent is a simple, yet powerful entity framework for Go, that makes it easy to build and maintain applications with large data-models and sticks with the following principles:

- Easily model database schema as a graph structure.
- Define schema as a programmatic Go code.
- Static typing based on code generation.
- Database queries and graph traversals are easy to write.
- Simple to extend and customize using Go templates.

[Quick Introduction](https://entgo.io/docs/getting-started/)

```go
package schema

import "entgo.io/ent"

// User holds the schema definition for the User entity.
type User struct {
  ent.Schema
}

// Fields of the User.
func (User) Fields() []ent.Field {
  return nil
}

// Edges of the User.
func (User) Edges() []ent.Edge {
  return nil
}
```

based on the written schema then you need to generate the ent code and after that you can do whatever you want with the ent.

## Logging

as I said there are two applications for golang. in the terminal application it is better to use [pterm](https://pterm.sh) to show the logs and other information.
in case of the server application [zap](https://github.com/uber-go/zap) is a better choice because it has structure logging an you can also write the logs on console and syslog at the same time.

## Telemetry

The current status of the major functional components for OpenTelemetry Go is as follows:

| Tracing | Metrics | Logging             |
| ------- | ------- | ------------------- |
| Beta    | Alpha   | Not Yet Implemented |

With this release we are introducing a split in module versions. The tracing API and SDK are entering the v1.0.0 Release Candidate phase with v1.0.0-RC1 while the experimental metrics API and SDK continue with v0.x releases at v0.21.0. Modules at major version 1 or greater will not depend on modules with major version 0.

[OpenTelemetry Go API and SDK](https://github.com/open-telemetry/opentelemetry-go)

### Exporter

The SDK requires an exporter to be created. Exporters are packages that allow telemetry data to be emitted somewhere - either to the console (which is what we’re doing here), or to a remote system or collector for further analysis and/or enrichment. OpenTelemetry supports a variety of exporters through its ecosystem including popular open source tools like Jaeger, Zipkin, and Prometheus.

```go
import stdout "go.opentelemetry.io/otel/exporters/stdout/stdouttrace"

func main() {
	exporter, err := stdout.New(
		stdout.WithPrettyPrint(),
	)
	if err != nil {
		log.Fatalf("failed to initialize stdout export pipeline: %v", err)
	}
}
```

Exporter depend on the task and the service for example the Jaeger exporter is in the following package:

```go
import "go.opentelemetry.io/otel/exporters/jaeger"
```

### Tracer Provider

This block of code will create a new batch span processor, a type of span processor that batches up multiple spans over a period of time, that writes to the exporter we created in the previous step.

```go
	ctx := context.Background()

	bsp := sdktrace.NewBatchSpanProcessor(exporter)
	s := sdktrace.AlwaysSampler()
	tp := sdktrace.NewTracerProvider(sdktrace.WithSpanProcessor(bsp), sdktrace.WithSampler(s))

	// Handle this error in a sensible manner where possible
	defer func() { _ = tp.Shutdown(ctx) }()
```

OpenTelemetry requires a trace provider to be initialized in order to generate traces. A trace provider can have multiple span processors, which are components that allow for span data to be modified or exported after it’s created.

### Quick Start

First, we’re asking the global trace provider for an instance of a tracer, which is the object that manages spans for our service.

```go
tracer := otel.Tracer("ex.com/basic")
ctx = baggage.ContextWithValues(ctx,
    fooKey.String("foo1"),
    barKey.String("bar1"),
)

func(ctx context.Context) {
    var span trace.Span
    ctx, span = tracer.Start(ctx, "operation")
    defer span.End()

    span.AddEvent("Nice operation!", trace.WithAttributes(attribute.Int("bogons", 100)))
    span.SetAttributes(anotherKey.String("yes"))

    meter.RecordBatch(
        // Note: call-site variables added as context Entries:
        baggage.ContextWithValues(ctx, anotherKey.String("xyz")),
        commonAttributes,

        valueRecorder.Measurement(2.0),
    )

    func(ctx context.Context) {
        var span trace.Span
        ctx, span = tracer.Start(ctx, "Sub operation...")
        defer span.End()

        span.SetAttributes(lemonsKey.String("five"))
        span.AddEvent("Sub span event")
        boundRecorder.Record(ctx, 1.3)
    }(ctx)
}(ctx)
```

### Contribution

There are tracers for internals of go libraries available at opentelemetry-go-contrib with experimental version v0.21.0:

- [mongodb](https://github.com/open-telemetry/opentelemetry-go-contrib/tree/main/instrumentation/go.mongodb.org/mongo-driver/mongo/otelmongo)
- [echo](https://github.com/open-telemetry/opentelemetry-go-contrib/tree/main/instrumentation/github.com/labstack/echo/otelecho)

## RabbitMQ

There is an official library for AMQP in Golang:

[An AMQP 0-9-1 Go client maintained by the RabbitMQ team](https://github.com/rabbitmq/amqp091-go)

Also there is another official library for Streams in Golang:

[A client library for RabbitMQ streams](https://github.com/rabbitmq/rabbitmq-stream-go-client)

## MQTT

the pure go implementation of mqtt protocol is available from [paho.mqtt.golang](https://github.com/eclipse/paho.mqtt.golang).

```go
	c.setConnected(connected)
	DEBUG.Println(CLI, "client is connected/reconnected")
	if c.options.OnConnect != nil {
		go c.options.OnConnect(c)
	}
```

this implementation works great and you must not forget to re-subscribe on connection lost. to this just subscribe with on-connect.

## ToRead

- [BadgerDB is an embeddable, persistent and fast key-value (KV) database written in pure Go.](https://github.com/dgraph-io/badger)
- https://github.com/hibiken/asynq
