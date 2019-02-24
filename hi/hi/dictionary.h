#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdio.h>
#include <string.h>
struct dic
{
	char *hanguel;
	char *english;
};
int make_dictionary(void);
int translate(char *word);

#endif