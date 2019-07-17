#include<stdio.h>
char menu(void); //�޴��Լ�
int inputInt(const char *msg); //���ڿ� ���, ���� ����
int deposit(int *total); //�Ա�ó��
int withdraw(int *total); //���ó��
void myflush(void);

int main()
{
	int total = 0;
	//int num;
	char select;

	printf("* ���� �ܾ��� %d�� �Դϴ�.\n", total);

	while (1)
	{
		select = menu();
		if (select == 'i') {deposit(&total);}
		else if (select == 'o') { withdraw(&total);}
		else { break; }
	}
	return 0;
}

char menu()
{
	char select;
	while (1)
	{
		printf("\n�޴��� �����Ͻÿ�(i-�Ա�, o-���, q-����) : ");
		scanf(" %c", &select);
		if (select == 'i' || select == 'o' || select == 'q') { break; }
		else {
			myflush();
			printf("* �߸� �Է��ϼ̽��ϴ�.\n");
		}
	}
	return select;
}
int deposit(int *total)
{
	int money;
	money = inputInt("# �Աݾ��� �Է��ϼ��� : ");
	while(money<0)
	{
		money = inputInt("* �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��Ͻʽÿ� : ");
	}
	*total += money;
	printf("* ���� �ܾ��� %d�� �Դϴ�.\n", *total);

	return 0;
}
int withdraw(int *total) 
{
	int money; 
	money = inputInt("# ��ݾ��� �Է��ϼ��� : ");
	while (money<0)
	{
		money = inputInt("* �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��Ͻʽÿ� : ");
	}
	if (*total < money)
	{
		printf("* �ܾ��� �����մϴ�.\n");
		printf("* ���� �ܾ��� %d�� �Դϴ�.\n", *total);
	}
	else
	{
		*total -= money;
		printf("* ���� �ܾ��� %d�� �Դϴ�.\n", *total);
	}
	return 0;
}
int inputInt(const char *msg)
{
	int num, res;

	while (1)
	{
		printf("%s", msg);
		res = scanf("%d", &num);
		if (res == 1) { break; }
		else{myflush();}
	}
	return num;
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