#include "gameManager.h"
//double buffering
//setcursorxy
int map[MAX_HEIGHT][MAX_WIDTH] = {
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,1,1},
	{1,1,0,0,2,0,0,0,1,1},
	{1,1,0,0,0,0,0,0,1,1},
	{1,1,0,0,0,4,0,0,1,1},
	{1,1,0,0,3,0,0,0,1,1},
	{1,1,0,0,3,4,0,0,1,1},
	{1,1,0,0,0,0,0,0,1,1},
	{1,1,0,0,0,0,0,0,1,1},
	{1,1,1,1,1,1,1,1,1,1},
};

int main(void) {
	Position MovePosition;
	Position PlayerPosition;
	PlayerPosition.x = 4;
	PlayerPosition.y = 2;

	Position Box1MovePosition;
	Position Box1Position;
	Box1Position.x = 5;
	Box1Position.y = 4;

	Position Box2Position;
	Box2Position.x = 5;
	Box2Position.y = 6;

	int State, ch;

	for (;;) {
		DrawMap(map, MAX_HEIGHT);
		
		State = FindPlayerPosition(map, MAX_HEIGHT, &PlayerPosition);
		
		SetBox1Position(&Box1Position);
		SetBox2Position(&Box2Position);
		
		Box1Position.x = GetBox1PositionX(&Box1Position);
		Box1Position.y = GetBox1PositionY(&Box1Position);

		Box2Position.x = GetBox2PositionX(&Box2Position);
		Box2Position.y = GetBox2PositionY(&Box2Position);

		printf("Box1 : %d, %d ", Box1Position.x, Box1Position.y);
		printf("Box2 : %d, %d", Box2Position.x, Box2Position.y);

		if (_kbhit()) {
			ch = _getch();
			if (ch == 0xE0) {
				ch = _getch();
				switch (ch) {
				case UP:
					MovePosition.x = GetPlayerPositionX(&PlayerPosition);
					MovePosition.y = GetPlayerPositionY(&PlayerPosition) - 1 ;
					if (IsPlayerInMap(&map[MovePosition.y][MovePosition.x])) {
						if (map[MovePosition.y][MovePosition.x] == HOLE) {
							if (State == HOLEWITHPLAYER) {
								ChangePlayerState(&map[PlayerPosition.y][PlayerPosition.x], HOLE);
								PlayerPosition.y = PlayerPosition.y - 1;
								ChangePlayerState(&map[PlayerPosition.y][PlayerPosition.x], HOLEWITHPLAYER);
							}
							else {
								ChangePlayerState(&map[PlayerPosition.y][PlayerPosition.x], EMPTY);
								PlayerPosition.y = PlayerPosition.y - 1;
								ChangePlayerState(&map[PlayerPosition.y][PlayerPosition.x], HOLEWITHPLAYER);
							}
						}
						if (map[MovePosition.y][MovePosition.x] == BOX) {
							Box1MovePosition.x = GetBox1PositionX(&Box1Position);
							Box1MovePosition.y = GetBox1PositionY(&Box1Position) - 1;

							if (IsBox1InMap(&map[Box1MovePosition.y][Box1MovePosition.x])) {
								Box1Position.y = Box1Position.y - 1;
								SetBox1Position(&Box1Position);
								if (State == PLAYER) {
									ChangePlayerState(&map[PlayerPosition.y][PlayerPosition.x], EMPTY);
									PlayerPosition.y = PlayerPosition.y - 1;
									ChangePlayerState(&map[PlayerPosition.y][PlayerPosition.x], PLAYER);
									ChangeBox1State(&map[Box1Position.y][Box1Position.x], BOX);
								}
							}
						}
						else {
							if (State == HOLEWITHPLAYER) {
								ChangePlayerState(&map[PlayerPosition.y][PlayerPosition.x], HOLE);
								PlayerPosition.y = PlayerPosition.y - 1;
								ChangePlayerState(&map[PlayerPosition.y][PlayerPosition.x], PLAYER);
							}
							else {
								ChangePlayerState(&map[PlayerPosition.y][PlayerPosition.x], EMPTY);
								PlayerPosition.y = PlayerPosition.y - 1;
								ChangePlayerState(&map[PlayerPosition.y][PlayerPosition.x], PLAYER);
							}
							
						}
					}
					
					break;
				case DOWN:
					MovePosition.x = GetPlayerPositionX(&PlayerPosition);
					MovePosition.y = GetPlayerPositionY(&PlayerPosition) + 1;
					
					if (IsPlayerInMap(&map[MovePosition.y][MovePosition.x])) {
						if (map[MovePosition.y][MovePosition.x] == HOLE) {
							if (State == HOLEWITHPLAYER) {
								ChangePlayerState(&map[PlayerPosition.y][PlayerPosition.x], HOLE);
								PlayerPosition.y = PlayerPosition.y + 1;
								ChangePlayerState(&map[PlayerPosition.y][PlayerPosition.x], HOLEWITHPLAYER);
							}
							else {
								ChangePlayerState(&map[PlayerPosition.y][PlayerPosition.x], EMPTY);
								PlayerPosition.y = PlayerPosition.y + 1;
								ChangePlayerState(&map[PlayerPosition.y][PlayerPosition.x], HOLEWITHPLAYER);
							}
						}
						
						if (map[MovePosition.y][MovePosition.x] == BOX) {
							Box1MovePosition.x = GetBox1PositionX(&Box1Position);
							Box1MovePosition.y = GetBox1PositionY(&Box1Position) + 1;

							if (IsBox1InMap(&map[Box1MovePosition.y][Box1MovePosition.x])) {
								Box1Position.y = Box1Position.y + 1;
								SetBox1Position(&Box1Position);
								if (State == PLAYER) {
									ChangePlayerState(&map[PlayerPosition.y][PlayerPosition.x], EMPTY);
									PlayerPosition.y = PlayerPosition.y + 1;
									ChangePlayerState(&map[PlayerPosition.y][PlayerPosition.x], PLAYER);
									ChangeBox1State(&map[Box1Position.y][Box1Position.x], BOX);
								}
							}
						}
						else  {
							if (State == HOLEWITHPLAYER) {
								ChangePlayerState(&map[PlayerPosition.y][PlayerPosition.x], HOLE);
								PlayerPosition.y = PlayerPosition.y + 1;
								ChangePlayerState(&map[PlayerPosition.y][PlayerPosition.x], PLAYER);
							}
							else {
								ChangePlayerState(&map[PlayerPosition.y][PlayerPosition.x], EMPTY);
								PlayerPosition.y = PlayerPosition.y + 1;
								ChangePlayerState(&map[PlayerPosition.y][PlayerPosition.x], PLAYER);
							}

						}
						
					}

					break;
				case LEFT:
					MovePosition.x = GetPlayerPositionX(&PlayerPosition) -1;
					MovePosition.y = GetPlayerPositionY(&PlayerPosition);
					
					if (IsPlayerInMap(&map[MovePosition.y][MovePosition.x])) {
						if (map[MovePosition.y][MovePosition.x] == HOLE) {
							if (State == HOLEWITHPLAYER) {
								ChangePlayerState(&map[PlayerPosition.y][PlayerPosition.x], HOLE);
								PlayerPosition.x = PlayerPosition.x - 1;
								ChangePlayerState(&map[PlayerPosition.y][PlayerPosition.x], HOLEWITHPLAYER);
							}
							else {
								ChangePlayerState(&map[PlayerPosition.y][PlayerPosition.x], EMPTY);
								PlayerPosition.x = PlayerPosition.x - 1; 
								ChangePlayerState(&map[PlayerPosition.y][PlayerPosition.x], HOLEWITHPLAYER);
							}
						}
						if (map[MovePosition.y][MovePosition.x] == BOX) {
							Box1MovePosition.x = GetBox1PositionX(&Box1Position) - 1;
							Box1MovePosition.y = GetBox1PositionY(&Box1Position);

							if (IsBox1InMap(&map[Box1MovePosition.y][Box1MovePosition.x])) {
								Box1Position.x = Box1Position.x - 1;
								SetBox1Position(&Box1Position);
								if (State == PLAYER) {
									ChangePlayerState(&map[PlayerPosition.y][PlayerPosition.x], EMPTY);
									PlayerPosition.x = PlayerPosition.x - 1;
									ChangePlayerState(&map[PlayerPosition.y][PlayerPosition.x], PLAYER);
									ChangeBox1State(&map[Box1Position.y][Box1Position.x], BOX);
								}
							}
						}
						else {
							if (State == HOLEWITHPLAYER) {
								ChangePlayerState(&map[PlayerPosition.y][PlayerPosition.x], HOLE);
								PlayerPosition.x = PlayerPosition.x - 1; 
								ChangePlayerState(&map[PlayerPosition.y][PlayerPosition.x], PLAYER);
							}
							else {
								ChangePlayerState(&map[PlayerPosition.y][PlayerPosition.x], EMPTY);
								PlayerPosition.x = PlayerPosition.x - 1;
								ChangePlayerState(&map[PlayerPosition.y][PlayerPosition.x], PLAYER);
							}

						}

					}

					break;
				case RIGHT:
					MovePosition.x = GetPlayerPositionX(&PlayerPosition) + 1;
					MovePosition.y = GetPlayerPositionY(&PlayerPosition);
					

					if (IsPlayerInMap(&map[MovePosition.y][MovePosition.x])) {
						if (map[MovePosition.y][MovePosition.x] == HOLE) {
							if (State == HOLEWITHPLAYER) {
								ChangePlayerState(&map[PlayerPosition.y][PlayerPosition.x], HOLE);
								PlayerPosition.x = PlayerPosition.x + 1;
								ChangePlayerState(&map[PlayerPosition.y][PlayerPosition.x], HOLEWITHPLAYER);
							}
							else {
								ChangePlayerState(&map[PlayerPosition.y][PlayerPosition.x], EMPTY);
								PlayerPosition.x = PlayerPosition.x + 1;
								ChangePlayerState(&map[PlayerPosition.y][PlayerPosition.x], HOLEWITHPLAYER);
							}
						}
						
						if (map[MovePosition.y][MovePosition.x] == BOX) {
							Box1MovePosition.x = GetBox1PositionX(&Box1Position) + 1;
							Box1MovePosition.y = GetBox1PositionY(&Box1Position);

							if (IsBox1InMap(&map[Box1MovePosition.y][Box1MovePosition.x])) {
								Box1Position.x = Box1Position.x + 1;
								SetBox1Position(&Box1Position);
								if (State == PLAYER) {
									ChangePlayerState(&map[PlayerPosition.y][PlayerPosition.x], EMPTY);
									PlayerPosition.x = PlayerPosition.x + 1;
									ChangePlayerState(&map[PlayerPosition.y][PlayerPosition.x], PLAYER);
									ChangeBox1State(&map[Box1Position.y][Box1Position.x], BOX);
								}
							}
						}
						else {
							if (State == HOLEWITHPLAYER) {
								ChangePlayerState(&map[PlayerPosition.y][PlayerPosition.x], HOLE);
								PlayerPosition.x = PlayerPosition.x + 1;
								ChangePlayerState(&map[PlayerPosition.y][PlayerPosition.x], PLAYER);
							}
							else {
								ChangePlayerState(&map[PlayerPosition.y][PlayerPosition.x], EMPTY);
								PlayerPosition.x = PlayerPosition.x + 1;
								ChangePlayerState(&map[PlayerPosition.y][PlayerPosition.x], PLAYER);
							}

						}

					}

					break;
				}
			}
			else {
				if (ch == ESC) {
					break;
				}
			}
		}
	}
	getchar();
}