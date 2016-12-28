#ifndef SHIFTAND_H
#define SHIFTAND_H
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

char* unique_chars(const char* pattern, char *text);
int contains_char(char* pattern, char c);
void fill_mask(unsigned int *mask, char *unique_chars, const char *pattern);
void calculate_array(unsigned int *array, char *text, unsigned int *mask, char *unique_chars, const char *pattern);
char* merge_arrays(const char* a, const char* b);
int indexof(char *unique_chars, char c);
unsigned int bit_shift(unsigned int n, int pattern_length);
void print_result(unsigned int *array_risolvente, int textlen, int patlen);

#endif