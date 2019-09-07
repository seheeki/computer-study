//1년을 일 , 시, 분, 초로 환산하는 프로그램
#include<stdio.h>

int main()
{
	double day = 365.2422;
	int days, hours, minutes;
	double seconds;

	days = (int)day;
	hours = (int)((day - days)*24);
	minutes = (int)((((day - days) * 24) - hours)*60);
	seconds = ((((day - days) * 24) - hours) * 60 - minutes)*60;

	printf("%.4lf일은 %d일 %d시간 %d분 %.2lf초입니다.", day, days, hours, minutes, seconds);
	return 0;
}