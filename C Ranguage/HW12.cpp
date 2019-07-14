// 이름을 영문으로 입력 받아 출력
#include<stdio.h>
#include<string.h>
int main()
{
	char name[20];

	printf("이름을 입력하시오 : ");
	fgets(name, strlen(name), stdin);
	name[strlen(name) - 1] = '\0';

	printf("\"%s\"\n", name);
	printf("\"%20s\"\n", name);
	printf("\"%-20s\"\n", name);

	return 0;
}