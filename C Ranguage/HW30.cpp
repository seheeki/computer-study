#include<stdio.h>
int main()
{
	int num;
	int i;
	int digit;
	printf("* 10 ���� ������ �Է��Ͻÿ� : ");
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
