//����ð� ���
#include<stdio.h>
double inputD(void); //�Ÿ� �Է��Լ�
double inputV(void); // �ü� �Է��Լ�
int output(double distance, int hour, int minute, double second); //��� �Լ�

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

	printf("�Ÿ��� �Է��Ͻÿ�(km����) : ");
	scanf("%lf", &distance);

	return distance;
}

double inputV()
{
	double velocity;

	printf("�ü��� �Է��Ͻÿ�(km/h����) : ");
	scanf("%lf", &velocity);

	return velocity;
}

int output(double distance, int hour, int minute, double second)
{
	printf("%.2lf km = > %d�ð� %d�� %.3lf �� �ҿ��\n", distance, hour, minute, second);

	return 0;
}
