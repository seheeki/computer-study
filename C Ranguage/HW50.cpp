#include<stdio.h>
#include<string.h>
int input(char *sp, char *lp); //���ڿ�, ���� �Է� �Լ�
void myflush(void);
int strcheck(char *stp, char letter); //���� ��ġ �˻� �Լ�, ���ϰ˻�

int main()
{
	char msg[99] = { '\0' };
	char letter;
	int size;
	int res;

	input(msg, &letter);

	res = strcheck(msg, letter);
	if (res != -1)
	{
		printf("\"%s\"���ڿ� �ȿ� '%c'���ڴ� %d�� ��ġ�� �����մϴ�.\n", msg, letter, res);
	}
	else
	{
		printf("\"%s\"���ڿ� �ȿ� '%c'���ڴ� �������� �ʽ��ϴ�.\n", msg, letter);
	}
	return 0;
}
int input(char *sp, char *lp)
{
	printf("# ���ڿ��� �Է��ϼ��� : ");
	scanf("%s", sp);
	myflush();
	printf("# ���ڸ� �Է��Ͻÿ� : ");
	scanf("%c", lp);
	return 0;
}
int strcheck(char *stp, char letter)
{
	int i=0;
	int res = 0;
	int index;

	while(1)
	{
		if (stp[i] == letter)
		{
			res += 1;
			index = i;
			break;
		}
		else if (stp[i] == '\0')
		{
			break;
		}
		i++;
	}
	if (res == 0)
	{
		return -1;
	}
	else
	{
		return index;
	}
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