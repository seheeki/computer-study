//����ö ��� ����ϱ�
#include<stdio.h>

int input(void); // �Է��Լ�
int caculate(int num); //��ݰ���Լ�
int output(int num); //����Լ�

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

	printf("������ �Է��Ͻÿ� : ");
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
	printf("��� : %d\n", money);
	return 0;
}