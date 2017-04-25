#include <stdio.h>
#include <sys/ptrace.h>


#define EXIT_FAILURE -1

char password[11] = {0x68, 0x7e, 0x64, 0x4e, 0x76, 0x7e, 0x65, 0x4e, 0x78, 0x65};

int main(int argc, char *argv[]){
	char buffer[11];
	int len;
	
	if (ptrace(PTRACE_TRACEME, 0, 0, 0) != 0){
		fprintf(stderr, "Debugger Detected!\n");
		exit(EXIT_FAILURE);
	}
	
	if(argc != 2){
		fprintf(stderr, "Usage: %s <password> \n");
		exit(EXIT_FAILURE);
	}

	strncpy(buffer, argv[1], 11);
	for(int i=0; i <strlen(argv[1]); i++){
		buffer[i] = buffer[i] ^ 0x11;
	}
	
	if(strcmp(password, buffer) != 0){
		puts("Someting went wrong !");
		exit(EXIT_FAILURE);
	}
	puts("Good job !");
	return 0;
}
