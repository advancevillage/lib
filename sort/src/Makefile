NAME = test

CXX = g++
RM = rm -rf
CFLAGS = -O0 -g -std=c++11 

INCLUDES= -I. sort.hpp sortdef.h

TARGET=$(NAME)

$(TARGET): test.cpp
	$(CXX) $(CFLAGS) $^ $(INCLUDES) -o $@

clean:
	$(RM) $(TARGET)
