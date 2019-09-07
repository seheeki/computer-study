#include<stdio.h>
#include<string.h>
int input(char *sp, char *lp); //문자열, 문자 입력 함수
void myflush(void);
int strcheck(char *stp, char letter); //문자 위치 검사 함수, 단일검색

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
		printf("\"%s\"문자열 안에 '%c'문자는 %d번 위치에 존재합니다.\n", msg, letter, res);
	}
	else
	{
		printf("\"%s\"문자열 안에 '%c'문자는 존재하지 않습니다.\n", msg, letter);
	}
	return 0;
}
int input(char *sp, char *lp)
{
	printf("# 문자열을 입력하세요 : ");
	scanf("%s", sp);
	myflush();
	printf("# 문자를 입력하시오 : ");
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