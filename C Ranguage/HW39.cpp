#include<stdio.h>
//�����Լ� �ϳ��� ó��
int main()
{
	int i, j;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j <= 90; j += 10)
		{
			printf("%d ", j + i);
		}
		printf("\n");
	}
	return 0;
}