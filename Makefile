CC = gcc
CFLAGS = -Wall -Wextra -g

SRC = personal.c personal_load.c personal_add.c personal_print.c personal_delete.c personal_modify.c get_string_int.c
OBJ = $(SRC:.c=.o)
TARGET = contact_manager

# 의존성 추가
DEPS = personal.h personal_load.h personal_add.h personal_print.h personal_delete.h personal_modify.h get_string_int.h node.h

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) $(TARGET)
