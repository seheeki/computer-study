#pragma warning(disable:4996)
#include<stdio.h>
int menu(void); //메뉴 함수
int openFan(unsigned char *open); //환풍구 열기 함수
int offFan(unsigned char *close); //환풍구 닫기 함수
int reverseFan(unsigned char *rp); // 환풍구 온오프 함수를 역으로 바꾸는 함수*/
int displayFan(unsigned char *dp); // 팬의 상태 출력
void myflush(void);

int main()
{
	int menuN;
	unsigned char fan = 0;
	
	while (1)
	{
		menuN = menu();
		if (menuN == 1) { 
			openFan(&fan);
			displayFan(&fan);
		}
		else if (menuN == 2)
		{
			offFan(&fan);
			displayFan(&fan);
		}
		else if (menuN == 3)
		{
			reverseFan(&fan);
			displayFan(&fan);
		}
		else
		{
			break;
		}
	}
	return 0;
}

int menu()
{
	int list;
	while (1)
	{
		printf("1. 환풍구 열기 / 2. 환풍구 닫기 / 3. 환풍구 전체 전환 / 4. 종료 : ");
		scanf("%d", &list);
		printf("-----------------------------------------------------------\n");
		if (list != 1 && list != 2 && list != 3 && list != 4)
		{
			myflush();
		}
		else
		{
			break;
		}
	}
	return list;
}
int openFan(unsigned char *open)
{
	int on;
	int res;
	unsigned char digit = 0;
	char msg[31] = "Fan 열기 작업 실행 화면";
	while (1)
	{
		printf("%43s\n", msg);
		printf("-----------------------------------------------------------\n");
		printf(" * OPEN할 FAN 번호를 입력하시오(1~8) : ");
		res = scanf("%d", &on);
		printf("-----------------------------------------------------------\n");
		if (res != 1 || on<1 || on>8)
		{
			myflush();
		}
		else
		{
			digit = (digit >> (on - 1) ^ 1 << (on - 1));
			*open = digit|(*open);
			break;
		}
	}
	return 0;
}
int offFan(unsigned char *close)
{
	int off;
	int res;
	unsigned char digit = 1;
	char msg[30] = "FAN 닫기 작업 실행 화면";

	while (1)
	{
		printf("%43s\n", msg);
		printf("-----------------------------------------------------------\n");
		printf(" * CLOSE할 FAN 번호를 입력하시오(1~8) : ");
		res = scanf("%d", &off);
		printf("-----------------------------------------------------------\n");

		if (res != 1 || off < 1 || off>8)
		{
			myflush();
		}
		else
		{
			digit = ~(digit << (off - 1));
			*close = digit &(*close);
			break;
		}
	}
	return 0;
}
int reverseFan(unsigned char *rp)
{
	char msg[40] = "FAN 전체 전환 작업 실행 화면";
	char msg1[60] = "전체 FAN의 상태가 전환되었습니다.(ON, OFF 상태 뒤바뀜)";

	printf("%48s\n", msg);
	printf("-----------------------------------------------------------\n");
	printf("%s\n", msg1);
	printf("-----------------------------------------------------------\n");

	*rp = ~(*rp);
	return 0;
}
int displayFan(unsigned char *dp)
{
	int i;
	char *on = "ON", *off = "OFF";

	for(i=8;i>0;i--)
	{ 
		if (i == 8) { printf("%d번FAN", i); }
		else { printf("%3d번FAN", i); }
	}
	printf("\n");
	for (i = 7; i >= 0; i--)
	{
		if ((*dp >> i & 1 )==1)
		{
			printf("%4s\t", on);
		}
		else
		{
			printf("%4s\t", off);
		}
	}
	printf("\n");
	printf("-----------------------------------------------------------\n");

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