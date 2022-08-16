src = $(wildcard *.c)
obj = $(src:.c=.o)

LDFLAGS = -lGL -lpng -lz -lm

filter: $(obj)
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) filter
