#include <stdio.h>
#include <stdlib.h>


typedef struct prototype{
	char buffer[8];
	struct prototype* fd;
	struct prototype* bk;
}P;



void unlink(P* chunk){
	P* BK;
	P* FD;
	BK=chunk->bk;
	FD=chunk->fd;
	FD->bk=BK;
	BK->fd=FD;
}



int main(int argc, char *argv[]){
	malloc(1024);

	P* first  = (P*)malloc(sizeof(P));	
	P* second = (P*)malloc(sizeof(P));
	P* third  = (P*)malloc(sizeof(P));
	P* fourth = (P*)malloc(sizeof(P));
	
	first->fd = second;
	
	second->bk = first;
	second->fd = third;
	
	third->bk = second;
	third->fd = fourth;
	
	fourth->bk = third;	


	

	
	strncpy(first->buffer, "AAAAAAAA", 8); 
	strncpy(second->buffer,"BBBBBBBB", 8);
	strncpy(third->buffer, "CCCCCCCC", 8);
	strncpy(fourth->buffer,"DDDDDDDD", 8);
	
	unlink(fourth);
	unlink(third);
	unlink(second);
	unlink(first);
	
	return 0;

}

