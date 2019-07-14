#include<stdio.h>
int transNumber(int num); //양의 정수를 각 자릿수로 분할해 곱한 결과 리턴
int inputUInt(void); // 양의 정수만 입력 받아 리턴하는 함수 음수, 문자 예외 처리
int inputUInt2(const char *msg); //양의 정수만 입력 받아 리턴하는 함수 음수, 문자 예외 처리
int output(int count); // 결과 출력함수
void myflush(void);

int main()
{
	int p1, p2, n;
	int i;
	int res;
	int total = 0, count = 0;
	
	p1 = inputUInt2("시작 값(P1) : ");
	p2 = inputUInt2("끝 값(P2) : ");
	n = inputUInt();
	
	printf("고집수가 %d인 숫자 출력\n", n);
	for (i = p1; i <= p2; i++)
	{
		res = transNumber(i);
		while(1)
		{
			if (res<10)
			{
				total += 1;
				break;
			}
			else
			{
				total += 1;
				res = transNumber(res);

			}
		}
		if (total == n)
		{
			printf("%d\n", i);
			count += 1;
		}
		total = 0;
	}
	output(count);
	return 0;
}
int transNumber(int num)
{
	int n1, res, n10, n100, n1000, n10000;

	if (num < 10)
	{
		res = num;
	}
	else if (num < 100)
	{
		n10 = num / 10;
		n1 = num % 10;
		res = n10*n1;
	}
	else if (num < 1000)
	{
		n100 = num / 100;
		n10 = (num - n100 * 100) / 10;
		n1 = num % 10;
		res = n1*n10*n100;
	}
	else if (num < 10000)
	{
		n1000 = num / 1000;
		n100 = (num - n1000 * 1000) / 100;
		n10 = (num - (n100 * 100 + n1000 * 1000)) / 10;
		n1 = num % 10;
		res = n1*n10*n100*n1000;
	}
	else
	{
		n10000 = num / 10000;
		n1000 = (num - n10000*10000)/ 1000;
		n100 = (num - (n10000*10000 + n1000*1000)) / 100;
		n10 = (num - (n100 * 100 + n1000 * 1000 + n10000 * 10000)) / 10;
		n1 = num % 10;
		res = n1*n10*n100*n1000;
	}
	return res;
}

int inputUInt()
{
	int n;
	int numR;

	while (1)
	{
		printf("고집수(N) : ");
		numR = scanf("%d", &n);
		if (numR == 1 && n>0)
		{
			break;
		}
		else
		{
			myflush();
		}
	}
	return n;
}
int inputUInt2(const char *msg)
{
	int n;
	int numR;

	while (1)
	{
		printf("%s", msg);
		numR = scanf("%d", &n);
		if (numR == 1 && (n>=100 && n<=10000))
		{
			break;
		}
		else
		{
			myflush();
		}
	}
	return n;
}

int output(int count)
{
	printf("총 개수 : %d개\n", count);
	return 0;
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