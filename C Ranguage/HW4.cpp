//1���� �� , ��, ��, �ʷ� ȯ���ϴ� ���α׷�
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

	printf("%.4lf���� %d�� %d�ð� %d�� %.2lf���Դϴ�.", day, days, hours, minutes, seconds);
	return 0;
}