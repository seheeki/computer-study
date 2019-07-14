#include<stdio.h>

int input(void); //입력함수
int glossPay(int time); //총수입 계산함수
int taxes(int money); //세금 계산함수
int output(int total, int tax, int netPay); //결과 출력함수

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

	printf("1주일간의 근무시간을 입력하시오 : ");
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
	printf("# 총수입 :");
	printf("%7d원\n", total);
	printf("# 세  금 :");
	printf("%7d원\n", tax);
	printf("# 실수입 :");
	printf("%7d원\n", netPay);

	return 0;
} 