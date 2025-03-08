bin/tasks: src/main.c
	gcc -o bin/tasks src/main.c
	bin/tasks

clean:
	rm bin/tasks
	rm .tasks.txt

run:
	bin/tasks
