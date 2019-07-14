//온도 변화하기
#include<stdio.h>
double input(void); //입력함수
int output(double tempF); //출력함수

int main()
{
	double tempF, tempC;
	
	tempF = input();
	output(tempF);
	return 0;
}

double input()
{
	double tempF;

	printf("화씨 온도를 입력하세요 : ");
	scanf("%lf", &tempF);

	return tempF;
}

int output(double tempF)
{
	double tempC;

	tempC = (5.0 / 9.0)*(tempF - 32);
	printf("섭씨 온도는 %.1lf 도입니다.", tempC);

	return 0;
}