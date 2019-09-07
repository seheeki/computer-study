#include<stdio.h>
//배열 하나만 사용
void swap(int *ap, int size);//swap 함수

int main()
{
	int ary[] = { 1,2,3,4,5 };
	int size;
	int i;

	size = sizeof(ary) / sizeof(ary[0]);
	printf("처음 배열에 저장된 값 : ");
	for (i = 0; i < size; i++)
	{
		printf("%3d", ary[i]);
	}
	swap(ary, size);

	printf("\n바뀐 배열에 저장된 값 : ");
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