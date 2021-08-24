module github.com/monotrade/platform

go 1.13

replace github.com/monotrade/api => ../api

require (
	git.apache.org/thrift.git v0.13.0
	github.com/AsynkronIT/protoactor-go v0.0.0-20200317173033-c483abfa40e2
	github.com/apache/thrift v0.13.0
	github.com/monotrade/api v0.0.0
)
