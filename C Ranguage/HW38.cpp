#pragma warning(disable:4996)
#include<stdio.h>
//�ݺ� ����, ���� �Է� �� ����
//�ܵ� x, ��� ǰ�� �� �� �̻� ����
void myflush(void);

int main()
{
	int cream = 500, shrimp = 700, cola = 400;
	int money, res;
	int i, j, k;
	int change, change2;
	int spend;

	while (1)
	{
		printf("���� ����� ���� �ݾ� �Է� : ");
		res = scanf("%d", &money);
		if (res != 1) { break; }
		else if (money < 0) { myflush(); }
		else
		{
			for(i=1;i<=money/cream; i++)
			{
				change = money - i*cream;
				for (j = 1; j <= change / shrimp; j++)
				{
					change2 = change - j*shrimp;
					for (k = 1; k <= change2 / cola; k++)
					{
						spend = i*cream + j*shrimp + k*cola;
						if (spend == money) { printf("ũ����(%d ��), �����(%d ��), �ݶ�(%d ��)\n", i, j, k); }
					}
				}
			}
			printf("��� �����Ͻðڽ��ϱ�?\n\n");
		}
	}
	return 0;
}
void myflush()
{
	char ch;
	while ((ch = getchar()) != '\n')
	{
		;
	}
	return;
}