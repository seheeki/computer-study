#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int random(int n); //���� �߻�
int initAry(int(*np)[4]); //������ �迭�� �ʱ�ȭ ��Ű�� �Լ�
int outputAry(int(*ap)[4]); //�迭�� ����� ����� �հ踦 ����ϴ� �Լ�

int main()
{
	int num[3][4];

	initAry(num);
	outputAry(num);
	printf("\n");
	return 0;
}
int initAry(int(*np)[4])
{
	int i, j;
	i = 0;
	srand((unsigned int)time(NULL));
	for (i = 0; i<3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			np[i][j] = random(9);
		}
	}
	return 0;
}
int outputAry(int(*ap)[4])
{
	int i, j;
	int row = 0, column = 0;

	for (i = 0; i < 3; i++)
	{
		printf("%d��\t: ", i);
		for (j = 0; j < 4; j++)
		{
			printf("%-3d", ap[i][j]);
			row += ap[i][j];
		}
		printf("\t%d ���� �� : %d\n", i, row);
		row = 0;
	}

	printf("���� �� :");
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 3; j++)
		{
			column += ap[j][i];
		}
		if (column < 10) { printf(" %d ", column); }
		else { printf("%-3d", column); }
		column = 0;
	}
	return 0;
}
int random(int n)
{
	int res;
	res = rand() % n + 1;
	return res;
}