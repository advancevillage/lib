NAME = testbinarytree


CXX = g++
RM = rm -rf
CXXFLAGS = -O0 -std=c++11 -g 

INCLUDES = -I . binarytree.hpp node.hpp

TARGET = $(NAME)

$(TARGET): test.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@


clean:
	$(RM) $(TARGET)
