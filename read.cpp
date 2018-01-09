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
}player;
typedef struct infoteams{
	char *name;
	player *p;
}teams;
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
void ReadFromFile(void){
	FILE *fp=fopen("Iran.csv","r");
	char q[100];
	char p[100];
	char mainpost;
	char name[100];
	player array[40];
	int num, i=0,age;
	
	for( i=0;fgets(q,100,fp)!=NULL;i++){
		RemoveChars(q,',');
		sscanf(q,"%d %s %s %d %c",&num , q  , p , &age,&mainpost);
		array[i].num = num;
		array[i].age=age;
		array[i].mainpost=mainpost;
		strcat(q,p);
		strcpy(array[i].playername,q);
				
	//	printf("num=%d		%s       age=%d    mainpost=%c\n",num,q,age,mainpost);
	}
	for(int i=0;i<33;i++){
		printf("num=%d 	  name=%s 	 age=%d 	 mainpost=%c\n",array[i].num,array[i].playername,array[i].age,array[i].mainpost);
	}
/*	fseek(fp,0,SEEK_SET);
	
	for(i=0 ; fgets(q,100,fp)!=NULL ; i++){
		//name=(char*)calloc(30,sizeof(char));
		
		
	}*/
	
	
	fclose(fp);
}
int main(){
	ReadFromFile();
}
