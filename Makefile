SOURCE = src/grader.cpp src/lib/libsandbox/platform.c src/lib/libsandbox/internal.c src/lib/libsandbox/sandbox.c src/lib/SimpleJSON/JSON.cpp src/lib/SimpleJSON/JSONValue.cpp 
HEADER = src/lib/libsandbox/platform.h src/lib/libsandbox/internal.h src/lib/libsandbox/sandbox.h src/lib/libsandbox/config.h src/lib/SimpleJSON/JSON.h src/lib/SimpleJSON/JSONValue.h
NORM = src/normalizer.cpp

all : clean	build

clean : 
	rm -f bin/*

build : $(HEADER) $(SOURCE) $(NORM)
	g++ $(SOURCE) -o cgi-bin/grader.cgi -std=c++11 -pthread
	g++ $(NORM) -o cgi-bin/norm -std=c++11