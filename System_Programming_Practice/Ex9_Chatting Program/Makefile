# Makefile
TARGET=ex9
CXX=gcc
CXXFLAGS=-Wall
OBJECTS=9_chat_skeleton.o
$(TARGET) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^
9_chat_skeleton.o: 9_chat_skeleton.c
	$(CXX) $(CXXFLAGS) -c 9_chat_skeleton.c
clean:
	rm $(OBJECTS) $(TARGET)
