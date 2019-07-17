#pragma warning(disable:4996)
#include<stdio.h>
int fibo(int n);
void myflush(void);

int main()
{
	int n;
	int i;
	long long total = 0;

	while (1)
	{
		printf("피보나치 수열의 항수를 입력하시오 : ");
		scanf("%d", &n);
		if (n >= 1 && n <= 30) { break; }
		else { myflush(); }
	}

	for (i = 1; i <= n; i++)
	{
		printf("%d ", fibo(i));
		if (i <= n - 1) { printf("+ "); }
		total += fibo(i);
	}
	printf("= %lld\n", total);
	return 0;
}

int fibo(int n)
{
	if (n == 1 || n == 2) { return 1; }
	else { return fibo(n - 1) + fibo(n - 2); }
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