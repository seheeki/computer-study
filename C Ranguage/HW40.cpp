#pragma warning(disable:4996)
#include<stdio.h>
//메인함수에서 작성
//iterator변수 2개, 라인 저장변수 1개만 사용
//문자 입력 시 종료
int main()
{
	int i, j;
	int line;

	while (1)
	{
		printf("# 출력 라인수를 입력하시오 : ");
		if (scanf("%d", &line) == 1)
		{
			for (i = 0; i <= line; i++)
			{
				for (j = 0; j < i; j++)
				{
					printf("*");
				}
				for (j = 0; j < (line*2+2)-2*i; j++)
				{
					printf(" ");
				}
				for (j = 0; j < i; j++)
				{
					printf("*");
				}
				printf("\n");
			}
		}
		else 
		{ 
			break; 
		}
		printf("\n");
	}
	return 0;
}