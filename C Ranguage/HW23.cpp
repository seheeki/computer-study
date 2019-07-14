//반복적으로 두 개의 정수를 입력 받아 두 수의 차를 출력 
// 큰수에서 작은 수를 뺀다
// 문자를 입력하면 종료
#include<stdio.h>

int main()
{
	while (1)
	{
		int n1, n2, res;

		printf("# 두 개의 정수를 입력하세요 : ");
		res = scanf("%d %d", &n1, &n2);

		if(res != 2)
		{
			break;
		}
		else
		{
			if (n1 >= n2)
			{
				printf("%d - %d = %d\n", n1, n2, n1 - n2);
			}
			else
			{
				printf("%d - %d = %d\n", n2, n1, n2 - n1);
			}
		}
	}
	return 0;
}