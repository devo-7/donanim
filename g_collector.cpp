#include <stdio.h>
#include <stdlib.h>
 
int main(void) {
    size_t adet = 3;
    int *olcumler = malloc(adet * sizeof *olcumler);
    if (olcumler == NULL) {
        fprintf(stderr, "Bellek ayrilamadi.\n");
        return EXIT_FAILURE;
    }
 
    olcumler[0] = 18;
    olcumler[1] = 20;
    olcumler[2] = 22;
 
    size_t yeni_adet = 5;
    int *gecici = realloc(olcumler,
                         yeni_adet * sizeof *olcumler);
    if (gecici == NULL) {
        fprintf(stderr, "Bellek buyutulemedi.\n");
        free(olcumler);
        return EXIT_FAILURE;
    }
    olcumler = gecici;
    olcumler[3] = 24;
    olcumler[4] = 26;
    adet = yeni_adet;
 
    int toplam = 0;
    for (size_t i = 0; i < adet; ++i) {
        printf("%d ", olcumler[i]);
        toplam += olcumler[i];
    }
    printf("\nOrtalama: %.2f\n", (double)toplam / adet);
 
    free(olcumler);
    olcumler = NULL;
    return EXIT_SUCCESS;
}

