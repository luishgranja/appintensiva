#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <sys/param.h>



int tamanoArchivo(const char* nomArchivo) {
	// Definicion e inicializacion de variables
	
	FILE *archivo;
	//Variable que cuenta
	int count = 0;

	// Se abre el archivo y se contara caracter por caracter el numero
	// de bytes del archivo
	archivo = fopen(nomArchivo,"r");
	if (archivo == NULL) {
		perror("No se pudo abrir archivo\n");
		return -1;
	}
	while (fgetc(archivo) != EOF) {
		count++;
	}
	
	fclose(archivo);
	return count;
}

int archivos(const char* path) {

struct dirent *directory;
DIR *pdirectory;
struct stat fileinfo;
int contador = 0;

if ((pdirectory = opendir(path)) == NULL) {

            printf("Error: Unable to open directory\n");
            exit(0);
    }

    chdir(path);
    while ((directory=readdir(pdirectory)) != NULL)
    {

        if (!stat(directory->d_name,&fileinfo))
        {
            if (S_ISREG(fileinfo.st_mode))
            {
				contador++;
			}
		}
	}
	closedir(pdirectory);
    return contador;
}



const char ** list(const char* path) {
struct dirent *directory;
DIR *pdirectory;
struct stat fileinfo;
int contador = 0;
const char **arreglo;
char * concatenador;
arreglo = (const char **)malloc(250*sizeof(const char **));


if ((pdirectory = opendir(path)) == NULL) {
	
	    printf("Error: Unable to open directory\n");
        exit(0);
    }

    chdir(path);
    while ((directory=readdir(pdirectory)) != NULL)
    {

        if (!stat(directory->d_name,&fileinfo))
        {
            if (S_ISREG(fileinfo.st_mode))
            {
			  concatenador = (char *)malloc(strlen(path)+1+strlen(directory->d_name) * sizeof(char *));
              strcpy(concatenador,path);
              strcat(concatenador,"/");
              strcat(concatenador,directory->d_name);
              contador++;
              arreglo[contador] = (const char *)malloc(sizeof(const char) * strlen(directory->d_name));
              arreglo[contador] = concatenador;
            }
            }


    }
closedir(pdirectory);

    return arreglo;

        

   }
   

int tamanoDir(const char* dir){
	
	const char ** arreglo;
	int length;
	int contador=0;
	arreglo = (const char **) malloc(5000 * sizeof(const char *));
	length = archivos(dir);
    arreglo = list(dir);
    
    for(int i=1;i<=length;i++){
		
		contador = contador + tamanoArchivo(arreglo[i]);
	
	}
    
	return contador;
}


