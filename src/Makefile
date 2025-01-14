# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
LDFLAGS = 

# Source files and output
SRC = main.c data_structures.h menu_management.c billing_functions.c
OBJ = $(SRC:.c=.o)
TARGET = restaurant_billing

# Default rule
all: $(TARGET)

# Linking rule
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

# Compilation rule
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJ) $(TARGET)

# Phony targets
.PHONY: all clean
