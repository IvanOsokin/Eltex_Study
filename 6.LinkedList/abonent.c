#include <malloc.h>
#include <string.h>

#include "abonent.h"

int Add(struct abonent **abonents, const char *name, const char *surname, const char *phone)
{
	if (strlen(name) == 0 || strlen(surname) == 0 || strlen(phone) == 0) {
		return -1;
	}

	struct abonent *newAbonent = (struct abonent*)malloc(sizeof(struct abonent));
	if (!newAbonent) {
		return -2;
	}

	strcpy(newAbonent->name, name);
	strcpy(newAbonent->surname, surname);
	strcpy(newAbonent->phone, phone);
	newAbonent->prev = NULL;
	newAbonent->next = NULL;

	if (NULL == *abonents) {
		*abonents = newAbonent;
	}
	else {
		struct abonent* tempAbonent = *abonents;
		while (NULL != tempAbonent->next) {
			tempAbonent = tempAbonent->next;
		}
		tempAbonent->next = newAbonent;
		newAbonent->prev = tempAbonent;
	}

	return 1;
}

int Remove(struct abonent **abonents, int refPosition)
{
	if (!(*abonents)) {
		return 1;
	}
	if (refPosition < 0) {
		return -1;
	}

	struct abonent* abonent = *abonents;
	int curIdx = 0;
	while (abonent) {
		if (curIdx == refPosition) {
			if (abonent->prev) {
				abonent->prev->next = abonent->next ? abonent->next->prev : NULL;
			}
			if (abonent->next) {
				abonent->next->prev = abonent->prev ? abonent->prev->next : NULL;
			}
			if (!refPosition) {
				*abonents = (*abonents)->next;
			}
			free(abonent);
			return 1;
		}
		abonent = abonent->next;
		++curIdx;
	}
	return -2;
}

struct abonent *SearchByName(struct abonent *abonents, const char *searchName)
{
	struct abonent *searchAbonent = NULL;
	while (abonents) {
		if (strcmp(searchName, abonents->name) == 0) {
			searchAbonent = abonents;
			break;
		}
		abonents = abonents->next;
	}
	return searchAbonent;
}

void Clear(struct abonent *abonents)
{
	struct abonent *abonent = NULL;
	while (abonents) {
		abonent = abonents->next;
		free(abonents);
		abonents = abonent;
	}
}
