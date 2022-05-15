#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void listMenu(Menu *m, int count); // 전체 등록된 메뉴의 리스트 출력
int showMenu();
void showAllMenu(Menu *m,int button,int count);
void showPriceMenu(Menu *m,int button,int count);
void showBoothMenu(Menu *m,int button,int count);