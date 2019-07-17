#include<stdio.h>
char menu(void); //메뉴함수
int inputInt(const char *msg); //문자열 출력, 정수 리턴
int deposit(int *total); //입금처리
int withdraw(int *total); //출금처리
void myflush(void);

int main()
{
	int total = 0;
	//int num;
	char select;

	printf("* 현재 잔액은 %d원 입니다.\n", total);

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
		printf("\n메뉴를 선택하시오(i-입금, o-출금, q-종료) : ");
		scanf(" %c", &select);
		if (select == 'i' || select == 'o' || select == 'q') { break; }
		else {
			myflush();
			printf("* 잘못 입력하셨습니다.\n");
		}
	}
	return select;
}
int deposit(int *total)
{
	int money;
	money = inputInt("# 입금액을 입력하세요 : ");
	while(money<0)
	{
		money = inputInt("* 잘못 입력하셨습니다. 다시 입력하십시오 : ");
	}
	*total += money;
	printf("* 현재 잔액은 %d원 입니다.\n", *total);

	return 0;
}
int withdraw(int *total) 
{
	int money; 
	money = inputInt("# 출금액을 입력하세요 : ");
	while (money<0)
	{
		money = inputInt("* 잘못 입력하셨습니다. 다시 입력하십시오 : ");
	}
	if (*total < money)
	{
		printf("* 잔액이 부족합니다.\n");
		printf("* 현재 잔액은 %d원 입니다.\n", *total);
	}
	else
	{
		*total -= money;
		printf("* 현재 잔액은 %d원 입니다.\n", *total);
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