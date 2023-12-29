# Makefile
TARGET=ex5
CXX=gcc
CXXFLAGS=-Wall
OBJECTS=ex5.o
$(TARGET) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^
ex4.o: ex5.c
	$(CXX) $(CXXFLAGS) -c ex5.c
clean:
	rm $(OBJECTS) $(TARGET)
