#include <stdio.h>
#include <string.h>

int print_title_screen()
{
	const int width = 30;
    const int height = 10;
    const char* menuLines[6] = {
        "         Dino RUN          ",
        "           V.0.1           ",
        "                           ",
        "  1. Start Game            ",
        "  2. How to Play           ",
        "  3. Exit                  "
    };

    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {
            if (h == 0 || h == height - 1 || w == 0 || w == width - 1) {
                printf("#");
            } else if (h >= (height - 6) / 2 && h < (height - 6) / 2 + 6 &&
                       w >= (width - strlen(menuLines[0])) / 2 && w < (width - strlen(menuLines[0])) / 2 + strlen(menuLines[0])) {
                printf("%c", menuLines[h - (height - 6) / 2][w - (width - strlen(menuLines[0])) / 2]);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;

}

int print_rule_screen()
{	
	const int width = 38;
    const int height = 9;
    const char* menuLines[3] = {
        "           How to Play             ",
        "                                   ",
        "   Press the space to jump Dino    "
    };

    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {
            if (h == 0 || h == height - 1 || w == 0 || w == width - 1) {
                printf("#");
            } else if (h >= (height - 3) / 2 && h < (height - 3) / 2 + 3 &&
                       w >= (width - strlen(menuLines[0])) / 2 && w < (width - strlen(menuLines[0])) / 2 + strlen(menuLines[0])) {
                printf("%c", menuLines[h - (height - 3) / 2][w - (width - strlen(menuLines[0])) / 2]);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
int print_map_screen()
{
	printf("*MAP*\n");

	for (int h = 1; h < 16; h++) {
 
        for (int w = 1; w < 31; w++) {
 
            if((h == 1 || h == 15) ||(w==1||w==30)){
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
	return 0;
}

int main()
{
	int game_state;
	while(game_state)
	{
		 print_title_screen();
		 printf("input>");
		 scanf("%d",&game_state);
		 if(game_state == 1)
		 {
			while(game_state)
			{
				print_map_screen();
				printf("\n");
				printf("Return to menu? (1.yes  2.no)");
				printf("input>");
			 	scanf("%d",&game_state);
				if(game_state == 1){
					break;
				}
			}
		 }
		 if(game_state == 2)
		 {
			while(game_state)
			{
				print_rule_screen();
				printf("Return to menu? (1.yes  2.no)");
				printf("input>");
			 	scanf("%d",&game_state);
				if(game_state == 1){
					break;
				}
			}
		 }
		 else if(game_state==3)
		 {
			break;
		 }
	}

	return 0;
}