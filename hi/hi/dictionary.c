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

int translate_memory(char *word)
{
	struct dic st_dic;
    int init_value = 4;
	FILE *fp;
	char ch;
	int count = 0;
	char *p_start = 0;
	char *p_end = 0;
	int b_find = 0;
	int result = 0;
	int file_size = 0;
	char *p_all_words = NULL;
	char *p_current = NULL;

	fp = fopen("dictionary.dat", "r");
	file_size = get_file_size(fp);
//	printf("file size = %d\n", file_size);

	p_all_words = (char *)malloc(sizeof(char) * (file_size+1));
	memset(p_all_words, 0, (file_size+1)*sizeof(char));
	fseek(fp, 0, SEEK_SET);
	fread(p_all_words, file_size, 1, fp);
	fclose(fp);
//	printf("all words : %s\n", p_all_words);

	st_dic.hanguel = (char *)malloc(sizeof(char) * init_value);
	st_dic.english = (char *)malloc(sizeof(char) * init_value);

	memset(st_dic.hanguel, 0, init_value*sizeof(char));
	memset(st_dic.english, 0, init_value*sizeof(char));
	
	//�޸��� ��ó�� ��ġ�� ��´�.
	p_current = p_all_words;
    p_start = p_current;
//	printf("p_start : %p\n", p_start);
	
	//�޸𸮸� 1����Ʈ�� �д´�. �޸� �����ʹ� 1����Ʈ�� ������Ų��.
	while ( (ch = *p_current) != 0)
	{	
		//���� ����Ʈ ũ�⸦ �ϳ� �����Ѵ�.
		p_current++;
		count++;
		//,�� \n�� ������ �ܾ� �б⸦ �õ��Ѵ�.
		if( ch == ',' || ch == '\n')
		{
			
			//�ܾ��� ���� �޸� ������ ��ġ�� ��´�.
			p_end = p_current; 
			//�ܾ� �����ڱ��� ���� ���ڿ����� �ܾ� �����ڸ� �� ũ�⸦ ���Ѵ�.
			count = count - 1;
//			printf("\n count = %d byte \n", count);
			//�ܾ ���۵Ǵ� ���� ��ġ�� �޸� �����͸� �̵��Ѵ�.
			p_current = p_start;

			//�ѱ� �ܾ��� ���
			if( ch == ',')
			{
				//�޸� ũ�⸦ �����Ͽ� �ٽ� �޸𸮸� �Ҵ��Ѵ�. count+1�� NULL�� ���� ��.
				st_dic.hanguel = (char *)realloc(st_dic.hanguel, sizeof(char) * (count+1));
				//�޸𸮸� �ʱ�ȭ�Ѵ�.
				memset(st_dic.hanguel, 0, (count+1)*sizeof(char));
//				printf("st_dic.hanguel: %s\n", st_dic.hanguel);
				//�޸� �������� ���� ��ġ�������� countũ�⸸ŭ ���ڿ��� �ѱ� �޸𸮿� �����Ѵ�.
				memcpy( st_dic.hanguel, p_current, count*sizeof(char)); 
//				printf("count : %d, ch: %c, st_dic.hanguel: %s\n", count, ch, st_dic.hanguel);
			}
			else
			{
				st_dic.english = (char *)realloc(st_dic.english, sizeof(char) * (count+1));
				memset(st_dic.english, 0, (count+1)*sizeof(char));
				memcpy( st_dic.english, p_current, count*sizeof(char)); 
//				printf("st_dic.english: %s\n", st_dic.english);
			}

			//������ �ܾ� ����Ʈ ��ŭ �޸� �����͸� �����Ѵ�.
			p_current += count*sizeof(char);
			//������ 1����Ʈ��ŭ �޸� �����͸� 1����Ʈ �����Ѵ� 
			p_current++;

			//�ܾ� ũ������ ������ count�� �ʱ�ȭ�Ѵ�.
			count = 0;
			//�޸��������� �ܾ� �������� �����Ѵ�.
			p_start = p_current;
			
		}


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

	free(st_dic.english);
	free(st_dic.hanguel);
	printf("���� ��\n");

	return result;
}


int get_file_size(FILE *fp)
{
	int size;

	fseek(fp, 0, SEEK_END);
	size = ftell(fp);

	return size;
}