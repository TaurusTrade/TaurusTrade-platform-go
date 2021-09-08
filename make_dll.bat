set GOARCH=386
set CGO_ENABLED=1
go build -ldflags "-s -w" -buildmode=c-shared -o taurustrade.dll main.go
