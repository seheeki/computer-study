#include<stdio.h>
int main()
{
	int num;
	int i;
	int digit;
	printf("* 10 진수 정수를 입력하시오 : ");
	scanf("%d", &num);
	printf("%d(10) = ", num);
	for (i = 31; i>=0; i--)
	{
		digit = num >> i & 1;
		printf("%d", digit);
	}
	printf("(2)\n");
	return 0;
}
