CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRC = src/main.c src/file_ops.c
OBJ = $(SRC:.c=.o)
TARGET = sfo  # Executable name

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

clean:
	rm -f $(OBJ) $(TARGET)
