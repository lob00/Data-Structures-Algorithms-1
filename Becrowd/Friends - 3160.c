#include <stdio.h>
#include <string.h>

#define MAX_FRIENDS 1000
#define MAX_NAME_LENGTH 20

int main() {
    char current_friends[MAX_FRIENDS][MAX_NAME_LENGTH];
    char new_friends[MAX_FRIENDS][MAX_NAME_LENGTH];
    char target_friend[MAX_NAME_LENGTH];
    
    int current_count = 0;
    int new_count = 0;

    // Lendo a lista atual de amigos como uma linha completa
    char line[10000];
    fgets(line, sizeof(line), stdin);
    
    // Separando os amigos da linha
    char *token = strtok(line, " \n");
    while (token != NULL) {
        strcpy(current_friends[current_count++], token);
        token = strtok(NULL, " \n");
    }

    // Lendo a nova lista de amigos como uma linha completa
    fgets(line, sizeof(line), stdin);
    
    // Separando os novos amigos
    token = strtok(line, " \n");
    while (token != NULL) {
        strcpy(new_friends[new_count++], token);
        token = strtok(NULL, " \n");
    }

    // Lendo o nome do amigo alvo ou "nao"
    fgets(target_friend, sizeof(target_friend), stdin);
    target_friend[strcspn(target_friend, "\n")] = 0; // Remove o newline

    // Encontrando a posição do amigo alvo, se existir
    int target_pos = -1;
    if (strcmp(target_friend, "nao") != 0) {
        for (int i = 0; i < current_count; i++) {
            if (strcmp(current_friends[i], target_friend) == 0) {
                target_pos = i;
                break;
            }
        }
    }

    // Atualizando a lista de amigos
    if (target_pos == -1) {
        // Se não há amigo alvo, adiciona novos amigos ao final
        for (int i = 0; i < new_count; i++) {
            strcpy(current_friends[current_count++], new_friends[i]);
        }
    } else {
        // Insere os novos amigos antes do amigo alvo
        for (int i = current_count - 1; i >= target_pos; i--) {
            strcpy(current_friends[i + new_count], current_friends[i]);
        }
        for (int i = 0; i < new_count; i++) {
            strcpy(current_friends[target_pos + i], new_friends[i]);
        }
        current_count += new_count;
    }

    // Imprimindo a lista atualizada de amigos
    for (int i = 0; i < current_count; i++) {
        printf("%s", current_friends[i]);
        if (i < current_count - 1) printf(" ");
    }
    printf("\n");

    return 0;
}
