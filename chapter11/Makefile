CC=g++ -std=c++11
RM=rm -rf
CFLAGS= 
OBJECTS := $(patsubst %.cpp,%.o,$(wildcard *.cpp))

all: $(OBJECTS)

$(OBJECTS): %.o: %.cpp
	$(CC) $(CFLAGS) $< -o $(@:.o=)

clean:
	$(RM) $(OBJECTS:.o=)
