#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

char *read_long_line(FILE*);

int main()
{
	char* line1 = NULL;
	char* line2 = NULL;

	FILE *fPointer = stdin;

	if(fPointer == NULL)
	{
		perror("Error: \n");
		exit(EXIT_FAILURE);
	}

	line1 = read_long_line(fPointer);
	line2 = NULL;
	
	while(!feof(fPointer))
	{
		line2 = line1;
		line1 = read_long_line(fPointer);
		if(strcmp(line2, line1) == 0)	
		{
			continue;
		}
		else
		{
			printf("%s", line2);
		}

	}
	free(line1);
	fclose(fPointer);

	return 0;
}

char *read_long_line(FILE *file)
{
	int i = 0;
	char *charArray = (char*)malloc(1000 * sizeof(char));
	int c = 0;
	int size = 1000;

	if(charArray == NULL)	/*check if memory was properly allocated */
	{
		perror("Error: \n");
		exit(EXIT_FAILURE);
	}
	
	while(c != '\n' && c != EOF)
	{
	 if((i + 1) == size)
	 {
 	   charArray = (char*)realloc(charArray, (size + 1000) * sizeof(char));
	   size += 1000; 
	 }

		if(charArray == NULL)
		{
			perror("Error: \n");
			exit(EXIT_FAILURE);
		}
	
		c = getc(file);
		charArray[i] = c;
		i++;
	}
	return charArray;	/* return character pointer */
}
