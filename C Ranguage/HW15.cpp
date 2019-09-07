#include<stdio.h>
double inputWeight(void);
double inputHeight(void);
double calBmi(double weight, double height);

int main()
{
	double BMI;
	double height, weight;

	weight = inputWeight();
	height = inputHeight();
	BMI = calBmi(weight, height);

	if (BMI < 18.5)
	{
		printf("����� BMI�� %.1lf���� ��ü���Դϴ�.", BMI);
	}
	else if (BMI < 25.0)
	{
		printf("����� BMI�� %.1lf���� ����ü���Դϴ�.", BMI);
	}
	else if (BMI < 30.0)
	{
		printf("����� BMI�� %.1lf���� ��ü���Դϴ�.", BMI);
	}
	else
	{
		printf("����� BMI�� %.1lf���� �����Դϴ�.", BMI);
	}
	getchar();
	getchar();
	return 0;
}
double inputWeight()
{
	double weight;

	printf("�����Ը� �Է��ϼ���(kg) : ");
	scanf("%lf", &weight);

	return weight;
}
double inputHeight()
{
	double height;

	printf("Ű�� �Է��ϼ���(m) : ");
	scanf("%lf", &height);

	return height;
}
double calBmi(double weight, double height)
{
	double BMI;
	BMI = weight / (height*height);
	return BMI;
}