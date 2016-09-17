NAME = test

LIBNAME = libmath.so

CXX = g++
RM = rm -rf
CXXFLAGS = -O2

SRCS = math.cpp
OBJS = $(patsubst %.cpp, %.o, $(SRCS))
TARGET = $(NAME)

INCLUDES = math.hpp

all: $(LIBNAME) $(TARGET)


$(LIBNAME):$(OBJS)
	$(CXX) -shared $^ -o $@

$(OBJS):$(SRCS)
	$(CXX) -c -fPIC $^ -o $@

$(TARGET):$(LIBNAME) test.cpp
	$(CXX) test.cpp -L. -lmath $(INCLUDES) $(CXXFLAGS) -o $@

clean:
	$(RM) -rf $(TARGET)
	$(RM) -rf $(OBJS)
	$(RM) -rf $(LIBNAME)
