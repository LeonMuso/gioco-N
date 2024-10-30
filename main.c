#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int n, nInserito, tent = 0;
    int diff;
    int vite;
    int min, max;
    printf("- 1 Facile \n");
    printf("- 2 Medio \n");
    printf("- 3 Difficile \n");
    printf("- 4 Hardcore \n");
    printf("inserisci la difficolta':");
    scanf("%d", &diff);

    switch (diff) {
        case 1:
            min = 0;
            max = 12;
            vite = 5;
            srand(time(NULL));
            n = rand() % (max - min + 1) + min;
            break;
        case 2:
            min = 0;
            max = 50;
            vite = 3;
            srand(time(NULL));
            n = rand() % (max - min + 1) + min;
            break;
        case 3:
            min = 0;
            max = 100;
            vite = 2;
            srand(time(NULL));
            n = rand() % (max - min + 1) + min;
            break;
        default://4 hardcore
            min = 0;
            max = 150;
            vite = 1;
            srand(time(NULL));
            n = rand() % (max - min + 1) + min;
    }
    printf("indovina il numero nell'intervallo %d-%d \n ", min, max);
    do {
        scanf("%d", &nInserito);
        if (nInserito < min || nInserito > max) {
            printf("numero fuori range riprova\n");
        } else if (nInserito == n) {
            printf("hai vinto!\n");
            tent++;
        } else if (nInserito < n) {
            printf("il numero da indovinare e' piu' grande\n");
            tent++;
            vite--;
            printf("vite rimaste: %d\n \n", vite);
        } else {
            printf("il numero da indovinare e' piu' piccolo\n");
            tent++;
            vite--;
            printf("vite rimaste: %d\n \n", vite);
        }
    } while (nInserito != n && vite != 0);
    if (vite == 0) {
        printf("  -- GAME OVER -- \n");
        printf("hai esaurito le vite \n \n");
        printf("il numero era %d\n", n);
    } else {
        printf("tentativi: %d\n \n", tent);
        printf("vite rimaste: %d\n", vite);
    }
    return 0;
}
