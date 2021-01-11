#include "salloc.h"


void* smalloc(size_t size, char* file, const char* function, int line) {
	void* ptr = malloc(size);
	if (!ptr) panic(file, function, line);
	return ptr;
}

void* scalloc(size_t nitems, size_t size, char* file, const char* function, int line) {
	void* ptr = calloc(nitems, size);
	if (!ptr) panic(file, function, line);
	return ptr;
}

void sfree(void* ptr) {
	free(ptr);
	ptr = NULL;
}

void ohno(char* file, const char* function, int line) {
	printf(
		"Error!\n"
		"File: %s\n"
		"Function: %s\n"
		"Line: %d\n"
		"errno: %d\n",
		file, function, line, errno);
	perror("");
}

void panic(char* file, const char* function, int line) {
		printf(
		"Error!\n"
		"File: %s\n"
		"Function: %s\n"
		"Line: %d\n"
		"errno: %d\n",
		file, function, line, errno);
	perror("");
	exit(errno);
}
