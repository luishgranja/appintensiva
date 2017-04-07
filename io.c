#include <stdio.h>
#include <stdlib.h>
#include "fileutil.h"




int main(int argc, const char** argv){
	
		
		printf("Estudiante_1: 201533329\n");
		printf("Total archivos: %d\n",archivos(argv[1]));
		printf("Total bytes: %d\n ",tamanoDir( argv[1]));
		return 0;
}
