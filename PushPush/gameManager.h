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
	BLACK, /* 0 : 까망 */
	DARK_BLUE, /* 1 : 어두운 파랑 */
	DARK_GREEN, /* 2 : 어두운 초록 */
	DARK_SKY_BLUE, /* 3 : 어두운 하늘 */
	DARK_RED, /* 4 : 어두운 빨강 */
	DARK_VIOLET, /* 5 : 어두운 보라 */
	DARK_YELLOW, /* 6 : 어두운 노랑 */
	GRAY, /* 7 : 회색 */
	DARK_GRAY, /* 8 : 어두운 회색 */
	BLUE, /* 9 : 파랑 */
	GREEN, /* 10 : 초록 */
	SKY_BLUE, /* 11 : 하늘 */
	RED, /* 12 : 빨강 */
	VIOLET, /* 13 : 보라 */
	YELLOW, /* 14 : 노랑 */
	WHITE, /* 15 : 하양 */
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