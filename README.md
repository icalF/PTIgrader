# PTIgrader
Dedicated for lovely TPB kids, grader for PTI course

### Introduction
PTIgrader is designed to make a boring grading job a lot much easier. This program only need source files which to be graded, testcase files, and answer files for each testcase to perform automated grading. The output is a textfile contain details of programs made from each source file.

This project is under GNU General Public License. Feel free to use and share it FOR NON-COMMERCIAL USE.

### Requirement
1. GNU C++ compiler installed (by standalone package like [MinGW](http://sourceforge.net/projects/mingw/files/Installer/), or IDE built-in like [Code::Blocks](http://www.codeblocks.org/downloads/binaries) and [Dev-C++](http://www.bloodshed.net/dev/devcpp.html) ). Don't be confused with Turbo C++ or MS C++ (if you have Visual Studio). Make sure of using latest compiler version because grader using C++11 features.
2. For Windows : path of compiler has added to `PATH Environment`. If you don't really understand how to add it, follow instruction below in the `Add gcc Path` section.

### Getting Started
1. Download zip of this source by click `Download ZIP` in the right panel
2. Extract zip to somewhere
3. Put all source files (CPP files) into PTIgrader-master folder
4. Put all testcases into case folder inside PTIgrader-master
5. Put all answers into ans folder inside PTIgrader-master. Make sure each testcases and answers filename match lexicographically. Alternatively, you can rename each answer file with correspondent testcase file
6. Edit the `normalizer.cpp` to catch only expected character from program output. See `Set the normalizer` for more details
7. Finally run the `autograder.sh` (for Unix) or `autograder.bat` (for Windows) and open **result.txt** to see the practice score
