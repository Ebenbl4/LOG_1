#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <string.h>
#define RECORDS_COUNT 3
typedef struct {
    char lastName[20];
    char firstName[20];
    char faculty[20];
    int ZachetkaNum;
} base;
void printStruct(base student[], int id);
void search(base student[]);
int cmpString(char string1[20], char string2[20]);
void fillBase(base student[]);
int main()
{
    int searchType = 0;
    setlocale(LC_ALL, "Russian");
    base student[RECORDS_COUNT];
    fillBase(student);
    search(student);
    return 0;
    
}

void fillBase(base student[]) {
    for (int i = 0; i < RECORDS_COUNT; i++) {
        printf("%s%d", "Студент №", i+1);
        printf("\nВведите фамилию студента: ");
        scanf("%19s", &student[i].lastName);
        printf("\nВведите имя студента: ");
        scanf("%19s", &student[i].firstName);
        printf("\nВведите факультет студента: ");
        scanf("%19s", &student[i].faculty);
        printf("\nВведите номер зачетной книжки студента: ");
        scanf("%d", &student[i].ZachetkaNum);
    }
}

int cmpString(char string1[20], char string2[20]) {
    int i = 0;
    while (string1[i] != '\0' || string1[i] != '\0') {
        if (string1[i] == string2[i]) {
            i++;
            continue;
        }
        else {
            return 0;
        }
        
    }
    return 1;
}

void printStruct(base student[], int id) {
    printf("\n%s%s\n%s%s\n%s%s\n%s%d\n",
        "Фамилия: ", student[id].lastName,
        "Имя: ", student[id].firstName,
        "Факультет: ", student[id].faculty,
        "Номер зачетной книжки: ", student[id].ZachetkaNum);
}

void search(base student[]) {
    int type = 0;
    int success = 0;
    int id;
    char string[20];
    int zachetkaSearch;
    printf("\nПоиск по\n 1 - Фамилия\n 2 - Имя\n 3 - Факультет\n 4 - Номер зачетной книжки\n");
    scanf("%1d", &type);
    switch (type)
    {
    case 1:
        printf("Введите запрос для поиска: ");
        scanf("%19s", &string);
        for (int i=0; i< RECORDS_COUNT; i++){
            success = cmpString(string, student[i].lastName);
            if (success) {
                id = i;
                printStruct(student, id);
                break;
            }
            else continue;
        }
        break;
    case 2:
        scanf("%19s", &string);
        for (int i = 0; i < RECORDS_COUNT; i++) {
            success = cmpString(string, student[i].firstName);
            if (success) {
                id = i;
                printStruct(student, id);
                break;
            }
            else continue;
        }
        break;
    case 3:
        scanf("%19s", &string);
        for (int i = 0; i < RECORDS_COUNT; i++) {
            success = cmpString(string, student[i].faculty);
            if (success) {
                id = i;
                printStruct(student, id);
                break;
            }
            else continue;
        }
        break;
    case 4:
        scanf("%d", &zachetkaSearch);
        for (int i = 0; i < RECORDS_COUNT; i++) {
            if (zachetkaSearch == student[i].ZachetkaNum) {
                id = i;
                success = 1;
                printStruct(student, id);
                break;
            }
            else continue;

        }
        break;
    default:
        printf("\nОшибка: неверное значение\n");
        search(student);
        break;
        if (!success) {
            printf("Запись не найдена");
        }
    }

}
