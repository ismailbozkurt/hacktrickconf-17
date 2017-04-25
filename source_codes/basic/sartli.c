#include <stdio.h>

int main(){
	int unique;
	printf("Bi sey gir lutfen ! : \n") 
	scanf("%d", &unique);
	
	if (unique != 1337){
		fprintf(stderr, "%s\n", "batirdin !");
	}
	
	printf("Nasil anlasiliyor mu ?\n");
	return 0;
}
