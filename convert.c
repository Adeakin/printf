#include "main.h"
#include <stdio.h>

int main(void)
{
	int covt;

	printf("Enter an interger: ");

	if (scanf("%d", &covt) != 1)
	{
		printf("Invalid input. Please enter an integer. \n");
		return 1;
	}

	printf("You entered: %d\n", covt);

	return 0;
}
