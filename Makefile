all: SAT
SAT: SAT.o readFile.o pick.o simplify.o backtracking.o
	g++ SAT.o readFile.o pick.o simplify.o backtracking.o -o SAT
backtracking.o: backtracking.cpp
	g++ -c backtracking.cpp 
SAT.o: SAT.cpp 
	g++ -c SAT.cpp
readFile.o: readFile.cpp 
	g++ -c readFile.cpp
pick.o: pick.cpp
	g++ -c pick.cpp
simplify.o: simplify.cpp
	g++ -c simplify.cpp
clean: 	
	rm -rf *o 