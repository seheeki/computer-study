#include<stdio.h>

int main()
{
	char sp;
	int alpha = 0;
	int number = 0;
	int space = 0;
	int others = 0;

	printf("# 영어 문장을 입력 하시오 : \n");

	while (1)
	{
		sp = getchar();
		
		if ((sp >= 'a'&& sp <= 'z') || (sp >= 'A' && sp <= 'Z'))
		{
			alpha += 1;
		}
		else if (sp == ' ' || sp == '\n' || sp == '\t')
		{
			space += 1;
		}
		else if (sp >= '0' && sp <= '9')
		{
			number += 1;
		}
		else if (sp == EOF)
		{
			break;
		}
		else
		{
			others += 1;
		}

	}

	printf("* 영문자 대소문자 개수 : %d개\n", alpha);
	printf("* 숫자문자 개수 : %d개\n", number);
	printf("* 여백문자(space, tab, enter) 개수 : %d개\n", space);
	printf("* 그 외 기타문자 개수 : %d개\n", others);

	return 0;
}