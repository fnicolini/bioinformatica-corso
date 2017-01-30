#ifndef SHIFTAND_H
#define SHIFTAND_H
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "linkedlist.h"

char* unique_chars(const char* pattern);
int contains_char(char* pattern, char c);
unsigned int* create_masks(char *unique_chars, const char *pattern, int totsymbols);
void calculate_array(char *text, unsigned int *mask, char *unique_chars, const char *pattern);
int indexof(char *unique_chars, char c);
unsigned int bit_shift(unsigned int n, int pattern_length);

#endif