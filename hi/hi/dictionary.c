#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "dictionary.h"



int make_dictionary(void)
{
	FILE *fp;
	fp = fopen("dictionary.dat", "w");

	fputs("��,dog\n�����,cat\nȿ���ʵ��б�,Hyojachodeonghakkyo\n", fp);

	fclose(fp);
	return 0;
}

int translate(char *word)
{
	struct dic st_dic;
    int init_value = 4;
	FILE *fp;
	char ch;
	int count = 0;
	fpos_t start_fp = 0;
	fpos_t end_fp = 0;
	int b_find = 0;
	int result = 0;

	fp = fopen("dictionary.dat", "r");
	st_dic.hanguel = (char *)malloc(sizeof(char) * init_value);
	st_dic.english = (char *)malloc(sizeof(char) * init_value);

	memset(st_dic.hanguel, 0, init_value*sizeof(char));
	memset(st_dic.english, 0, init_value*sizeof(char));
	
	// ������ ��ó�� ��ġ�� ��´�.
    fgetpos(fp, &start_fp);
	//������ 1����Ʈ�� �д´�. ���� �����ʹ� 1����Ʈ�� �����Ѵ�.
	while ( (ch = fgetc(fp)) != EOF)
	{
		//���� ����Ʈ ũ�⸦ �ϳ� �����Ѵ�.
		count++;
		//,�� \n�� ������ �ܾ� �б⸦ �õ��Ѵ�.
		if( ch == ',' || ch == '\n')
		{
			//�ܾ��� ���� ���� ��ġ�� ��´�.
			fgetpos(fp, &end_fp); 
			//�ܾ� �����ڱ��� ���� ���ڿ����� �ܾ� �����ڸ� �� ũ�⸦ ���Ѵ�.
			count = count - 1;
//			printf("\n count = %d byte \n", count);
			//�ܾ ���۵Ǵ� ���� ��ġ�� ���� �����͸� �̵��Ѵ�.
			fseek(fp, start_fp, SEEK_SET);

			//�ѱ� �ܾ��� ���
			if( ch == ',')
			{
				//�޸� ũ�⸦ �����Ͽ� �ٽ� �޸𸮸� �Ҵ��Ѵ�. count+1�� NULL�� ���� ��.
				st_dic.hanguel = (char *)realloc(st_dic.hanguel, sizeof(char) * (count+1));
				//�޸𸮸� �ʱ�ȭ�Ѵ�.
				memset(st_dic.hanguel, 0, (count+1)*sizeof(char));
				//������������ ���� ��ġ�������� countũ�⸸ŭ ���ڿ��� �ѱ� �޸𸮿� �����Ѵ�.
				fgets (st_dic.hanguel, count+1, fp);
			}
			else
			{
				st_dic.english = (char *)realloc(st_dic.english, sizeof(char) * (count+1));
				memset(st_dic.english, 0, (count+1)*sizeof(char));
				fgets (st_dic.english, count+1, fp);
			}

			//������ 1����Ʈ�� �о ���� �����͸� 1����Ʈ �����Ѵ� 
			ch = fgetc(fp);
/*
			if( ch == ',')
			{
				printf("�ѱ� : %s\n", st_dic.hanguel);
			}
			else
			{
				printf("���� : %s\n", st_dic.english);
			}
*/
			//�ܾ� ũ������ ������ count�� �ʱ�ȭ�Ѵ�.
			count = 0;
			//������������ �ܾ� �������� �����Ѵ�.
			fgetpos(fp, &start_fp);
		}
/*		else
		{
		    printf("%c", ch);
		}
*/

		//�ܾ� �����ڰ� ���๮���� ��� ����ܾ��̴�. �ѱ۰� ��� ��� ���� �����̴�.
		if(ch == '\n')
		{
			//�Էµ� �ѱ۴ܾ�� ����� �ѱ۴ܾ ���Ѵ�.
			if(strncmp(st_dic.hanguel, word, strlen(word)) == 0)
			{
				printf("%s,%s\n", st_dic.hanguel, st_dic.english);
				//�ܾ ��ġ�� ��� b_find�� 1�� �����Ѵ�.			
				b_find = 1;
				break;
			}
		}
	} 
	//while�� ������ �����Ͽ� �ܾ �� ã�� ��� ȭ�鿡 ǥ���Ѵ�.
	if(b_find == 0)
	{
		printf("can not found %s \n", word);
		result = -1;
	} 

	fclose(fp);
	free(st_dic.english);
	free(st_dic.hanguel);
	printf("���� ��\n");

	return result;
}