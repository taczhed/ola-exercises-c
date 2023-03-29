#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
 
int main(int argc, char *argv[])
{

    char *sortType = argv[1];
    char *dataFile = argv[2];

    if (argc < 3) {
        printf("Za mało parametrów\n");
        return -1;
    }

    FILE *file;
    int arraySize;

    file = fopen("dane.txt", "r"); // otwiera plik

    fscanf(file, "%d", &arraySize); // wczytuje pierwszą linię

    int array[arraySize]; // tablica o rozmiarze pobranym z pierwszej lini
    
    for (int i = 0; i < arraySize; i++) { // wczytuje drugą linię i wrzuca elementy do tablicy array
        fscanf(file, "%d", &array[i]);
    }

    fclose(file); // zamyka plik

    printf("Przed sortowaniem:\n");

    for (int i = 0; i < arraySize; i++) { // przed
        printf("%d ", array[i]);
    }

    int sl = 0;
    int swbr = 0;

    clock_t start_t, end_t, total_t;

    start_t = clock();

    for (int i = 0; i < arraySize; i++) { // przed
        sl += array[i];

        if (i < arraySize - 1) {
            swbr += abs(array[i + 1] - array[i]);
        }
    }

    if (strcmp(sortType, "babelkowe") == 0) { // strcmp -> porównaj ze sobą dwa ciągi znaków, jeśli takie same zwraca 0

        for (int k = 0; k < arraySize; k++) {
            for (int i = 0; i < arraySize; i++) {
                if (i < arraySize - 1) { // jeżeli nie jestesmy na koncu teblicy
                    if (array[i + 1] < array[i]) { //zamień
                        int temp = array[i];
                        array[i] = array[i + 1];
                        array[i + 1] = temp;
                    }
                }
            }
        }
        printf("\n");

    } else if (strcmp(sortType, "wstawianie") == 0) {

        printf("tutaj bedzie wstawianie\n");

    } else if (strcmp(sortType, "ekstremum") == 0) {

        printf("tutaj bedzie ekstremum\n");

    } else if (strcmp(sortType, "shell") == 0) {

        printf("tutaj bedzie shell\n");

    } else if (strcmp(sortType, "stogowe") == 0) {

        printf("tutaj bedzie stogowe\n");

    } else if (strcmp(sortType, "szybkie") == 0) {

        printf("tutaj bedzie szybkie\n");

    }

    printf("Po sortowaniu: \n");

    for (int i = 0; i < arraySize; i++) { // po
        printf("%d ", array[i]);
    }

    printf("\n");

    end_t = clock();
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;

    printf("SL: %d\n", sl);
    printf("SWBR: %d\n", swbr);
    printf("Czas: %ld ms\n", total_t);

    return 0;
}