CC=g++
SRCS=$(wildcard *.cpp)
DATA_SRCS=$(wildcard data/*.cpp)
OBJS=$(SRCS:.cpp=.o)
DATA_OBJS=$(DATA_SRCS:.cpp=.o)

all: edge

edge: $(OBJS) $(DATA_OBJS)
	$(CC) -o $@ $^

%.o: %.cpp
	$(CC) -c $< -o $@

data/%.o: data/%.cpp
	$(CC) -c $< -o $@

clean:
	$(RM) edge $(OBJS) $(DATA_OBJS)
