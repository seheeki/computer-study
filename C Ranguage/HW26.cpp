//����������
#pragma warning(disable:4996)
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int random(int n); // ���� �߻� �Լ�
int input(void); // �Է� �Լ�
int output(int user, int computer); // ��� �Լ�

int win=0, lose=0;
int main()
{
	int user;
	
	while (1)
	{
		int computer;
		int i;
		char res[20];

		srand((unsigned int)time(NULL));
		i = 0;
		while (i < 5)
		{
			computer = random(3);
			++i;
		}

		user = input();
		output(user, computer);
		while (lose < 1)
		{
			srand((unsigned int)time(NULL));
			i = 0;
			while (i < 5)
			{
				computer = random(3);
				++i;
			}
			user = input();
			output(user, computer);
		}

		printf("���� ��� : %d �� %d ��\n", win, lose);
		return 0;
	}
}
int random(int n)
{
	int res;
	res = rand() % n + 1;
	return res;
}
int input()
{
	int user;

	printf(" # ������ 1, ������ 2, ���� 3 �߿��� �����ϼ��� : ");
	scanf("%d", &user);
	return user;
}

int output(int user, int computer)
{
	int result;

	if (user == 1){
		if (computer == 1) {
			printf("   ����� ���� ����, ��ǻ�ʹ� ���� ���� : �����ϴ�.\n");
		}
		else if (computer ==2){
			printf("   ����� ���� ����, ��ǻ�ʹ� ���� ���� : �̰���ϴ�.\n");
			win += 1;
		}
		else {
			printf("   ����� ���� ����, ��ǻ�ʹ� �� ���� : �����ϴ�.\n");
			lose += 1;
		}
	}
	else if (user == 2)
	{
		if (computer == 1) {
			printf("   ����� ���� ����, ��ǻ�ʹ� ���� ���� : �����ϴ�.\n");
			lose += 1;
		}
		else if (computer == 2) {
			printf("   ����� ���� ����, ��ǻ�ʹ� ���� ���� : �����ϴ�.\n");
		}
		else {
			printf("   ����� ���� ����, ��ǻ�ʹ� �� ���� : �̰���ϴ�.\n");
			win += 1;
		}
	}
	else
	{
		if (computer == 1) {
			printf("����� �� ����, ��ǻ�ʹ� ���� ���� : �̰���ϴ�.\n");
			win += 1;
		}
		else if (computer == 2) {
			printf("����� �� ����, ��ǻ�ʹ� ���� ���� : �����ϴ�.\n");
			lose += 1;
		}
		else {
			printf("����� �� ����, ��ǻ�ʹ� �� ���� : �����ϴ�.\n");
		}
	}
	return 0;
}