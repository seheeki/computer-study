#pragma warning(disable:4996)
#include<stdio.h>
int input(int *cp, int *tp); //입력함수
int calMoney(int code, int ton); // 수도요금 계산함수
int output(int code, int ton, int total); //결과 출력 함수
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
		printf("* 사용자 코드를 입력하시오(1:가정용/2:상업용/3:공업용) : ");
		res1 = scanf("%d", cp);
		if (res1 != 1 || *cp < 1 || *cp > 3) { myflush(); }
		else { break; }
	}
	while (1)
	{
		printf("* 사용량을 입력하시오(ton단위) : ");
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
	case 1: printf("# 사용자 코드 : %d(가정용)\n", code); break;
	case 2: printf("# 사용자 코드 : %d(상업용)\n", code); break;
	case 3: printf("# 사용자 코드 : %d(공업용)\n", code); break;
	default: break;
	}
	printf("# 사용량 : %d ton\n", ton);
	printf("# 총수도요금 : %d원\n", total);
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