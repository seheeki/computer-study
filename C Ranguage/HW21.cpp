//다섯명 학생키 입력, 평균
#include<stdio.h>

int main()
{
	int i;
	double height, total = 0.0, mean;

	for (i = 1; i < 6; i++)
	{
		printf("%d 번 학생의 키는? ", i);
		scanf("%lf", &height);
		total += height;
	}

	mean = total / 5;
	printf("다섯 명의 평균 키는 %.1lf 입니다.\n", mean);

	return 0;
}