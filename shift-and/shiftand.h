#ifndef SHIFTAND_H
#define SHIFTAND_H
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

char* unique_chars(const char* pattern, char *text);
int contains_char(char* pattern, char c);
unsigned int* create_masks(char *unique_chars, const char *pattern, int totsymbols);
unsigned int* calculate_array(char *text, unsigned int *mask, char *unique_chars, const char *pattern);
char* merge_arrays(const char* a, const char* b);
int indexof(char *unique_chars, char c);
unsigned int bit_shift(unsigned int n, int pattern_length);

#endif