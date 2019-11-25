#include <stdio.h>
#include <stdlib.h>

#define NrLinii 3
#define NrColoane 3

int ** AlocareMatrice () { 

    int **a = (int **) malloc (NrLinii * sizeof (int *));

    for (int i = 0; i < NrLinii; i++) {
        a[i] = (int *) malloc (NrColoane * sizeof(int));
    }

    return a;
    //a este POINTER la VECTOR DE POINTERI * la int * => **
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

    matrice = AlocareMatrice(); 
    // PopulareMatrice(&(matrice[0]));
    PopulareMatrice(matrice);
    AfisareMatrice(matrice);

    // 1. Vectorul este pointer catre primul sau element
    // 2. Ca sa modifici in memorie in functie este nevoie de pointer
    // 3. Matrice[0] = primul element dintr-un VECTOR de pointeri (int *)
    
    return 0;
}