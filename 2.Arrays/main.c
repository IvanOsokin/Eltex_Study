#include <stdio.h>

#define N 10

void DisplayMatrix(int arr[N][N])
{
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (0 != j) {
				printf(" ");
			}
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void DisplayArray(int arr[N])
{
	for (int i = 0; i < N; ++i) {
		if (0 != i) {
			printf(" ");
		}
		printf("%d", arr[i]);
	}
	printf("\n\n");
}

void ReverseArray(int arr[N])
{
	for (int i = 0, j = N - 1; i < j; ++i, --j) {
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
}

int main()
{
	//----------------------- Fill and display squared matrix -----------------------

	int matrix[N][N];
	int value = 1;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			matrix[i][j] = value++;
		}
	}
	printf("Filled matrix\n");
	DisplayMatrix(matrix);

	//----------------------- Display reversed array -----------------------

	int arr[N];
	printf("Enter an array of size %d: ", N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &arr[i]);
	}
	printf("Initial array: ");
	DisplayArray(arr);
	ReverseArray(arr);
	printf("Reversed array: ");
	DisplayArray(arr);

	//----------------------- Display triangles -----------------------

	printf("Triangle matrix\n");
	int triangleMatrix[N][N];
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (j >= N - i - 1) {
				triangleMatrix[i][j] = 1;
			}
			else {
				triangleMatrix[i][j] = 0;
			}
		}
	}
	DisplayMatrix(triangleMatrix);

	//----------------------- Display triangles -----------------------

	printf("Snail matrix\n");
	int snailMatrix[N][N];	
	int minJ = -1, maxJ = N;
	int minI = 0, maxI = N;
	int coefI = 0, coefJ = 1;
	int i = 0, j = 0;
	int snailValue = 1;
	while (minJ != maxJ - 1 || minI != maxI - 1) {
		snailMatrix[i][j] = snailValue++;

		i += 1 * coefI;
		j += 1 * coefJ;
		if (j == maxJ && coefJ == 1) {
			--j;
			++i;
			--maxJ;
			coefJ = 0;
			coefI = 1;
		}
		else if (i == maxI && coefI == 1) {
			--i;
			--j;
			--maxI;
			coefJ = -1;
			coefI = 0;
		}
		else if (j == minJ && coefJ == -1) {
			++j;
			--i;
			++minJ;
			coefJ = 0;
			coefI = -1;
		}
		else if (i == minI && coefI == -1) {
			++i;
			++j;
			++minI;
			coefJ = 1;
			coefI = 0;
		}
	}
	DisplayMatrix(snailMatrix);

	return 0;
}