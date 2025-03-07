#include <stdio.h>
#include <string.h>

#define NAME_LEN 50


typedef struct {
	char name[NAME_LEN];
} Task;

Task createTask(char name[NAME_LEN]);
void printTask(Task task);


int main() {
	Task test_task;
	char name[NAME_LEN];

	printf("Enter Task Name: ");
	scanf("%s", name);
	if (strlen(name) >= NAME_LEN) {
		printf("Error: Name can be 50 chars or less\n");
		return 1;
	} 
	
	test_task = createTask(name);
	printTask(test_task);

	return 0;
}


Task createTask(char name[NAME_LEN]) {
	Task new_task;
	strcpy(new_task.name, name);
	return new_task;
}

void printTask(Task task) {
	printf("Name: %s\n", task.name);
}
