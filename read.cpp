#include<stdio.h>
#include<stdlib.h>
#include <string.h>
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
	char group;
	int placeInGroup;
	char confedration[20];
	int seed;
	char filename[40];
	players *p;
}teams;



char groupArray[20][32];

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
	for(int j=0;j<i;j++){
		printf("%d.Teamname=%10s	  group=%2c 	 place=%3d 	\n confedration=%5s seed=%3d  filename=%10s \n",j+1,team_array[j].name,team_array[j].group,team_array[j].placeInGroup,team_array[j].confedration,team_array[j].seed,team_array[j].filename);
	}
	fclose(fp);
}
void ReadFromFilePlayerinfo(void){
	//for(int count=0;count<32;count++){
		//char file[strlen(team_array[count].filename)+1];
		//strcpy(file,team_array[count].filename);
	FILE *fpo=fopen("Argentina.csv","r");
	if(fpo == NULL)
	puts(" hoooooooooooo");
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
	for(int j=0;j<i;j++){
		printf("num=%3d 	  name=%10s 	 age=%3d 	 mainpost=%2c\n",player_array[j].num,player_array[j].playername,player_array[j].age,player_array[j].mainpost);
	}
	fclose(fpo);
	//printf("\n\n\n\n\n\n\"Team : %s\"\n\n\n\n\n",team_array[count].filename);
	//}
}


void search_group(){
	
	int i=0 , j=0;
	char y = 'A';
	char *x=0;
	int cnt =0 ;
	 x = (char*)calloc(20 , sizeof(char));
	for(cnt=0 ; cnt<32 ; cnt++){
		for(i=0 , j=0 ; i<32 ; i++){
			
			
		if(team_array[i].group == y){

			strcpy(x , (team_array[i].name )) ;
			j++;
			printf("%s\n", x);

			if(j % 4 == 0)
				y++;
				
			if(y > 'G')
			  return;

		}
	
}

		puts("");
}
}



void print_groups(){
	int i=0;
	for(i=0 ; i<32 ;i++){
		
		printf("%s\n", groupArray[i]);
	}	

	}

	

int main(){
	ReadFromFileTeaminfo();

	ReadFromFilePlayerinfo();


	//search_group();
	//print_groups();


}
