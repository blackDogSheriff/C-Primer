CC=g++
RM=rm -rf
CFLAGS=

OBJECTS := $(patsubst %.cpp, %.o, $(wildcard *.cpp))
EXCLUDE := add_element init_vector init
TARGET := $(filter-out $(EXCLUDE), $(patsubst %.o, %, $(OBJECTS)))

all: $(TARGET)

$(TARGET): %: %.cpp
	$(CC) $< -o $@

clean:
	$(RM) $(OBJECTS:.o=) *.o

