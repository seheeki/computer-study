#pragma warning(disable:4996)
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int input(void); //�Է� �Լ�
int output(int num, int correct); //��� �Լ�
int random(int n); //���� �߻� �Լ�
void myflush(void); 
int max = 100, min = 0;

int main()
{
	int num;
	int i=0;
	int count = 0, correct = 0;

	srand((unsigned int)time (NULL));
	while (i < 5)
	{
		correct = random(100);
		++i;
	}

	while (1)
	{
		num = input();
		output(num, correct);
		count += 1;
		if (num == correct) { break; }
	}
	if (correct == num)
	{
		printf("���~ �¾Ҵ�~~~ ��ī��ī~~ %d ��° ���� ���߼̽��ϴ�.\n", count);
	}

	return 0;
}

int input() //�Է� �Լ�
{
	int num, res;

	printf("# ���ڸ� �Է��Ͻÿ� : ");
	res = scanf("%d", &num);
	while(res != 1 || (num<1 || num>100))
	{
		myflush();
		printf("# ���ڸ� �Է��Ͻÿ� : ");
		res = scanf("%d", &num);
	}
	
	return num;
}

int output(int num, int correct) //��� �Լ�
{
	if (correct > num)
	{
		min = num;
		printf("%d ���ٴ� ũ�� %d ���ٴ� �۽��ϴ�.\n", min, max);
	}
	else if (correct < num)
	{
		max = num;
		printf("%d ���ٴ� ũ�� %d ���ٴ� �۽��ϴ�.\n", min, max);
	}
	return 0;
}

void myflush()
{
	char ch;
	while ((ch = getchar()) != '\n')
	{
		;
	}
	return;
}
int random(int n) //���� �߻� �Լ�
{
	int res;
	res = rand() % n + 1;
	return res;
}