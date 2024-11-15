#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ESTOQUE 100

typedef struct {
    int codigo;
    char nome[50];
    int quantidade;
    float valor_unitario;
} Produto;

Produto estoque[MAX_ESTOQUE];
int topo = -1;

void adicionarProduto(int codigo, const char* nome, int quantidade, float valor_unitario) {
    if (topo == MAX_ESTOQUE - 1) {
        printf("Content-Type: text/plain\n\nArmazém cheio. Não é possível adicionar mais produtos.\n");
        return;
    }

    Produto p = {codigo, "", quantidade, valor_unitario};
    strcpy(p.nome, nome);
    estoque[++topo] = p;
    printf("Content-Type: text/plain\n\nProduto adicionado com sucesso!\n");
}

// Outras funções aqui adaptadas para CGI

int main() {
    char *request_method = getenv("REQUEST_METHOD");
    
    if (strcmp(request_method, "POST") == 0) {
        // Ler e processar a entrada de dados para adicionar produto, etc.
        adicionarProduto(1, "Produto Teste", 10, 15.5);  // exemplo
    } else {
        printf("Content-Type: text/plain\n\nMétodo não suportado.\n");
    }
    
    return 0;
}
