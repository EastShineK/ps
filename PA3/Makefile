# Makefile
TARGET=pa3.out
CXX=gcc
CXXFLAGS=-Wall
OBJECTS=PA3.o
$(TARGET) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ -lpthread
PA3.o: PA3.c
	$(CXX) $(CXXFLAGS) -c PA3.c
clean:
	rm $(OBJECTS) $(TARGET)

