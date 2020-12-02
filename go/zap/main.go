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
	"log"
	"os"

	"go.uber.org/zap"
	"go.uber.org/zap/zapcore"
)

func main() {
	w := zapcore.AddSync(os.Stdout)

	core := zapcore.NewCore(
		zapcore.NewJSONEncoder(zap.NewDevelopmentEncoderConfig()),
		w,
		zap.InfoLevel,
	)

	logger := zap.New(core)

	defer func() {
		if err := logger.Sync(); err != nil {
			log.Printf("logs doesn't sync: %s", err)
		}
	}()

	sugar := logger.Named("main").WithOptions(zap.Fields(zap.Any("parent", 12.2))).Sugar()

	sugar.Infow("Everything is up and running", "key", 1)
}
