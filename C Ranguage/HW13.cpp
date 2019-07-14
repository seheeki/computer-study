//이름 받아 출력, 숫자
#include<stdio.h>
#include<string.h>
int main()
{
	char firstN[20];
	char lastN[20];

	printf("#성을 입력하시오 : ");
	fgets(firstN, strlen(firstN), stdin);
	firstN[strlen(firstN) - 1] = '\0';

	printf("#이름을 입력하시오 : ");
	fgets(lastN, strlen(lastN), stdin);
	lastN[strlen(lastN) - 1] = '\0';

	printf("%s %s\n", firstN, lastN);
	printf("%*d %*d", strlen(firstN), strlen(firstN), strlen(lastN), strlen(lastN));

	return 0;
}