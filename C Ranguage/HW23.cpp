//�ݺ������� �� ���� ������ �Է� �޾� �� ���� ���� ��� 
// ū������ ���� ���� ����
// ���ڸ� �Է��ϸ� ����
#include<stdio.h>

int main()
{
	while (1)
	{
		int n1, n2, res;

		printf("# �� ���� ������ �Է��ϼ��� : ");
		res = scanf("%d %d", &n1, &n2);

		if(res != 2)
		{
			break;
		}
		else
		{
			if (n1 >= n2)
			{
				printf("%d - %d = %d\n", n1, n2, n1 - n2);
			}
			else
			{
				printf("%d - %d = %d\n", n2, n1, n2 - n1);
			}
		}
	}
	return 0;
}