#include <stdio.h>
#include <string.h>
#include "dictionary.h"

int main()
{
	char word[100];

	make_dictionary();

	while(1)
	{
		memset(word, 0, 100*sizeof(char));
		scanf("%s", word);
		fflush(stdin); 
		if(strncmp("��", word, strlen(word)) == 0)
		{
			break;
		}
	    //translate(word);
		translate_memory(word);
	}



	return 0;
}