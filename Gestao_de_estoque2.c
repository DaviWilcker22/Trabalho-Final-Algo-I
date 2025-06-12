#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PRODUTOS 100
#define ESTOQUE_BAIXO 3

// Arrays paralelos para armazenar os dados dos produtos
int codigos[MAX_PRODUTOS];
char nomes[MAX_PRODUTOS][50];
char categorias[MAX_PRODUTOS][30];
float precosVenda[MAX_PRODUTOS];
float precosCusto[MAX_PRODUTOS];
int quantidades[MAX_PRODUTOS];
int saidas[MAX_PRODUTOS];

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
int encontrarIndice(int codigo);

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
        if (opcao != 1) {
            printf("\nErro: Entrada invalida. Reinicie o programa.\n");
            return;
        }

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

int verificarCodigoDuplicado(int codigo) {
    for (int i = 0; i < totalProdutos; i++) {
        if (codigos[i] == codigo) return 1;
    }
    return 0;
}

int encontrarIndice(int codigo) {
    for (int i = 0; i < totalProdutos; i++) {
        if (codigos[i] == codigo) return i;
    }
    return -1;
}

void cadastrarProduto() {
    if (totalProdutos >= MAX_PRODUTOS) {
        printf("\nErro: Estoque cheio.\n");
        return;
    }

    int codigo;
    printf("\n========== Cadastro de Produto ==========\n");
    printf("Informe o codigo: ");
    scanf("%d", &codigo);
    if (codigo <= 0 || verificarCodigoDuplicado(codigo)) {
        printf("\nErro: Codigo invalido ou ja cadastrado.\n");
        return;
    }

    codigos[totalProdutos] = codigo;
    printf("Informe o nome do produto: ");
    scanf(" %[^\n]s", nomes[totalProdutos]);
    printf("Informe a categoria: ");
    scanf(" %[^\n]s", categorias[totalProdutos]);
    printf("Informe o preco de venda: R$ ");
    scanf("%f", &precosVenda[totalProdutos]);
    if (precosVenda[totalProdutos] <= 0) return;
    printf("Informe o preco de custo: R$ ");
    scanf("%f", &precosCusto[totalProdutos]);
    if (precosCusto[totalProdutos] <= 0) return;
    printf("Informe a quantidade inicial: ");
    scanf("%d", &quantidades[totalProdutos]);
    if (quantidades[totalProdutos] < 0) return;

    saidas[totalProdutos] = 0;
    totalProdutos++;
    printf("\nProduto cadastrado com sucesso!\n");
}

void consultarProduto() {
    int codigo;
    printf("\n========== Consulta de Produto ==========\n");
    printf("Informe o codigo do produto: ");
    scanf("%d", &codigo);

    int i = encontrarIndice(codigo);
    if (i == -1) {
        printf("Produto nao encontrado.\n");
        return;
    }

    printf("\n---------- Produto Encontrado ----------\n");
    printf("Nome: %s\n", nomes[i]);
    printf("Categoria: %s\n", categorias[i]);
    printf("Preço de Venda: R$ %.2f\n", precosVenda[i]);
    printf("Preço de Custo: R$ %.2f\n", precosCusto[i]);
    printf("Quantidade em Estoque: %d\n", quantidades[i]);
    printf("Saidas Registradas: %d\n", saidas[i]);
}

void editarProduto() {
    int codigo;
    printf("\n--- Editar Produto ---\n");
    printf("Informe o codigo do produto: ");
    scanf("%d", &codigo);

    int i = encontrarIndice(codigo);
    if (i == -1) {
        printf("Produto nao encontrado.\n");
        return;
    }

    printf("Nome atual: %s\n", nomes[i]);
    printf("Categoria atual: %s\n", categorias[i]);
    printf("Novo nome: ");
    scanf(" %[^\n]", nomes[i]);
    printf("Nova categoria: ");
    scanf(" %[^\n]", categorias[i]);
    printf("Novo preco de venda: ");
    scanf("%f", &precosVenda[i]);
    if (precosVenda[i] <= 0) return;
    printf("Novo preco de custo: ");
    scanf("%f", &precosCusto[i]);
    if (precosCusto[i] <= 0) return;

    printf("Produto editado com sucesso!\n");
}

void entradaEstoque() {
    int codigo, quantidade;
    printf("\n--- Entrada em Estoque ---\n");
    printf("Informe o codigo do produto: ");
    scanf("%d", &codigo);

    int i = encontrarIndice(codigo);
    if (i == -1) {
        printf("Produto nao encontrado.\n");
        return;
    }

    printf("Quantidade atual: %d\n", quantidades[i]);
    printf("Informe a quantidade a adicionar: ");
    scanf("%d", &quantidade);
    if (quantidade < 0) return;

    quantidades[i] += quantidade;
    printf("Estoque atualizado com sucesso!\n");
}

void registrarSaida() {
    int codigo, quantidade;
    printf("\n--- Registrar Saida ---\n");
    printf("Informe o codigo do produto: ");
    scanf("%d", &codigo);

    int i = encontrarIndice(codigo);
    if (i == -1) {
        printf("Produto nao encontrado.\n");
        return;
    }

    printf("Quantidade atual: %d\n", quantidades[i]);
    printf("Informe a quantidade a remover: ");
    scanf("%d", &quantidade);
    if (quantidade <= 0 || quantidade > quantidades[i]) {
        printf("Quantidade invalida ou insuficiente.\n");
        return;
    }

    quantidades[i] -= quantidade;
    saidas[i] += quantidade;
    caixa += quantidade * precosVenda[i];
    printf("Saida registrada com sucesso!\n");

    if (quantidades[i] < ESTOQUE_BAIXO) {
        printf("Atencao: Estoque baixo para o produto '%s'.\n", nomes[i]);
    }
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
    for (int i = 0; i < totalProdutos; i++) {
        valorTotalEstoque += quantidades[i] * precosCusto[i];
        lucroPotencial += quantidades[i] * (precosVenda[i] - precosCusto[i]);
        printf("Codigo: %d | Nome: %s | Quantidade: %d\n", codigos[i], nomes[i], quantidades[i]);
    }

    printf("\nValor total do estoque: R$ %.2f\n", valorTotalEstoque);
    printf("Lucro potencial: R$ %.2f\n", lucroPotencial);
}
