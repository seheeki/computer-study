//������ Ż�� ~,~
#include<stdio.h>
int input(void); // �Է��Լ�
int output(double deep, int day); // ��� ����Լ�
int calDay(int deep); //Ż�� ��¥ ��� �Լ�

int main()
{
	int day;
	double deep;

	deep = input();
	day = calDay(deep);
	deep = deep * 0.01;
	output(deep, day);

	return 0;
}

int input()
{
	int deep;

	printf("* �칰�� ���̸� �Է��Ͻÿ�(cm����) : ");
	scanf("%d", &deep);

	return deep;
}

int calDay(int deep)
{
	int day=0, morning=50, night=20, height=0;

	while (1)
	{
		height += morning;

		if (deep == 0)
		{
			day = 0;
			break;
		}
		else
		{
			if (height >= deep)
			{
				day += 1;
				break;
			}
			else
			{
				height -= night;
			}
		}
		day += 1;
	}

	return day;
}

int output(double deep, int day)
{
	printf("* %.2lf���� ������ �칰�� Ż���ϱ� ���ؼ��� %d���� �ɸ��ϴ�.\n", deep, day);
	return 0;
}