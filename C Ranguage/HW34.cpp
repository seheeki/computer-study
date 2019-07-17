#pragma warning(disable:4996)
#include<stdio.h>
int input(int *cp, int *tp); //�Է��Լ�
int calMoney(int code, int ton); // ������� ����Լ�
int output(int code, int ton, int total); //��� ��� �Լ�
void myflush(void);

int main()
{
	int code, ton;
	int total;

	input(&code, &ton);
	total = calMoney(code, ton);
	printf("\n");
	output(code, ton, total);
	return 0;
}
int input(int *cp, int *tp)
{
	int res1, res2;
	while (1)
	{
		printf("* ����� �ڵ带 �Է��Ͻÿ�(1:������/2:�����/3:������) : ");
		res1 = scanf("%d", cp);
		if (res1 != 1 || *cp < 1 || *cp > 3) { myflush(); }
		else { break; }
	}
	while (1)
	{
		printf("* ��뷮�� �Է��Ͻÿ�(ton����) : ");
		res2 = scanf("%d", tp);
		if (res2 != 1 || *tp < 0) { myflush(); }
		else { break; }
	}
	
	return 0;
}
int calMoney(int code, int ton)
{
	int tax;
	int total;

	switch (code)
	{
	case 1: tax = 50 * ton; break;
	case 2: tax = 45 * ton; break;
	case 3: tax = 30 * ton; break;
	default: break;
	}

	total = tax + tax*0.05;
	return total;
}
int output(int code, int ton, int total)
{
	switch (code)
	{
	case 1: printf("# ����� �ڵ� : %d(������)\n", code); break;
	case 2: printf("# ����� �ڵ� : %d(�����)\n", code); break;
	case 3: printf("# ����� �ڵ� : %d(������)\n", code); break;
	default: break;
	}
	printf("# ��뷮 : %d ton\n", ton);
	printf("# �Ѽ������ : %d��\n", total);
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