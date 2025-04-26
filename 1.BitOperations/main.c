#include <stdio.h>

void NewLine()
{
	printf("\n");
}

void ClearInputBuffer()
{
	while (getchar() != '\n');
}

int main()
{
	int userNumber;

	//----------------------- Positive -----------------------

	printf("Enter a positive integer: ");
	while (scanf("%d", &userNumber) != 1 || userNumber < 0) {
		ClearInputBuffer();
		printf("Invalid positive integer. Try Again.\n");
	}
	for (int i = sizeof(userNumber) * 8 - 1; 0 <= i; --i) {
		printf("%c", ((userNumber >> i) & 1) == 1 ? '1' : '0');
	}

	ClearInputBuffer();
	NewLine();

	//----------------------- Negative -----------------------

	printf("Enter a negative integer: ");
	while (scanf("%d", &userNumber) != 1 || userNumber > 0) {
		ClearInputBuffer();
		printf("Invalid negative integer. Try Again.\n");
	}
	for (int i = sizeof(userNumber) * 8 - 1; 0 <= i; --i) {
		printf("%c", ((userNumber >> i) & 1) == 1 ? '1' : '0');
	}
	
	ClearInputBuffer();
	NewLine();

	//----------------------- Count of 1 -----------------------

	short oneCount = 0;
	printf("Enter an integer: ");
	while (scanf("%d", &userNumber) != 1) {
		ClearInputBuffer();
		printf("Invalid integer. Try Again.\n");
	}
	for (int i = sizeof(userNumber) * 8 - 1; 0 <= i; --i) {
		if (((userNumber >> i) & 1) == 1) {
			++oneCount;
		}
	}
	printf("Count of <1> in \"%d\": %d", userNumber, oneCount);
	
	ClearInputBuffer();
	NewLine();

	//----------------------- Replace 3rd byte -----------------------

	printf("Enter a positive integer: ");
	while (scanf("%d", &userNumber) != 1 || userNumber < 0) {
		ClearInputBuffer();
		printf("Invalid positive integer. Try Again.\n");
	}
	unsigned int replacementValue;
	printf("Enter a replacement integer (0..255): ");
	while (scanf("%d", &replacementValue) != 1 || replacementValue < 0 || replacementValue > 255) {
		ClearInputBuffer();
		printf("Invalid value. Try Again.\n");
	}
	userNumber &= 0xFF00FFFF;
	int newUserNumber = userNumber | (replacementValue << 16);
	printf("Initial number: %d; new number: %d\n", userNumber, newUserNumber);

	return 0;
}