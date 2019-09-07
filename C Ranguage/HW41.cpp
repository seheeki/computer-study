#pragma warning(disable:4996)
#include<stdio.h>
//메인함수에서 작성
//iterator변수 2개, 저장변수 1개만 사용
//영문자 대문자 외 다른 문자 입력 시 종료

int main()
{
	int i, j;
	char letter;
	
	while (1)
	{
		printf("* 영문자 대문자 입력('A'~ 'Z') : ");
		scanf("%c", &letter);
		if (letter >= 'A' && letter <= 'Z')
		{
			for (i = letter; i >= 'A'; i--)
			{
				for (j = letter; j >= i; j--)
				{
					printf("%c", j);

				}
				printf("\n");
			}
			while ((letter = getchar()) != '\n')
			{
				;
			}
		}
		else { break; }
		printf("\n");
	}
	return 0;
}