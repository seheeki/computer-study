#include<stdio.h>

int input(void); //�Է��Լ�
int glossPay(int time); //�Ѽ��� ����Լ�
int taxes(int money); //���� ����Լ�
int output(int total, int tax, int netPay); //��� ����Լ�

int main()
{
	int time, tax, netPay;
	int total;

	time = input();
	total = glossPay(time);
	tax = taxes(total);
	netPay = total - tax;
	output(total, tax, netPay);

	return 0;
}

int input()
{
	int time;

	printf("1���ϰ��� �ٹ��ð��� �Է��Ͻÿ� : ");
	scanf("%d", &time);

	return time;
}

int glossPay(int time)
{
	int total;
	int basicT, addT;

	if (time <= 40)
	{
		basicT = time;
		addT = 0;
	}
	else
	{
		basicT = 40;
		addT = time - 40;
	}
	total = basicT * 3000 + addT * 3000 * 1.5;
	return total;
}

int taxes(int money)
{
	int tax;

	if (money <= 100000)
	{
		tax = money * 0.15;
	}
	else
	{
		tax = 100000 * 0.15 + (money - 100000) * 0.25;
	}

	return tax;
}

int output(int total, int tax, int netPay)
{
	printf("# �Ѽ��� :");
	printf("%7d��\n", total);
	printf("# ��  �� :");
	printf("%7d��\n", tax);
	printf("# �Ǽ��� :");
	printf("%7d��\n", netPay);

	return 0;
} 