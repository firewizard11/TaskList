#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TASK 20
#define MAX_CHAR 10


typedef struct {
	char name[MAX_CHAR];
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

void saveTaskList(TaskList* list);
TaskList loadTaskList();

void printTaskList(TaskList* list);


int main() {
	TaskList test_list = loadTaskList();
	removeTask(&test_list, 0);
	printTaskList(&test_list);
	saveTaskList(&test_list);
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
	strcpy(list->list[idx].name, new_name);	
	return 0;
}

int removeTask(TaskList* list, int idx) {
	if (idx == list->len - 1) {
		list->len--;
		return 0;
	}

	for (int i = idx; i < list->len; i++) {
		list->list[i] = list->list[i + 1];	
	}
	list->len--;	

	return 0;
}

void printTaskList(TaskList* list) {
	for (int i = 0; i < list->len; i++) {
		printf("[%d] %s\n", i + 1, list->list[i].name);
	}
}

void saveTaskList(TaskList* list) {
	FILE* fp = fopen(".tasks.txt", "w");

	for (int i = 0; i < list->len; i++) {
		fputs(strcat(list->list[i].name, "\n"), fp);
	}
}

TaskList loadTaskList() {
	TaskList new_list = createTaskList();
	FILE* fp = fopen(".tasks.txt", "r");
	char line[MAX_CHAR];

	if (fp == NULL) {
		return new_list;
	}

	fgets(&line, MAX_CHAR, fp);	

	return new_list;
}


