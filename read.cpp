#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<time.h>
typedef struct teamplayer{
	char playername[40];
	int form;
	int fitness;
	int skill;
	char mainpost;
	char post;
	int num;
	int age;
}players;
typedef struct infoteams{
	char name[30];
	int system;
	char group;
	int placeInGroup;
	char confedration[20];
	int seed;
    char filename[40];
	players *p;
}teams;




teams team_array[32];


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
     		strcpy(filename,token);
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
	char s[32][40]={{"Argentina.csv"},{"Australia.csv"},{"Belgium.csv"},{"Brazil.csv"},{"Colombia.csv"},{"CostaRica.csv"},{"Croatia.csv"},{"Denmark.csv"},{"Egypt.csv"},{"England.csv"},{"France.csv"},{"Germany.csv"},{"Iceland.csv"},{"Iran.csv"},{"Japan.csv"},{"Korea.csv"},{"Mexico.csv"},{"Morocco.csv"},{"Nigeria.csv"},{"Panama.csv"},{"Peru.csv"},{"Poland.csv"},{"Portugal.csv"},{"Russia.csv"},{"SaudiArabia.csv"},{"Senegal.csv"},{"Serbia.csv"},{"Spain.csv"},{"Sweden.csv"},{"Switzerland.csv"},{"Tunisia.csv"},{"Uruguay.csv"}};
	for(int count=0;count<32;count++){
	
	FILE *fpo=fopen(s[count],"r");
	if(fpo == NULL){
	perror("file open");
	}
	char tmp[100];
	char *token;
	char mainpost;
	char name[30];
	players player_array[60];
	int num, i=0,age;
	for( i=0;fgets(tmp,100,fpo)!=NULL;i++){
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
		player_array[i].num = num;
		player_array[i].age=age;
		player_array[i].mainpost=mainpost;
		strcpy(player_array[i].playername,name);
	}
	/*for(int j=0;j<i;j++){
		printf("num=%3d 	  name=%10s 	 age=%3d 	 mainpost=%2c\n",player_array[j].num,player_array[j].playername,player_array[j].age,player_array[j].mainpost);
	}*/
	fclose(fpo);
	//printf("\n\n\n\n\n\n\"Team : %s\"\n\n\n\n\n",team_array[count].filename);
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
			  return;
		
		
		printf("      GROUP   %c\n" , groupName);
		for(i=0 , j=0 ; i<32 ; i++){
			
		if(groupName > 'H')
			  return;
			
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
	
	switch (n){
		case 1:
			team_array[i].system = 352;
			break;
			
		case 2:
			team_array[i].system = 343;
			break;

		case 3:
			team_array[i].system = 442;
			break;

		case 4:
			team_array[i].system = 451;
			break;

		case 5:
			team_array[i].system = 433;
			break;

		case 6:
			team_array[i].system = 541;
			break;

		case 7:
			team_array[i].system = 532;
			break;

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



	

int main(){
	ReadFromFileTeaminfo();

//	ReadFromFilePlayerinfo();
	systemOfTeam(4);


	//print_seed();
	//print_group();
	//print_groups();


	
}
