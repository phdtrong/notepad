CXX = clang++
override CXXFLAGS += -g -Wno-everything

SRCS = $(shell find . -type f -name '*.cpp' -print)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))
		
main: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o main

clean:
	rm -f $(OBJS) main
	clear &&  make -s && ./main
clear:
	rm *.o && rm main