CXXFLAGS=-ggdb -std=c++20 -Wall -Wextra -Werror -Wfatal-errors -pedantic
main: src/dijkstras.cpp src/ladder.cpp
	g++ $(CXXFLAGS) src/dijkstras.cpp src/ladder.cpp -o main

clean:
	rm -f src/*.o main