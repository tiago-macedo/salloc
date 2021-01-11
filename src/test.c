#include <stdio.h>
#include "salloc.h"

//================================
// MAIN
//================================
int main(int argc, char* argv[], char* envp[]) {
	int n = argc > 1 ? atoi(argv[1]) : 20;
	char* ch = smalloc(n * sizeof(char), WHERE);
	int* num = scalloc(n, sizeof(int), WHERE);
	for (int i=0; i<n; i++) {
		printf("%d:0x%x ", num[i], ch[i]);
	}
	printf("\n");
	sfree(ch);
	sfree(num);
	return 0;
}
