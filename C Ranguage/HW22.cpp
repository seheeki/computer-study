//���ٿ� 5���� �� ���
#include<stdio.h>
int input(void); //�Է��Լ�

int main()
{
	int num, i=1;

	num = input();

	while (i <= num)
	{
		printf("*");
		if (i % 5 == 0)
		{
			printf("\n");
		}
		i += 1;
	}
	printf("\n");
	return 0;
}

int input()
{
	int num;

	printf("# �������� �Է��ϼ��� : ");
	scanf("%d", &num);

	return num;
}