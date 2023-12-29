# Makefile
TARGET=crond
CXX=gcc
CXXFLAGS=-Wall
OBJECTS=6_cron.o
$(TARGET) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^
6_cron.o: 6_cron.c
	$(CXX) $(CXXFLAGS) -c 6_cron.c
clean:
	rm $(OBJECTS) $(TARGET)

