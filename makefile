_explode_: main.o lab1.o
	$(CC) -o $@ main.o lab1.o

main.o: main.c
	$(CC) -c main.c

lab1.o: lab1.c
	$(CC) -c lab1.c

clean:
	-rm -f _explode_ *.o
	@echo "All clean!"