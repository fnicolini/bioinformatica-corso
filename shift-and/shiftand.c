#include "shiftand.h"

char* unique_chars(const char* pattern, char* text) {

	char *merged_array = merge_arrays(pattern, text);

	int counter = 0;
	int merged_length = strlen(merged_array);
	char *res = (char*)calloc(merged_length, sizeof(char));

	for (int i = 0; i < merged_length; ++i) {
		if(!contains_char(res, merged_array[i])){
			res[counter] = merged_array[i];
			counter++;
		}
	}
	free(merged_array);
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

unsigned int* calculate_array(char *text, unsigned int *mask, char *unique_chars, const char *pattern) {
	int matches = 0;
	unsigned int *array = (unsigned int*)calloc(strlen(text), sizeof(unsigned int));
	unsigned int tmp = 0;
	char current_char;
    int current_symbol_index;

	if(pattern[0] == text[0])
		array[0] = pow(2, strlen(pattern) - 1);
	else
		array[0] = 0;

	for (size_t i = 1; i < strlen(text); ++i) {
		tmp = bit_shift(array[i-1], strlen(pattern));
		current_char = text[i];
		current_symbol_index = indexof(unique_chars, current_char);
		array[i] = tmp & mask[current_symbol_index];
		if(array[i] == 1){
			printf("Match found, starting at character %zu\n", i - strlen(pattern) + 2);
			matches++;
		}

	}

	printf("Total matches: %d\n", matches);

	return array;
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

char* merge_arrays(const char* a, const char* b) {
	char *res = (char*)calloc(strlen(a) + strlen(b), sizeof(char));

	memcpy(res, a, strlen(a));
	memcpy(&res[strlen(a)], b, strlen(b));
	return res;

}
