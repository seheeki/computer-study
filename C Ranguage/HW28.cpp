#include<stdio.h>

int main()
{
	char sp;
	int alpha = 0;
	int number = 0;
	int space = 0;
	int others = 0;

	printf("# ���� ������ �Է� �Ͻÿ� : \n");

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

	printf("* ������ ��ҹ��� ���� : %d��\n", alpha);
	printf("* ���ڹ��� ���� : %d��\n", number);
	printf("* ���鹮��(space, tab, enter) ���� : %d��\n", space);
	printf("* �� �� ��Ÿ���� ���� : %d��\n", others);

	return 0;
}