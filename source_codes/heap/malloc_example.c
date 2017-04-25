#include <stdio.h>
#include <stdlib.h>

typedef struct hacktrick{
	int number;
	char describe[20];
}HT;

void main(void){
	malloc(1024);
	
	HT *A,*B,*C;
	
	A = malloc(sizeof(HT));
	A->number = 1;
	gets(A->describe);

	B = malloc(sizeof(HT));
	B->number = 2;
	gets(B->describe);
	
	C = malloc(sizeof(HT));
	C->number = 3;
	gets(C->describe);
		
	malloc(1024);
	
	free(C);
	free(B);
	free(A);



}
