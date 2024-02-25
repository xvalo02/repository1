#include <stdio.h>
#include <math.h>
int main() 
{
    double pozicka;
    printf("Zadajte vysku pozicky: ");
    scanf("%lf", &pozicka);
    
    if(pozicka<=20000){
        printf("Na pozicku %.2lf je potrebne zaplatit prvu splatku %.2lf eur", pozicka, pozicka * .01);
    }
    else if(pozicka > 20000 && pozicka <= 49999.99) {
        printf("Na pozicku %.2lf je potrebne zaplatit prvu splatku %.2lf eur", pozicka, pozicka * .02 + 200);
    }
    else if(pozicka >= 50000 && pozicka <= 150000) {
        printf("Na pozicku %.2lf je potrebne zaplatit prvu splatku %.2lf eur", pozicka, pozicka * .03 + 800);
    }
    else {
        printf("Banka neposkytuje pozicky nad 1500000");
    }
    return 0;
}
