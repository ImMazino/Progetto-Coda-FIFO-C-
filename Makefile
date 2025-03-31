#Variabili
CXX = g++
CXXFLAGS = -Wall -g

#File sorgente e oggetto
SOURCES = main.cpp
OBJECTS = main.o
EXECUTABLE = main.exe

#Regole
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^
	
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
.PHONY: clean all

doc:
	doxygen
	
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

all: $(EXECUTABLE) doc
	./$(EXECUTABLE)

run: all

valgrind: $(EXECUTABLE)
	valgrind -s --leak-check=full ./main.exe