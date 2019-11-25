#include <stdio.h>
#include <stdlib.h>

#define NrLinii 3
#define NrColoane 3

void AlocareMatrice (int ***a) { // -> POINTER la o matrice (POINTER la un vector de pointeri <3) => * ** => 3 stelute

// SE PUNE * jos pentru ca vrem sa obtinem ADRESA MATRICII, adica ADRESA STOCATA IN POINTERUL DAT CA SI PARAMETRU

    *a = (int **) malloc (NrLinii * sizeof (int *));

    for (int i = 0; i < NrLinii; i++) {
        (*a)[i] = (int *) malloc (NrColoane * sizeof(int));
    }
}

void PopulareMatrice (int **a) {
    for (int i = 0; i < NrLinii; i++) {
        for (int j = 0; j < NrColoane; j++) {
            a[i][j] = i + j;
        }
    }
}

void AfisareMatrice (int **a) { 
  for (int i = 0; i < NrLinii; i++) {
        for (int j = 0; j < NrColoane; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
int main(){

    int **matrice;

    AlocareMatrice(&matrice); 
    // PopulareMatrice(&(matrice[0]));
    PopulareMatrice(matrice);
    AfisareMatrice(matrice);

    // 1. Vectorul este pointer catre primul sau element
    // 2. Ca sa modifici in memorie in functie este nevoie de pointer
    // 3. Matrice[0] = primul element dintr-un VECTOR de pointeri (int *)


    return 0;
}