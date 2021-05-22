CC := g++
CFLAGS := -Wall -Wextra -Ofast -march=native
LDFLAGS := -lm
SRC := $(wildcard *.cpp)
OBJ := $(SRC:.cpp=.o)
OUT := out
INC_DIR=../include
$(OUT): $(OBJ)
	$(CC) $^ -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) $< -c -o $@

.PHONY: clean
clean:
	rm -f $(OUT)
	rm -f $(OBJ)
