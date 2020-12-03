/*
 *
 * In The Name of God
 *
 * +===============================================
 * | Author:        Parham Alvani <parham.alvani@gmail.com>
 * |
 * | Creation Date: 02-12-2020
 * |
 * | File Name:     main.go
 * +===============================================
 */

package main

import (
	"log/syslog"
	"os"

	"github.com/tchap/zapext/zapsyslog"
	"go.uber.org/zap"
	"go.uber.org/zap/zapcore"
)

func main() {
	syslogEncoder := zapcore.NewJSONEncoder(zap.NewProductionEncoderConfig())
	consoleEncoder := zapcore.NewConsoleEncoder(zap.NewDevelopmentEncoderConfig())

	// Initialize a syslog writer.
	writer, err := syslog.Dial("tcp", "127.0.0.1:1514", syslog.LOG_ERR|syslog.LOG_LOCAL0, "zap-hello")
	if err != nil {
		panic(err)
	}

	core := zapcore.NewTee(
		zapcore.NewCore(consoleEncoder, zapcore.Lock(zapcore.AddSync(os.Stderr)), zapcore.InfoLevel),
		zapsyslog.NewCore(zapcore.ErrorLevel, syslogEncoder, writer),
	)

	// From a zapcore.Core, it's easy to construct a Logger.
	logger := zap.New(core)
	logger.Info("constructed a logger")

	defer func() {
		// ignore the sync error based on
		// https://github.com/uber-go/zap/issues/328
		err := logger.Sync()
		_ = err
	}()

	sugar := logger.Named("main").WithOptions(zap.Fields(zap.Any("version", 1))).Sugar()

	sugar.Infow("Everything is up and running", "key", 1)
	sugar.Errorw("There is an error", "key", 1378)
}
