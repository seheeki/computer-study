#pragma warning(disable:4996)
#include<stdio.h>
//�����Լ����� �ۼ�
//iterator���� 2��, ���庯�� 1���� ���
//������ �빮�� �� �ٸ� ���� �Է� �� ����

int main()
{
	int i, j;
	char letter;
	
	while (1)
	{
		printf("* ������ �빮�� �Է�('A'~ 'Z') : ");
		scanf("%c", &letter);
		if (letter >= 'A' && letter <= 'Z')
		{
			for (i = letter; i >= 'A'; i--)
			{
				for (j = letter; j >= i; j--)
				{
					printf("%c", j);

				}
				printf("\n");
			}
			while ((letter = getchar()) != '\n')
			{
				;
			}
		}
		else { break; }
		printf("\n");
	}
	return 0;
}