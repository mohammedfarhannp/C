#include <stdio.h>

int int_input(char *prompt) {
	int number;
	printf("%s", prompt);
	scanf("%d",&number);
	return number;
}

float float_input(char* prompt)
{
	float number;
	printf("%s", prompt);
	scanf("%f", &number);
	return number;
}

void char_pointer_input(char* prompt, int size, char* ptr)
{
	printf("%s", prompt);
	fgets(ptr, size, stdin);
}

double double_input(char* prompt)
{
	double number;
	printf("%s", prompt);
	scanf("%lf", &number);
	return number;
}

long double long_double_input(char* prompt)
{
	long double number;
	printf("%s", prompt);
	scanf("%Lf", &number);
	return number;
}

short short_input(char* prompt)
{
	short number;
	printf("%s", prompt);
	scanf("%hd", &number);
	return number;
}

long long_input(char* prompt)
{
	long number;
	printf("%s", prompt);
	scanf("%ld", &number);
	return number;
}

long long long_long_input(char* prompt)
{
	long long number;
	printf("%s", prompt);
	scanf("%lld", &number);
	return number;
}

void char_array_input(char* prompt, int size, char array[])
{
	printf("%s", prompt);
	fgets(array, size, stdin);
}
