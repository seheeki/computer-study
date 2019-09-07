#include<stdio.h>
int main()
{
	int sec = 54321;
	int hour, minute, second;

	hour = sec / 3600;
	
	minute = (sec % 3600) / 60;
	
	second = ((sec % 3600) % 60 ) % 60;

	printf("%d초는 %d시간 %d분 %d초입니다.", sec, hour, minute, second);
	getchar();
	return 0;
}