#include<stdio.h>

int main()
{
	unsigned int history, letter, art;
	int tot;

	printf("����, ����, ���� ������ �Է��ϼ��� : ");
	scanf("%u %u %u", &history, &letter, &art);
	tot = history + letter + art;
	printf("������ %u �̰� ����� %.2lf �Դϴ�.", tot, tot / 3.0);

	return 0;
}