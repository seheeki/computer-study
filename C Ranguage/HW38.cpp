#pragma warning(disable:4996)
#include<stdio.h>
//반복 수행, 문자 입력 시 종료
//잔돈 x, 모든 품목 한 개 이상씩 구매
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
		printf("현재 당신의 소유 금액 입력 : ");
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
						if (spend == money) { printf("크림빵(%d 개), 새우깡(%d 개), 콜라(%d 개)\n", i, j, k); }
					}
				}
			}
			printf("어떻게 구입하시겠습니까?\n\n");
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