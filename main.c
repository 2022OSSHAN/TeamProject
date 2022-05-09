#include <stdio.h>
#include <string.h>
#include "basic.h"


int main(void){
    
    Menu slist[100];
    int curcount=0;
    int count = 0, menu;
    
    count = loadData(slist);
    curcount=count; 

    while (1){
        menu = selectMenu();
        getchar();
        if(menu == EXIT) break;
        if(menu == CHECK || menu ==MODIFY || menu == DELETE){	
		    if (count==0){ 
                printf(" 데이터가 없습니다!\n");
			    continue;
			}
		}

        if(menu == CHECK) listMenu(slist,curcount); 
        else if (menu == ADD) {
            count+=createMenu(&slist[curcount++]); 
        }
        else if (menu == MODIFY) {
            int no=selectDataNo(slist, curcount);
            if(no==0){
                printf("=>취소됨!");
                continue;
            }
            updateMenu(&slist[no-1]);
        }
        else if (menu == DELETE) {
            int no=selectDataNo(slist, curcount);
            if(no==0){
                printf("=>취소됨!");
                continue;
            }
            int deleteok;
            printf("정말로 삭제하시겠습니까?(삭제:1)");
            scanf("%d",&deleteok);
            if(deleteok == 1){
                if(deleteMenu(&slist[no-1])) count --;       
           	 } 
        }
	    else if (menu == 5){
		    if (count==0) printf("데이터가 없습니다!\n");
		    else saveData(slist,curcount);
	    }
	}

	printf("\n종료됨!\n");
   	return 0;
}