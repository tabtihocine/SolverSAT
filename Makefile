all: SAT
SAT: SAT.o readFile.o pick.o simplify.o 
	g++ SAT.o readFile.o pick.o simplify.o -o SAT
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