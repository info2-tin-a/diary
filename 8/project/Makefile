OBJS=$(patsubs, %.c=%.o, $(wildcards, *.c))
EXEC=foo
CFLAGS=-std=c11 -g -O2
LDFLAGS=-lm 

all: $(EXEC)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(EXEC): $(OBJS)
	$(CC) $^ -o $@ $(LDFLAGS)

clean: 
	$(RM) *.o *.d

mrproper: clean 
	