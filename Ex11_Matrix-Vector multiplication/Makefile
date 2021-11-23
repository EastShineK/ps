# Makefile
TARGET=ex11
CXX=gcc
CXXFLAGS=-Wall
OBJECTS=11_Pthreads_skeleton.o
$(TARGET) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ -lpthread
11_Pthreads_skeleton.o: 11_Pthreads_skeleton.c
	$(CXX) $(CXXFLAGS) -c 11_Pthreads_skeleton.c
clean:
	rm $(OBJECTS) $(TARGET)

