#include<stdio.h>
int main()
{
	int sec = 54321;
	int hour, minute, second;

	hour = sec / 3600;
	
	minute = (sec % 3600) / 60;
	
	second = ((sec % 3600) % 60 ) % 60;

	printf("%d�ʴ� %d�ð� %d�� %d���Դϴ�.", sec, hour, minute, second);
	getchar();
	return 0;
}