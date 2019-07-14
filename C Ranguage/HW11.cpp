//ASCII code를 입력 받아 해당 문자 출력
#include<stdio.h>

int main()
{
	int ascii;

	printf("ASCII code값을 입력하시오 : ");
	scanf("%d", &ascii);

	printf("%d은 '%c'의 ASCII code 입니다.\n", ascii, ascii);
	return 0;
}