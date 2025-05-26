#include <stdio.h>
#include <malloc.h>

#define MAX 4096

char lowercase[26] = "abcdefghijklmnopqrstuvwxyz";
char uppercase[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(int argc, char* argv[])
{
	if (argc != 1)
	{
		printf("Program doesn't take command-line arguments!\n");
		return 1;
	}

	char* plaintext = malloc(MAX);

	printf("Enter text to be encoded in rot13 algorithm: ");
	fgets(plaintext, MAX, stdin);

	
	char* ciphertext = malloc(MAX);

	int i = 0, j;
	char c;

	while (plaintext[i] != '\0') {
		c = plaintext[i];
		for (j=0; j < 26; j++)
		{
			if (plaintext[i] == lowercase[j])
			{
				c = lowercase[(j+13) % 26];
				break;
			}

			else if (plaintext[i] == uppercase[j]) 
			{
				c = uppercase[(j + 13) % 26];
				break;
			}
		}

		ciphertext[i] = c;
		i++;
	}

	ciphertext[i] = '\0';

	printf("Rot13 Text: %s", ciphertext);

	free(plaintext);
	free(ciphertext);

	return 0;
}