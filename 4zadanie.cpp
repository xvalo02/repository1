#include <stdio.h>
#include <stdlib.h>

// Funkcia na zistenie poètu slov (èísel) v súbore
int pocet_slov(FILE* subor) {
    int pocet = 0;
    int znak;

    while ((znak = fgetc(subor)) != EOF) {
        if (znak >= '0' && znak <= '9') {
            pocet++;
        }
    }

    rewind(subor); // Vráti kurzor na zaèiatok súboru
    return pocet;
}

// Funkcia na dynamickú alokáciu po¾a
int* alokuj_pole(int pocet_slov) {
    return (int*)malloc(pocet_slov * sizeof(int));
}

// Funkcia na naèítanie textu zo súboru do po¾a
void load(FILE* subor, int* text, int pocet) {
    for (int i = 0; i < pocet; i++) {
        fscanf(subor, "%d", &text[i]);
    }
}

// Funkcia na preklad textu pomocou klúèa
void preloz(int kluc[][2], int* text, int pocet, FILE* out) {
    for (int i = 0; i < pocet; i++) {
        int cislo = text[i];
        int najdene = 0;

        for (int j = 0; j < 26; j++) {
            if (kluc[j][0] == cislo) {
                fputc(kluc[j][1], out);
                najdene = 1;
                break;
            }
        }

        // Ak sa èíslo v klúèi nenachádza, vypíšte medzeru
        if (!najdene) {
            fputc(' ', out);
        }
    }
}

int main() {
    FILE* text_subor, * kluc_subor, * preklad_subor;
    int pocet;
    int* text;

    // Otvoríme súbory
    text_subor = fopen("text.txt", "r");
    kluc_subor = fopen("kluc.txt", "r");
    preklad_subor = fopen("preklad.txt", "w");

    // Získame poèet èísel (znakov) v súbore text.txt
    pocet = pocet_slov(text_subor);

    // Alokujeme pole pre naèítaný text
    text = alokuj_pole(pocet);

    // Naèítame text zo súboru do po¾a
    load(text_subor, text, pocet);

    // Naèítame klúè
    int kluc[26][2];
    for (int i = 0; i < 26; i++) {
        fscanf(kluc_subor, "%d %c", &kluc[i][0], &kluc[i][1]);
    }

    // Preložíme text a zapíšeme do súboru preklad.txt
    preloz(kluc, text, pocet, preklad_subor);

    // Uzavrieme súbory
    fclose(text_subor);
    fclose(kluc_subor);
    fclose(preklad_subor);

    // Uvo¾níme alokovanú pamä
    free(text);

    return 0;
}
