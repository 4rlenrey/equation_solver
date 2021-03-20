CC = g++
FLAGS = -g -Wall
CODE_LOCATION = code
INCLUDES = -I code/

CPP =\
	${CODE_LOCATION}/*.cpp\
	${CODE_LOCATION}/*/*.cpp

all: main

clean:
	@rm -f *.o ${CODE_LOCATION}/*.o ${CODE_LOCATION}/*/*.o

compile:
	$(CC) -g -c $(CPP) $(INCLUDES) $(FLAGS) $<

main: $(CPP)
	$(CC) -g $(CPP) $(INCLUDES) -pthread -std=c++11  -o a
	make clean
