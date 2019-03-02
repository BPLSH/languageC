#include "gameManager.h"

void Clrscr()
{
		system("cls");
}
void SetColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void DrawMap(int (*map)[MAX_HEIGHT], int width)
{
	Clrscr();

	for (int y = 0; y < MAX_HEIGHT; ++y) {
		for (int x = 0; x < MAX_WIDTH; ++x) {
			switch (map[y][x]) {
			case EMPTY:
				printf("  ");
				break;
			case WALL:
				SetColor(BLUE);
				printf("¢Ì");
				break;
			case PLAYER:
				SetColor(YELLOW);
				printf("¡Ú");
				break;
			case HOLE:
				SetColor(RED);
				printf("¡à");
				break;
			case BOX:
				SetColor(DARK_RED);
				printf("¢Ç");
				break;
			case HOLEWITHBOX:
				SetColor(VIOLET);
				printf("¡á");
				break;
			case HOLEWITHPLAYER:
				SetColor(YELLOW);
				printf("¢Ã");
				break;
			}
		}
		printf("\n");
	}
}
void gotoxy(int x, int y) {
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}
void SetPlayerPosition(Position* PlayerPosition) {
	PlayerPosition->x = PlayerPosition->x;
	PlayerPosition->y = PlayerPosition->y;
}
void SetBox1Position(Position* Box1Position) {
	Box1Position->x = Box1Position->x;
	Box1Position->y = Box1Position->y;
}
void SetBox2Position(Position* Box2Position) {
	Box2Position->x = Box2Position->x;
	Box2Position->y = Box2Position->y;
}
int GetBox1PositionX(Position* Box1Position) {
	return Box1Position->x;
}
int GetBox1PositionY(Position* Box1Position) {
	return Box1Position->y;
}
int GetBox2PositionX(Position* Box2Position) {
	return Box2Position->x;
}
int GetBox2PositionY(Position* Box2Position) {
	return Box2Position->y;
}
int GetPlayerPositionX(Position* PlayerPosition) {
	return PlayerPosition->x;
}
int GetPlayerPositionY(Position* PlayerPosition) {
	return PlayerPosition->y;
}
int CurrentPlayerState(int(*map)[MAX_HEIGHT], int width, Position* PlayerPosition) {
	return map[PlayerPosition->y][PlayerPosition->x];
}
void ChangePlayerState(int* map, int State) {
	*map = State;
}
void ChangeBox1State(int* map, int State) {
	*map = State;
}

int FindPlayerPosition(int(*map)[MAX_HEIGHT], int width, Position* PlayerPosition) {
	SetPlayerPosition(PlayerPosition);
	int State = CurrentPlayerState(map, MAX_HEIGHT, PlayerPosition);
	return State;
}
bool IsPlayerInMap(int * map) {
	return *map != WALL;
}
bool IsBox1InMap(int * map) {
	return *map != WALL;
}
bool IsBox2InMap(int * map) {
	return *map != WALL;
}
