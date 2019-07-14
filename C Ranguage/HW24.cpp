//달팽이 탈출 ~,~
#include<stdio.h>
int input(void); // 입력함수
int output(double deep, int day); // 결과 출력함수
int calDay(int deep); //탈출 날짜 계산 함수

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

	printf("* 우물의 깊이를 입력하시오(cm단위) : ");
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
	printf("* %.2lf미터 깊이의 우물을 탈출하기 위해서는 %d일이 걸립니다.\n", deep, day);
	return 0;
}