#include<stdio.h>
int change(int value, int result);
int money = 278970;

int main()
{
	
	int m50000, m10000, m5000, m1000, m500, m100, m50, m10;

	m50000 = money / 50000;
	change(50000, m50000);

	m10000 = money / 10000;
	change(10000, m10000);

	m5000 = money / 5000;
	change(5000, m5000);

	m1000 = money / 1000;
	change(1000, m1000);

	m500 = money / 500;
	change(500, m500);

	m100 = money / 100;
	change(100, m100);

	m50 = money / 50;
	change(50, m50);

	m10 = money / 10;
	change(10, m10);

	getchar();
	return 0;
}
int change(int value, int result)
{
	printf("%d¿ø±Ç => %d\n", value, result);
	money = money - result * value;
	return money;
}