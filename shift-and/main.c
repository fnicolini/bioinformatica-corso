// C implementation of shift-and algorithm for exact matching
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shiftand.h"


// argv[1] is the pattern
// argv[2] is the file that contains the text in which to look for the pattern
int main(int argc, char const *argv[])
{
	FILE *textfile;
	char *text;
	long numbytes;

	printf("%s\n", argv[2]);

	//open the file
	textfile = fopen(argv[2], "r");

	//if there is an error, exit the program
	if(textfile == NULL)
		return 1;

	//get the number of bytes
	fseek(textfile, 0L, SEEK_END);
	numbytes = ftell(textfile);

	// reset the file position indicator to	the beginning of the file
	fseek(textfile, 0L, SEEK_SET);

	//allocate memory for the text
	text = (char*)calloc(numbytes, sizeof(char));

	//if allocation went wrong, exit the program
	if(text == NULL)
		return 1;

	//Copy the whole file into the array
	fread(text, sizeof(char), numbytes, textfile);
	fclose(textfile);

	char *unique_pchars = unique_chars(argv[1], text);
	int totunique_pchars = strlen(unique_pchars);

	unsigned int *pattern_masks = (unsigned int*)calloc(totunique_pchars, sizeof(unsigned int));

	fill_mask(pattern_masks, unique_pchars, argv[1]);

	//create array

	unsigned int *array_risolvente = (unsigned int*)calloc(strlen(text), sizeof(unsigned int));

	calculate_array(array_risolvente, text, pattern_masks, unique_pchars, argv[1]); 

	print_result(array_risolvente, strlen(text), strlen(argv[1]));


	/*
	printf("\nnumero di elementi: %d\n", argc);
	printf("pattern length: %d\n", strlen(argv[1]));
	printf("text length: %d\n", numbytes);
	printf("number of unique_pchars: %d\n", totunique_pchars);
	printf("unique pchars: %s\n", unique_pchars);
	printf("pattern: %s\n", argv[1]);

	for (int i = 0; i < totunique_pchars; ++i) {

		printf("%d ", pattern_masks[i]);

	}

	puts("\n");




	for (int i = 0; i < strlen(text); ++i) {

		printf("%d ", array_risolvente[i]);

	}

	puts("\n");
	*/

	// free the memory we used for the buffer
	free(text);

	return 0;
}


