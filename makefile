list: linkedList.c
	gcc linkedList.c -o list

clean:
	rm *~

run: list
	./list
