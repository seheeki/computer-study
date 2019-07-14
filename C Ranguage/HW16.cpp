//지하철 요금 계산하기
#include<stdio.h>

int input(void); // 입력함수
int caculate(int num); //요금계산함수
int output(int num); //출력함수

int main()
{
	int subwayStop, money;
	int i;

	for (i = 0; i < 5; i++)
	{
		subwayStop = input();
		money = caculate(subwayStop);
		output(money);
	}

	return 0;
}

int input()
{
	int num;

	printf("역수를 입력하시오 : ");
	scanf("%d", &num);

	return num;
}

int caculate(int num)
{
	int money;

	if (num < 6)
	{
		money = 600;
	}
	else if (num < 11)
	{
		money = 800;
	}
	else
	{
		if (num % 2 == 0)
		{ 
			money = 800 + (num - 10) * 50;
		}
		else
		{
			money = 800 + (num - 9) * 50;
		}
	}
	return money;
}

int output(int money)
{
	printf("요금 : %d\n", money);
	return 0;
}