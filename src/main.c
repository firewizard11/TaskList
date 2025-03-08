#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TASK 20


typedef struct {
	char name[10];
} Task;

typedef struct {
	Task list[MAX_TASK];
	int len;
} TaskList;

Task createTask(char* name);
TaskList createTaskList();

int addTask(TaskList* list, Task task);
int editTask(TaskList* list, int idx, char* new_name);
int removeTask(TaskList* list, int idx);

void saveTaskList(TaskList list);
TaskList loadTaskList();

void printTaskList(TaskList list);


int main() {
	Task test_task = createTask("task1");
	TaskList test_list = createTaskList();
	
	addTask(&test_list, test_task);
	addTask(&test_list, createTask("task2"));

	printf("Number of Tasks: %d\n", test_list.len);
	printf("Task 1: %s\n", test_list.list[0].name);
	printf("Task 2: %s\n", test_list.list[1].name);

	return 0;
}


Task createTask(char* name) {
	Task new_task;
	strcpy(new_task.name, name);
	return new_task;
}

TaskList createTaskList() {
	TaskList new_list;
	new_list.len = 0;
	return new_list;
}

int addTask(TaskList* list, Task task) {
	list->list[list->len] = task;
	list->len++;
	return 0;
}

int editTask(TaskList* list, int idx, char* new_name) {
	
}

int removeTask(TaskList* list, int idx);

void saveTaskList(TaskList list);
TaskList loadTaskList();

void printTaskList(TaskList list);


