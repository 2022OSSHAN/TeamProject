#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CHECK 1
#define ADD 2
#define MODIFY 3
#define DELETE 4
#define SAVE 5
#define SEARCH 6
#define RANDOM 7
#define EXIT 0

typedef struct {
	char food[40]; // 음식 이름
	int price; // 가격
	char booth[30]; // 판매부스
} Menu;

int selectButton(); // 프로그램 기능(버튼) 선택
int createMenu(Menu *m); // 메뉴 추가
void readMenu(Menu m); // 하나의 메뉴를 출력

int selectDataNum(Menu *m, int count); // 수정 또는 삭제하고자 하는 메뉴의 번호를 선택
int updateMenu(Menu *m); // 메뉴 수정
int deleteMenu(Menu *m); // 메뉴 삭제
int loadData(Menu *m); // 파일에 저장된 데이터 불러오기
void saveData(Menu *m, int count); // 입력한 데이터를 파일에 저장
