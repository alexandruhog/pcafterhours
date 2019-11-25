#include <stdio.h>

void PopulareArray (int *a) {
    for (int i = 0; i < 10; i ++) {
        a[i] = i;
    }
}

void AfisareArray(int *a) {
    for (int i = 0; i < 10; i ++) {
        printf("%d ", a[i]);
    }
}

int main() {
    
    int a[10];

    PopulareArray(a);
    AfisareArray(a);

    return 0;

}