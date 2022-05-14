CXX = clang++
override CXXFLAGS += -g -Wno-everything

SRCS = $(shell find . -name '*.cpp' -print)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))
MAIN = $(shell find . -name 'main.o' -print)

run:$(OBJS)
	$(CXX) $(CXXFLAGS) $(MAIN) -o main && ./main
clear:
	(rm *.o || rm main) || (rm *.o && rm main) || (echo 'nothing to clear')