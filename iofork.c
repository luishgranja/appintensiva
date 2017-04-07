 
#include <stdio.h>
#include "fileutil.h"
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, const char** argv){	

	const char ** arreglo;
	int length;
	arreglo = (const char **) malloc(5000 * sizeof(const char *));
	length = archivos(argv[1]);
    arreglo = list(argv[1]);
	int i, count=0;	
	int pid;
	int fd[2];
	pipe(fd);
	if ((pid = fork())) {
		int counth;
		close(fd[1]);
		for (i = 1; i <= (length/2) ;i++) {
			count = count + tamanoArchivo(arreglo[i]);
		}	
		printf("Estudiante_1: 201533329\n");
		printf("Total archivos: %d\n",length);
		read(fd[0],&counth,sizeof(counth));
		printf("Total bytes: %d\n",(count+counth));
		
	}else {
				
		close(fd[0]);
		
		for (i = (length/2)+1; i <= length;i++){
		count = count + tamanoArchivo(arreglo[i]);
		}
		
		write(fd[1],&count,sizeof(count));
		
}
		
		

return 0;

		}



