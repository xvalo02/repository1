#include <stdio.h>

// Zistenie ci je rok prestupny
int je_priestupny(int rok) {
    if ((rok % 4 == 0 && rok % 100 != 0) || (rok % 400 == 0)) {
        return 1; // Ked neni, vrati 1
    }
    else {
        return 0; // Ked je, vrati 2
    }
}

// Vytvorenie kalendara fukciou pre dany rok zacinajuci urcitym dnom v jan.
void urob_kalendar(int rok, int den_januar) {
    // Pole obsahujúce názvy mesiacov
    char* mesiace[] = { "Január", "Február", "Marec", "Apríl", "Máj", "Jún", "Júl", "August", "September", "Október", "November", "December" };

    // Pocet dni v mesiacoch(bez prestup. roka)
    int dni_v_mesiaci[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // Prisposobenie prestup. roka
    if (je_priestupny(rok)) {
        dni_v_mesiaci[1] = 29;
    }

    // Vypisanie roka
    printf("\n       %d\n\n", rok);

    // Cyklus pre kazdy mesiac
    for (int mesiac = 0; mesiac < 12; mesiac++) {
        printf("\n       %s\n", mesiace[mesiac]); // Vypise nazov mesiaca
        printf("\n");
        printf(" P  U  S  Š  P  S  N\n"); // Vypise dni v tyzdni
        printf("--------------------\n");

        // Vypise medzeri pred prvym dnom v mes.
        for (int i = 0; i < den_januar; i++) {
            printf("   ");
        }

        // Vypise dni v mesiace
        for (int den = 1; den <= dni_v_mesiaci[mesiac]; den++) {
            printf("%2d ", den); // Na vypisanie dna pouzije 2 znaky

            // Ked je posledny den v tydzni, prejde do noveho riadka
            if ((den + den_januar) % 7 == 0) {
                printf("\n");
            }
        }

        printf("\n");

        // Vypocita prvy den pre dalsi mesiac
        den_januar = (den_januar + dni_v_mesiaci[mesiac]) % 7;
    }
}

int main() {
    int rok, den_januar;
    printf("Zadajte rok, pre ktory sa vytvori kalendar: ");
    scanf("%d", &rok);
    printf("Zadaj den: ");
    scanf("%d", &den_januar);

    // Overenie vstupu
    if (den_januar < 0 || den_januar > 6) {
        printf("CHYBA: Den nieje v rozmadzi 0-6.\n");
        return 1;
    }

    // Vytvori kalender
    urob_kalendar(rok, den_januar);
    return 0;
}