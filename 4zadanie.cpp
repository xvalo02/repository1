#include <stdio.h>
#include <stdlib.h>

// Funkcia na zistenie po�tu slov (��sel) v s�bore
int pocet_slov(FILE* subor) {
    int pocet = 0;
    int znak;

    while ((znak = fgetc(subor)) != EOF) {
        if (znak >= '0' && znak <= '9') {
            pocet++;
        }
    }

    rewind(subor); // Vr�ti kurzor na za�iatok s�boru
    return pocet;
}

// Funkcia na dynamick� alok�ciu po�a
int* alokuj_pole(int pocet_slov) {
    return (int*)malloc(pocet_slov * sizeof(int));
}

// Funkcia na na��tanie textu zo s�boru do po�a
void load(FILE* subor, int* text, int pocet) {
    for (int i = 0; i < pocet; i++) {
        fscanf(subor, "%d", &text[i]);
    }
}

// Funkcia na preklad textu pomocou kl��a
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

        // Ak sa ��slo v kl��i nenach�dza, vyp�te medzeru
        if (!najdene) {
            fputc(' ', out);
        }
    }
}

int main() {
    FILE* text_subor, * kluc_subor, * preklad_subor;
    int pocet;
    int* text;

    // Otvor�me s�bory
    text_subor = fopen("text.txt", "r");
    kluc_subor = fopen("kluc.txt", "r");
    preklad_subor = fopen("preklad.txt", "w");

    // Z�skame po�et ��sel (znakov) v s�bore text.txt
    pocet = pocet_slov(text_subor);

    // Alokujeme pole pre na��tan� text
    text = alokuj_pole(pocet);

    // Na��tame text zo s�boru do po�a
    load(text_subor, text, pocet);

    // Na��tame kl��
    int kluc[26][2];
    for (int i = 0; i < 26; i++) {
        fscanf(kluc_subor, "%d %c", &kluc[i][0], &kluc[i][1]);
    }

    // Prelo��me text a zap�eme do s�boru preklad.txt
    preloz(kluc, text, pocet, preklad_subor);

    // Uzavrieme s�bory
    fclose(text_subor);
    fclose(kluc_subor);
    fclose(preklad_subor);

    // Uvo�n�me alokovan� pam�
    free(text);

    return 0;
}
