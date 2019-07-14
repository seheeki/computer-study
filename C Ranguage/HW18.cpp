#include<stdio.h>
int inputAge(void); // 나이입력함수
int inputNum(void); // 명수입력함수
int output(int age, int num); //출력함수

int main()
{
	int age, num;

	age = inputAge();
	num = inputNum();
	output(age, num);

	return 0;
}

int inputAge()
{
	int age;

	printf("입장객의 나이를 입력하시오 : ");
	scanf("%d", &age);

	return age;
}

int inputNum()
{
	int num;

	printf("입장객의 수를 입력하시오 : ");
	scanf("%d", &num);
	
	getchar();
	return num;
}

int output(int age, int num)
{
	int pay, total;
	int discount = 0;

	if (age < 8)
	{
		pay = 500;
	}
	else if (age < 14)
	{
		pay = 700;
	}
	else if (age < 20)
	{
		pay = 1000;
	}
	else if (age < 56)
	{
		pay = 1500;
	}
	else
	{
		pay = 500;
	}

	total = pay * num;

	if (num >= 5)
	{
		discount = total*0.1;
		total = total*0.9;
	}

	printf("입장료 => %d원\n", pay*num);
	printf("할인금액 => %d원\n", discount);
	printf("결제금액 => %d원\n", total);

	return 0;
}