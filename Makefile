CC=g++
CFLAGS=-c -Wall -std=c++11 -pthread
LDFLAGS=-std=c++11 -pthread
SOURCES=main.cpp brute.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=sudoku_solver

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o $(EXECUTABLE)
