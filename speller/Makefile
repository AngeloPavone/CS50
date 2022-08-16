src = $(wildcard *.c)
obj = $(src:.c=.o)

LDFLAGS=-lGL -lpng -lz -lm -fsanitize=signed-integer-overflow -fsanitize=undefined -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow
CFLAGS=-g

speller: $(obj)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) filter
