#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char hehe[11] = "unlocked_me";

int main(int argc, char *argv[]){
	FILE *fp;
	char foo[12];
	char user[12];
	
	puts("Give my password if you wanna come in !"); scanf("%16s", &user);

	if((fp = fopen("key.lol", "r")) == NULL){
		printf("Where is my file !\n");
		exit(1);
	}
	
	if( (fgets(foo, 12, (FILE *)fp)) == NULL ){
		printf("Foolish file couldn't read my bro !\n");
		exit(2);
	}
	
	if (strcmp(foo, hehe) == 0){
		printf("Good job my bro !\n");
	}else{
		printf("Someting goes wrong check it again !\n");
		exit(3);
	}
	
	return 0;
}
