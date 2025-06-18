#ifndef _ABONENT_H
#define _ABONENT_H

struct abonent {
	char name[10];
	char surname[10];
	char phone[10];

	struct abonent *prev;
	struct abonent *next;
};

int Add(struct abonent **abonents, const char *name, const char* surname, const char* phone);
int Remove(struct abonent **abonents, int refPosition);
struct abonent *SearchByName(struct abonent *abonents, const char *searchName);
void Clear(struct abonent *abonents);

#endif // _ABONENT_H
