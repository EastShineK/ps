# Makefile
TARGET=ex4
CXX=gcc
CXXFLAGS=-Wall
OBJECTS=ex4.o
$(TARGET) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^
ex4.o: ex4.c
	$(CXX) $(CXXFLAGS) -c ex4.c
clean:
	rm $(OBJECTS) $(TARGET)

