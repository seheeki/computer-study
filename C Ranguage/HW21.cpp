//�ټ��� �л�Ű �Է�, ���
#include<stdio.h>

int main()
{
	int i;
	double height, total = 0.0, mean;

	for (i = 1; i < 6; i++)
	{
		printf("%d �� �л��� Ű��? ", i);
		scanf("%lf", &height);
		total += height;
	}

	mean = total / 5;
	printf("�ټ� ���� ��� Ű�� %.1lf �Դϴ�.\n", mean);

	return 0;
}