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

	return res;

}

int contains_char(char* a, char c) {

	for (int i = 0; i < strlen(a); ++i) {
		if(a[i] == c)
			return 1;
	}

	return 0;

}


void fill_mask(unsigned int *mask, char *unique_chars, const char *pattern) {

	for (int i = 0; i < strlen(unique_chars); ++i) {
		for (int j = 0; j < strlen(pattern); ++j) {

			if(pattern[j] == unique_chars[i])
				mask[i] = mask[i] + pow(2, strlen(pattern) - j - 1);
		}
	}

}

void calculate_array(unsigned int *array, char *text, unsigned int *mask, char *unique_chars, const char *pattern) {
	unsigned int tmp = 0;
	char current_char;
    int current_symbol_index;

	if(pattern[0] == text[0])
		array[0] = pow(2, strlen(pattern) - 1);
	else
		array[0] = 0;

	for (int i = 1; i < strlen(text); ++i) {
		tmp = bit_shift(array[i-1], strlen(pattern));
		current_char = text[i];
		current_symbol_index = indexof(unique_chars, current_char);
		array[i] = tmp & mask[current_symbol_index];

	}


}

unsigned int bit_shift(unsigned int n, int pattern_length) {

	unsigned int tmp = n >> 1;

	return tmp + pow(2, pattern_length - 1);

}

int indexof(char *unique_chars, char c) {


	for (int i = 0; i < strlen(unique_chars); ++i) {
	
		if(unique_chars[i] == c)
			return i;

	}

}

char* merge_arrays(const char* a, const char* b) {

	char *res = (char*)calloc(strlen(a) + strlen(b), sizeof(char));

	memcpy(res, a, strlen(a));
	memcpy(&res[strlen(a)], b, strlen(b));

}

void print_result(unsigned int *array_risolvente, int textlen, int patlen) {


	for (int i = 0; i < textlen; ++i) {
		
		if(array_risolvente[i] == 1)
			printf("Ho trovato un'occorrenza del pattern, inizia alla posizione %d\n", i - patlen + 2);

	}


}