#include "fonction.h"

int main(int argc, char* argv[]){
	int car= 0, mot = 0, lig = 0;
	int carTot = 0, motTot =0, ligTot=0;


	int l=0;
	int c =0;
	int w = 0;
	int opt;

	while((opt = getopt(argc, argv, "lcw")) != -1){
		switch(opt){
			case 'c':
				c++;
				break;

			case 'l':
				l++;
				break;

			case 'w':
				w++;
				break;

			case '?':
				fprintf(stderr, "usage: %s [-l] [-c] [-w] [chemin de fichier] \n", argv[0]);
				exit(EXIT_FAILURE);
				break;
			default:
			fprintf(stderr, "usage: %s [-l] [-c] [-w] [chemin de fichier] \n", argv[0]);
			exit(EXIT_FAILURE);
		}
	}

	int fd;
	if(optind == argc){
		
		traiter (0, &car, &mot, &lig);
		carTot += car;
		motTot += mot;
		ligTot += lig;
	}
	else{
		while(optind < argc){
		
			fd = open(argv[optind], O_RDONLY);
	
			if (fd == -1){
				perror(argv[optind]);
				//exit(EXIT_FAILURE);
			}
			else{
			  traiter (fd, &car, &mot, &lig);


				carTot += car;
				motTot += mot;
				ligTot += lig;


				if(c>0)
					printf("%d ", car);

				if(l>0)
					printf("%d ", lig);

				if(w>0)
					printf("%d ", mot);

				else
					printf("%d , %d, %d\n", car, mot, lig);

				printf("\n");
			}
			optind ++;
		}
	}
	printf("%d, %d, %d\n", ligTot, motTot, carTot);

	close(fd);

return 0;
}
