#pragma warning(disable:4996)
#include<stdio.h>
int input(void); //���� ���� ����ó��
void myflush(void);

int main()
{
	int n;
	int i=1, j;
	int gold = 0;
	int day = 0;

	n = input();
	while (1)
	{
		if (day == n) { break; }
		for (j = 0; j < i; j++)
		{
			gold += i;
			day++;
			if (day == n) { break; }
		}
		i++;
	}
	printf("  �ٹ��� : %d �� / �� ��ȭ �� : %d ��\n", n, gold);
	return 0;
}
int input()
{
	int n;
	int res;

	while (1)
	{
		printf("* ����� �ٹ��ϼ��� �Է��Ͻÿ� : ");
		res = scanf("%d", &n);
		if (n < 0 || res != 1) { myflush(); }
		else { break; }
	}
	return n;
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