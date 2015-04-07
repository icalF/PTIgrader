g++ bin/grader.cpp -o grader -std=c++0x		# compile main grader
g++ bin/nodelalizer.cpp -o nodel -std=c++0x	# compile output nodelalizer
grader > result.txt				# execute grader and echo output to result.txt
del output & del nodel & del grader & del main	# remove all temporary files
# Copyright (C) 2015 Afrizal Fikri