#pragma warning(disable:4996)
#include<stdio.h>
void myflush(void);
int input(int *sp, int size); //입력함수 허용

int main()
{
	int ary[5];
	int size;
	int i, total = 0;

	size = sizeof(ary) / sizeof(ary[0]);
	input(ary, size);

	for (i = 0; i < size; i++)
	{
		total += ary[i];
	}
	printf("입력된 값의 총 합 : %d\n", total);
	return 0;
}

int input(int *sp, int size)
{
	int i, res;

	for (i = 0; i < size; i++)
	{
		while (1)
		{
			printf("0보다 큰수를 입력하시오(%d번째) : ", i+1);
			res = scanf("%d", &sp[i]);
			if (res != 1 || sp[i] <= 0)
			{
				myflush();
			}
			else
			{
				break;
			}
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