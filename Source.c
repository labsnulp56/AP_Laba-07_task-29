#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 100

int main(int argc, char *argv[])
{
	system("chcp 1251");
	char main_char[] = "int main()\n";
	char left[] = "{\n";
	char right[] = "}\n";
	int left_brackets = 0;
	int right_bracket = 0;
	char c[100];
	int in_main = 0;
	FILE *fptr;

	fptr = fopen("program.txt", "r");
	if (fptr == NULL)
	{
		printf("error");
		exit(1);
	}
	while ((fgets(c, LEN, fptr)) != NULL) {
		if (strcmp(c, main_char) == 0)
		{
			do {
				fgets(c, LEN, fptr);
				if (strcmp(c, left) == 0) left_brackets++;
				if (strcmp(c, right) == 0) right_bracket++;
		
			} while (right_bracket != left_brackets);
		}
		else printf("%s", c);
	}
	printf("\n");
	system("pause");
	return 0;
} 

