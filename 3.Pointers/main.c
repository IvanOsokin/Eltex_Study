#include <stdio.h>

void ClearInputBuffer()
{
	while (getchar() != '\n');
}

int StringLength(const char *string)
{
	int length = 0;
	while (*string++ != '\0') {
		++length;
	}
	return length;
}

const char* FindSubstring(const char *string, const char *subString)
{
	const int subStrSize = StringLength(subString);
	for (; *string != '\0'; ++string) {
		if (StringLength(string) < subStrSize) {
			return NULL;
		}

		if (*string == *subString) {
			short different = 0;
			const char* sp = string;
			const char* ssp = subString;
			while (*ssp != '\0') {
				if (*ssp++ != *sp++) {
					different = 1;
					break;
				}
			}
			if (!different) {
				return string;
			}
		}
	}
}

int main()
{
	//----------------------- Replace 3rd byte (use pointers) -----------------------

	int userNumber;
	printf("Enter a positive integer: ");
	while (scanf("%d", &userNumber) != 1 || userNumber < 0) {
		ClearInputBuffer();
		printf("Invalid positive integer. Try Again.\n");
	}
	int newUserNumber = userNumber;
	int replacementValue;
	printf("Enter a replacement integer (0..255): ");
	while (scanf("%d", &replacementValue) != 1 || replacementValue < 0 || replacementValue > 255) {
		ClearInputBuffer();
		printf("Invalid value. Try Again.\n");
	}

	unsigned char *byte = (unsigned char*)&newUserNumber;
	*(byte + 2) = (unsigned char)replacementValue;

	printf("Initial number: %d; new number: %d\n", userNumber, newUserNumber);

	//----------------------- Fix up the code -----------------------

	float x = 5.0;
	printf("x = %f, ", x);
	float y = 6.0;
	printf("y = %f\n", y);
	float* xp = &y;
	float* yp = &y;
	printf("Результат: %f\n", *xp + *yp);

	//----------------------- Display array -----------------------

	int array[] = { 1,2,3,4,5,6,7,8,9,10 };
	int *ap = array;
	const int arraySize = sizeof(array) / sizeof(int);
	for (int i = 0, *ap = array; i < arraySize; ++i, ++ap) {
		printf("%d ", *ap);
	}
	
	//----------------------- Find a substring -----------------------

	char string[81] = { '\0' };
	printf("Enter a string: ");
	while (scanf("%80[^\n]s", string) != 1) {
		ClearInputBuffer();
		printf("Empty initial string. Try Again.\n");
	}
	ClearInputBuffer();

	char subString[81];	
	printf("Enter a substring: ");
	while (scanf("%80[^\n]s", subString) != 1) {
		ClearInputBuffer();
		printf("Empty substring. Try Again.\n");
	}
	ClearInputBuffer();

	const char* substr = FindSubstring(string, subString);
	if (substr == NULL) {
		printf("\"%s\" is not a substring of \"%s\"", subString, string);
	}
	else {
		printf("Substring: \"%s\"", substr);
	}

	return 0;
}