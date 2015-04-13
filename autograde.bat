g++ bin/grader.cpp -o grader -std=c++0x			:: compile main grader
g++ bin/normalizer.cpp -o norm -std=c++0x		:: compile output nodelalizer
grader > result.txt								:: execute grader and echo output to result.txt
del output & del norm & del grader & del main	:: remove all temporary files
:: Copyright (C) 2015 Afrizal Fikri
