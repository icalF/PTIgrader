g++ bin/grader.cpp -o grader -std=c++0x
g++ bin/normalizer.cpp -o norm -std=c++0x
./grader > result.txt
rm output | rm norm | rm grader | rm lol
