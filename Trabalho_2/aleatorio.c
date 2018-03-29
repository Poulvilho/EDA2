#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int main() {
	unsigned long int aleatorio[MAX];
	for (unsigned long int i = 0; i < MAX; i++) {
		aleatorio[i] = rand() % MAX;
		
	}
	FILE* file = fopen("pessoas.txt", "a");
	for (int i = 0; i < MAX; i++) {
		fprintf(file, "%lu BrunoDantas%d\n", aleatorio[i], i);
	}
	fclose(file);

	return 0;
}