all : clean	build

clean : 
	rm -f bin/*

build : src/grader.cpp src/lib/libsandbox/platform.c src/lib/libsandbox/platform.h src/lib/libsandbox/internal.c src/lib/libsandbox/internal.h src/lib/libsandbox/sandbox.c src/lib/libsandbox/sandbox.h src/lib/libsandbox/config.h src/lib/SimpleJSON/JSON.cpp src/lib/SimpleJSON/JSONValue.cpp src/lib/SimpleJSON/JSON.h src/lib/SimpleJSON/JSONValue.h
	g++ src/grader.cpp src/lib/libsandbox/platform.c src/lib/libsandbox/internal.c src/lib/libsandbox/sandbox.c src/lib/SimpleJSON/JSON.cpp src/lib/SimpleJSON/JSONValue.cpp -o bin/grader.cgi -std=c++11 -pthread
	g++ src/normalizer.cpp -o bin/norm -std=c++11