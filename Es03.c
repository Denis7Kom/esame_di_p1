#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 8

typedef struct {
    char *lunga;
    char *corta;
    int totale;
} report;

void alloca_parole (char **parole, FILE *fp);
report *maxmin (char **parole);
void stampa(report *r);

int main(int argc, char *argv[]) {
    char *parole[MAX];
    FILE *fp;
    report *r;

    fp = fopen("numeri.txt", "r");
    if (fp == NULL) {
        perror("Errore nell'apertura del file");
        return 1;
    }

    alloca_parole(parole, fp);
    r = maxmin(parole);
    stampa(r);

    free(r->lunga);
    free(r->corta);
    free(r);
    fclose(fp);

    return 0;
}

void alloca_parole (char **parole, FILE *fp){
    int dim = 0;
    for (int i = 0; i < MAX; i++){
        fscanf(fp, "%d", &dim)
        *parole[i] = malloc(sizeof(char)*dim);
        printf("Inserisci una parola di %d caratteri: ", dim);
        scanf("%s", *parole[i]);
        puts("");
    }
}

report *maxmin (char **parole){

    int temp_max = strlen(*parole);
    int temp_min = strlen(*parole);
    report *r_temp = malloc(sizeof(report));
    if (*r_temp == NULL)
        exit(1);

    *r_temp->lunga = malloc(sizeof(char)*temp_max); // se la prossima parola é piú grande, come si fa?
    if (*r_temp->lunga == NULL)
        exit(1);
    *r_temp->corta = malloc(sizeof(char)*temp_min); // se la prossima parola é piú piccola, come si fa?
    if (*r_temp->corta == NULL)
        exit(1);


    for (int i = 1; i < MAX; i++){
        if (strlen(*parole[i]) > temp_max){
            temp_max = strlen(*parole[i]);
            free(*r_temp->lunga);
            *r_temp->lunga = realloc(*r_temp->lunga, temp_max*sizeof(char));
            if (*r_temp->lunga == NULL)
                exit(1);
            *r_temp->lunga = *parole[i];
        }
    } 
    for (int i = 1; i < MAX; i++){
        if (strlen(*parole[i]) < temp_min){
            temp_min = strlen(*parole[i]);
            free(*r_temp->corta);
            *r_temp->corta = realloc(*r_temp->corta, temp_min*sizeof(char));
            if (*r_temp->corta == NULL)
                exit(1);
            *r_temp->corta = *parole[i];
        }
    } 

    *r_temp->totale = temp_max + temp_min;

    return r_temp;
}

