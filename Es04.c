#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 30

typedef struct {
    char *str;
    int dim;
} record;

int concatena(char *str1, char *str2, record *);

void leggidaFILE (char *nomeFile, record *rec);

int main() {
    char str1[MAX], str2[MAX];
    record *rec = malloc(sizeof(record));

    if (rec == NULL) {
        printf("Errore nell'allocazione della memoria per il record.\n");
        return 1;
    }

    rec->str = NULL;
    rec->dim = 0;

    printf("Dammi le due stringhe:\n");
    scanf("%s", str1);
    scanf("%s", str2);

    int dim_str = concatena(str1, str2, rec);
    printf("Lunghezza della stringa concatenata: %d\n", dim_str);

    leggiDaFile("file.txt", rec);

    printf("Il contenuto del record è: %s \nDi lunghezza: %d\n", rec->str, rec->dim);

    free(rec->str);
    free(rec);
    return 0;
}

int concatena (char *s1, char *s2, record *rec){
    int size_s1 = strlen(s1);
    int size_s2 = strlen(s2);
    int size_max = size_s1 + size_s2 + 1;
    char s1s2[size_max];
    char rec->str = malloc(size_max*sizeof(char));
    if (rec->str == NULL)
        exit(1);
    strcpy(s1s2, s1);
    strcat(s1s2, s2);
    strcat(rec->str, s1s2);
    rec->dim = size_max-1;
    return size_max-1;
}

void leggidaFILE(char *nomeFile, record *rec){
    
}