#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int main() {
	int cm[MAX], dm[MAX], m[MAX], c[MAX], d[MAX], u[MAX];
	for (int i = 0; i < MAX; i++) {
		cm[i] = rand() % 10;
		dm[i] = rand() % 10;
		m[i] = rand() % 10;
		c[i] = rand() % 10;
		d[i] = rand() % 10;
		u[i] = rand() % 10;
	}
	FILE* file = fopen("pessoas.txt", "w");
	for (int i = 0; i < MAX; i++) {
		fprintf(file, "%d%d%d%d%d%d PauloVictor%d\n", cm[i], dm[i], m[i],
			c[i], d[i], u[i], i);
	}
	fclose(file);

	return 0;
}