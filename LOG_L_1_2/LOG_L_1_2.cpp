#define MASSIVE_SIZE 20
#include <stdio.h>
#include <time.h>
#include <random>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	srand(time(NULL));
	int massive[MASSIVE_SIZE] = { 0 };
	int* p = massive;
	for (int i = 0; i < MASSIVE_SIZE; i++) {
		*p = rand() % 100; // 0 - 99
		printf("%d ", *p);
		p++;
	}
	printf("\n");
	return 0;
}