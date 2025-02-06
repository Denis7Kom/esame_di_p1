#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char *nome_dispositivo;
    float prezzo;
}dispositivo;

dispositivo* leggi_dispositivi(FILE* fp, int* n);
dispositivo * aggiungi_dispositivo(dispositivo * dispositivi, int* n);
void piu_costoso(dispositivo *dispositivi, int n);
void stampa(dispositivo *dispositivo, int n);

int main(){

    dispositivo *dispositivi;
    int *n;
    FILE *fp = fopen("dispositivi.txt", "r");
    dispositivi = leggi_dispositivi(fp, n);
    stampa(dispositivi, *n);
    piu_costoso(dispositivi, *n);
    fclose(fp);
}
void stampa(dispositivo *dispositivi, int n){
    int i = 0;
    while (i<n){
        printf("%s - %d\n", dispositivi[i].nome_dispositivo, dispositivi[i].prezzo);
        i++;
    }
}
dispositivo* leggi_dispositivi(FILE* fp, int* n){

    char nome_temp[250]; 
    *n = 0;



    dispositivo *LISTA; 
    LISTA = malloc(sizeof(dispositivo));
    
    while (fscanf(fp, "%s", nome_temp) != EOF && strcmp(nome_temp, "fine-lista") != 0){

        LISTA[(*n)].nome_dispositivo = malloc(strlen(nome_temp)+1);
        strcpy(LISTA[(*n)].nome_dispositivo, nome_temp);
        printf("Inserisci il prezzo per %s dispositivo: ", nome_temp);
        scanf("%f", &LISTA[(*n)].prezzo);
        (*n)++;
        LISTA = realloc(LISTA, (*n + 1)*sizeof(dispositivo));
        
    }




    return LISTA;

}
