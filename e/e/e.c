#include <stdio.h>

// ���� Ž�� �˰��� �ݺ��� ����
// ã�� ���ڰ� ������ ã�� ������ �ε��� ���� ������ -1 ����

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
// ���� Ž�� �˰��� ��� ����

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
	//printf("a�� �� : %d\n", 'a');
//	printf("b�� ��: %d\n", 'b');

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
