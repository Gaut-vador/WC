#include "fonction.h"

int traiter (int fd, int *car, int *mot, int *lig){

	int r;
	char buff[80];
	*car = 0;
	*mot = 0;
	*lig = 0;
	char ch;

	while((r = read(fd, buff, 80)) > 0){
		*car += r;
		while(r >= 0){
			if(buff[r] == '\n'){
				*lig += 1;
			}

		
			if(isspace((ch = buff[r])) && !isspace(ch = buff[r -1]))
				*mot += 1;

			r--;
		}
	}

	return 0;
}