#pragma warning(disable:4996)
#include<stdio.h>
//�����Լ����� �ۼ�
//iterator���� 2��, ���� ���庯�� 1���� ���
//���� �Է� �� ����
int main()
{
	int i, j;
	int line;

	while (1)
	{
		printf("# ��� ���μ��� �Է��Ͻÿ� : ");
		if (scanf("%d", &line) == 1)
		{
			for (i = 0; i <= line; i++)
			{
				for (j = 0; j < i; j++)
				{
					printf("*");
				}
				for (j = 0; j < (line*2+2)-2*i; j++)
				{
					printf(" ");
				}
				for (j = 0; j < i; j++)
				{
					printf("*");
				}
				printf("\n");
			}
		}
		else 
		{ 
			break; 
		}
		printf("\n");
	}
	return 0;
}