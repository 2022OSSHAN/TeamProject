#include "basic.h"
#include "menu.h"

#define ALL 1
#define PRICE 2
#define BOOTH 3

void listMenu(Menu *m, int count)
{
    int button = 0;
    
    button = showMenu();
    showAllMenu(m,button,count);
    showPriceMenu(m,button,count);
    showBoothMenu(m,button,count);

}

int showMenu()
{
    int button;
    printf("\n*** 메뉴 조회 방식 ***\n");
    printf("1. 전체 조회\n");
    printf("2. 가격대별 조회\n");
    printf("3. 부스별 조회\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &button);
    return button;
}

void showAllMenu(Menu *m,int button,int count)
{
    if(button == ALL)
    {
    printf("\n======== 전체 메뉴판 ========\n");
    for (int i = 0; i < count; i++)
    {
        if (m[i].price == -1)
            continue;
        printf("%2d ", i + 1);
        readMenu(m[i]);
    }
    printf("\n");
    }
}

void showPriceMenu(Menu *m, int button, int count)
{
    if(button == PRICE)
    {
        int price;
        printf("가격대를 입력하세요 (든든한동, fryfry, 따스한동) ");
        scanf("%d",&price);
        printf("\n======== 가격대별 메뉴판 ========\n");
        for (int i = 0; i < count; i++)
        {   
            if(price==3000)
            if(m[i].price >= 3000 && m[i].price<4000)
            {
                if (m[i].price == -1)
                    continue;
                printf("%2d ", i + 1);
                readMenu(m[i]);
            }
            
            if(price==4000)
            if(m[i].price >= 4000 && m[i].price<5000)
            {
                if (m[i].price == -1)
                    continue;
                printf("%2d ", i + 1);
                readMenu(m[i]);
            }

            if(price == 5000)
            if(m[i].price >= 5000)
            {
                if (m[i].price == -1)
                    continue;
                printf("%2d ", i + 1);
                readMenu(m[i]);
            }
        }
        printf("\n");
    }
}

void showBoothMenu(Menu *m,int button,int count)
{
    if(button == BOOTH)
    {
        char booth[40];
        printf("부스를 입력하세요 (3000,4000,5000)");
        scanf("%s",booth);
        printf("\n======== 부스별 메뉴판 ========\n");
        for (int i = 0; i < count; i++)
        {
            if (m[i].price == -1)
                continue;
            if (strstr(m[i].booth, booth))
            {
                printf("%2d ", i + 1);
                readMenu(m[i]);
            }
        }
        printf("\n");
    }
}
