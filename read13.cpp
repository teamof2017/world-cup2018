#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#include <time.h>
#include <windows.h>

void showTeamList();

typedef struct teamplayer{
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




typedef struct infoteams{
	char name[30];
	int system;
	char group;
	int placeInGroup;
	char confedration[20];
	int seed;
    char filename[40];
	int numberOfPlayer;
	float power;
	players mainplayers[11];
	players storeplayers[50];
	players playerinfo[60];
} teams;




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
		perror("file open");
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
		}
		team_array[count].numberOfPlayer = i;
		fclose(fpo);
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


void systemOfTeam(){
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
	int flag = 0;
	puts("Do you want to change your team system?\n1.No\n2.Yes");
	scanf("%d",&flag);
	
	if(flag == 2){
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
}
	while( n>7 && n<1 && flag == 2){
		puts("Your number is incorrect Please try again!");
		scanf("%d",&n);
	}

	
	switch (n){
		case 1:
			team_array[team_number -1].system = 352;
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
	puts("                                        ******************");
	puts("                                       ********************");
	puts("                                      **********************");
	puts("                                     ************************");
	puts("                                    **************************");
	puts("                                   ****************************");
	puts("                                  ******************************");
	puts("                                 ********************************");
	puts("                                **********************************");
	puts("                               ************************************");
	puts("                              **************************************");
	puts("                              **************************************");
	puts("                              **************************************");
	puts("                               ************************************");
	puts("                                **********************************");
	puts("                                 ********************************");
	puts("                                  ******************************");
	puts("                                   ****************************");
	puts("                                    **************************");
	puts("                                     ************************");
	puts("                                      *********************");
	puts("                                       *******************");
	puts("                                        *****************");
	puts("                                         ***************");
	puts("                                          *************");
	puts("                                           ***********");
	puts("                                           ***********");
	puts("                                           ***********");
	puts("                                          *************");
	puts("                                         ***************");
	puts("                                        *****************");
	
	puts("                                        *******************************");
	puts("                                  ****************************************");
	puts("                             ***********************************************");
	puts("                            ***************************************************");
	puts("                          *******************************************************");
	puts("                       ************************************************************");
	puts("                      ***************************************************************");
	puts("                   *******************************************************************");
	puts("                  *********************************************************************");
	puts("                  *********************************************************************");
	puts("                  *********************************************************************");
	puts("                  *********************************************************************");
	puts("                  ********************************************************************");
	puts("                   ******************************************************************");
	puts("                    ****************************************************************");
	puts("                     **************************************************************");
	puts("                      ***********************************************************");
	puts("                       ********************************************************");
	puts("                         ****************************************************");
	puts("                           ************************************************");
	puts("                             ***************************************");
	puts("                                       *******************");
	puts("                                      *********************");
	puts("                                     ***********************");
	puts("                                    *************************");
	puts("\n                                           RUSSIA 2018\n\n\n");
}

int search_player(players player_number, int x)
{
	if(x == 1) {
		int cnt = 0;
		for (cnt = 0; cnt < 11; cnt++) {
			if (team_array[cnt].mainplayers[cnt].num == player_number.num);
				return cnt;
		}
	}
	
	else if(x == 2) {
		int count = 0;
		for (count = 0; count < team_array[team_number].numberOfPlayer - 11; count++) {
			if (team_array[count].mainplayers[count].num == player_number.num)
				return count;
		}
	}
}

void change()
{
	players main_player, store_player;
	scanf("%d %d", &main_player.num, &store_player.num);
	int main_player_element = search_player(main_player, 1);
	int store_player_element = search_player(store_player, 2);
	
	teams tmp;
	
	//changing numbers
	//tmp.num = main_player.num;
	tmp.mainplayers[main_player_element].num = team_array[team_number].mainplayers[main_player_element].num;
	//main_player.num = store_player.num;
	team_array[team_number].mainplayers[main_player_element].num = team_array[team_number].storeplayers[store_player_element].num;
	//store_player.num = tmp.num;
	team_array[team_number].storeplayers[store_player_element].num = tmp.mainplayers[main_player_element].num;
	
	//keeping skills
	//tmp.skill = main_player.skill;
	tmp.mainplayers[main_player_element].skill = team_array[team_number].mainplayers[main_player_element].skill;
	//main_player.skill = store_player.skill;
	team_array[team_number].mainplayers[main_player_element].skill = team_array[team_number].storeplayers[store_player_element].skill;
	//store_player.skill = tmp.skill;
	team_array[team_number].storeplayers[store_player_element].skill = tmp.mainplayers[main_player_element].skill;
	
	//keeping fitness
	//tmp.fitness = main_player.fitness;
	tmp.mainplayers[main_player_element].fitness = team_array[team_number].mainplayers[main_player_element].fitness;
	//main_player.fitness = store_player.fitness;
	team_array[team_number].mainplayers[main_player_element].fitness = team_array[team_number].storeplayers[store_player_element].fitness;
	//store_player.fitness = tmp.fitness;
	team_array[team_number].storeplayers[store_player_element].fitness = tmp.mainplayers[main_player_element].fitness;
	
	//keeping form
	//tmp.form = main_player.form;
	tmp.mainplayers[main_player_element].form = team_array[team_number].mainplayers[main_player_element].form;
	//main_player.form = store_player.form;
	team_array[team_number].mainplayers[main_player_element].form = team_array[team_number].storeplayers[store_player_element].form;
	//store_player.form = tmp.form;
	team_array[team_number].storeplayers[store_player_element].form = tmp.mainplayers[main_player_element].form;
	
	//keeping name
	//tmp.playername = strcpy(tmp.playername, main_player.playername);
	strcpy(tmp.mainplayers[main_player_element].playername, team_array[team_number].mainplayers[main_player_element].playername);
	//main_player.playername = strcpy(main_player.playername, store_player.playername);
	strcpy(team_array[team_number].mainplayers[main_player_element].playername, team_array[team_number].storeplayers[store_player_element].playername);
	//store_player.playername = strcpy(store_player.playername, tmp.playername);
	strcpy(team_array[team_number].storeplayers[store_player_element].playername, tmp.mainplayers[main_player_element].playername);
	
	//changing post
	//main_player.post = main_player.mainpost;
	team_array[team_number].mainplayers[main_player_element].post = team_array[team_number].mainplayers[main_player_element].mainpost;
	//store_player.post = store_player.mainpost;
	team_array[team_number].storeplayers[store_player_element].post = team_array[team_number].storeplayers[store_player_element].mainpost;
	//store_player.post = main_player.post;
	team_array[team_number].storeplayers[store_player_element].mainpost = team_array[team_number].mainplayers[main_player_element].post;
}

void typeInConsole(char sentence[])
{
	int cnt = 0;
	for (cnt = 0; cnt < strlen(sentence); cnt++) {
		printf("%c", sentence[cnt]);
		Sleep(80);
	}
}

void lineup(int team_number)
{
	
	
	
	
}

int  game_start()
{
	//printBall();
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




void playerSkill(){
	float sum=0;
	srand( time (NULL));
	for(int i=0; i<32 ;i++){
		for(int j=0 ; j<team_array[i].numberOfPlayer ; j++){
			
			team_array[i].playerinfo[j].skill = rand() % 50 + 50;
			team_array[i].playerinfo[j].form = rand() % 10 + 90;
			team_array[i].playerinfo[j].fitness = rand() % 30 +70;
			team_array[i].playerinfo[j].avg=(team_array[i].playerinfo[j].skill+team_array[i].playerinfo[j].form+team_array[i].playerinfo[j].fitness)/3;
			sum+=team_array[i].playerinfo[j].avg;
			
		}
		sum /= team_array[i].numberOfPlayer;
		team_array[i].power = sum;
		sum=0;
	}
}


void print_players(){
	
	puts("\n\t MAIN PLAYERS:");
	puts("NUM        NAME                         SKILL    FITNESS    FORM    MAINPOST    POST");
	
	for(int i=0 ; i<11 ; i++){
		printf("%2d.%-20s%4d%4d%4d%4c%4c\n",team_array[team_number].mainplayers[i].num , team_array[team_number].mainplayers[i].playername , team_array[team_number].mainplayers[i].skill , team_array[team_number].mainplayers[i].fitness , team_array[team_number].mainplayers[i].form , team_array[team_number].mainplayers[i].mainpost , team_array[team_number].mainplayers[i].post);
	}
	
	int j = team_array[team_number].numberOfPlayer - 11;
	
	puts("\n\t STORE PLAYERS:");
	puts("NUM        NAME                         SKILL    FITNESS    FORM    MAINPOST    POST");

	for(int i=0 ; i<j ; i++){
		printf("%2d.%-20s%4d%4d%4d%4c%4c\n",team_array[team_number].storeplayers[i].num , team_array[team_number].storeplayers[i].playername , team_array[team_number].storeplayers[i].skill , team_array[team_number].storeplayers[i].fitness , team_array[team_number].storeplayers[i].form , team_array[team_number].storeplayers[i].mainpost , team_array[team_number].storeplayers[i].post);
	}
	
	
}


void save(){
	 FILE *filesave = fopen( "output.txt" , "w");

	for(int cnt =0 ; cnt < 32 ; cnt++){

		fprintf(filesave , "     %s\n" ,  team_array[cnt].name );
		fprintf(filesave , "system =  %d\n" ,  team_array[cnt].system );
		fprintf(filesave , "group = %c\n" ,  team_array[cnt].group );
		fprintf(filesave , "%d , %d\n" , cnt+1 , team_array[cnt].numberOfPlayer );
		fprintf(filesave , "%d , %f\n" , cnt+1 , team_array[cnt].power );
		fprintf(filesave , "%d , %d\n" , cnt+1 , team_array[cnt].seed );
		fprintf(filesave , "%d , %s\n" , cnt+1, team_array[cnt].confedration );
		puts("\n\n");

		//fprintf(filesave , "%d" , cnt);		

		/*for( int i = 0 ; i < 11 ; i++){
		
			fprintf(filesave , "%d.%s", i , team_array[cnt].mainplayers[i] );
			
}			
			puts("\n\n");

		for(int i = 0 ; i < team_array[cnt].numberOfPlayer - 11 ; i++){
			
			fprintf(filesave , "%d.%s", i , team_array[cnt].storeplayers[i] );
		}*/
		
		puts("\n\n");

}
		fclose(filesave);

}




	

int main(){
	
	ReadFromFileTeaminfo();
	ReadFromFilePlayerinfo();

	game_start();
	systemOfTeam();
	/*for(int cnt = 0 ; cnt <32 ; cnt++)
		printf("%d\n",team_array[cnt].system);
*/
	//print_seed();
	//print_seed();
	int n=0;
	//print_seed();
	//print_group();
	
	playerSkill();

	
	while(1){
	int proceedNum = 0;
	char *input;
	char *input2;
	input =(char *) calloc(15 , sizeof(char));
	input2 =(char *) calloc(15 , sizeof(char));
	puts("Please Insert Correct Order :");
	scanf("%s",input);

	//sscanf( input2,"%s%d", input ,&proceedNum);
	
			
		if( !strcmp(input , "lineup") ){
			puts("lineup");
		}
		
		
		if( !strcmp(input , "save") ){
		
			save();

		}
		
		
		if(!strcmp(input , "proceed") ){
			//if(fgets(input2 , 20 , stdin)!= NULL)
			scanf("%d" , &proceedNum);
		
			/*else{
				proceedNum = 1;
			}*/
			
			printf("%d\n", proceedNum);

				}
		
		if(!strcmp(input , "exit")){
			return 0;
		}
	}

//	systemOfTeam(i);
	
		//print_group();

	//print_seed();
	//print_group();
	//print_groups();
	playerSkill();
	
	



	


}