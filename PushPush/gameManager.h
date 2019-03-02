#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#define MAX_HEIGHT 10
#define MAX_WIDTH 10
enum {
	EMPTY, //space
	WALL,
	PLAYER,
	HOLE,
	BOX,
	HOLEWITHBOX,
	HOLEWITHPLAYER
};
enum KEYBOARD{
	UP = 72,
	LEFT = 75,
	RIGHT = 77,
	DOWN = 80,
	ESC = 27
};
enum {
	BLACK, /* 0 : ��� */
	DARK_BLUE, /* 1 : ��ο� �Ķ� */
	DARK_GREEN, /* 2 : ��ο� �ʷ� */
	DARK_SKY_BLUE, /* 3 : ��ο� �ϴ� */
	DARK_RED, /* 4 : ��ο� ���� */
	DARK_VIOLET, /* 5 : ��ο� ���� */
	DARK_YELLOW, /* 6 : ��ο� ��� */
	GRAY, /* 7 : ȸ�� */
	DARK_GRAY, /* 8 : ��ο� ȸ�� */
	BLUE, /* 9 : �Ķ� */
	GREEN, /* 10 : �ʷ� */
	SKY_BLUE, /* 11 : �ϴ� */
	RED, /* 12 : ���� */
	VIOLET, /* 13 : ���� */
	YELLOW, /* 14 : ��� */
	WHITE, /* 15 : �Ͼ� */
};
typedef struct postition {
	int x;
	int y;
}Position;

void SetColor(int color);
void Clrscr();
void DrawMap(int (*map)[MAX_HEIGHT], int width);
void gotoxy(int x, int y);
void SetPlayerPosition(Position* PlayerPosition);
void SetBox1Position(Position* Box1Position);
void SetBox2Position(Position* Box1Position);
int GetBox1PositionX(Position* Box1Position);
int GetBox1PositionY(Position* Box1Position);
int GetBox2PositionX(Position* Box2Position);
int GetBox2PositionY(Position* Box2Position);
int GetPlayerPositionX(Position* PlayerPosition);
int GetPlayerPositionY(Position* PlayerPosition);
int CurrentPlayerState(int(*map)[MAX_HEIGHT], int width, Position* PlayerPosition);
void ChangePlayerState(int* map, int State);
void ChangeBox1State(int* map, int State);
int FindPlayerPosition(int(*map)[MAX_HEIGHT], int width, Position* PlayerPosition);
bool IsPlayerInMap(int * map);
bool IsBox1InMap(int * map);
bool IsBox2InMap(int * map);