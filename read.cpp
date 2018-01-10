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
	char name[20];
	char group;
	int placeInGroup;
	char confedration[20];
	int seed;
	char filename[40];
	players *p;
}teams;

teams team_array[32];


void RemoveChars(char *s, char c)
{
    int writer = 0, reader = 0;

    while (s[reader])
    {
    	if(s[reader]==c){
        s[reader]=' ';
		}
        if (s[reader]!=c) 
        {   
            s[writer++] = s[reader];
        }

        reader++;       
    }

    s[writer]=0;
}
void ReadFromFileTeaminfo(void){
	FILE *fp=fopen("Teams.csv","r");
	char tmp[100];
	char TeamName[20];
	char TeamName2[20];
	char group;
	int placeInGroup,seed,i=0;
	char confedration[20];
	char filename[20];
	char filename2[20];
	for( i=0;fgets(tmp,100,fp)!=NULL;i++){
		RemoveChars(tmp,',');
		sscanf(tmp,"%5s %s %c %d %s %d %5s %s", TeamName,TeamName2 , &group  , &placeInGroup , confedration , &seed , filename,filename2 );
		printf("%d. 	name=%s 	  group=%c 	 placeInGroup=%d 	\n 	confedration=%s   seed=%d    filename=%s\n\n\n\n\n\n",i+1,TeamName,group,placeInGroup,confedration,seed,filename);
		strcat(TeamName,TeamName2);
		strcat(filename,filename2);
		strcpy(team_array[i].name , TeamName);
		team_array[i].group=group;
		team_array[i].placeInGroup=placeInGroup;
		strcpy(team_array[i].confedration,confedration);
		team_array[i].seed=seed;
		strcpy(team_array[i].filename,filename);
	}
	puts("\n\n\n\n\n now in array: \n\n\n\n\n");
	for(int j=0;j<i;j++){
		printf("%d. 	name=%s 	  group=%c 	 placeInGroup=%d 	 \n	 confedration=%s   seed=%d    filename=%s\n\n\n\n\n\n\n",j+1,team_array[j].name,team_array[j].group,team_array[j].placeInGroup,team_array[j].confedration,team_array[j].seed,team_array[j].filename);
	}
	printf("\n\n\n\n\n\n\"Teaminfo\"\n\n\n\n\n");
	fclose(fp);
}
void ReadFromFilePlayerinfo(void){
	//for(int count=0;count<32;count++){
	//FILE *fpo=fopen(team_array[count].filename,"r");
	FILE *fpo=fopen("Russia.csv","r");
	char tmp[100];//tmp is temp and first name in this function
	char mainpost;
	char lastname[20];
	players player_array[40];
	int num, i=0,age;
	for( i=0;fgets(tmp,100,fpo)!=NULL;i++){
		RemoveChars(tmp,',');
		sscanf(tmp,"%d %s %s %d %c",&num , tmp  , lastname , &age,&mainpost);
		//printf("num=%d	name=%s %s   age=%d    mainpost=%c\n",num,tmp,lastname,age,mainpost);
		player_array[i].num = num;
		player_array[i].age=age;
		player_array[i].mainpost=mainpost;
		strcat(tmp,lastname);
		strcpy(player_array[i].playername,tmp);
	}
	for(int j=0;j<i;j++){
		printf("num=%d 	  name=%s 	 age=%d 	 mainpost=%c\n",player_array[j].num,player_array[j].playername,player_array[j].age,player_array[j].mainpost);
	}	
	fclose(fpo);
//	printf("\n\n\n\n\n\n\"Team : %s\"\n\n\n\n\n",team_array[count].name);
	//}
}
int main(){
	ReadFromFileTeaminfo();
//	ReadFromFilePlayerinfo();
}
