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
        printf("%s%d", "������� �", i+1);
        printf("\n������� ������� ��������: ");
        scanf("%19s", &student[i].lastName);
        printf("\n������� ��� ��������: ");
        scanf("%19s", &student[i].firstName);
        printf("\n������� ��������� ��������: ");
        scanf("%19s", &student[i].faculty);
        printf("\n������� ����� �������� ������ ��������: ");
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
        "�������: ", student[id].lastName,
        "���: ", student[id].firstName,
        "���������: ", student[id].faculty,
        "����� �������� ������: ", student[id].ZachetkaNum);
}

void search(base student[]) {
    int type = 0;
    int success = 0;
    int id;
    char string[20];
    int zachetkaSearch;
    printf("\n����� ��\n 1 - �������\n 2 - ���\n 3 - ���������\n 4 - ����� �������� ������\n");
    scanf("%1d", &type);
    switch (type)
    {
    case 1:
        printf("������� ������ ��� ������: ");
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
        printf("\n������: �������� ��������\n");
        search(student);
        break;
        if (!success) {
            printf("������ �� �������");
        }
    }

}
