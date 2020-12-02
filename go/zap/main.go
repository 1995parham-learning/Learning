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

import "go.uber.org/zap"

func main() {
	logger, err := zap.NewDevelopment()
	if err != nil {
		panic(err)
	}

	sugar := logger.Named("main").WithOptions(zap.Fields(zap.Any("parent", 12.2))).Sugar()

	sugar.Infow("Everything is up and running", "key", 1)
}
