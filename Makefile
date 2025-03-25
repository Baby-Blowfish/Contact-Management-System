CC = gcc
CFLAGS = -Wall -Wextra -g

SRC = personal.c personal_load.c personal_add.c personal_print.c
OBJ = $(SRC:.c=.o)
TARGET = contact_manager

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) $(TARGET)
