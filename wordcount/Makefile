CC=gcc

# Runs in order from bottom to top
tester: main.c wordmap.o
	$(CC) -o tester main.c wordmap.o
wordmap.o: wordmap.c
	$(CC) -c wordmap.c -o wordmap.o

clean:
	rm tester wordmap.o