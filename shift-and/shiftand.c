#include "shiftand.h"

char* unique_chars(const char* pattern) {

	int counter = 0;
	char *res = (char*)calloc(strlen(pattern), sizeof(char));

	for (int i = 0; i < strlen(pattern); ++i) {
		if(!contains_char(res, pattern[i])){
			res[counter] = pattern[i];
			counter++;
		}
	}
	return res;

}

int contains_char(char* a, char c) {

	for (size_t i = 0; i < strlen(a); ++i) {
		if(a[i] == c)
			return 1;
	}

	return 0;

}


unsigned int* create_masks(char *unique_chars, const char *pattern, int totsymbols) {
	unsigned int *masks = (unsigned int*)calloc(totsymbols, sizeof(unsigned int));
	for (size_t i = 0; i < strlen(unique_chars); ++i) {
		for (size_t j = 0; j < strlen(pattern); ++j) {

			if(pattern[j] == unique_chars[i])
				masks[i] = masks[i] + pow(2, strlen(pattern) - j - 1);
		}
	}
	return masks;
}

void calculate_array(char *text, unsigned int *mask, char *unique_chars, const char *pattern) {
	int totmatches = 0;
	unsigned int result = 0;
	unsigned int tmp = 0;
	char current_char;
    int current_symbol_index;
    unsigned int supp = 0;

    size_t text_size = strlen(text);

    size_t unit = text_size / 100;
    size_t progress = 0;

    Node *matches;



	if(pattern[0] == text[0])
		tmp = pow(2, strlen(pattern) - 1);
	else
		tmp = 0;

	for (size_t i = 1; i < text_size; ++i) {
		supp = bit_shift(tmp, strlen(pattern));
		current_char = text[i];
		current_symbol_index = indexof(unique_chars, current_char);
		if(current_symbol_index == -1)
			result = supp & 0;
		else
			result = supp & mask[current_symbol_index];
		if(result == 1){
			totmatches++;
			if(totmatches == 1){
				matches = createList(i);
			}
			else
				insert(i, matches);
		}
		tmp = result;

		if(i % unit == 0){
			progress++;
			printf("\rsearching[%zu%c]	current matches[%d]", progress, 37, totmatches);
			fflush(stdout);
			
		}

	}
	printf("\rsearching[100%c]	current matches[%d]\n", 37, totmatches);
	if(totmatches != 0){
		printf("Matches for \"%s\" found at these positions: \n", pattern);
		printList(matches);
		free(matches);
	}

	

}

unsigned int bit_shift(unsigned int n, int pattern_length) {

	unsigned int tmp = n >> 1;

	return tmp + pow(2, pattern_length - 1);

}

int indexof(char *unique_chars, char c) {


	for (size_t i = 0; i < strlen(unique_chars); ++i) {
	
		if(unique_chars[i] == c)
			return i;

	}

	return -1;

}

