#include "hilib.h" 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

int main(void){

	FILE *fp;
	char command[4096],line[256],script[8192]="",*emsg=NULL;
	const char *translation;

	fgets(command,4096,stdin);
	emsg=new char[1024];
	while(command[0]!='\n'){
		translation=hi(command,"HUN",emsg);
		if(!translation){
			std::cout<<"Invalid command\n"<<std::endl;
			if(emsg!=NULL){
				std::cout<<emsg<<std::endl;
			}
		}
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
	delete emsg;
}
