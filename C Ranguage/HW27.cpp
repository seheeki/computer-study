//달걀 포장
#pragma warning(disable : 4996)
#include<stdio.h>
int input(void); //입력함수
void myflush(void);

int main()
{
	int g;
	int eggN = 0;

	while (eggN < 10)
	{
		g = input();
		if (g >= 150 && g <= 500)
		{
			eggN += 1;
			printf("* 현재 달걀의 수 : %d\n", eggN);
		}
		else if(g < 150)
		{
			printf("* 메추리알 가지고 장난하지 마시오~^^\n");
		}
		else
		{
			printf("* 타조알 가지고 장난하지 마시오~^^\n");
		}
	}
	printf("\n*** 달걀 포장이 끝났습니다.\n");
	return 0;
}

int input()
{
	int g;
	int res;

	while(1)
	{
		printf("# 계란의 무게를 입력하세요(단위 : g) : ");
		res = scanf("%d", &g);

		if (res != 1)
		{
			myflush();
		}
		else
		{
			break;
		}
	
	}

	return g;
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