#define MASSIVE_SIZE 10
#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <random>
#define _CRT_SECURE_NO_WARNINGS_

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int maxValue = INT_MIN;
	int minValue = INT_MAX;
	int massive[MASSIVE_SIZE] = { 0 };
	int* p = massive;
	for (int i = 0; i < 10; i++) {
		*p = rand() % 10000;
		printf("%d\n", *p);
		if (*p > maxValue) maxValue = *p;
		if (*p < minValue) minValue = *p;
		p++;
	}
	printf("\n%s\n%d\n", "Разница между максимальным и минимальным значением:", maxValue - minValue);
	return 0;
}

