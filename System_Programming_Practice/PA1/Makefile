# Makefile
TARGET=2020312812
CXX=gcc
CXXFLAGS=-Wall
OBJECTS=2020312812.o
$(TARGET) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^
2020312812.o: 2020312812.c
	$(CXX) $(CXXFLAGS) -c 2020312812.c
clean:
	rm $(OBJECTS) $(TARGET)
