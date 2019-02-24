#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "dictionary.h"



int make_dictionary(void)
{
	FILE *fp;
	fp = fopen("dictionary.dat", "w");

	fputs("개,dog\n고양이,cat\n효자초등학교,Hyojachodeonghakkyo\n", fp);

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
	
	// 파일의 맨처음 위치를 얻는다.
    fgetpos(fp, &start_fp);
	//파일을 1바이트씩 읽는다. 파일 포인터는 1바이트씩 증가한다.
	while ( (ch = fgetc(fp)) != EOF)
	{
		//읽은 바이트 크기를 하나 증가한다.
		count++;
		//,나 \n를 만나면 단어 읽기를 시도한다.
		if( ch == ',' || ch == '\n')
		{
			//단어의 끝의 파일 위치를 얻는다.
			fgetpos(fp, &end_fp); 
			//단어 구분자까지 읽은 문자열에서 단어 구분자를 뺀 크기를 구한다.
			count = count - 1;
//			printf("\n count = %d byte \n", count);
			//단어가 시작되는 시작 위치로 파일 포인터를 이동한다.
			fseek(fp, start_fp, SEEK_SET);

			//한글 단어인 경우
			if( ch == ',')
			{
				//메모리 크기를 변경하여 다시 메모리를 할당한다. count+1은 NULL을 위한 것.
				st_dic.hanguel = (char *)realloc(st_dic.hanguel, sizeof(char) * (count+1));
				//메모리를 초기화한다.
				memset(st_dic.hanguel, 0, (count+1)*sizeof(char));
				//파일포인터의 현재 위치에서부터 count크기만큼 문자열을 한글 메모리에 저장한다.
				fgets (st_dic.hanguel, count+1, fp);
			}
			else
			{
				st_dic.english = (char *)realloc(st_dic.english, sizeof(char) * (count+1));
				memset(st_dic.english, 0, (count+1)*sizeof(char));
				fgets (st_dic.english, count+1, fp);
			}

			//구분자 1바이트를 읽어서 파일 포인터를 1바이트 전진한다 
			ch = fgetc(fp);
/*
			if( ch == ',')
			{
				printf("한글 : %s\n", st_dic.hanguel);
			}
			else
			{
				printf("영어 : %s\n", st_dic.english);
			}
*/
			//단어 크기측정 변수인 count를 초기화한다.
			count = 0;
			//파일포인터의 단어 시작점을 저장한다.
			fgetpos(fp, &start_fp);
		}
/*		else
		{
		    printf("%c", ch);
		}
*/

		//단어 구분자가 개행문자일 경우 영어단어이다. 한글과 영어를 모두 읽은 상태이다.
		if(ch == '\n')
		{
			//입력된 한글단어와 저장된 한글단어를 비교한다.
			if(strncmp(st_dic.hanguel, word, strlen(word)) == 0)
			{
				printf("%s,%s\n", st_dic.hanguel, st_dic.english);
				//단어가 일치할 경우 b_find를 1로 저장한다.			
				b_find = 1;
				break;
			}
		}
	} 
	//while문 끝까지 실행하여 단어를 못 찾을 경우 화면에 표시한다.
	if(b_find == 0)
	{
		printf("can not found %s \n", word);
		result = -1;
	} 

	fclose(fp);
	free(st_dic.english);
	free(st_dic.hanguel);
	printf("사전 끝\n");

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
	
	//메모리의 맨처음 위치를 얻는다.
	p_current = p_all_words;
    p_start = p_current;
//	printf("p_start : %p\n", p_start);
	
	//메모리를 1바이트씩 읽는다. 메모리 포인터는 1바이트씩 증가시킨다.
	while ( (ch = *p_current) != 0)
	{	
		//읽은 바이트 크기를 하나 증가한다.
		p_current++;
		count++;
		//,나 \n를 만나면 단어 읽기를 시도한다.
		if( ch == ',' || ch == '\n')
		{
			
			//단어의 끝의 메모리 포인터 위치를 얻는다.
			p_end = p_current; 
			//단어 구분자까지 읽은 문자열에서 단어 구분자를 뺀 크기를 구한다.
			count = count - 1;
//			printf("\n count = %d byte \n", count);
			//단어가 시작되는 시작 위치로 메모리 포인터를 이동한다.
			p_current = p_start;

			//한글 단어인 경우
			if( ch == ',')
			{
				//메모리 크기를 변경하여 다시 메모리를 할당한다. count+1은 NULL을 위한 것.
				st_dic.hanguel = (char *)realloc(st_dic.hanguel, sizeof(char) * (count+1));
				//메모리를 초기화한다.
				memset(st_dic.hanguel, 0, (count+1)*sizeof(char));
//				printf("st_dic.hanguel: %s\n", st_dic.hanguel);
				//메모리 포인터의 현재 위치에서부터 count크기만큼 문자열을 한글 메모리에 저장한다.
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

			//복사한 단어 바이트 만큼 메모리 포인터를 전진한다.
			p_current += count*sizeof(char);
			//구분자 1바이트만큼 메모리 포인터를 1바이트 전진한다 
			p_current++;

			//단어 크기측정 변수인 count를 초기화한다.
			count = 0;
			//메모리포인터의 단어 시작점을 저장한다.
			p_start = p_current;
			
		}


		//단어 구분자가 개행문자일 경우 영어단어이다. 한글과 영어를 모두 읽은 상태이다.
		if(ch == '\n')
		{
			//입력된 한글단어와 저장된 한글단어를 비교한다.
			if(strncmp(st_dic.hanguel, word, strlen(word)) == 0)
			{
				printf("%s,%s\n", st_dic.hanguel, st_dic.english);
				//단어가 일치할 경우 b_find를 1로 저장한다.			
				b_find = 1;
				break;
			}
		} 
	}

	//while문 끝까지 실행하여 단어를 못 찾을 경우 화면에 표시한다.
	if(b_find == 0)
	{
		printf("can not found %s \n", word);
		result = -1;
	} 

	free(st_dic.english);
	free(st_dic.hanguel);
	printf("사전 끝\n");

	return result;
}


int get_file_size(FILE *fp)
{
	int size;

	fseek(fp, 0, SEEK_END);
	size = ftell(fp);

	return size;
}