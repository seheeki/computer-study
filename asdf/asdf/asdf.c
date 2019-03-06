#include <stdio.h>

void print_array(int arr[], int NUM)
{
	int k;

	for(k=0;k<NUM;k++)
	{
		printf("%d,", arr[k]);
	}
	printf("\n");
}
int main()
{
	int i;
	int j;
	int arr[] = {1, 9, 7, 3, 5, 2, 4, 10, 6, 8};
	int NUM = 10;

	print_array(arr, NUM);

	for(i=0;i<NUM-1;i++)
	{
		for(j=0;j<NUM-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int t = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = t;
			}
			print_array(arr, NUM);
		}
		print_array(arr, NUM);
	}
	return 0;
}