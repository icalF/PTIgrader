g++ bin/grader.cpp -o grader -std=c++0x		# compile main grader
g++ bin/normalizer.cpp -o norm -std=c++0x	# compile output normalizer
./grader > result.txt						# execute grader and echo output to result.txt
rm output & rm norm & rm grader & rm main	# remove all temporary files
# Copyright (C) 2015 Afrizal Fikri