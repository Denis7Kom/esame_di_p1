#include <stdio.h>
#define SIZE 3 // Numero di righe e colonne fisso (3x3)
// Dichiarazione delle funzioni
void leggiMatrice (int (*matrice) [SIZE]);
void calcolaSommaRighe (int (*matrice) [SIZE], int *sommaRighe); void stampaRisultati(int (*matrice) [SIZE], int *sommaRighe);
int main() {
    int matrice [SIZE] [SIZE]; // Matrice 3x3 int sommaRighe [SIZE];
    int sommaRighe[SIZE] = {0};
    // Leggi la matrice
    leggiMatrice (matrice);
    // Array per le somme delle righe
    // Calcola la somma delle righe
    calcolaSommaRighe (matrice, sommaRighe);
    // Stampa la matrice e le somme
    stampaRisultati(matrice, sommaRighe);
    return 0;
}


void calcolaSommaRighe (int (*matrice) [SIZE], int *sommaRighe) {
    int i, j;
    // Inizializza l'array delle somme a zero
    /*for (i = 0; i < SIZE; i++) {
        *(sommaRighe + 1) = 0; // Usa puntatori per accedere all'array somma Righe
    }*/
    
        
    // Calcola la somma degli elementi di ogni riga
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            *(sommaRighe + i) += *(*(matrice + i) + j); // Usa puntatori per sommare
        }
    }
}

 
void leggiMatrice (int (*matrice) [SIZE]) {
    int i, j;
    printf("Inserisci i valori della matrice (%dx%d): \n", SIZE, SIZE);
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("Elemento [%d] [%d]: ", i, j);
            scanf("%d", (*(matrice + i) + j)); // Usa aritmetica dei puntatori
        }
    }
}

// Funzione per stampare la matrice e le somme delle righe 
void stampaRisultati(int (*matrice)[SIZE], int *sommaRighe) {
    int i, j;
    printf("\nMatrice inserita:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d\t", *(*(matrice + i) + j)); // Usa puntatori per stampare
        }
        puts("");
    }
    
    
    printf("\nSomma degli elementi di ciascuna riga:\n");
    for (i = 0; i < SIZE; i++) {
        printf("Riga %d: %d\n", i, *(sommaRighe + i)); // Usa puntatori per stampare
    }
}
