//������ ����ϱ�
#include<stdio.h>

int input(void); // �Է��Լ�
int output(double use); // ����Լ�

int main()
{
	double use, pay, fee, total;
	int basic = 660;

	use = input();
	pay = basic + 88.5*use;
	fee = pay * 0.09;
	total = pay + fee;

	output(total);
	return 0;
}

int input()
{
	double use;

	printf("���� ��뷮�� �Է��ϼ���(kw) : ");
	scanf("%lf", &use);
	return use;
}

int output(double use)
{
	printf("���� ������� %lf �� �Դϴ�.", use);
	return 0;
}