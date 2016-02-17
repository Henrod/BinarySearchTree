CXX		= g++
CXXFLAGS 	= -std=c++11 -Wall -Wextra

CPP_FILES = $(wildcard src/*.cpp)
OBJ_FILES = obj/main.o 

HPP_PATH  = hdr

all:
	$(CXX) $(CXXFLAGS) -I$(HPP_PATH) $(CPP_FILES) -o $(OBJ_FILES)

clean:
	rm -f $(OBJ_FILES)
