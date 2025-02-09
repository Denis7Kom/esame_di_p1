#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char *nome;
    char *produttore;
    float prezzo;
    int anno;
}automobile;

automobile *crea_automobile();
void salva_automobile (automobile*);

int main(){
    automobile *a;

    a = crea_automobile();

    salva_automobile(a);
    return 0;
}

automobile *crea_automobile(){ // "*" ci vuole perché vogliamo restituire un puntatore per la struttura di tipo "automobile"
    char nome[20];
    char produttore[30];

    automobile *a = malloc(sizeof(automobile));
    if (a == NULL)
        exit(1);
    
    puts("Dammi nome della macchina, subito! ");
    scanf("%19s", nome);
    a->nome = malloc(strlen(nome)*(sizeof(char)+1));
    if (a->nome == NULL)
        exit(1);
    strcpy(a->nome, nome);

    puts("Dammi produttore della macchina, subito! ");
    scanf("%29s", produttore);
    a->produttore = malloc(strlen(produttore)*(sizeof(char)+1));
    if (a->produttore == NULL)
        exit(1);
    strcpy(a->produttore, produttore);

    puts("Dammi anno della macchina, subito! ");
    scanf("%d", &a->anno);
    puts("Dammi prezzo della macchina, subito! ");
    scanf("%f", &a->prezzo);

    return a;
}

void salva_automobile(automobile *a){
    FILE *f = fopen("automobile.txt", "a");
    if (f == NULL)
        exit(1);
    fprintf(f, "%s\n", a->nome);
    fprintf(f, "%s\n", a->produttore);    
    fprintf(f, "%d\n", a->anno);
    fprintf(f, "%.2f\n", a->prezzo);
    fclose(f);
    free(a->produttore);
    free(a->nome);
    free(a);
}