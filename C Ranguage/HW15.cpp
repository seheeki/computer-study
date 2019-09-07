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
		printf("당신의 BMI는 %.1lf으로 저체중입니다.", BMI);
	}
	else if (BMI < 25.0)
	{
		printf("당신의 BMI는 %.1lf으로 정상체중입니다.", BMI);
	}
	else if (BMI < 30.0)
	{
		printf("당신의 BMI는 %.1lf으로 과체중입니다.", BMI);
	}
	else
	{
		printf("당신의 BMI는 %.1lf으로 고도비만입니다.", BMI);
	}
	getchar();
	getchar();
	return 0;
}
double inputWeight()
{
	double weight;

	printf("몸무게를 입력하세요(kg) : ");
	scanf("%lf", &weight);

	return weight;
}
double inputHeight()
{
	double height;

	printf("키를 입력하세요(m) : ");
	scanf("%lf", &height);

	return height;
}
double calBmi(double weight, double height)
{
	double BMI;
	BMI = weight / (height*height);
	return BMI;
}