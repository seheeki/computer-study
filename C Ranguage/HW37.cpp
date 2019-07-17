#include<stdio.h>
//메인 함수 하나로 처리

int main()
{
	int j, k=1;
	int num;

	for (j = 0; j <= 90; j += 10)
	{
		for (k = 1; k < 11; k++)
		{
			num = k+j;
			
			if (num % 3 == 0 || num % 5 == 0) {
				if (num % 3 == 0 && num % 5 == 0) { printf("%3d", num); }
				else if (num % 3 == 0) { printf("  *"); }
				else { printf("  #"); }
			}
			else { printf("%3d", num); }
		}
		printf("\n");
	}
	return 0;
}