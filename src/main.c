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
int editTask(TaskList* list, int idx);
int removeTask(TaskList* list, int idx);

void saveTaskList(TaskList list);
TaskList loadTaskList();

void printTaskList(TaskList list);


int main() {
	Task test_task = createTask("task1");
	TaskList test_list = createTaskList();
	
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

int addTask(TaskList* list, Task task);
int editTask(TaskList* list, int idx);
int removeTask(TaskList* list, int idx);

void saveTaskList(TaskList list);
TaskList loadTaskList();

void printTaskList(TaskList list);


