#include "basic.h"
#include "menu.h"
int selectButton()
{
    int button;
    printf("\n*** 제품 관리 ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 저장\n");
    printf("6. 검색\n");
    printf("7. 추천\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &button);
    return button;
}

int createMenu(Menu *m)
{
    printf("메뉴 이름은? ");
    getchar();
    fgets(m->food, sizeof(m->food), stdin);
    int len = strlen(m->food);
    m->food[--len] = '\0';
    do
    {
        printf("가격은? ");
        scanf("%d", &m->price);
    } while (m->price < 0);
    printf("판매 부스는 (든든한동, fryfry, 따스한동)? ");
    scanf("%s", m->booth);

    return 1;
}

void readMenu(Menu m)
{
    printf("%s %5d원 %s\n", m.food, m.price, m.booth);
}

// void listMenu(Menu *m, int count)
// {
//     printf("\n======== 메뉴판 ========\n");
//     for (int i = 0; i < count; i++)
//     {
//         if (m[i].price == -1)
//             continue;
//         printf("%2d ", i + 1);
//         readMenu(m[i]);
//     }
//     printf("\n");
// }

int selectDataNum(Menu *m, int count)
{
    int selec;
    listMenu(m, count);
    printf("번호는(취소: 0)? ");
    scanf("%d", &selec);

    return selec;
}

int updateMenu(Menu *m)
{
    printf("새로운 메뉴의 이름은? ");
    getchar();
    fgets(m->food, sizeof(m->food), stdin);
    int len = strlen(m->food);
    m->food[--len] = '\0';
    do
    {
        printf("새로운 메뉴의 가격은? ");
        scanf("%d", &m->price);
    } while (m->price < 0);
    printf("새로운 메뉴의 판매 부스는? ");
    scanf("%s", m->booth);

    return 1;
}

int deleteMenu(Menu *m)
{
    m->price = -1;
    printf("=> 삭제됨!\n");
    return 0;
}

int loadData(Menu *m)
{
    int count = 0;
    FILE *fp;

    fp = fopen("Product.txt", "rt");
    if (fp == NULL)
        printf("=> 파일 없음\n");
    else
    {
        for (; count < 100; count++)
        {
            fgets(m[count].food, 40, fp);
            m[count].food[strlen(m[count].food)-1] = '\0';
            if (feof(fp))
                break;
            fscanf(fp, "%d\n", &m[count].price);
            fgets(m[count].booth, 30, fp);
            m[count].booth[strlen(m[count].booth)-1] = '\0';
        }
        fclose(fp);
        printf("=> 로딩 성공!\n");
        printf("%d개의 데이터를 찾았습니다!\n", count);
    }
    return count;
}

void saveData(Menu *m, int count)
{
    FILE *fp;
    fp = fopen("Product.txt", "wt");
    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "%s\n%d\n%s\n", m[i].food, m[i].price, m[i].booth);
    }
    fclose(fp);
}

