#pragma warning(disable:4996)
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int input(void); //입력 함수
int output(int num, int correct); //출력 함수
int random(int n); //난수 발생 함수
void myflush(void); 
int max = 100, min = 0;

int main()
{
	int num;
	int i=0;
	int count = 0, correct = 0;

	srand((unsigned int)time (NULL));
	while (i < 5)
	{
		correct = random(100);
		++i;
	}

	while (1)
	{
		num = input();
		output(num, correct);
		count += 1;
		if (num == correct) { break; }
	}
	if (correct == num)
	{
		printf("우와~ 맞았당~~~ 추카추카~~ %d 번째 만에 맞추셨습니다.\n", count);
	}

	return 0;
}

int input() //입력 함수
{
	int num, res;

	printf("# 숫자를 입력하시오 : ");
	res = scanf("%d", &num);
	while(res != 1 || (num<1 || num>100))
	{
		myflush();
		printf("# 숫자를 입력하시오 : ");
		res = scanf("%d", &num);
	}
	
	return num;
}

int output(int num, int correct) //출력 함수
{
	if (correct > num)
	{
		min = num;
		printf("%d 보다는 크고 %d 보다는 작습니다.\n", min, max);
	}
	else if (correct < num)
	{
		max = num;
		printf("%d 보다는 크고 %d 보다는 작습니다.\n", min, max);
	}
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
int random(int n) //난수 발생 함수
{
	int res;
	res = rand() % n + 1;
	return res;
}