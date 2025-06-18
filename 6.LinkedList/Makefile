BIN := abonents
SRC := main.c abonent.c
OBJ := $(SRC:.c=.o)
HDR := abonent.h command.h

CC := gcc
CFLAGS := -Wall -Wextra -Werror

.PHONY: clean #Список абстрактных целей. Выполняются всегда, даже если имя цели совпадает с файлом.

$(BIN): $(OBJ)
		$(CC) $(OBJ) -o $(BIN)

$(OBJ): $(SRC)
		$(CC) $(CFLAGS) $(SRC) -c

$(BIN): $(HDR)


clean:
		rm -rf $(BIN) *.o
