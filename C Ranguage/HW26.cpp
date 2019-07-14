//가위바위보
#pragma warning(disable:4996)
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int random(int n); // 난수 발생 함수
int input(void); // 입력 함수
int output(int user, int computer); // 출력 함수

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

		printf("게임 결과 : %d 승 %d 무\n", win, lose);
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

	printf(" # 바위는 1, 가위는 2, 보는 3 중에서 선택하세요 : ");
	scanf("%d", &user);
	return user;
}

int output(int user, int computer)
{
	int result;

	if (user == 1){
		if (computer == 1) {
			printf("   당신은 바위 선택, 컴퓨터는 바위 선택 : 비겼습니다.\n");
		}
		else if (computer ==2){
			printf("   당신은 바위 선택, 컴퓨터는 가위 선택 : 이겼습니다.\n");
			win += 1;
		}
		else {
			printf("   당신은 바위 선택, 컴퓨터는 보 선택 : 졌습니다.\n");
			lose += 1;
		}
	}
	else if (user == 2)
	{
		if (computer == 1) {
			printf("   당신은 가위 선택, 컴퓨터는 바위 선택 : 졌습니다.\n");
			lose += 1;
		}
		else if (computer == 2) {
			printf("   당신은 가위 선택, 컴퓨터는 가위 선택 : 비겼습니다.\n");
		}
		else {
			printf("   당신은 가위 선택, 컴퓨터는 보 선택 : 이겼습니다.\n");
			win += 1;
		}
	}
	else
	{
		if (computer == 1) {
			printf("당신은 보 선택, 컴퓨터는 바위 선택 : 이겼습니다.\n");
			win += 1;
		}
		else if (computer == 2) {
			printf("당신은 보 선택, 컴퓨터는 가위 선택 : 졌습니다.\n");
			lose += 1;
		}
		else {
			printf("당신은 보 선택, 컴퓨터는 보 선택 : 비겼습니다.\n");
		}
	}
	return 0;
}