#include<stdio.h>
#include<string.h>

#define MAX_ESTOQUE 100

// Estrutura para representar um produto
typedef struct {
    int codigo;
    char nome[50];
    int quantidade;
    float valor_unitario;
} Produto;

// Declaração de variáveis globais
Produto estoque[MAX_ESTOQUE];
int topo = -1;

// Funções do programa
void adicionarProduto() {
    if (topo == MAX_ESTOQUE - 1) {
        printf("Armazém cheio. Não é possível adicionar mais produtos.\n");
        return;
    }

    Produto p;
    printf("Digite o código do produto: ");
    scanf("%d", &p.codigo);
    printf("Digite o nome do produto: ");
    scanf("%s", p.nome);
    printf("Digite a quantidade: ");
    scanf("%d", &p.quantidade);
    printf("Digite o valor unitário: ");
    scanf("%f", &p.valor_unitario);

    estoque[++topo] = p;
    printf("Produto adicionado com sucesso!\n");
}

void removerProduto() {
    if (topo == -1) {
        printf("Armazém vazio. Não há produtos para remover.\n");
        return;
    }
    
    printf("Produto removido: %s\n", estoque[topo].nome);
    topo--;
}

void verificarProduto() {
    int codigo;
    printf("Digite o código do produto para verificar: ");
    scanf("%d", &codigo);
    
    for (int i = 0; i <= topo; i++) {
        if (estoque[i].codigo == codigo) {
            printf("Produto encontrado: %s, Quantidade: %d, Valor Unitário: %.2f\n", estoque[i].nome, estoque[i].quantidade, estoque[i].valor_unitario);
            return;
        }
    }
    printf("Produto não encontrado no armazém.\n");
}

void exibirProdutos() {
    if (topo == -1) {
        printf("Armazém vazio.\n");
        return;
    }
    
    printf("Lista de produtos no armazém:\n");
    for (int i = 0; i <= topo; i++) {
        printf("Código: %d, Nome: %s, Quantidade: %d, Valor Unitário: %.2f\n", estoque[i].codigo, estoque[i].nome, estoque[i].quantidade, estoque[i].valor_unitario);
    }
}

void venderProduto() {
    int codigo, quantidade, continuar, encontrado = 0;
    char nome[50];
    float total = 0;

    printf("Deseja procurar o produto por (1) Código ou (2) Nome? ");
    scanf("%d", &continuar);

    do {
        encontrado = 0;
        if (continuar == 1) {
            printf("Digite o código do produto: ");
            scanf("%d", &codigo);

            for (int i = 0; i <= topo; i++) {
                if (estoque[i].codigo == codigo && estoque[i].quantidade > 0) {
                    printf("Produto encontrado: %s, Quantidade disponível: %d, Valor Unitário: %.2f\n", estoque[i].nome, estoque[i].quantidade, estoque[i].valor_unitario);
                    printf("Digite a quantidade a comprar: ");
                    scanf("%d", &quantidade);

                    if (quantidade <= estoque[i].quantidade) {
                        estoque[i].quantidade -= quantidade;
                        total += quantidade * estoque[i].valor_unitario;
                        printf("Produto %s adicionado ao carrinho. Valor Parcial: %.2f\n", estoque[i].nome, quantidade * estoque[i].valor_unitario);
                        encontrado = 1;
                    } else {
                        printf("Quantidade insuficiente em estoque.\n");
                    }
                    break;
                }
            }
        } else if (continuar == 2) {
            printf("Digite o nome do produto: ");
            scanf("%s", nome);

            for (int i = 0; i <= topo; i++) {
                if (strcmp(estoque[i].nome, nome) == 0 && estoque[i].quantidade > 0) {
                    printf("Produto encontrado: %s, Quantidade disponível: %d, Valor Unitário: %.2f\n", estoque[i].nome, estoque[i].quantidade, estoque[i].valor_unitario);
                    printf("Digite a quantidade a comprar: ");
                    scanf("%d", &quantidade);

                    if (quantidade <= estoque[i].quantidade) {
                        estoque[i].quantidade -= quantidade;
                        total += quantidade * estoque[i].valor_unitario;
                        printf("Produto %s adicionado ao carrinho. Valor Parcial: %.2f\n", estoque[i].nome, quantidade * estoque[i].valor_unitario);
                        encontrado = 1;
                    } else {
                        printf("Quantidade insuficiente em estoque.\n");
                    }
                    break;
                }
            }
        }

        if (!encontrado) {
            printf("Produto não encontrado ou sem estoque.\n");
        }

        printf("Deseja comprar mais itens? (1 para sim / 0 para não): ");
        scanf("%d", &continuar);

    } while (continuar == 1);

    printf("Total da compra: %.2f\n", total);
}

void sobreDesenvolvedor() {
    int opcao;

    do {
        printf("\nSobre o Desenvolvedor:\n");
        printf("1. Ir para o site do desenvolvedor\n");
        printf("2. Chamar no WhatsApp\n");
        printf("3. Ir para o GitHub do projeto\n");
        printf("4. Voltar ao menu principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Abrindo site: www.walterdyna.com.br\n");
                break;
            case 2:
                printf("Abrindo WhatsApp: https://w.app/SZPGlC\n");
                break;
            case 3:
                printf("Abrindo GitHub: https://github.com/walterdyna/Empresa-de-log-stica\n");
                break;
            case 4:
                return;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (1);
}

int main() {
    int opcao;

    do {
        printf("\nBem-vindo à Empresa DynaS Logística LTDA\n");
        printf("\nMenu:\n");
        printf("1. Adicionar Produto\n");
        printf("2. Remover Produto\n");
        printf("3. Verificar Produto no Armazém\n");
        printf("4. Exibir Produtos\n");
        printf("5. Sair\n");
        printf("6. Vender Produto\n");
        printf("7. Sobre o Desenvolvedor\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarProduto();
                break;
            case 2:
                removerProduto();
                break;
            case 3:
                verificarProduto();
                break;
            case 4:
                exibirProdutos();
                break;
            case 6:
                venderProduto();
                break;
            case 7:
                sobreDesenvolvedor();
                break;
            case 5:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 5);

    return 0;
}
