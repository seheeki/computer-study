#include<stdio.h>
int printAge(int age);
int printHeight(double height);

int main()
{
	char name[20] = "�輼��";
	int age = 500;
	double height = 170.8;

	printf("���� : %s\n", name);
	printAge(age);
	printHeight(height);
	getchar();
	return 0;
}

int printAge(int age)
{
	printf("���� : %d\n", age);
	return 0;
}

int printHeight(double height)
{
	printf("Ű : %lf\n", height);
	return 0;
}