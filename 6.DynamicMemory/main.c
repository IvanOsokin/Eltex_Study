#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

#include "abonent.h"
#include "command.h"

void ClearInputBuffer()
{
	while (getchar() != '\n');
}

void DisplayAbonent(struct abonent *abonent)
{
	if (!abonent) {
		return;
	}

	printf("Имя: %s\n", abonent->name);
	printf("Фамилия: %s\n", abonent->surname);
	printf("Телефон: %s\n", abonent->phone);
}

void DisplayMenu()
{
	printf("\t**************************\n\t********** МЕНЮ **********\n\t**************************\n");
	printf("%d. Добавить абонента\n", ADD);
	printf("%d. Удалить абонента\n", REMOVE);
	printf("%d. Поиск абонента по имени\n", SEARCH);
	printf("%d. Выход\n", EXIT);
}

void ReleaseReference(struct abonent *abonents)
{
	Clear(abonents);
}

void AddAbonent(struct abonent **abonents)
{
	printf("\tДобавление абонента\n");

	char name[10] = { 0 };
	char surname[10] = { 0 };
	char phone[10] = { 0 };

	printf("Имя: ");
	if (scanf("%9[^\n]s", name) != 1) {
		name[0] = '\0';
	}
	ClearInputBuffer();

	printf("Фамилия: ");
	if (scanf("%9[^\n]s", surname) != 1) {
		surname[0] = '\0';
	}
	ClearInputBuffer();

	printf("Телефон: ");
	if (scanf("%9[^\n]s", phone) != 1) {
		phone[0] = '\0';
	}
	ClearInputBuffer();
	
	int addResult = Add(abonents, name, surname, phone);
	if (addResult <= 0) {
		fprintf(stderr, "Ошибка при добавлении абонента!");
		if (-1 == addResult) {
			fprintf(stderr, " Не задано одно из полей!\n");
		}
	}
}

void RemoveAbonent(struct abonent **abonents)
{
	printf("\tУдаление абонента\n");
	printf("Введите номер записи абонента для удаления: ");

	int abonentNumber = 0;
	if (scanf("%d", &abonentNumber) == 1) {
		ClearInputBuffer();
		if (abonentNumber < 1) {
			fprintf(stderr, "Номер записи недействителен. Должен быть больше 1.\n");
		}
		else {
			if (Remove(abonents, abonentNumber - 1) <= 0) {
				fprintf(stderr, "Ошибка при удалении абонента!\n");
			}
		}
	}
	else {
		fprintf(stderr, "Некорректный ввод!\n");
	}
}

void SearchAbonentByName(struct abonent* abonents)
{
	printf("\tПоиск абонента по имени\n");
	printf("Введите имя для поиска: ");

	char searchName[10] = { 0 };
	if (scanf("%9[^\n]s", searchName) == 1) {
		ClearInputBuffer();
		if (strlen(searchName) > 0) {
			struct abonent* searchAbonent = SearchByName(abonents, searchName);
			if (searchAbonent) {
				DisplayAbonent(searchAbonent);
			}
			else {
				printf("Абонент с именем \"%s\" не найден в справочнике.\n", searchName);
			}
		}
	}
	else {
		fprintf(stderr, "Некорректный ввод!\n");
	}
}

int main()
{
	struct abonent *abonents = NULL;

	enum MenuCommand command = 0;
	int failure = 0;
	int userCmd = 0;
	while (command != EXIT) {
		DisplayMenu();

		printf("Выберите пункт меню: ");
		errno = 0;
		int readVal = 0;
		readVal = scanf("%d", &userCmd);
		ClearInputBuffer();
		if (readVal != 1) {
			if (errno != 0) {
				perror("Ошибка ввода!");
				failure = 1;
			}
			fprintf(stderr, "Некорректный ввод!\n");
		}
		else {
			command = (enum MenuCommand)userCmd;
			switch (command) {
				case ADD: {
					AddAbonent(&abonents);
					break;
				}
				case REMOVE: {
					RemoveAbonent(&abonents);
					break;
				}
				case SEARCH: {
					SearchAbonentByName(abonents);
					break;
				}
				case EXIT:
					break;
				default: {
					printf("Выбран невырный пункт меню!\n");
					break;
				}
			}
		}		
	}
	if (abonents) {
		ReleaseReference(abonents);
	}
	if (failure) {
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
