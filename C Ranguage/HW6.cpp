//�µ� ��ȭ�ϱ�
#include<stdio.h>
double input(void); //�Է��Լ�
int output(double tempF); //����Լ�

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

	printf("ȭ�� �µ��� �Է��ϼ��� : ");
	scanf("%lf", &tempF);

	return tempF;
}

int output(double tempF)
{
	double tempC;

	tempC = (5.0 / 9.0)*(tempF - 32);
	printf("���� �µ��� %.1lf ���Դϴ�.", tempC);

	return 0;
}