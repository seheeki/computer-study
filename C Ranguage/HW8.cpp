#include<stdio.h>

int main()
{
	unsigned int history, letter, art;
	int tot;

	printf("역사, 문학, 예능 점수를 입력하세요 : ");
	scanf("%u %u %u", &history, &letter, &art);
	tot = history + letter + art;
	printf("총점은 %u 이고 평균은 %.2lf 입니다.", tot, tot / 3.0);

	return 0;
}