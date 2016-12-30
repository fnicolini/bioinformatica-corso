// C implementation of shift-and algorithm for exact matching
#include "shiftand.h"

/* 
	To run the program 2 command line arguments are needed: 
	1. The string you want to search for in a text
	2. The text file in which to look for the string 

*/

char* process_file(const char *filename);	


int main(int argc, char const *argv[])
{
	//Load into memory the whole text
	char *text = process_file(argv[2]);
	//Return an array of all the symbols used in this context(i.e pattern and text)
	char *symbols = unique_chars(argv[1], text);
	int totsymbols = strlen(symbols);

	unsigned int *pattern_masks = create_masks(symbols, argv[1], totsymbols);

	//Create and calculate the array containing the values used for the exact matching
	//at the same time, when a match is found print it to the console

	unsigned int *final_array = calculate_array(text, pattern_masks, symbols, argv[1]);

	// free the memory
	free(text);
	free(final_array);
	free(pattern_masks);
	free(symbols);

	return 0;
}


char* process_file(const char *filename) {
	FILE *textfile;
	long numbytes;

	//open the file
	textfile = fopen(filename, "r");

	//if there is an error, exit the program
	if(textfile == NULL){
		puts("file open error");
		exit(1);
	}

	//get the number of bytes
	fseek(textfile, 0L, SEEK_END);
	numbytes = ftell(textfile);

	// reset the file position indicator to	the beginning of the file
	fseek(textfile, 0L, SEEK_SET);

	//allocate memory for the text
	char *text = (char*)calloc(numbytes, sizeof(char));

	//if allocation went wrong, exit the program
	if(text == NULL){
		puts("file variable allocation error");
		exit(1);
	}

	//Copy the whole file into the array
	fread(text, sizeof(char), numbytes, textfile);
	fclose(textfile);

	return text;	
}