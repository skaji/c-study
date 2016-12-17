CPPFLAGS = -pedantic -Wall -Wextra -Werror -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -fstrict-aliasing

main: main.o list.o
	$(CC) -o main $^

%.o: %.c
	$(CC) -c $(CPPFLAGS) $<

clean:
	rm -f *.o main
