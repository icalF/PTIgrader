all : clean	build

clean : 
	rm -f norm grader

build :
	g++ src/grader.cpp src/platform.c src/internal.c src/sandbox.c -o grader -std=c++11 -pthread
	g++ src/normalizer.cpp -o norm -std=c++11