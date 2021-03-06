#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "dictionary.h"



int make_dictionary(void)
{
	FILE *fp;
	fp = fopen("dictionary.dat", "w");

	fputs("개/dog; 동물 갯과의 포유류. 가축으로 사람을 잘 따르고 영리하다. 일반적으로 늑대 따위와 비슷하게 생겼으며 날카로운 이빨이 있다. 냄새를 잘 맡으며 귀가 밝아 사냥이나 군용, 맹인 선도와 마약 및 폭약 탐지에 쓰인다. 전 세계에 걸쳐 모양, 크기, 색깔이 다양한 300여 품종이 있다.\n고양이/cat; 동물  고양잇과의 하나. 원래 아프리카의 리비아살쾡이를 길들인 것으로, 턱과 송곳니가 특히 발달해서 육식을 주로 한다. 발톱은 자유롭게 감추거나 드러낼 수 있으며, 눈은 어두운 곳에서도 잘 볼 수 있다. 애완동물로도 육종하여 여러 품종이 있다.\n효자초등학교/Hyojachodeonghakkyo; 성복동에 위치하는 초등학교\n", fp);

	fclose(fp);
	return 0;
}

/*int translate(char *word)
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

			if( ch == ',')
			{
				printf("한글 : %s\n", st_dic.hanguel);
			}
			else
			{
				printf("영어 : %s\n", st_dic.english);
			}

			//단어 크기측정 변수인 count를 초기화한다.
			count = 0;
			//파일포인터의 단어 시작점을 저장한다.
			fgetpos(fp, &start_fp);
		}
		else
		{
		    printf("%c", ch);
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

	fclose(fp);
	free(st_dic.english);
	free(st_dic.hanguel);
	printf("사전 끝\n");

	return result;
} */

int translate_memory(char *word)
{
	struct dic st_dic;  //dic 구조체
    int init_value = 4; // 초기 alloc 에 4바이트 할당할때 사용함 나중에 realloc으로 동적으로 할당됨 
	FILE *fp; // 사전 파일포인터
	char ch; // ch 변수 사전 메모리에서 한글자씩 읽어올때 사용
	int count = 0; // 단어수 세기
	char *p_start = 0; // 단어의 시작 포인터
	char *p_end = 0; // 단어의 마지막 포인터
	int b_find = 0; // 단어를 찾았는지에 대한 플래그
	int result = 0; // 결과 0은 못찾은거
	int file_size = 0; // 파일크기
	char *p_all_words = NULL; //모든 단어
	char *p_current = NULL; //메모리의 현채 위치 포인터
	char sep_hanguel = '/';
	char sep_english = ';';
	char sep_meaning = '\n';

	fp = fopen("dictionary.dat", "r"); // 사전파일 읽는다.
	file_size = get_file_size(fp); // 파일크기를 얻는다.
//	printf("file size = %d\n", file_size);

	p_all_words = (char *)malloc(sizeof(char) * (file_size+1)); // p_all_words에 파일 사이즈만큼 메모리를 할당한다.
	memset(p_all_words, 0, (file_size+1)*sizeof(char)); // p_all_words 메모리에 0을 채운다.
	fseek(fp, 0, SEEK_SET); // 파일 포인터를 처음으로 지정한다. 
	fread(p_all_words, file_size, 1, fp); // fp에서 file_size만큼 읽어서 p_all_words메모리에 저장한다.
	fclose(fp); //파일닫음
//	printf("all words : %s\n", p_all_words);

	st_dic.hanguel = (char *)malloc(sizeof(char) * init_value); //초기메모리할당
	st_dic.english = (char *)malloc(sizeof(char) * init_value);
	st_dic.meaning = (char *)malloc(sizeof(char) * init_value);

	memset(st_dic.hanguel, 0, init_value*sizeof(char)); //init_value*sizeof(char)를 0으로 채운다.
	memset(st_dic.english, 0, init_value*sizeof(char));
	
	
	p_current = p_all_words; //메모리의 현재 위치를 얻는다.
    p_start = p_current; //메모리의 맨처음 위치를 얻는다.
//	printf("p_start : %p\n", p_start);
	
	//메모리를 1바이트씩 읽는다. 메모리 포인터는 1바이트씩 증가시킨다.
	while ( (ch = *p_current) != 0)
	{	
		//읽은 바이트 크기를 하나 증가한다.
		p_current++; // 포인터의 위치 증가
		count++; // 단어의 증가
		// /, ;, \n를 만나면 단어 읽기를 시도한다.
		if( ch == sep_hanguel || ch == sep_english  || ch == sep_meaning)
		{
			
			//단어의 끝의 메모리 포인터 위치를 얻는다.
			p_end = p_current; 
			//단어 구분자까지 읽은 문자열에서 단어 구분자를 뺀 크기를 구한다.
			count = count - 1;
//			printf("\n count = %d byte \n", count);
			//단어가 시작되는 시작 위치로 메모리 포인터를 이동한다.
			p_current = p_start;

			//한글 단어인 경우
			if( ch == sep_hanguel)
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
			else if(ch == sep_english)
			{
				st_dic.english = (char *)realloc(st_dic.english, sizeof(char) * (count+1));
				memset(st_dic.english, 0, (count+1)*sizeof(char));
				memcpy( st_dic.english, p_current, count*sizeof(char)); 
//				printf("st_dic.english: %s\n", st_dic.english);
			}
			else if(ch == sep_meaning)
			{
				st_dic.meaning = (char *)realloc(st_dic.meaning, sizeof(char) * (count+1));
				memset(st_dic.meaning, 0, (count+1)*sizeof(char));
				memcpy( st_dic.meaning, p_current, count*sizeof(char)); 
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
		if(ch == sep_meaning)
		{
			//입력된 한글단어와 저장된 한글단어를 비교한다.
			if(strncmp(st_dic.hanguel, word, strlen(word)) == 0)
			{
				printf("%s,%s;%s\n", st_dic.hanguel, st_dic.english, st_dic.meaning);
				//단어가 일치할 경우 b_find를 1로 저장한다.			
				b_find = 1;
				break;
			}
			else if(strncmp(st_dic.english, word, strlen(word)) == 0)
			{
				printf("%s,%s;%s\n", st_dic.english, st_dic.hanguel, st_dic.meaning);
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
	free(st_dic.meaning);
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

