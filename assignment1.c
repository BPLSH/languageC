#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void winthegame(char user, char com){
	if(user == com)
		printf("비겼습니다.\n");
	else{
		if(user == 'O' && com == 'X')
			printf("당신이 이겼습니다.\n");
		else if(user == 'X' && com =='#')
			printf("당신이 이겼습니다.\n");
		else if(user == '#' && com == 'O')
			printf("당신이 이겼습니다.\n");
		else
			printf("내가 이겼습니다.\n");
	}
	return;
}
int main(void){
	srand(time(NULL));

	printf("가위(X) 바위(O) 보(#) 게임을 시작합니다. (게임종료 : 9)\n");
	do{
		printf("가위 바위 보를 선택하세요 :\n");

		char user = getchar();
		char enter = getchar();
		if(user == '9'){
			printf("가위 바위 보를 종료합니다.\n");
			break;
		}
		switch(user){
		case 'X' :
			break;
		case 'x' :
			break;
		case 'O' :
			break;
		case 'o' :
			break;
		case '#' :
			break;
		default :
			printf("잘못 입력하였습니다. 가위 바위 보를 다시 선택해주세요.\n");
			continue;
		}
		char com = rand() % 3 + 1;

		switch(com)
		{
			case 1 :
				com = 'X';
				break;
			case 2 :
				com = 'O';
				break;
			case 3 :
				com = '#';
				break;
			default :
				break;	
		}
		printf("당신은 %c를 냈고 나는 %c를 냈습니다.\n", user, com);
		if(user == 'x' || user == 'o')
			user = user - 32;
		winthegame(user, com);
	}while(1);

	return 0;
}

//모두 구현했습니다.
