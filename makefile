antMain: antMain.o menu.o inputValidation.o rangeChecker.o ant.o board.o
	g++ -std=c++11 antMain.o menu.o inputValidation.o rangeChecker.o ant.o board.o -o antMain

antMain.o: antMain.cpp
	g++ -std=c++11 -c antMain.cpp 

menu.o: menu.hpp menu.cpp
	g++ -std=c++11 -c menu.cpp

inputValidation.o: inputValidation.hpp inputValidation.cpp
	g++ -std=c++11 -c inputValidation.cpp

rangeChecker.o: rangeChecker.hpp rangeChecker.cpp
	g++ -std=c++11 -c rangeChecker.cpp

ant.o: ant.hpp ant.cpp
	g++ -std=c++11 -c ant.cpp

board.o: board.hpp board.cpp
	g++ -std=c++11 -c board.cpp

clean:
	rm *.o antMain
