#include<stdio.h>
#include<stdlib.h>
typedef struct teamplayer{
	char *playername;
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
void ReadFromFile(void){
	FILE *fp=fopen("Iran.csv","r");
	char q[100];
	player p[100];
	for(int i=0;fgets(q,100,fp)!=NULL;i++){
		//fgets(q,100,fp);
		//printf("%s\n",q);
		sscanf(q,"%d %s %d %c",&p[i].num,p[i].playername,&p[i].age,&p[i].mainpost);
	}
	for(int i=0;i<33;i++){
		printf("num=%d  playername=%s  age=%d  mainpost=%c",p[i].num,p[i].playername,p[i].age,p[i].mainpost);
	}
	fclose(fp);
}
int main(){
	ReadFromFile();
}
