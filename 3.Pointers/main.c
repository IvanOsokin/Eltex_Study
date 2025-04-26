#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void ClearInputBuffer()
{
	while (getchar() != '\n');
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
	

	return 0;
}