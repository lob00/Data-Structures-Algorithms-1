#include <stdio.h>

int main() {
    int totalDias, anos, meses, dias;

    // Lê o valor total de dias
    scanf("%d", &totalDias);

    // Calcula o número de anos
    anos = totalDias / 365;
    totalDias %= 365;

    // Calcula o número de meses
    meses = totalDias / 30;
    dias = totalDias % 30;

    // Imprime o resultado no formato esperado
    printf("%d ano(s)\n", anos);
    printf("%d mes(es)\n", meses);
    printf("%d dia(s)\n", dias);

    return 0;
}
