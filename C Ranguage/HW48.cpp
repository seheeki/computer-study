#pragma warning (disable : 4996)
#include <stdio.h>
//메인함수 내에서 처리
int main()
{
	int ary[] = { 2,8,15,1,8,10,5,19,19,3,5,6,6,2,8,2,12,16,3,8,17,
		12,5,3,14,13,3,2,17,19,16,8,7,12,19,10,13,8,20,
		16,15,4,12,3,14,14,5,2,12,14,9,8,5,3,18,18,20,4 };
	int count[20] = { 0 };
	int i, j;
	int size;

	size = sizeof(ary) / sizeof(ary[0]);
	for (i = 0; i < size; i++)
	{
		count[ary[i]-1] += 1;
	}
	for (j = 0; j < 20; j++)
	{
		printf("%d - %d 개\n", j+1, count[j]);
	}
	return 0;
}