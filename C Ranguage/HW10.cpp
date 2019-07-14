//두 정수를 입력 받아 합, 차, 곱, 몫의 값을 출력하는 프로그램 작성. 실수 값은 소수점 이하 둘째 자리까지 출력
#include<stdio.h>

int main()
{
	int num1, num2;
	
	printf("두개의 정수를 입력하시오 : ");
	scanf("%d %d", &num1, &num2);

	printf("%d+%d = %d\n", num1, num2, num1 + num2);
	printf("%d-%d = %d\n", num1, num2, num1 - num2);
	printf("%d*%d = %d\n", num1, num2, num1 * num2);
	printf("%d/%d = %.2lf\n", num1, num2, num1 / (double)num2);

	return 0;
}