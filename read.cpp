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


char groupArray[20][32];

teams team_array[40];
players player_array[40];





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
	char group;
	int placeInGroup,seed,i=0;
	char confedration[20];
	char filename[40];
	for( i=0;fgets(tmp,100,fp)!=NULL;i++){
		RemoveChars(tmp,',');
		sscanf(tmp,"%s %c %d %s %d %s", TeamName , &group  , &placeInGroup , confedration , &seed , filename );
		//printf("name=%s 	  group=%c 	 placeInGroup=%d 	 confedration=%s   seed=%d    filename=%s\n",TeamName,group,placeInGroup,confedration,seed,filename);
		strcpy(team_array[i].name , TeamName);
		team_array[i].group=group;
		team_array[i].placeInGroup=placeInGroup;
		strcpy(team_array[i].confedration,confedration);
		team_array[i].seed=seed;
		strcpy(team_array[i].filename,filename);
	}
/*	for(int j=0;j<i;j++){
		printf("name=%s 	  group=%c 	 placeInGroup=%d 	 confedration=%s   seed=%d    filename=%s\n",team_array[j].name,team_array[j].group,team_array[j].placeInGroup,team_array[j].confedration,team_array[j].seed,team_array[j].filename);
	}*/
	fclose(fp);
}
void ReadFromFilePlayerinfo(void){
	for(int count=0;count<32;count++){
	FILE *fp=fopen(team_array[count].filename,"r");
	char tmp[100];//tmp is temp and first name in this function
	char mainpost;
	char lastname[20];
	int num, i=0,age;
	for( i=0;fgets(tmp,100,fp)!=NULL;i++){
		RemoveChars(tmp,',');
		sscanf(tmp,"%d %s %s %d %c",&num , tmp  , lastname , &age,&mainpost);
		//printf("num=%d	name=%s %s   age=%d    mainpost=%c\n",num,tmp,lastname,age,mainpost);
		player_array[i].num = num;
		player_array[i].age=age;
		player_array[i].mainpost=mainpost;
		strcat(tmp,lastname);
		strcpy(player_array[i].playername,tmp);
	}
	/*for(int j=0;j<i;j++){
		printf("num=%d 	  name=%s 	 age=%d 	 mainpost=%c\n",player_array[j].num,player_array[j].playername,player_array[j].age,player_array[j].mainpost);
	}*/	
	fclose(fp);
	}
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
	//ReadFromFilePlayerinfo();
	search_group();
	//print_groups();
}
