#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char foo[25];
	char *password = "secret_password";
	printf("Please enter your password !\nPassword Entry: "); scanf("%s", &foo);
	if (!strcmp(foo, password)){
		printf("Good Job !\n");
		return -1;
	}
	printf("lol :)\n");
	
	return 0;
	
}

