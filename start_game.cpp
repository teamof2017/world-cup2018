#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
//#include "game_start.h"

void game_start();

void typeInConsole(char sentence[])
{
	int cnt = 0;
	for (cnt = 0; cnt < strlen(sentence); cnt++) {
		printf("%c", sentence[cnt]);
		Sleep(100);
	}
}





void lineup(int team_number)
{
	
}

void game_start()
{
	char username[100];
	system("color 0E");
	Sleep(2000);
	printf("\n");
    char hello[45] = "Hello. Welcome to the World Cup Simulator!";
    typeInConsole(hello);
	Sleep(3000);
	system("cls");
	printf("\n");
	char wait[] = "PLEASE WAIT!";
	typeInConsole(wait);
	Sleep(500);
	printf("\n\nLOADING");
	Sleep(2000);
	printf(".");
	Sleep(1000);
	printf(".");
	Sleep(1000);
	printf(".\n\n\n");
	Sleep(500);
	system("cls");
	Sleep(1000);
	printf("\n");
	char yourname[] = "Please tell me your name to be more intimate : ";
	typeInConsole(yourname);
	puts("\n");
    scanf("%s", &username);
    Sleep(1000);
    
	system("cls");
	char welcome[] = "Welcome ";
	char welcome2[] = " to World Cup 2018 !";
	printf("\n'%s', ", username);
	typeInConsole(welcome);
	typeInConsole(welcome2);
	Sleep(1000);
	printf("\n\n");
	char choose[] = "Make your choose : \n\n1. NEW GAME\n\n2. CONTINUE PREVIOUS GAME\n\nIf you want to make a new game : Wirte '1'\n\nIf you want to continue previous game : Wirte '2'\n\nWrite Here : ";
	typeInConsole(choose);
    Sleep(500);
	
	int start;
	scanf("%d", &start);
	
	system("cls");
	
	Sleep(1000);
	if(start == 1) {
		int cnt = 0;
		for (cnt = 0; cnt < 32; cnt++) {
			printf("\n%d. %s\n", cnt + 1, team_array[cnt].name);
			Sleep(200);
		}
		Sleep(800);
		int team_number = 0;
		char write_teamNum[] = " write the number of the team you want to play with : ";
		printf("\n\n'%s'", username);
		typeInConsole(write_teamNum);
		scanf("%d", &team_number);
	}
}

void showTeamList()
{
	int team_number;
}

int main(){
	ReadFromFileTeaminfo();
	//ReadFromFilePlayerinfo();
	game_start();
}
