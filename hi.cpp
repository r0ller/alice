#include "hilib.h" 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){

	FILE *fp;
	char command[4096],line[256],script[4096]="";
	const char *translation;

	//TODO:Environment variables should be taken from config file (DB table read by the library on first call)
//	putenv("source=.");
//	putenv("target=.");
	fgets(command,4096,stdin);
	while(command[0]!='\n'){
		translation=hi(command);
		if(!translation)printf("Invalid command\n");
		else{
			sprintf(script,"#!/usr/pkg/bin/bash\n%s",translation);
//			fp=popen(script,"r");
//			printf("%s\n",script);
//			while(fgets(line,sizeof line,fp))
//			{
//				printf("%s",line);
//			}
//			pclose(fp);
			fp=fopen("script","w");
			fprintf(fp,"%s",script);
			fclose(fp);
			fp=popen("./script","r");
			pclose(fp);
		}
	//printf("$source=%s\n",getenv("source"));
	fgets(command,4096,stdin);
	}
}
