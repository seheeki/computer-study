#include<stdio.h>
int inputAge(void); // �����Է��Լ�
int inputNum(void); // ����Է��Լ�
int output(int age, int num); //����Լ�

int main()
{
	int age, num;

	age = inputAge();
	num = inputNum();
	output(age, num);

	return 0;
}

int inputAge()
{
	int age;

	printf("���尴�� ���̸� �Է��Ͻÿ� : ");
	scanf("%d", &age);

	return age;
}

int inputNum()
{
	int num;

	printf("���尴�� ���� �Է��Ͻÿ� : ");
	scanf("%d", &num);
	
	getchar();
	return num;
}

int output(int age, int num)
{
	int pay, total;
	int discount = 0;

	if (age < 8)
	{
		pay = 500;
	}
	else if (age < 14)
	{
		pay = 700;
	}
	else if (age < 20)
	{
		pay = 1000;
	}
	else if (age < 56)
	{
		pay = 1500;
	}
	else
	{
		pay = 500;
	}

	total = pay * num;

	if (num >= 5)
	{
		discount = total*0.1;
		total = total*0.9;
	}

	printf("����� => %d��\n", pay*num);
	printf("���αݾ� => %d��\n", discount);
	printf("�����ݾ� => %d��\n", total);

	return 0;
}