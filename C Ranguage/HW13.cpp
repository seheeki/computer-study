//�̸� �޾� ���, ����
#include<stdio.h>
#include<string.h>
int main()
{
	char firstN[20];
	char lastN[20];

	printf("#���� �Է��Ͻÿ� : ");
	fgets(firstN, strlen(firstN), stdin);
	firstN[strlen(firstN) - 1] = '\0';

	printf("#�̸��� �Է��Ͻÿ� : ");
	fgets(lastN, strlen(lastN), stdin);
	lastN[strlen(lastN) - 1] = '\0';

	printf("%s %s\n", firstN, lastN);
	printf("%*d %*d", strlen(firstN), strlen(firstN), strlen(lastN), strlen(lastN));

	return 0;
}