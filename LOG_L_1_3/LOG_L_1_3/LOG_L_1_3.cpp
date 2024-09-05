#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <locale.h>
int* createMassive(int size);
int fillMassive(int size, int* p);
int main()
{
    setlocale(LC_ALL, "Russian");
    int size = 0;
    int result;
    int* p;
    printf("Введите размер массива:");
    result = scanf("%d", &size);

    if (result != 1 && size <= 0) {
        printf("\nОшибка: Размер массива должен быть больше нуля\n");
        return 1;
    }
    else {
        p = createMassive(size);
        result = fillMassive(size, p);
    }
    return result;
}

int* createMassive(int size) {
    int* p;
    p = (int*)malloc(sizeof(int) * size);
    return p;
}
int fillMassive(int size, int* p) {
    for (int i = 0; i < size; i++) {
        printf("\n%s%d%s", "Введите элемент ", i+1, ":");
        int result = scanf("%d", p);
        retry:
        if (result != 1) {
            printf("Ошибка: введены не десятичные символы");
            return 1;
        }
        p++;
    }
    printf("Ввод массива завершен");
    return 0;
}