lab1Full: main.o lab1.o
	$(CC) -o lab1Full main.o lab1.o

main.o: main.c
	$(CC) -c main.c

lab1.o: lab1.c
	$(CC) -c lab1.c

clean:
	-rm -f lab1_app *.o
	@echo "All clean!"