//한줄에 5개씩 별 출력
#include<stdio.h>
int input(void); //입력함수

int main()
{
	int num, i=1;

	num = input();

	while (i <= num)
	{
		printf("*");
		if (i % 5 == 0)
		{
			printf("\n");
		}
		i += 1;
	}
	printf("\n");
	return 0;
}

int input()
{
	int num;

	printf("# 정수값을 입력하세요 : ");
	scanf("%d", &num);

	return num;
}