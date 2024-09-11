#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <malloc.h>
#define RECORDS_COUNT 3
typedef struct {
    char lastName[20];
    char firstName[20];
    char faculty[20];
    int ZachetkaNum;
} base;
typedef struct node {
    base student;
    struct node* next;
} node;
node* head;
node* lastElement;
int* success_id;
void printStruct(int* success_id);
void search();
int cmpString(char string1[20], char string2[20]);
void createSuccesIdMassive();
int structCounter = 0;
void fillBase();
int main()
{
    int searchType = 0;
    setlocale(LC_ALL, "Russian");
    fillBase();
    createSuccesIdMassive();
    search();
    printStruct(success_id);
    return 0;
}
void createSuccesIdMassive() {
    success_id = (int*)malloc(sizeof(int) * structCounter);
    int* success_id_copy = success_id;
    for (int i = 0; i < structCounter; i++) {
        *success_id_copy = -1;
        success_id_copy++;
    }
};
void fillBase() {
    int flag = 1;
    while (flag) {
        node* data = (node*)malloc(sizeof(node));
        structCounter++;
        printf("\n������� ������� ��������: ");
        scanf("%19s", &data->student.lastName);
        printf("\n������� ��� ��������: ");
        scanf("%19s", &data->student.firstName);
        printf("\n������� ��������� ��������: ");
        scanf("%19s", &data->student.faculty);
        printf("\n������� ����� �������� ������ ��������: ");
        scanf("%d", &data->student.ZachetkaNum);
        printf("������� ����� �������?\n");
        printf("0 - ���     1 - ��\n");
        scanf("%1d", &flag);
        data->next = NULL;
        if (lastElement == NULL && head == NULL) {
            head = data;
            lastElement = data;
            continue;
        }
        lastElement->next = data;
        lastElement = data;
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

void printStruct(int*success_id) {

    node* temp_head = head;

    for (int i = 0; i < structCounter; i++) {
        if (*success_id == 1) {
            node* temp_temp_head = temp_head;
            for (int j = 0; j < i; j++) {
                temp_temp_head = temp_temp_head->next;
            }
            printf("\n%s%s\n%s%s\n%s%s\n%s%d\n",
                "�������: ", temp_temp_head->student.lastName,
                "���: ", temp_temp_head->student.firstName,
                "���������: ", temp_temp_head->student.faculty,
                "����� �������� ������: ", temp_temp_head->student.ZachetkaNum);
        }
        success_id++;
    }

    
}

void search() {
    node* temp_head = head;
    int type = 0;
    int success = 0;
    int id = 0;
    char string[20];
    int zachetkaSearch;
    printf("\n����� ��\n 1 - �������\n 2 - ���\n 3 - ���������\n 4 - ����� �������� ������\n");
    scanf("%1d", &type);
    switch (type)
    {
    case 1:
        printf("������� ������ ��� ������: ");
        scanf("%19s", &string);
        while (1) {
            success = cmpString(string, temp_head->student.lastName);

            if (success) {
                int* success_id_copy = success_id;
                success_id_copy += id;
                *success_id_copy = 1;
                
            }
            if (temp_head->next == NULL) {
                break;
            }
            id++;
            temp_head = temp_head->next;
        }
        break;
    case 2:
        printf("������� ������ ��� ������: ");
        scanf("%19s", &string);
        while (1) {
            success = cmpString(string, temp_head->student.firstName);

            if (success) {
                int* success_id_copy = success_id;
                success_id_copy += id;
                *success_id_copy = 1;

            }
            if (temp_head->next == NULL) {
                break;
            }
            id++;
            temp_head = temp_head->next;
        }
        break;
    case 3:
        printf("������� ������ ��� ������: ");
        scanf("%19s", &string);
        while (1) {
            success = cmpString(string, temp_head->student.faculty);

            if (success) {
                int* success_id_copy = success_id;
                success_id_copy += id;
                *success_id_copy = 1;

            }
            if (temp_head->next == NULL) {
                break;
            }
            id++;
            temp_head = temp_head->next;
        }
        break;
    case 4:
        printf("������� ������ ��� ������: ");
        scanf("%d", &zachetkaSearch);
        while (1) {
          
            
            if (zachetkaSearch == temp_head->student.ZachetkaNum) {
                int* success_id_copy = success_id;
                success_id_copy += id;
                *success_id_copy = 1;
            }
            else if (temp_head->next == NULL) {
                break;
            }
            id++;
            temp_head = temp_head->next;
        }
        break;
    default:
        printf("\n������: �������� ��������\n");
        search();
        break;
        if (!success) {
            printf("������ �� �������");
        }
    }

}
