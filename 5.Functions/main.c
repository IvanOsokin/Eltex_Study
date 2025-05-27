#include <stdio.h>

#define REFERENCE_AMOUNT 100

struct abonent {
	char name[10];
	char second_name[10];
	char tel[10];
};

int StringLength(const char* string)
{
	int length = 0;
	while (*string++ != '\0') {
		++length;
	}
	return length;
}

void ClearInputBuffer()
{
	while (getchar() != '\n');
}

int IsEmptyAbonent(const struct abonent a)
{
	return StringLength(a.name) == 0 && StringLength(a.second_name) == 0 && StringLength(a.tel) == 0;
}

void DisplayAbonent(struct abonent a)
{
	printf("Имя: %s\n", a.name);
	printf("Фамилия: %s\n", a.second_name);
	printf("Телефон: %s\n", a.tel);
}

void AddAbonent(struct abonent *abonents)
{
	int filled = 1;
	printf("\tДобавление абонента\n");
	for (int i = 0; i < REFERENCE_AMOUNT; ++i) {
		if (!IsEmptyAbonent(abonents[i])) {
			continue;
		}
		filled = 0;
		printf("Имя: ");
		scanf("%9[^\n]s", abonents[i].name);
		ClearInputBuffer();
		printf("Фамилия: ");
		scanf("%9[^\n]s", abonents[i].second_name);
		ClearInputBuffer();
		printf("Телефон: ");
		scanf("%9[^\n]s", abonents[i].tel);
		ClearInputBuffer();
		break;
	}
	if (filled) {
		printf("Справочник заполнен!\n");
	}
}

void RemoveAbonent(struct abonent *abonents)
{
	printf("\tУдаление абонента\n");
	printf("Введите номер записи абонента для удаления: ");
	int abonentNumber = 0;
	scanf("%d", &abonentNumber);
	ClearInputBuffer();
	if (abonentNumber < 1 || abonentNumber > 100) {
		printf("Номер записи недействителен. Должен быть 1..100");
	}
	else {
		abonentNumber -= 1;
		abonents[abonentNumber].name[0] = '\0';
		abonents[abonentNumber].second_name[0] = '\0';
		abonents[abonentNumber].tel[0] = '\0';
	}
}

void SearchAbonentByName(struct abonent *abonents)
{
	char searchName[10] = { 0 };
	printf("Введите имя для поиска: ");
	scanf("%9[^\n]s", searchName);
	ClearInputBuffer();
	if (StringLength(searchName) > 0) {
		for (int i = 0; i < REFERENCE_AMOUNT; ++i) {
			if (StringLength(abonents[i].name) == 0) {
				continue;
			}
			char* sn = searchName;
			char* n = abonents[i].name;
			int differenet = 0;
			while (*sn != '\0' && *n != '\0') {
				if (*sn++ != *n++) {
					differenet = 1;
					break;
				}
			}
			if (*sn == *n && !differenet) {
				printf("%d\n", i + 1);
				DisplayAbonent(abonents[i]);
				printf("\n");
			}
		}
	}
}

void DisplayAbonents(struct abonent *abonents)
{
	int empty = 1;
	for (int i = 0; i < REFERENCE_AMOUNT; ++i) {
		if (IsEmptyAbonent(abonents[i])) {
			continue;
		}
		empty = 0;
		printf("%d\n", i + 1);
		DisplayAbonent(abonents[i]);
		printf("\n");
	}
	if (empty) {
		printf("Спарвочник пуст!\n");
	}
}

int main()
{
	struct abonent abonents[REFERENCE_AMOUNT] = { 0 };

	int command = 0;
	while (command != 5) {
		printf("\t**************************\n\t********** МЕНЮ **********\n\t**************************\n");
		printf("1. Добавить абонента\n");
		printf("2. Удалить абонента\n");
		printf("3. Поиск абонента по имени\n");
		printf("4. Вывод всех записей\n");
		printf("5. Выход\n");

		printf("Выберите пункт меню: ");
		scanf("%d", &command);
		ClearInputBuffer();

		switch (command) {
		case 1: {
			AddAbonent(abonents);
			break;
		}
		case 2: {
			RemoveAbonent(abonents);
			break;
		}
		case 3: {
			SearchAbonentByName(abonents);
			break;
		}
		case 4: {
			DisplayAbonents(abonents);
			break;
		}
		case 5:
			break;
		default:
			printf("Выбран неверный пункт меню!\n");
			break;
		}
	}

	return 0;
}
