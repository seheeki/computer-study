//�ް� ����
#pragma warning(disable : 4996)
#include<stdio.h>
int input(void); //�Է��Լ�
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
			printf("* ���� �ް��� �� : %d\n", eggN);
		}
		else if(g < 150)
		{
			printf("* ���߸��� ������ �峭���� ���ÿ�~^^\n");
		}
		else
		{
			printf("* Ÿ���� ������ �峭���� ���ÿ�~^^\n");
		}
	}
	printf("\n*** �ް� ������ �������ϴ�.\n");
	return 0;
}

int input()
{
	int g;
	int res;

	while(1)
	{
		printf("# ����� ���Ը� �Է��ϼ���(���� : g) : ");
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