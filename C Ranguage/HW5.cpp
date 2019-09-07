//전기요금 계산하기
#include<stdio.h>

int input(void); // 입력함수
int output(double use); // 출력함수

int main()
{
	double use, pay, fee, total;
	int basic = 660;

	use = input();
	pay = basic + 88.5*use;
	fee = pay * 0.09;
	total = pay + fee;

	output(total);
	return 0;
}

int input()
{
	double use;

	printf("전기 사용량을 입력하세요(kw) : ");
	scanf("%lf", &use);
	return use;
}

int output(double use)
{
	printf("전기 사용요금은 %lf 원 입니다.", use);
	return 0;
}