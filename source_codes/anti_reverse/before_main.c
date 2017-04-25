#include <stdio.h>
#include <sys/ptrace.h>
#include <crypt.h>

#define EXIT_FAILURE -1

void __attribute__((constructor)) lol(){
	dont_look();
}

int checker(const char *s1, const char *s2){
	for ( ; *s1 == *s2; s1++, s2++)
	if (*s1 == '\0')
	    return 0;
    	return ((*(unsigned char *)s1 < *(unsigned char *)s2) ? -1 : +1);
}


void dont_look(){
	if (ptrace(PTRACE_TRACEME, 0, 0, 0) != 0){
		fprintf(stderr, "Debugger Detected!\n");
		exit(EXIT_FAILURE);
	}
	else {
		char password[10];
		printf("Give a password : "); scanf("%10s", &password);
		
		if(checker("gjx8s949DaqJo", crypt(password, "gj")) == 0){
			printf("Good Job\n");
		}
	}
}

int main(){
	puts("What I am doing tell me !");
	
	return 0;
}


