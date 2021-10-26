# Makefile
TARGET=ex8
CXX=gcc
CXXFLAGS=-Wall
OBJECTS=ex8.o
$(TARGET) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^
ex8.o: ex8.c
	$(CXX) $(CXXFLAGS) -c ex8.c
clean:
	rm $(OBJECTS) $(TARGET)

