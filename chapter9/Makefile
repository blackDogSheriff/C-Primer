CC=@g++
RM=@rm -rf
ECHO=@echo
CFLAGS=

OBJECTS := $(patsubst %.cpp, %.o, $(wildcard *.cpp))
EXCLUDE := add_element init_vector init
TARGET := $(filter-out $(EXCLUDE).cpp, $(patsubst %.o, %, $(OBJECTS)))

all: $(TARGET)

$(TARGET): %: %.cpp
	$(ECHO) "++++++++++++++++ compiling $< ++++++++++++++++"
	$(CC) $< -o $@

clean:
	$(RM) $(OBJECTS:.o=) *.o

