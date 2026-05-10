
OBJ := $(patsubst %.c, %.o, $(wildcard *.c))

mp3: $(OBJ)
	     gcc -o $@ $^

clean:
	rm *.O *.exe