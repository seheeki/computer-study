#include<stdio.h>
//�迭 �ϳ��� ���
void swap(int *ap, int size);//swap �Լ�

int main()
{
	int ary[] = { 1,2,3,4,5 };
	int size;
	int i;

	size = sizeof(ary) / sizeof(ary[0]);
	printf("ó�� �迭�� ����� �� : ");
	for (i = 0; i < size; i++)
	{
		printf("%3d", ary[i]);
	}
	swap(ary, size);

	printf("\n�ٲ� �迭�� ����� �� : ");
	for (i = 0; i < size; i++)
	{
		printf("%3d", ary[i]);
	}
	printf("\n");
	return 0;
}

void swap(int *ap, int size)
{
	int temp;
	int i, j;

	for (i = 0; i < size / 2; i++)
	{
		temp = ap[i];
		ap[i] = ap[size - 1 - i];
		ap[size - 1 - i] = temp;
	}

	return;
}