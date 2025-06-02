#include <stdlib.h>
#include <stdio.h>
#include <time.h>

const char ALPHA[52] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

long random_num(long LOWER, long UPPER)
{
	static short init = 0;

	if (!init)
	{
		srand(time(0));
		init = 1;
	}

	if (LOWER < 0 || UPPER < 0)
	{
		printf("ERROR:\nLimits must be Greater than -1\n");
		return 0;
	}
	else if (LOWER > UPPER) {
		printf("ERROR:\nLower limit greater than upper limit\n");
		return 0;
	}
	long rand_int = (rand() % (UPPER - LOWER + 1)) + LOWER;
	return rand_int;
}

void random_str(int SIZE,char buffer[])
{
	for (int i = 0; i < SIZE; i++)
	{
		buffer[i] = ALPHA[random_num(0, 51)];
	}
	buffer[SIZE] = '\0';
}

