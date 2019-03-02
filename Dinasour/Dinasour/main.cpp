#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#define DINO_BOTTOM_Y 12
#define TREE_START_X 40
#define TREE_BOTTOM_Y 20
void gotoxy(int x, int y) {
	COORD Pos;
	Pos.X = 2 * x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void DrawDino(int dinoY) {
	gotoxy(0, dinoY);
	static bool legFlag = 1;

	printf("        $$$$$$$$ \n");
	printf("       $$ $$$$$$$\n");
	printf("       $$$$$$$$$$\n");
	printf("$      $$$$$     \n");
	printf("$$     $$$$$$$$  \n");
	printf("$$$   $$$$$$     \n");
	printf(" $$  $$$$$$$$$$$ \n");
	printf(" $$$$$$$$$$$$    \n");
	printf("  $$$$$$$$$$     \n");
	printf("   $$$$$$$$$     \n");
	printf("    $$$$$$$      \n");
	if (legFlag) {
		printf("    $     $$$    \n");
		printf("    $$           \n");
		legFlag = 0;
	}
	else {
		printf("    $$$   $      \n");
		printf("          $$     \n");
		legFlag = 1;
	}

}
void DrawTree(int TreeX) {
	gotoxy(TreeX, TREE_BOTTOM_Y);
	printf("======\n");
	gotoxy(TreeX, TREE_BOTTOM_Y+1);
	printf("  ==  \n");
	gotoxy(TreeX, TREE_BOTTOM_Y+2);
	printf("  ==  \n");
	gotoxy(TreeX, TREE_BOTTOM_Y+3);
	printf("  ==  \n");
	gotoxy(TreeX, TREE_BOTTOM_Y+4);
	printf("  ==  \n");
}
void SetConsoleView() {
	system("mode con:conls=100 lines=25");
	system("title Google Dinosaurs. by sangho");
}
int main(void) {
	//SetConsoleView();
	bool isJumping = false;
	bool isBottom = true;
	int dinoY = DINO_BOTTOM_Y;
	int TreeX = TREE_START_X;
	const int gravity = 2;

	while (1) {
		if (dinoY == DINO_BOTTOM_Y) {
			if (_kbhit()) {
				char click = _getch();
				//bufferºñ¿ì±â
				if (click == 'z') {
					isJumping = true;
					isBottom = false;
				}
			}
		}
		if (isJumping) {
			dinoY -= gravity;
			if (dinoY <= 6) {
				isJumping = false;
			}
		}
		else {
			dinoY += gravity;
			if (dinoY >= DINO_BOTTOM_Y) {
				dinoY = DINO_BOTTOM_Y;
				isBottom = true;
			}
		}
		system("cls");
		//Sleep(50);
		DrawDino(dinoY);
		

		DrawTree(TreeX);
	
		TreeX -= gravity;
		if (TreeX <= 0) {
			TreeX = TREE_START_X;
		}
	}
	return 0;
}