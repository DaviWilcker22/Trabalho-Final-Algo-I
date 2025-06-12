#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUTOS 100
#define ESTOQUE_BAIXO 3

typedef struct {
    int codigo;
    char nome[50];
    char categoria[30];
    float precoVenda;
    float precoCusto;
    int quantidade;
    int saidas;
} Produto;

Produto estoque[MAX_PRODUTOS];
int totalProdutos = 0;
float caixa = 0;

void menu();
void cadastrarProduto();
void consultarProduto();
void editarProduto();
void entradaEstoque();
void registrarSaida();
void consultarCaixa();
void listarRelatorios();
int verificarCodigoDuplicado(int codigo);

int main() {
    menu();
    return 0;
}

void menu() {
    int opcao;
    do {
        printf("\n=========================================\n");
        printf("          SISTEMA DE GESTAO DE ESTOQUE   \n");
        printf("=========================================\n");
        printf("1. Cadastrar Produto\n");
        printf("2. Consultar Produto\n");
        printf("3. Editar Produto\n");
        printf("4. Registrar Entrada em Estoque\n");
        printf("5. Registrar Saida de Produto\n");
        printf("6. Consultar Saldo no Caixa\n");
        printf("7. Relatorios e Estatisticas\n");
        printf("0. Sair\n");
        printf("=========================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1: cadastrarProduto(); break;
            case 2: consultarProduto(); break;
            case 3: editarProduto(); break;
            case 4: entradaEstoque(); break;
            case 5: registrarSaida(); break;
            case 6: consultarCaixa(); break;
            case 7: listarRelatorios(); break;
            case 0: printf("\nEncerrando o programa...\n"); break;
            default: printf("\nOpcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);
}

void cadastrarProduto() {
    if (totalProdutos >= MAX_PRODUTOS) {
        printf("\nErro: Estoque cheio.\n");
        return;
    }

    Produto p;
    printf("\n========== Cadastro de Produto ==========\n");
    printf("Informe o codigo: ");
    scanf("%d", &p.codigo);
    if (p.codigo <= 0) {
        printf("\nErro: Codigo invalido.\n");
        return;
    }

    if (verificarCodigoDuplicado(p.codigo)) {
        printf("\nErro: Codigo ja cadastrado.\n");
        return;
    }

    printf("Informe o nome do produto: ");
    scanf(" %[^\n]", p.nome);
    printf("Informe a categoria: ");
    scanf(" %[^\n]", p.categoria);
    printf("Informe o preco de venda: R$ ");
    scanf("%f", &p.precoVenda);
    if (p.precoVenda <= 0) {
        printf("\nErro: Preco de venda invalido.\n");
        return;
    }

    printf("Informe o preco de custo: R$ ");
    scanf("%f", &p.precoCusto);
    if (p.precoCusto <= 0) {
        printf("\nErro: Preco de custo invalido.\n");
        return;
    }

    printf("Informe a quantidade inicial: ");
    scanf("%d", &p.quantidade);
    if (p.quantidade < 0) {
        printf("\nErro: Quantidade inicial invalida.\n");
        return;
    }

    p.saidas = 0;
    estoque[totalProdutos++] = p;
    printf("\nProduto cadastrado com sucesso!\n");
}

int verificarCodigoDuplicado(int codigo) {
    for (int i = 0; i < totalProdutos; i++) {
        if (estoque[i].codigo == codigo) {
            return 1;
        }
    }
    return 0;
}

void consultarProduto() {
    int codigo;
    printf("\n========== Consulta de Produto ==========\n");
    printf("Informe o codigo do produto: ");
    scanf("%d", &codigo);

    for (int i = 0; i < totalProdutos; i++) {
        if (estoque[i].codigo == codigo) {
            printf("\n---------- Produto Encontrado ----------\n");
            printf("Nome: %s\n", estoque[i].nome);
            printf("Categoria: %s\n", estoque[i].categoria);
            printf("Preço de Venda: R$ %.2f\n", estoque[i].precoVenda);
            printf("Preço de Custo: R$ %.2f\n", estoque[i].precoCusto);
            printf("Quantidade em Estoque: %d\n", estoque[i].quantidade);
            printf("Saidas Registradas: %d\n", estoque[i].saidas);
            return;
        }
    }
    printf("\nProduto nao encontrado.\n");
}

void editarProduto() {
    int codigo;
    printf("\n--- Editar Produto ---\n");
    printf("Informe o codigo do produto: ");
    scanf("%d", &codigo);

    for (int i = 0; i < totalProdutos; i++) {
        if (estoque[i].codigo == codigo) {
            printf("\n--- Produto Encontrado ---\n");
            printf("Nome atual: %s\n", estoque[i].nome);
            printf("Categoria atual: %s\n", estoque[i].categoria);
            printf("Novo nome: ");
            scanf(" %[^\n]", estoque[i].nome);
            printf("Nova categoria: ");
            scanf(" %[^\n]", estoque[i].categoria);
            printf("Novo preco de venda: ");
            scanf("%f", &estoque[i].precoVenda);
            if (estoque[i].precoVenda <= 0) {
                printf("Preco invalido.\n");
                return;
            }
            printf("Novo preco de custo: ");
            scanf("%f", &estoque[i].precoCusto);
            if (estoque[i].precoCusto <= 0) {
                printf("Preco invalido.\n");
                return;
            }
            printf("Produto editado com sucesso!\n");
            return;
        }
    }
    printf("Produto nao encontrado.\n");
}

void entradaEstoque() {
    int codigo, quantidade;
    printf("\n--- Entrada em Estoque ---\n");
    printf("Informe o codigo do produto: ");
    scanf("%d", &codigo);

    for (int i = 0; i < totalProdutos; i++) {
        if (estoque[i].codigo == codigo) {
            printf("Quantidade atual: %d\n", estoque[i].quantidade);
            printf("Informe a quantidade a adicionar: ");
            scanf("%d", &quantidade);
            if (quantidade < 0) {
                printf("Quantidade invalida.\n");
                return;
            }

            estoque[i].quantidade += quantidade;
            printf("Estoque atualizado com sucesso!\n");
            return;
        }
    }
    printf("Produto nao encontrado.\n");
}

void registrarSaida() {
    int codigo, quantidade;
    printf("\n--- Registrar Saida ---\n");
    printf("Informe o codigo do produto: ");
    scanf("%d", &codigo);

    for (int i = 0; i < totalProdutos; i++) {
        if (estoque[i].codigo == codigo) {
            printf("Quantidade atual: %d\n", estoque[i].quantidade);
            printf("Informe a quantidade a remover: ");
            scanf("%d", &quantidade);
            if (quantidade <= 0 || quantidade > estoque[i].quantidade) {
                printf("Quantidade invalida ou insuficiente.\n");
                return;
            }

            estoque[i].quantidade -= quantidade;
            estoque[i].saidas += quantidade;
            caixa += quantidade * estoque[i].precoVenda;
            printf("Saida registrada com sucesso!\n");

            if (estoque[i].quantidade < ESTOQUE_BAIXO) {
                printf("Atencao: Estoque baixo para o produto '%s'.\n", estoque[i].nome);
            }
            return;
        }
    }
    printf("Produto nao encontrado.\n");
}

void consultarCaixa() {
    printf("\n--- Consultar Caixa ---\n");
    printf("Saldo no caixa: R$ %.2f\n", caixa);
}

void listarRelatorios() {
    printf("\n========== Relatorios e Estatisticas ==========\n");
    if (totalProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    float valorTotalEstoque = 0, lucroPotencial = 0;
    printf("\nProdutos em Estoque:\n");
    for (int i = 0; i < totalProdutos; i++) {
        valorTotalEstoque += estoque[i].quantidade * estoque[i].precoCusto;
        lucroPotencial += estoque[i].quantidade * (estoque[i].precoVenda - estoque[i].precoCusto);
        printf("Codigo: %d | Nome: %s | Quantidade: %d\n", 
               estoque[i].codigo, estoque[i].nome, estoque[i].quantidade);
    }

    printf("\nValor total do estoque: R$ %.2f\n", valorTotalEstoque);
    printf("Lucro potencial: R$ %.2f\n", lucroPotencial);
}
