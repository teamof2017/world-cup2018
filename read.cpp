#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#include <time.h>
#include <windows.h>

int searchByPost(char post,int j);
void showTeamList();
void print_players();
void playerSkill();
void chooseMainPlayer();
void chooseStorePlayer();
void sortByPost();
int searchByName(char *name);
void printBall();
int determineWiner(int i , int j);
void saveResultGames(int n);
void table();

typedef struct teamplayer{
	char groupName;
	char playername[40];
	int form;
	int fitness;
	int skill;
	char mainpost;
	char post;
	int num;
	int age;
	float avg;
	
}players;

typedef struct group_stage{
	char groupname;
	char teams[4][20];
	int result[3][2]; //result[round][game Number]

} groups;




typedef struct team_Result_In_group_stage{

	int goalsF;
	int goalsA;
	int win;
	int lose;
	int draw;
	int score;
} team_In_group;



typedef struct infoteams{
	char name[30];
	int system;
	char group;
	int placeInGroup;
	char confedration[20];
	int seed;
  	char filename[40];
  	char filesaved[40];
	int numberOfPlayer;
	float power;
	players mainplayers[11];
	players storeplayers[50];
	players playerinfo[60];
	team_In_group	stand;

} teams;



groups  groups_array[8];
teams team_array[32];





enum teamsName{
	Argentina=1,
	Australia,
	Belgium,
	Brazil,
	Colombia,
	CostaRica,
	Croatia,
	Denmark,
	Egypt,
	England,
	France,
	Germany,
	Iceland,
	Iran,
	Japan,
	KoreaRepublic,
	Mexico,
	Morocco,
	Nigeria,
	Panama,
	Peru,
	Poland,
	Portugal,
	Russia,
	SaudiArabia,
	Senegal,
	Serbia,
	Spain,
	Sweden,
	Switzerland,
	Tunisia,
	Uruguay
};

enum teamsName team_number;

void ReadFromFileTeaminfo(void){
	FILE *fp=fopen("Teams.csv","r");
	char tmp[100];
	char *token;
	char TeamName[20];
	char group;
	char confedration[20];
	char filename[40];
	int placeInGroup,seed,i=0;
	
	for( i=0;fgets(tmp,100,fp)!=NULL;i++){
		token=strtok(tmp,",");
		while( token != NULL ) {
   		 	strcpy(TeamName,token);
     		token = strtok(NULL, ",");
     		sscanf(token,"%c",&group);
     		token = strtok(NULL, ",");
     		sscanf(token,"%d",&placeInGroup);
     		token = strtok(NULL, ",");
     		strcpy(confedration,token);
     		token = strtok(NULL, ",");
     		sscanf(token,"%d",&seed);
     		token = strtok(NULL, ",");
     		sscanf(token,"%s",filename);
     		token = strtok(NULL, ",");
  		 }
		team_array[i].group=group;
		team_array[i].placeInGroup=placeInGroup;
		team_array[i].seed=seed;
		strcpy(team_array[i].name,TeamName);
		strcpy(team_array[i].confedration,confedration);
		strcpy(team_array[i].filename,filename);
		strcpy(team_array[i].filesaved,team_array[i].filename);
		strcat(team_array[i].filesaved , "saved");
	}
	/*for(int j=0;j<i;j++){
		printf("%d.Teamname=%10s	  group=%2c 	 place=%3d 	\n confedration=%5s seed=%3d  filename=%10s \n",j+1,team_array[j].name,team_array[j].group,team_array[j].placeInGroup,team_array[j].confedration,team_array[j].seed,team_array[j].filename);
	}*/
	fclose(fp);
}

void ReadFromFilePlayerinfo(void){
	//char s[32][40]={{"Argentina.csv"},{"Australia.csv"},{"Belgium.csv"},{"Brazil.csv"},{"Colombia.csv"},{"CostaRica.csv"},{"Croatia.csv"},{"Denmark.csv"},{"Egypt.csv"},{"England.csv"},{"France.csv"},{"Germany.csv"},{"Iceland.csv"},{"Iran.csv"},{"Japan.csv"},{"Korea.csv"},{"Mexico.csv"},{"Morocco.csv"},{"Nigeria.csv"},{"Panama.csv"},{"Peru.csv"},{"Poland.csv"},{"Portugal.csv"},{"Russia.csv"},{"SaudiArabia.csv"},{"Senegal.csv"},{"Serbia.csv"},{"Spain.csv"},{"Sweden.csv"},{"Switzerland.csv"},{"Tunisia.csv"},{"Uruguay.csv"}};
	for(int count=0;count<32;count++){

		FILE *fpo=fopen(team_array[count].filename,"r");
		if(fpo == NULL){
		perror("file open666");
		}
		char tmp[100];
		char *token;
		char mainpost;
		char name[30];
		int num, i=0,age;
		for( i=0 ; fgets(tmp,100,fpo) != NULL ; i++ ){
			token=strtok(tmp,",");
			while( token != NULL ) {
	   		 	sscanf(token,"%d",&num);
	     		token = strtok(NULL, ",");
	     		strcpy(name,token);
	     		token = strtok(NULL, ",");
	     		sscanf(token,"%d",&age);
	     		token = strtok(NULL, ",");
    	 		sscanf(token,"%c",&mainpost);
     			token = strtok(NULL, ",");
  			}

  			team_array[count].playerinfo[i].num = num;
	  		strcpy(team_array[count].playerinfo[i].playername , name);
  			team_array[count].playerinfo[i].age = age;

  			team_array[count].playerinfo[i].mainpost = mainpost; 
	  		team_array[count].playerinfo[i].post = mainpost; 
		}
		team_array[count].numberOfPlayer = i;
		fclose(fpo);
	}

}



void save_group(){
	groups_array[0].groupname = 'A';
	groups_array[1].groupname = 'B';
	groups_array[2].groupname = 'C';
	groups_array[3].groupname = 'D';
	groups_array[4].groupname = 'E';
	groups_array[5].groupname = 'F';
	groups_array[6].groupname = 'G';
	groups_array[7].groupname = 'H';	
	
	int i=0 , j=0;
	char groupName = 'A';
	char *x = 0;
	int cnt = 0 ;
	 x = (char*)calloc(20 , sizeof(char));
	for(cnt=0 ; cnt<32 ; cnt++){
		if(groupName > 'H')
			  break;
		
		
		for(i=0 , j=0 ; i<32 ; i++){
			
		if(groupName > 'H')
			  break;
			
		if(team_array[i].group == groupName){
			strcpy(groups_array[(int)groupName - 65].teams[team_array[i].placeInGroup-1] , team_array[i].name);
			j++;

			if(j % 4 == 0){
				groupName++;
				break;
			}
				
			
		}
	
}

		puts("");
}
}

void print_group(){
	puts("\n\n GROUPS OF WORLD CUP 2018\n\n");
	
	int i=0 , j=0;
	char groupName = 'A';
	char *x = 0;
	int cnt = 0 ;
	 x = (char*)calloc(20 , sizeof(char));
	for(cnt=0 ; cnt<32 ; cnt++){
		if(groupName > 'H')
			  break;
		
		
		printf("      GROUP   %c\n" , groupName);
		for(i=0 , j=0 ; i<32 ; i++){
			
		if(groupName > 'H')
			  break;
			
		if(team_array[i].group == groupName){
			strcpy(x , (team_array[i].name )) ;
			j++;
			printf("\t%s\n", x);

			if(j % 4 == 0){
				groupName++;
				break;
			}
				
			
		}
	
}

		puts("");
}
}



void systemOfTeam(int i){
	int n = 0 , cnt = 0;
	srand( time ( NULL ));
	for(cnt = 0 ; cnt < 32 ; cnt++){
		
		n = rand () % 7 + 1 ;
	switch (n){
		case 1:
			team_array[cnt].system = 352;
			break;
			
		case 2:
			team_array[cnt].system = 343;
			break;

		case 3:
			team_array[cnt].system = 442;
			break;

		case 4:
			team_array[cnt].system = 451;
			break;

		case 5:
			team_array[cnt].system = 433;
			break;

		case 6:
			team_array[cnt].system = 541;
			break;

		case 7:
			team_array[cnt].system = 532;
			break;

	}
	
}

	if( i==1 ){
		n=0;
	puts("Please insert your team`s system\n\n");
	
	puts("\t1. 3-5-2\n");
	puts("\t2. 3-4-3\n");
	puts("\t3. 4-4-2\n");
	puts("\t4. 4-5-1\n");
	puts("\t5. 4-3-3\n");
	puts("\t6. 5-4-1\n");
	puts("\t7. 5-3-2\n");
	
	scanf("%d",&n);

	while( n>7 && n<1 ){
		puts("Your number is incorrect Please try again!");
		scanf("%d",&n);
	}

	
	switch (n){
		case 1:
			team_array[team_number-1].system = 352;
			break;
			
		case 2:
			team_array[team_number-1].system = 343;
			break;

		case 3:
			team_array[team_number-1].system = 442;
			break;

		case 4:
			team_array[team_number-1].system = 451;
			break;

		case 5:
			team_array[team_number-1].system = 433;
			break;

		case 6:
			team_array[team_number-1].system = 541;
			break;

		case 7:
			team_array[team_number-1].system = 532;
			break;
			
		default:
			puts("\tLotfan Bebin , 7 Ta Tarkib Bishtar Nist.\n\tHala Mitony Ye Bar Dige Emtehan Koni.");
			

	}


}
}



void print_seed(){
	
	
	puts("\n\n SEEDS OF WORLD CUP 2018\n\n");
	
	int i=0 , j=0;
	int  seedNumber = 1;	
	char *x = 0;
	int cnt = 0 ;
	 x = (char*)calloc(20 , sizeof(char));
	for(cnt=0 ; cnt<32 ; cnt++){
		if(seedNumber > 4)
			  return;
		
		
		printf("      SEED   %d\n" , seedNumber);
		for(i=0 , j=0 ; i<32 ; i++){
			
		if(seedNumber > 4)
			  return;
			  			
		if(team_array[i].seed == seedNumber){
			strcpy(x , (team_array[i].name )) ;

			j++;
			printf("\t%s\n", x);

			if(j % 8 == 0){
				seedNumber++;
				break;
			}
				
			
		}
	
}

		puts("");
}
		int z;

		puts("if you want to change seeds prees 1\nelse prees 2\n");
		scanf("%d" , &z);
		if (z == 1){
		//	lotterySeeds();
		}
		else{
		}
}


void printBall(){
	puts("                                              *********");
	puts("                                             *         *");
	puts("                                            * *****  ****");
	puts("                                           ** *****  *****");
	puts("                                          ***          ****");
	puts("                                         *******************");
	puts("                                        *** *********** *****");
	puts("                                       ****             ******");
	puts("                                      ***** *********** *******");
	puts("                                     ***************************");
	puts("                                    ********* ****** ************");
	puts("                                   ******** ****** *** ***********");
	puts("                                  ********* **** ****** ***********");
	puts("                                 ***********   *****   *************");
	puts("                                *************************************");
	puts("                               ************** ****** *****************");
	puts("                              ************* ****** *** ****************");
	puts("                              ************* **** ****** ***************");
	puts("                              **************   *****   ****************");
	puts("                               ***************************************");
	puts("                                ***********          ****************");
	puts("                                 ********************* *************");
	puts("                                  *******************  ************");
	puts("                                   ********          *************");
	puts("                                    *****************************");
	puts("                                     *******    **** ***********");
	puts("                                      ***** **** ** **********");
	puts("                                       **** ***** ***********");
	puts("                                        ***          *******");
	puts("                                         ******************");
	puts("                                          ****************");
	puts("                                           **************");
	puts("                                           **************");
	puts("                                           **************");
	puts("                                          ***************");
	puts("                                         *****************");
	puts("                                        *******************");
	puts("                                       *********************");
	puts("                                      ***********************");
	puts("                                     *************************");
	puts("                                    ***************************");
	puts("\n                                         RUSSIA 2018\n\n\n");
}

int search_player(int player_number, int x)
{
	if(x == 1) {
		int cnt = 0;
		while(team_array[team_number - 1].mainplayers[cnt].num != player_number) {
			cnt++;
		}
		return cnt;
	}
	
	else if(x == 2) {
		int count = 0;
		for (count = 0; count < team_array[team_number - 1].numberOfPlayer - 11; count++) {
			if (team_array[team_number - 1].storeplayers[count].num == player_number)
				return count;
		}
	}
}

void sortForTable(){
	int firstTeam=0,secTeam=0,thirdTeam=0,fourthTeam=0,flagForScore=0,flagForDiffrence=0,scoreTeams[1][4];
	for(int z=0;z<8;z++){
	firstTeam=searchByName(groups_array[z].teams[0]);
	secTeam=searchByName(groups_array[z].teams[1]);
	thirdTeam=searchByName(groups_array[z].teams[1]);
	fourthTeam=searchByName(groups_array[z].teams[1]);
	scoreTeams[0][0]=team_array[firstTeam].stand.score;
	scoreTeams[0][1]=team_array[secTeam].stand.score;
	scoreTeams[0][2]=team_array[thirdTeam].stand.score;
	scoreTeams[0][3]=team_array[fourthTeam].stand.score;
		for(char x='A'; x != 'H';x++){
			for(int j=0;j<4;j++){
				for(int i=0;i<3;i++){
					if(scoreTeams[0][i+1]>scoreTeams[0][i]){
						char tmp[20];
						strcpy(tmp,groups_array[z].teams[i]);
						strcpy(groups_array[z].teams[i],groups_array[z].teams[i+1]);
						strcpy(groups_array[z].teams[i+1],tmp);
					}
				}
			}
		}
		for(int i=0;i<3;i++){
			if(scoreTeams[0][i]==scoreTeams[0][i+1]){
				flagForScore=1;
			}
		}
			int difference[0][4];
			difference[0][0]=team_array[firstTeam].stand.goalsF-team_array[firstTeam].stand.goalsA;
			difference[0][1]=team_array[secTeam].stand.goalsF-team_array[secTeam].stand.goalsA;
			difference[0][2]=team_array[thirdTeam].stand.goalsF-team_array[thirdTeam].stand.goalsA;
			difference[0][3]=team_array[fourthTeam].stand.goalsF-team_array[fourthTeam].stand.goalsA;
		if(flagForScore==1){
				for(char x='A'; x != 'H';x++){
					for(int j=0;j<4;j++){
						for(int i=0;i<3;i++){
							if(difference[0][i+1]>difference[0][i]&&scoreTeams[0][i+1]==scoreTeams[0][i]){
								char tmp[20];
								strcpy(tmp,groups_array[z].teams[i]);
								strcpy(groups_array[z].teams[i],groups_array[z].teams[i+1]);
								strcpy(groups_array[z].teams[i+1],tmp);
							}
						}
					}
				}
		}
		for(int i=0;i<3;i++){
			if(difference[0][i]==difference[0][i+1]){
				flagForDiffrence=1;
			}
		}
		if(flagForScore==1&&flagForDiffrence==1){
			int goalsF[0][4];
			goalsF[0][0]=team_array[firstTeam].stand.goalsF;
			goalsF[0][1]=team_array[secTeam].stand.goalsF;
			goalsF[0][2]=team_array[thirdTeam].stand.goalsF;
			goalsF[0][3]=team_array[fourthTeam].stand.goalsF;
			
				for(char x='A'; x != 'H';x++){
					for(int j=0;j<4;j++){
						for(int i=0;i<3;i++){
							if(goalsF[0][i+1]>goalsF[0][i]&&difference[0][i+1]==difference[0][i]&&scoreTeams[0][i+1]==scoreTeams[0][i]){
								char tmp[20];
								strcpy(tmp,groups_array[z].teams[i]);
								strcpy(groups_array[z].teams[i],groups_array[z].teams[i+1]);
								strcpy(groups_array[z].teams[i+1],tmp);
							}
						}
					}
				}
		}
	}
}


void change() 
{
	int main_player, store_player;
	puts("Please enter the number of Main player:");
	scanf("%d", &main_player);
	puts("Please enter the number of Store player:");
	scanf("%d",  &store_player);
	int main_player_element = search_player(main_player, 1);
	int store_player_element = search_player(store_player, 2);
	
	players tmp;
	
	//changing players
	tmp = team_array[team_number - 1].mainplayers[main_player_element];
	team_array[team_number - 1].mainplayers[main_player_element] = team_array[team_number - 1].storeplayers[store_player_element];
	team_array[team_number - 1].storeplayers[store_player_element] = tmp;
	
	tmp.post = team_array[team_number - 1].mainplayers[main_player_element].post;
	team_array[team_number - 1].mainplayers[main_player_element].post = team_array[team_number - 1].storeplayers[store_player_element].post;
	team_array[team_number - 1].storeplayers[store_player_element].post = tmp.post;

}


void typeInConsole(char sentence[])
{
	int cnt = 0;
	for (cnt = 0; cnt < strlen(sentence); cnt++) {
		printf("%c", sentence[cnt]);
		Sleep(80);
	}
}

void lineup()
{  
	int num,n=0;
	while(1){
	if(n==0){
		print_players();
		n=1;
	}
	puts("Enter the number for each statement: ");
	puts("1 -> Change your team system.\n2 -> Change players.\n3 -> Show groups of world cup 2018\n4 -> Show seeds of world cup 2018\n5 -> Show table\n6 -> Exit lineup.\n");
	scanf("%d",& num);
	print_players();
	if(num == 1){
		systemOfTeam(1);
		print_players();

	}
	
	else if(num == 2){
		change();
		print_players();

	}
	
	else if(num == 3){
		print_group;
	}
	
	else if(num == 4){
		print_seed();
	}
	
	else if(num == 5){
		table();
	}

	
	else if(num == 6){
		break;
	}
	


}
	
	
}

int  game_start()
{	
	printBall();
	ReadFromFileTeaminfo();
	ReadFromFilePlayerinfo();
	save_group();
    playerSkill();
  	systemOfTeam(0);
	sortByPost();
 	 chooseMainPlayer();
	chooseStorePlayer();

	
  
	char username[100];
	system("color 0E");
	Sleep(2000);
	
	
	
	printf("\n");
    char hello[45] = "Hello. Welcome to the World Cup Simulator!";
    typeInConsole(hello);
	Sleep(2000);
	system("cls");
	printf("\n");
	
	char wait[] = "PLEASE WAIT!";
	typeInConsole(wait);
	Sleep(300);
	printf("\n\nLOADING");
	Sleep(1000);
	printf(".");
	Sleep(700);
	printf(".");
	Sleep(700);
	printf(".\n\n\n");
	Sleep(500);
	system("cls");
	Sleep(700);
	printf("\n");
	
	char yourname[] = "Please tell me your name to be more intimate : ";
	typeInConsole(yourname);
	puts("\n");
    scanf("%s", &username);
    Sleep(700);
    
	system("cls");
	char welcome[] = "Welcome to World Cup 2018 !";
	printf("\n'%s', ", username);
	typeInConsole(welcome);
	Sleep(700);
	printf("\n\n");
	
	char choose[] = "Make your choose : \n\n1. NEW GAME\n\n2. CONTINUE PREVIOUS GAME\n\nIf you want to make a new game : Wirte '1'\n\nIf you want to continue previous game : Wirte '2'\n\nWrite Here : ";
	typeInConsole(choose);
    Sleep(400);
	
	int start;
	scanf("%d", &start);
	
	system("cls");
	Sleep(700);
	
	if(start == 1) {
		int cnt = 0;
		for (cnt = 0; cnt < 16; cnt++) {
			printf("\n%-2d. %-16s		%-2d. %-16s\n", cnt + 1, team_array[cnt].name,cnt + 17,team_array[cnt+16].name);
			Sleep(100);
		}
		Sleep(500);
		
		char write_teamNum[] = "\nWrite the number of the team you want to play with : ";
		//printf("\n\n'%s'", username);
		typeInConsole(write_teamNum);
		//scanf("%d", &team_number);
		//system("cls");
		showTeamList();
		sortByPost();
		print_group();
			return team_number;

	}
	
}

void showTeamList()
{
	//enum teamsName team_number;
	scanf("%d", &team_number);
	int cnt = 0;
	system("cls");
	printf("Player Number		Player Name		Player MainPost\n\n\n");
	for (cnt = 0; cnt < team_array[team_number - 1].numberOfPlayer; cnt++) {
		printf("%6d                  %-20s%11c\n\n", team_array[team_number - 1].playerinfo[cnt].num, team_array[team_number - 1].playerinfo[cnt].playername, team_array[team_number - 1].playerinfo[cnt].mainpost);
		Sleep(200);
	}
}
int searchByPost(char post,int j){
	int tedad=0;	
		for(int i=0;i<team_array[j].numberOfPlayer;i++){
			if(team_array[j].playerinfo[i].mainpost == post)
			tedad++;
		}
		
	return tedad;
}

void sortByPost(){
	for(int j=0;j<32;j++){
		int sum=0;
		sum+=searchByPost('G',j);
		for(int x=0;x<searchByPost('G',j);x++){
			for(int i=0;i<searchByPost('G',j)-1;i++) {
			if(team_array[j].playerinfo[i].avg<team_array[j].playerinfo[i+1].avg){
				players tmp;
				tmp=team_array[j].playerinfo[i];
				team_array[j].playerinfo[i]=team_array[j].playerinfo[i+1];
				team_array[j].playerinfo[i+1]=tmp;
			}
			}
		}
		for(int x=sum;x<sum+searchByPost('D',j);x++){
			for(int i=sum;i<sum+searchByPost('D',j)-1;i++){
			if(team_array[j].playerinfo[i].avg<team_array[j].playerinfo[i+1].avg){	
				players tmp;
				tmp=team_array[j].playerinfo[i];
				team_array[j].playerinfo[i]=team_array[j].playerinfo[i+1];
				team_array[j].playerinfo[i+1]=tmp;
			}
			}
		}
		sum+=searchByPost('D',j);
		for(int x=sum;x<sum+searchByPost('M',j);x++){
			for(int i=sum;i<sum+searchByPost('M',j)-1;i++){
			if(team_array[j].playerinfo[i].avg<team_array[j].playerinfo[i+1].avg){
				players tmp;
				tmp=team_array[j].playerinfo[i];
				team_array[j].playerinfo[i]=team_array[j].playerinfo[i+1];
				team_array[j].playerinfo[i+1]=tmp;
			}
			}
		}
		sum+=searchByPost('M',j);
		for(int x=sum;x<sum+searchByPost('A',j);x++){
			for(int i=sum;i<sum+searchByPost('A',j)-1;i++){
			if(team_array[j].playerinfo[i].avg<team_array[j].playerinfo[i+1].avg){
				players tmp;
				tmp=team_array[j].playerinfo[i];
				team_array[j].playerinfo[i]=team_array[j].playerinfo[i+1];
				team_array[j].playerinfo[i+1]=tmp;

			}
			}
		}
	}
	
}

void playerSkill(){
	float sum=0;
	srand( time (NULL));
	for(int i=0; i<32 ;i++){
		for(int j=0 ; j<team_array[i].numberOfPlayer ; j++){
			

			team_array[i].playerinfo[j].skill = rand() % 30 + 70;
			team_array[i].playerinfo[j].form = rand() % 10 + 90;
			team_array[i].playerinfo[j].fitness = rand() % 30 +70;
			team_array[i].playerinfo[j].avg=(team_array[i].playerinfo[j].skill+team_array[i].playerinfo[j].form+team_array[i].playerinfo[j].fitness)/3;
			sum+=team_array[i].playerinfo[j].avg;
			
		}
		sum/=team_array[i].numberOfPlayer;
		team_array[i].power=sum;
		sum=0;
	}
}



void chooseMainPlayer(){	

	int attack=0,midle=0,defensive=0,sum=0, i=0;
			for(int j=0;j<32;j++){
				i=0;
				sum=searchByPost('G',j);
				attack=(team_array[j].system)%10;
				midle=((team_array[j].system)/10)%10;
				defensive=((team_array[j].system)/100)%10;
				team_array[j].mainplayers[0]=team_array[j].playerinfo[0];
				strcpy(team_array[j].mainplayers[0].playername,team_array[j].playerinfo[0].playername);
				i++;
				for(int z=0;z<defensive;i++,z++,sum++){
				team_array[j].mainplayers[i]=team_array[j].playerinfo[sum];
				strcpy(team_array[j].mainplayers[i].playername,team_array[j].playerinfo[sum].playername);	
				}
				sum=searchByPost('G',j) + searchByPost('D',j);
				for(int z=0;z<midle;i++,z++,sum++){
				team_array[j].mainplayers[i]=team_array[j].playerinfo[sum];
				strcpy(team_array[j].mainplayers[i].playername,team_array[j].playerinfo[sum].playername);	
				}
				sum=searchByPost('M',j)+searchByPost('G',j) + searchByPost('D',j);
				for(int z=0 ;z<attack;i++,z++,sum++){
				team_array[j].mainplayers[i]=team_array[j].playerinfo[sum];
				strcpy(team_array[j].mainplayers[i].playername,team_array[j].playerinfo[sum].playername);	
				}
							
							
			}

}
void chooseStorePlayer(){
	for (int j=0;j<32;j++){
		for(int i=0;i<team_array[j].numberOfPlayer-11;){
			for(int h=0,flag=0;h<team_array[j].numberOfPlayer;h++){
				flag=0;
				for(int z=0;z<11;z++){
					if(team_array[j].mainplayers[z].num==team_array[j].playerinfo[h].num){
					flag=1;
					}	
				
				}
				if(flag==0){
					team_array[j].storeplayers[i]=team_array[j].playerinfo[h];
					strcpy(team_array[j].storeplayers[i].playername,team_array[j].playerinfo[h].playername);
					i++;
				}
			}
		}
	}
}

void print_players(){
	
	puts("\n\t MAIN PLAYERS:");
	puts("NUM        NAME                         SKILL    FITNESS    FORM    MAINPOST    POST");
	
	for(int i=0 ; i<11 ; i++){
		printf("%2d.%-20s%20d%10d%9d%8c%4c\n",team_array[team_number - 1].mainplayers[i].num , team_array[team_number -1].mainplayers[i].playername , team_array[team_number-1].mainplayers[i].skill , team_array[team_number-1].mainplayers[i].fitness , team_array[team_number-1].mainplayers[i].form , team_array[team_number-1].mainplayers[i].mainpost , team_array[team_number-1].mainplayers[i].post);
	}
	
	
	int j = team_array[team_number - 1].numberOfPlayer - 11;
	
	puts("\n\t STORE PLAYERS:");
	puts("NUM        NAME                         SKILL    FITNESS    FORM    MAINPOST    POST");


	for(int i=0 ; i<j ; i++){
		printf("%2d.%-20s%20d%10d%9d%8c%4c\n",team_array[team_number-1].storeplayers[i].num , team_array[team_number-1].storeplayers[i].playername , team_array[team_number-1].storeplayers[i].skill , team_array[team_number-1].storeplayers[i].fitness , team_array[team_number-1].storeplayers[i].form , team_array[team_number-1].storeplayers[i].mainpost , team_array[team_number-1].storeplayers[i].post);
	}
	
	
}
int searchByName(char *name){
	for(int j=0;j<32;j++){
		if(strcmp(team_array[j].name,name) == 0)
			return j;
	}
	
}
void saveResultGames(int n){

	//Round one
	
	groups_array[0].result[0][0]=determineWiner(searchByName(groups_array[0].teams[0]),searchByName(groups_array[0].teams[1]));
	groups_array[0].result[0][1]=determineWiner(searchByName(groups_array[0].teams[2]),searchByName(groups_array[0].teams[3]));
	groups_array[1].result[0][0]=determineWiner(searchByName(groups_array[1].teams[0]),searchByName(groups_array[1].teams[3]));
	groups_array[1].result[0][1]=determineWiner(searchByName(groups_array[1].teams[0]),searchByName(groups_array[1].teams[1]));
	groups_array[2].result[0][0]=determineWiner(searchByName(groups_array[2].teams[0]),searchByName(groups_array[2].teams[1]));
	groups_array[3].result[0][0]=determineWiner(searchByName(groups_array[3].teams[0]),searchByName(groups_array[3].teams[1]));
	groups_array[2].result[0][1]=determineWiner(searchByName(groups_array[2].teams[2]),searchByName(groups_array[2].teams[3]));
	groups_array[3].result[0][1]=determineWiner(searchByName(groups_array[3].teams[2]),searchByName(groups_array[3].teams[3]));
	groups_array[4].result[0][0]=determineWiner(searchByName(groups_array[4].teams[2]),searchByName(groups_array[4].teams[3]));
	groups_array[5].result[0][0]=determineWiner(searchByName(groups_array[5].teams[0]),searchByName(groups_array[5].teams[1]));
	groups_array[4].result[0][1]=determineWiner(searchByName(groups_array[4].teams[0]),searchByName(groups_array[4].teams[1]));
	groups_array[5].result[0][1]=determineWiner(searchByName(groups_array[5].teams[2]),searchByName(groups_array[5].teams[3]));
	groups_array[6].result[0][0]=determineWiner(searchByName(groups_array[6].teams[0]),searchByName(groups_array[6].teams[1]));
	groups_array[6].result[0][1]=determineWiner(searchByName(groups_array[6].teams[2]),searchByName(groups_array[6].teams[3]));
	groups_array[7].result[0][0]=determineWiner(searchByName(groups_array[7].teams[2]),searchByName(groups_array[7].teams[3]));
	groups_array[7].result[0][1]=determineWiner(searchByName(groups_array[7].teams[0]),searchByName(groups_array[7].teams[1]));
	
	//Round two
	
	groups_array[0].result[1][0]=determineWiner(searchByName(groups_array[0].teams[0]),searchByName(groups_array[0].teams[2]));
	groups_array[1].result[1][0]=determineWiner(searchByName(groups_array[1].teams[0]),searchByName(groups_array[1].teams[2]));
	groups_array[0].result[1][1]=determineWiner(searchByName(groups_array[0].teams[3]),searchByName(groups_array[0].teams[1]));
	groups_array[1].result[1][1]=determineWiner(searchByName(groups_array[1].teams[3]),searchByName(groups_array[1].teams[1]));
	groups_array[2].result[1][0]=determineWiner(searchByName(groups_array[2].teams[3]),searchByName(groups_array[2].teams[1]));
	groups_array[2].result[1][1]=determineWiner(searchByName(groups_array[2].teams[0]),searchByName(groups_array[2].teams[2]));
	groups_array[3].result[1][0]=determineWiner(searchByName(groups_array[3].teams[0]),searchByName(groups_array[3].teams[2]));
	groups_array[4].result[1][0]=determineWiner(searchByName(groups_array[4].teams[0]),searchByName(groups_array[4].teams[2]));
	groups_array[3].result[1][1]=determineWiner(searchByName(groups_array[3].teams[3]),searchByName(groups_array[3].teams[1]));
	groups_array[4].result[1][1]=determineWiner(searchByName(groups_array[4].teams[3]),searchByName(groups_array[4].teams[1]));
	groups_array[6].result[1][0]=determineWiner(searchByName(groups_array[6].teams[0]),searchByName(groups_array[6].teams[2]));
	groups_array[5].result[1][0]=determineWiner(searchByName(groups_array[5].teams[3]),searchByName(groups_array[5].teams[1]));
	groups_array[5].result[1][1]=determineWiner(searchByName(groups_array[5].teams[0]),searchByName(groups_array[5].teams[2]));
	groups_array[6].result[1][1]=determineWiner(searchByName(groups_array[6].teams[3]),searchByName(groups_array[6].teams[1]));
	groups_array[7].result[1][0]=determineWiner(searchByName(groups_array[7].teams[3]),searchByName(groups_array[7].teams[1]));
	groups_array[7].result[1][1]=determineWiner(searchByName(groups_array[7].teams[0]),searchByName(groups_array[7].teams[2]));
	
	//Round three
	
	groups_array[0].result[2][0]=determineWiner(searchByName(groups_array[0].teams[3]),searchByName(groups_array[0].teams[0]));
	groups_array[0].result[2][1]=determineWiner(searchByName(groups_array[0].teams[1]),searchByName(groups_array[0].teams[2]));
	groups_array[1].result[2][0]=determineWiner(searchByName(groups_array[1].teams[3]),searchByName(groups_array[1].teams[0]));
	groups_array[1].result[2][1]=determineWiner(searchByName(groups_array[1].teams[1]),searchByName(groups_array[1].teams[2]));
	groups_array[2].result[2][0]=determineWiner(searchByName(groups_array[2].teams[3]),searchByName(groups_array[2].teams[0]));
	groups_array[2].result[2][1]=determineWiner(searchByName(groups_array[2].teams[1]),searchByName(groups_array[2].teams[2]));
	groups_array[3].result[2][0]=determineWiner(searchByName(groups_array[3].teams[3]),searchByName(groups_array[3].teams[0]));
	groups_array[3].result[2][1]=determineWiner(searchByName(groups_array[3].teams[1]),searchByName(groups_array[3].teams[2]));
	groups_array[5].result[2][0]=determineWiner(searchByName(groups_array[5].teams[1]),searchByName(groups_array[5].teams[2]));
	groups_array[5].result[2][1]=determineWiner(searchByName(groups_array[5].teams[3]),searchByName(groups_array[5].teams[0]));
	groups_array[4].result[2][0]=determineWiner(searchByName(groups_array[4].teams[3]),searchByName(groups_array[4].teams[0]));
	groups_array[4].result[2][1]=determineWiner(searchByName(groups_array[4].teams[1]),searchByName(groups_array[4].teams[2]));
	groups_array[7].result[2][0]=determineWiner(searchByName(groups_array[7].teams[3]),searchByName(groups_array[7].teams[0]));
	groups_array[7].result[2][1]=determineWiner(searchByName(groups_array[7].teams[1]),searchByName(groups_array[1].teams[2]));
	groups_array[6].result[2][0]=determineWiner(searchByName(groups_array[6].teams[1]),searchByName(groups_array[6].teams[2]));
	groups_array[6].result[2][1]=determineWiner(searchByName(groups_array[6].teams[3]),searchByName(groups_array[6].teams[0]));
	
	
}

void schedule()
{
	int cnt = 0, count = 0;
	
	printf("ROUND 1 STAGE\n\n");
	printf("%-10s		VS		%-10s\n", groups_array[cnt].teams[count], groups_array[cnt].teams[count + 1]);
	printf("%-10s		VS		%-10s\n", groups_array[cnt].teams[count + 2], groups_array[cnt].teams[count + 3]);
	printf("%-10s		VS		%-10s\n", groups_array[cnt + 1].teams[count + 2], groups_array[cnt + 1].teams[count + 3]);
	printf("%-10s		VS		%-10s\n", groups_array[cnt + 1].teams[count], groups_array[cnt + 1].teams[count + 1]);
	printf("%-10s		VS		%-10s\n", groups_array[cnt + 2].teams[count], groups_array[cnt + 2].teams[count + 1]);
	printf("%-10s		VS		%-10s\n", groups_array[cnt + 3].teams[count], groups_array[cnt + 3].teams[count + 1]);
	printf("%-10s		VS		%-10s\n", groups_array[cnt + 2].teams[count + 2], groups_array[cnt + 2].teams[count + 3]);
	printf("%-10s		VS		%-10s\n", groups_array[cnt + 3].teams[count + 2], groups_array[cnt + 3].teams[count + 3]);
	printf("%-10s		VS		%-10s\n", groups_array[cnt + 4].teams[count + 2], groups_array[cnt + 4].teams[count + 3]);
	printf("%-10s		VS		%-10s\n", groups_array[cnt + 5].teams[count], groups_array[cnt + 5].teams[count + 1]);
	printf("%-10s		VS		%-10s\n", groups_array[cnt + 4].teams[count], groups_array[cnt + 4].teams[count + 1]);
	printf("%-10s		VS		%-10s\n", groups_array[cnt + 5].teams[count + 2], groups_array[cnt + 5].teams[count + 3]);
	printf("%-10s		VS		%-10s\n", groups_array[cnt + 6].teams[count], groups_array[cnt + 6].teams[count + 1]);
	printf("%-10s		VS		%-10s\n", groups_array[cnt + 6].teams[count + 2], groups_array[cnt + 6].teams[count + 3]);
	printf("%-10s		VS		%-10s\n", groups_array[cnt + 7].teams[count + 2], groups_array[cnt + 7].teams[count + 3]);
	printf("%-10s		VS		%-10s\n\n\n", groups_array[cnt + 7].teams[count], groups_array[cnt + 7].teams[count + 1]);

	
	printf("ROUND 2 STAGE\n\n");
	printf("%-10s		VS		%-10s\n", groups_array[cnt].teams[count], groups_array[cnt].teams[count + 2]);
	printf("%-10s		VS		%-10s\n", groups_array[cnt + 1].teams[count], groups_array[cnt + 1].teams[count + 2]);
	printf("%-10s		VS		%-10s\n", groups_array[cnt].teams[count + 3], groups_array[cnt].teams[count + 1]);
	printf("%-10s		VS		%-10s\n", groups_array[cnt + 1].teams[count + 3], groups_array[cnt + 1].teams[count + 1]);
	printf("%-10s		VS		%-10s\n", groups_array[cnt + 2].teams[count + 3], groups_array[cnt + 2].teams[count + 1]);
	printf("%-10s		VS		%-10s\n", groups_array[cnt + 2].teams[count], groups_array[cnt + 2].teams[count + 2]);
	printf("%-10s		VS		%-10s\n", groups_array[cnt + 3].teams[count], groups_array[cnt + 3].teams[count + 2]);
	printf("%-10s		VS		%-10s\n", groups_array[cnt + 4].teams[count], groups_array[cnt + 4].teams[count + 2]);
	printf("%-10s		VS		%-10s\n", groups_array[cnt + 3].teams[count + 3], groups_array[cnt + 3].teams[count + 1]);
	printf("%-10s		VS		%-10s\n", groups_array[cnt + 4].teams[count + 3], groups_array[cnt + 4].teams[count + 1]);
	printf("%-10s		VS		%-10s\n", groups_array[cnt + 6].teams[count], groups_array[cnt + 6].teams[count + 2]);
	printf("%-10s		VS		%-10s\n", groups_array[cnt + 5].teams[count + 3], groups_array[cnt + 5].teams[count + 1]);
	printf("%-10s		VS		%-10s\n", groups_array[cnt + 5].teams[count], groups_array[cnt + 5].teams[count + 2]);
	printf("%-10s		VS		%-10s\n", groups_array[cnt + 6].teams[count + 3], groups_array[cnt + 6].teams[count + 1]);
	printf("%-10s		VS		%-10s\n", groups_array[cnt + 7].teams[count + 3], groups_array[cnt + 7].teams[count + 1]);
	printf("%-10s		VS		%-10s\n\n\n", groups_array[cnt + 7].teams[count], groups_array[cnt + 7].teams[count + 2]);
	
	printf("ROUND 3 STAGE\n\n");
	printf("%-10s		VS		%-10s\n", groups_array[cnt].teams[count + 3], groups_array[cnt].teams[count]);
	printf("%-10s		VS		%-10s\n", groups_array[cnt].teams[count + 1], groups_array[cnt].teams[count + 2]);
	printf("%-10s		VS		%-10s\n", groups_array[cnt + 1].teams[count + 3], groups_array[cnt + 1].teams[count]);
	printf("%-10s		VS		%-10s\n", groups_array[cnt + 1].teams[count + 1], groups_array[cnt + 1].teams[count + 2]);
	printf("%-10s		VS		%-10s\n", groups_array[cnt + 2].teams[count + 3], groups_array[cnt + 2].teams[count]);
	printf("%-10s		VS		%-10s\n", groups_array[cnt + 2].teams[count + 1], groups_array[cnt + 2].teams[count + 2]);
	printf("%-10s		VS		%-10s\n", groups_array[cnt + 3].teams[count + 3], groups_array[cnt + 3].teams[count]);
	printf("%-10s		VS		%-10s\n", groups_array[cnt + 3].teams[count + 1], groups_array[cnt + 3].teams[count + 2]);
	printf("%-10s		VS		%-10s\n", groups_array[cnt + 5].teams[count + 1], groups_array[cnt + 5].teams[count + 2]);
	printf("%-10s		VS		%-10s\n", groups_array[cnt + 5].teams[count + 3], groups_array[cnt + 5].teams[count]);
	printf("%-10s		VS		%-10s\n", groups_array[cnt + 4].teams[count + 3], groups_array[cnt + 4].teams[count]);
	printf("%-10s		VS		%-10s\n", groups_array[cnt + 4].teams[count + 1], groups_array[cnt + 4].teams[count + 2]);
	printf("%-10s		VS		%-10s\n", groups_array[cnt + 7].teams[count + 3], groups_array[cnt + 7].teams[count]);
	printf("%-10s		VS		%-10s\n", groups_array[cnt + 7].teams[count + 1], groups_array[cnt + 7].teams[count + 2]);
	printf("%-10s		VS		%-10s\n", groups_array[cnt + 6].teams[count + 1], groups_array[cnt + 6].teams[count + 2]);
	printf("%-10s		VS		%-10s\n\n\n", groups_array[cnt + 6].teams[count + 3], groups_array[cnt + 6].teams[count]);
}



void table() {
	
	sortForTable();
	int cnt = 0, count = 0;
	char group = 'A';
	for (cnt = 0; cnt < 8; cnt++, group++) {
		int firstTeam, secTeam, thirdTeam, fourthTeam;
		
		firstTeam = searchByName(groups_array[cnt].teams[0]);
		secTeam = searchByName(groups_array[cnt].teams[1]);
		thirdTeam = searchByName(groups_array[cnt].teams[2]);
		fourthTeam = searchByName(groups_array[cnt].teams[3]);
		
		int firstTeamScore = team_array[firstTeam].stand.score;
		int secTeamScore = team_array[secTeam].stand.score;
		int thirdTeamScore = team_array[thirdTeam].stand.score;
		int fourthTeamScore = team_array[fourthTeam].stand.score;
		
		int firstTeamGA = team_array[firstTeam].stand.goalsA;
		int secTeamGA = team_array[secTeam].stand.goalsA;
		int thirdTeamGA = team_array[thirdTeam].stand.goalsA;
		int fourthTeamGA = team_array[fourthTeam].stand.goalsA;
		
		int firstTeamGF = team_array[firstTeam].stand.goalsF;
		int secTeamGF = team_array[secTeam].stand.goalsF;
		int thirdTeamGF = team_array[thirdTeam].stand.goalsF;
		int fourthTeamGF = team_array[fourthTeam].stand.goalsF;
		
		int firstTeamWon = team_array[firstTeam].stand.win;
		int secTeamWon = team_array[secTeam].stand.win;
		int thirdTeamWon = team_array[thirdTeam].stand.win;
		int fourthTeamWon = team_array[fourthTeam].stand.win;
		
		int firstTeamDraw = team_array[firstTeam].stand.draw;
		int secTeamDraw = team_array[secTeam].stand.draw;
		int thirdTeamDraw = team_array[thirdTeam].stand.draw;
		int fourthTeamDraw = team_array[fourthTeam].stand.draw;
		
		int firstTeamLose = team_array[firstTeam].stand.lose;
		int secTeamLose = team_array[secTeam].stand.lose;
		int thirdTeamLose = team_array[thirdTeam].stand.lose;
		int fourthTeamLose = team_array[fourthTeam].stand.lose;
		
		int firstTeamDif = firstTeamGF - firstTeamGA;
		int secTeamDif = secTeamGF - secTeamGA;
		int thirdTeamDif = thirdTeamGF - thirdTeamGA;
		int fourthTeamDif = fourthTeamGF - fourthTeamGA;
		
		printf("GROUP %c\n", group);
		printf("		Pts	W	D	L	GF	GA	GD\n\n");
		printf("%-17s%-7d%-8d%-8d%-8d%-8d%-8d%-8d\n", groups_array[cnt].teams[0], firstTeamScore, firstTeamWon, firstTeamDraw, firstTeamLose, firstTeamGF, firstTeamGA, firstTeamDif);
		printf("\n%-17s%-7d%-8d%-8d%-8d%-8d%-8d%-8d\n", groups_array[cnt].teams[1], secTeamScore, secTeamWon, secTeamDraw, secTeamLose, secTeamGF, secTeamGA, secTeamDif);
		printf("\n%-17s%-7d%-8d%-8d%-8d%-8d%-8d%-8d\n", groups_array[cnt].teams[2], thirdTeamScore, thirdTeamWon, thirdTeamDraw, thirdTeamLose, thirdTeamGF, thirdTeamGA, thirdTeamDif);
		printf("\n%-17s%-7d%-8d%-8d%-8d%-8d%-8d%-8d\n\n\n\n\n", groups_array[cnt].teams[3], fourthTeamScore, fourthTeamWon, fourthTeamDraw, fourthTeamLose, fourthTeamGF, fourthTeamGA, fourthTeamDif);
	}
}




void save(){
	
	
	for(int cnt =0 ; cnt < 32 ; cnt++){
		 FILE *filesave = fopen( team_array[cnt].filesaved , "w");
		fprintf(filesave , "     %s\n" ,  team_array[cnt].name );
		fprintf(filesave , "system =  %d\n" ,  team_array[cnt].system );
		fprintf(filesave , "group = %c\n" ,  team_array[cnt].group );
		fprintf(filesave , "%d , %d\n" , cnt+1 , team_array[cnt].numberOfPlayer );
		fprintf(filesave , "%d , %f\n" , cnt+1 , team_array[cnt].power );
		fprintf(filesave , "%d , %d\n" , cnt+1 , team_array[cnt].seed );
		fprintf(filesave , "%d , %s\n" , cnt+1, team_array[cnt].confedration );
		fputs("\n\n" , filesave);
		fputs("MAIN PLAYERS\n" , filesave);
		for(int i=0 ; i<11 ; i++){
		fprintf(filesave , "%d . %s\n" , i+1, team_array[cnt].mainplayers[i] );
			
		}
		fputs("STORE PLAYERS\n" , filesave);

			for(int i=0 ; i<team_array[cnt].numberOfPlayer - 11 ; i++){
		fprintf(filesave , "%d . %s\n" , i+1, team_array[cnt].storeplayers[i] );
			
		}
	

				
		puts("\n\n");
		fclose(filesave);
}
		

}


int determineWiner(int i , int j){
	int defensiveavg1 = 0;
	int defensiveavg2 = 0;
	int middleavg1 = 0;
	int middleavg2 = 0;
	int attackavg1 = 0;
	int attackavg2 = 0;
	int cnt=0;
//	int j = searchByName(&team1);
	
	for(cnt=0 ; cnt< 11 ; cnt++){
		if(team_array[i].mainplayers[cnt].mainpost == 'G'){
			defensiveavg1 += team_array[i].mainplayers[cnt].avg;
		}
	}
	
	for( cnt=0 ; cnt< 11 ; cnt++){
		if(team_array[j].mainplayers[cnt].mainpost == 'G'){
			defensiveavg2 += team_array[j].mainplayers[cnt].avg;
		}
	}
	
	
	for(cnt=0 ; cnt< 11 ; cnt++){
		if(team_array[i].mainplayers[cnt].mainpost == 'D'){
			defensiveavg1 += team_array[i].mainplayers[cnt].avg;
		}
	}
	
	for(cnt=0 ; cnt< 11 ; cnt++){

		if(team_array[j].mainplayers[cnt].mainpost == 'D'){
			defensiveavg2 += team_array[j].mainplayers[cnt].avg;
		}
	}
	
	for(cnt=0 ; cnt<11 ;cnt++){
		if(team_array[i].mainplayers[cnt].mainpost == 'M'){
			middleavg1 += team_array[i].mainplayers[cnt].avg;
		}
	}
	
	for(cnt=0 ; cnt<11 ;cnt++){
		if(team_array[j].mainplayers[cnt].mainpost == 'M'){
			middleavg2 += team_array[j].mainplayers[cnt].avg;
		}
	}
	
	for(cnt=0 ; cnt<11 ;cnt++){
		if(team_array[i].mainplayers[cnt].mainpost == 'A'){
			attackavg1 += team_array[i].mainplayers[cnt].avg;
		}
	}
	
	for(cnt=0 ; cnt<11 ;cnt++){
		if(team_array[j].mainplayers[cnt].mainpost == 'A'){

			attackavg2 += team_array[j].mainplayers[cnt].avg;

  }

}

	
	attackavg1 /= ((team_array[i].system) % 10);
	attackavg2 /= ((team_array[j].system) % 10);
	middleavg1 /= (((team_array[i].system) / 10 )% 10);
	middleavg2 /= (((team_array[j].system) / 10 )% 10);
	defensiveavg1 /= (((team_array[i].system) / 100 )% 10) + 1;
	defensiveavg2 /= ((team_array[j].system) / 100 % 10) + 1;
	

	const int resault = ((attackavg1 + middleavg1 - defensiveavg2 -80) / 4) * 10 + ((attackavg2 + middleavg2 - defensiveavg1-80 ) / 4);

	


	
	
	
	for( cnt =0 ; cnt < 11 ; cnt++){
		team_array[i].mainplayers[cnt].fitness -= 2;
	}
	
	for( cnt =0 ; cnt < 11 ; cnt++){
		team_array[j].mainplayers[cnt].fitness -= 2;
	}
		//team1 win
	if( (resault/10) > (resault%10)){
		for(cnt=0 ; cnt<11 ; cnt++){
			if(team_array[i].mainplayers[cnt].mainpost == 'A'){
				team_array[i].mainplayers[cnt].form += 3;
			}
			
			if(team_array[j].mainplayers[cnt].mainpost == 'D'){
				team_array[j].mainplayers[cnt].form -= 3;
			}
		}
		
		team_array[i].stand.win += 1;
		team_array[i].stand.score += 3;
		team_array[i].stand.goalsF += (resault/10);
		team_array[i].stand.goalsA += (resault%10);
		team_array[j].stand.lose += 1;
		team_array[j].stand.goalsF += (resault%10);
		team_array[j].stand.goalsA += (resault/10);
	}
	
		//team2 win
	if( (resault/10) < (resault%10)){
		for(cnt=0 ; cnt<11 ; cnt++){
			if(team_array[j].mainplayers[cnt].mainpost == 'A'){
				team_array[j].mainplayers[cnt].form += 3;
			}
			
			if(team_array[i].mainplayers[cnt].mainpost == 'D'){
				team_array[i].mainplayers[cnt].form -= 3;
			}
		}
		
		team_array[j].stand.win += 1;
		team_array[j].stand.score += 3;
		team_array[j].stand.goalsF += (resault%10);
		team_array[j].stand.goalsA += (resault/10);
		team_array[i].stand.lose += 1;
		team_array[i].stand.goalsF += (resault/10);
		team_array[i].stand.goalsA += (resault%10);
	}
	
	//resault equal
	if( (resault/10) == (resault%10)){
		team_array[i].stand.score += 1;
		team_array[j].stand.score += 1;
		team_array[i].stand.draw += 1;
		team_array[j].stand.draw += 1;
		team_array[i].stand.goalsF += (resault/10);
		team_array[j].stand.goalsF += (resault%10);
		team_array[i].stand.goalsA += (resault%10);
		team_array[j].stand.goalsA += (resault/10);
	}
	


	return  resault; 

}


void proceed(int n){
	int num = (int)n - 48;
	saveResultGames(num);

}


	

int main(){

	game_start();
//	schedule();
	
//	table();
//	saveResultGames( n);
//	
//	table();

	while(1){
	int proceedNum = 0;
	char *input;

	input =(char *) calloc(15 , sizeof(char));

	puts("Please Insert Correct Order :");
	scanf("%s",input);

	
			
		if( !strcmp(input , "lineup") ){
			lineup();
		}
		
		
		if( !strcmp(input , "save") ){
			save();
		}
		
		

		if(!strcmp(input , "proceed") ){
			getchar();
			int entrance = getchar();
			
			if(entrance == '\n'){
				proceed('1');
				
			}
			
	
		
			else{
				proceed(entrance);
			}
			
}
		
		if(!strcmp(input , "exit")){
			return 0;
		}

}

}


