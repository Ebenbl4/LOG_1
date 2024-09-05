#define MATRIX_ROWS 5
#define MATRIX_COLS 8
#include <stdio.h>
#include <time.h>
#include <random>
#include <locale.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	int M[MATRIX_ROWS][MATRIX_COLS] = {0};
	int summ = 0;
	for (int i = 0; i < MATRIX_ROWS; i++) 
	{
		summ = 0;
		for (int j = 0; j < MATRIX_COLS; j++)
		{
			M[i][j] = rand() % 50; // 0 - 49
			summ += M[i][j];
			printf("%-2d ", M[i][j]);
		}
		printf(" Сумма: %d\n", summ);
	}
	return 0;
}