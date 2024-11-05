#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITEMS 1000
#define MAX_LENGTH 20

// Função de comparação para a função qsort
int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int N;
    scanf("%d", &N);
    getchar(); // Limpa o newline após o número de casos de teste

    for (int i = 0; i < N; i++) {
        char line[20000]; // Armazena a linha inteira de entrada
        char *items[MAX_ITEMS]; // Armazena ponteiros para cada item
        int item_count = 0;

        fgets(line, sizeof(line), stdin); // Lê a linha de itens

        // Separar itens na linha
        char *token = strtok(line, " \n");
        while (token != NULL) {
            items[item_count++] = strdup(token);
            token = strtok(NULL, " \n");
        }

        // Ordenar os itens
        qsort(items, item_count, sizeof(char *), compare);

        // Remover duplicatas e imprimir
        printf("%s", items[0]);
        for (int j = 1; j < item_count; j++) {
            if (strcmp(items[j], items[j - 1]) != 0) { // Verifica duplicatas
                printf(" %s", items[j]);
            }
        }
        printf("\n");

        // Liberar a memória alocada
        for (int j = 0; j < item_count; j++) {
            free(items[j]);
        }
    }

    return 0;
}
