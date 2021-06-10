package handler_test

import (
	"bytes"
	"fmt"
	"hello-multipart/handler"
	"mime/multipart"
	"net/http"
	"net/http/httptest"
	"testing"

	"github.com/labstack/echo/v4"
	"github.com/stretchr/testify/suite"
)

type HandlerTestSuite struct {
	suite.Suite
}

func (suite *HandlerTestSuite) TestFormValue() {
	require := suite.Require()
	e := echo.New()

	body := bytes.NewBuffer(make([]byte, 0))

	reqWriter := multipart.NewWriter(body)
	require.NoError(reqWriter.WriteField("k1", "Hello World"))
	reqWriter.Close()

	req := httptest.NewRequest(http.MethodPost, "/", body)
	req.Header.Set(echo.HeaderContentType, fmt.Sprintf("%s; boundary=%s", echo.MIMEMultipartForm, reqWriter.Boundary()))

	rec := httptest.NewRecorder()

	ctx := e.NewContext(req, rec)

	require.NoError(handler.Handler(ctx))
}

func TestHandler(t *testing.T) {
	suite.Run(t, new(HandlerTestSuite))
}
