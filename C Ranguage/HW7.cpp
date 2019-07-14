//주행시간 계산
#include<stdio.h>
double inputD(void); //거리 입력함수
double inputV(void); // 시속 입력함수
int output(double distance, int hour, int minute, double second); //출력 함수

int main()
{
	double distance, velocity, second;
	int hour, minute;

	distance = inputD();
	velocity = inputV();

	hour = (int)distance / velocity;
	minute = (int)((distance / velocity - hour)*60);
	second = ((distance / velocity - hour) * 60 - minute) * 60;

	output(distance, hour, minute, second);

	return 0;
}

double inputD()
{
	double distance;

	printf("거리를 입력하시오(km단위) : ");
	scanf("%lf", &distance);

	return distance;
}

double inputV()
{
	double velocity;

	printf("시속을 입력하시오(km/h단위) : ");
	scanf("%lf", &velocity);

	return velocity;
}

int output(double distance, int hour, int minute, double second)
{
	printf("%.2lf km = > %d시간 %d분 %.3lf 초 소요됨\n", distance, hour, minute, second);

	return 0;
}
