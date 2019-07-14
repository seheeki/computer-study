#include<stdio.h>
int input(void);
int output(int year, int num);
int yearCheck(int year);

int main()
{
	int year, num;

	year = input();
	num = yearCheck(year);
	output(year, num);

	return 0;
}
int input()
{
	int year;

	printf("년도를 입력하시오 : ");
	scanf("%d", &year);
	
	return year;
}
int output(int year, int num)
{
	if (num == 0)
	{
		printf("%d년은 평년(Common year)입니다.", year);
	}
	else
	{
		printf("%d년은 윤년(Leap year)입니다.", year);
	}
	return 0;
}

int yearCheck(int year)
{
	int num;

	if (year % 4 != 0)
	{
		num = 0;
	}
	else
	{
		if (year % 100 != 0)
		{
			num = 1;
		}
		else
		{
			if (year % 400 != 0)
			{
				num = 0;
			}
			else
			{
				num = 1;
			}
		}
	}

	return num;
}
