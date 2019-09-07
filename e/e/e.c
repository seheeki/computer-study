#include <stdio.h>

// 이진 탐색 알고리즘 반복문 구현
// 찾는 숫자가 있으면 찾는 숫자의 인덱스 리턴 없으면 -1 리턴

/*int BSearch(char ar[], int len, char target)
{
	int first=0;
	int last=len-1;
	int mid=0;

    while(first<=last)
	{
		mid = (first + last) / 2;
		if(ar[mid]==target)
		{
			return mid;
		}
		else
		{
			printf("ar[mid]= %d\n", ar[mid]);
			printf("target = %d\m", target);

			if(ar[mid] > target)
			{
				last = mid -1;
			}
			else
			{
				first = mid +1;
			}
		}
	}
	return -1;
}
*/
// 이진 탐색 알고리즘 재귀 구현

int BSearchRecur(char ar[], int first, int last, char target)
{
	int mid=0;
	
	if(first<=last)
	{
		mid = (first + last) / 2;
		if(ar[mid]==target)
		{
			return mid;
		}
		else
		{
			if(ar[mid]>target)
			{
				last = mid -1;
				return BSearchRecur(ar, first, last, target);
			}
			else
			{
				first = mid +1;
				return BSearchRecur(ar, first, last, target);
			}
		}
	}
	else if(first>last)
	{
		return -1;
	}
	
	
}


int main(int arc, char** argv)
{
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
    int idx = 0;
	char inputAlphabet = 0;
 
    scanf_s("%c", &inputAlphabet);
 
//	printf("sizeof(int) = %d\n", sizeof(int));
//	printf("sizeof(char) = %d\n", sizeof(char));

/*    idx = BSearch(arr, sizeof(arr) / sizeof(char), inputAlphabet);
    if (idx == -1)
	{
        printf("Fail\n");
    }
    else
	{
        printf("Target Index : %d\n", idx);
    }
	
*/ 
	//printf("a의 값 : %d\n", 'a');
//	printf("b의 값: %d\n", 'b');

    idx = BSearchRecur(arr, 0, sizeof(arr) / sizeof(char) - 1, inputAlphabet);
    if (idx == -1)
	{
        printf("Fail\n");
    }
    else
	{
        printf("Target Index : %d\n", idx);
    }
	
}
