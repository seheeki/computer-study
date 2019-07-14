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

	printf("�⵵�� �Է��Ͻÿ� : ");
	scanf("%d", &year);
	
	return year;
}
int output(int year, int num)
{
	if (num == 0)
	{
		printf("%d���� ���(Common year)�Դϴ�.", year);
	}
	else
	{
		printf("%d���� ����(Leap year)�Դϴ�.", year);
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
