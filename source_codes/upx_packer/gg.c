#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checker = 0;

int main() {
	int i, len, counter = 0;
	char foo[13];
	
	printf("Enter key please !\n"); scanf("%s", &foo);


	len = strlen(foo);
	if (len != 0xc){
		printf("wrong !\n");
		exit(1);
	}

	for(i=0; i<len; i++){
		
		if((i % 4 == 0) && i != 0){
			if((int)foo[i] != 0x2d){
				checker = 1;
			}
		}
		if ( i < 4){
			if ( (int)foo[i] < 0x41 || (int)foo[i] > 0x50){
				checker = 1;
			}
		}
		else if ( i > 4 && i < 8){
			if ( (int)foo[i] < 0x30 || (int)foo[i] > 0x39){
				checker = 1;
			}
		}
		else if ( i > 8){
			if ( (int)foo[i] < 0x70 || (int)foo[i] > 0x7a){
				checker = 1;
			}
		}

		
	}

	if (checker != 0){
		fprintf(stderr, "%s\n", "Zaaarrrrttttt!");
		exit(1);
	}

	printf("%s\n", "You got it !\n");

	return 0;
}
