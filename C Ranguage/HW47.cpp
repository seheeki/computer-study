#pragma warning(disable:4996)
#include<stdio.h>
int input(double *sp, int size); //입력 함수
double outputMax(double *maxp, int size); //최대값 구하는 함수
double outputMin(double *minp, int size); // 최소값 구하는 함수
int output(double max, double min); // 결과 출력 함수
void myflush(void);

int main()
{
	double ary[5];
	int size = sizeof(ary)/sizeof(ary[0]);
	double max, min;

	input(ary, size);
	max = outputMax(ary, size);
	min = outputMin(ary, size);
	printf("\n");
	output(max, min);

	return 0;
}
int input(double *sp, int size)
{
	int i, res;
	for (i = 0; i < size; i++)
	{
		while (1)
		{
			printf("%d 번 방 값 : ", i);
			res = scanf("%lf", &sp[i]);
			if(res != 1)
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
double outputMax(double *maxp, int size)
{
	double max;
	int i;

	max = maxp[0];
	for (i = 1; i < size; i++)
	{
		if (max < maxp[i])
		{
			max = maxp[i];
		}
	}
	return max;
}
double outputMin(double *minp, int size)
{
	double min;
	int i;
	min = minp[0];
	for (i = 1; i < size; i++)
	{
		if (min > minp[i])
		{
			min = minp[i];
		}
	}
	return min;
}
int output(double max, double min)
{
	printf("가장 큰 값 : %.2lf\n", max);
	printf("가장 작은 값 : %.2lf\n", min);
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