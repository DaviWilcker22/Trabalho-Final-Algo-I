#include <stdio.h>

// Define o número máximo de produtos e o limite para estoque baixo
#define MAX_PRODUTOS 100
#define ESTOQUE_BAIXO 3

// Estrutura que define um produto com várias informações importantes
typedef struct {
    int codigo;
    char nome[50];
    char categoria[30];
    float precoVenda;
    float precoCusto;
    int quantidade;
    int saidas;
} Produto;

// Variáveis globais para armazenar o estoque e controlar o total de produtos e o saldo em caixa
Produto estoque[MAX_PRODUTOS];
int totalProdutos = 0;
float caixa = 0;

// Declaração das funções
void menu();
void cadastrarProduto();
void consultarProduto();
void editarProduto();
void entradaEstoque();
void registrarSaida();
void consultarCaixa();
void listarRelatorios();
int verificarCodigoDuplicado(int codigo);

// Função principal que chama o menu do sistema
int main() {
    menu();
    return 0;
}

// Função que exibe o menu principal e captura a opção escolhida pelo usuário
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

        // Chama a função correspondente à opção escolhida
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
    } while (opcao != 0); // Continua exibindo o menu até que a opção de sair seja escolhida

}

// Função para cadastrar um novo produto no sistema
void cadastrarProduto() {
    if (totalProdutos >= MAX_PRODUTOS) {
        printf("\nErro: Estoque cheio.\n");
        return;
    }
    Produto p;
    printf("\n========== Cadastro de Produto ==========\n");
    printf("Informe o codigo: ");
    scanf("%d", &p.codigo);
    // Captura e valida o código do produto
    if (p.codigo <= 0) {
        printf("\nErro: Codigo invalido.\n");
        return;
    }

    if (verificarCodigoDuplicado(p.codigo)) { // Verifica se o código já está cadastrado
        printf("\nErro: Codigo ja cadastrado.\n");
        return;
    }
    // Captura as demais informações do produto
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
    estoque[totalProdutos++] = p;  // Adiciona o produto ao estoque
    printf("\nProduto cadastrado com sucesso!\n");
}

// Função para verificar se um código já está cadastrado no sistema
int verificarCodigoDuplicado(int codigo) {
    for (int i = 0; i < totalProdutos; i++) {
        if (estoque[i].codigo == codigo) {
            return 1; // Retorna 1 se o código for encontrado
        }
    }
    return 0; // Retorna 0 se o código não for encontrado
}

// Função para consultar um produto pelo código
void consultarProduto() {
    int codigo;
    printf("\n========== Consulta de Produto ==========\n");
    printf("Informe o codigo do produto: ");
    scanf("%d", &codigo); // Captura o código do produto
    // Busca o produto no estoque e exibe suas informações
    for (int i = 0; i < totalProdutos; i++) {
        if (estoque[i].codigo == codigo) {
            printf("\n---------- Produto Encontrado ----------\n");
            printf("Nome: %s\n", estoque[i].nome);
            printf("Categoria: %s\n", estoque[i].categoria);
            printf("Preco de Venda: R$ %.2f\n", estoque[i].precoVenda);
            printf("Preco de Custo: R$ %.2f\n", estoque[i].precoCusto);
            printf("Quantidade em Estoque: %d\n", estoque[i].quantidade);
            printf("Saidas Registradas: %d\n", estoque[i].saidas);
            return;
        }
    }
    printf("\nProduto nao encontrado.\n");
}

// Função para editar as informações de um produto
void editarProduto() {
    int codigo;
    printf("\n--- Editar Produto ---\n");
    printf("Informe o codigo do produto: ");
    scanf("%d", &codigo); // Captura o código do produto
    // Busca o produto no estoque e permite editar suas informações
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

// Função para registrar a entrada de produtos no estoque
void entradaEstoque() {
    int codigo, quantidade;
    printf("\n--- Entrada em Estoque ---\n");
    printf("Informe o codigo do produto: ");
    scanf("%d", &codigo); // Captura o código do produto
    // Busca o produto no estoque e permite adicionar mais unidades
    for (int i = 0; i < totalProdutos; i++) {
        if (estoque[i].codigo == codigo) {
            printf("Quantidade atual: %d\n", estoque[i].quantidade);
            printf("Informe a quantidade a adicionar: ");
            scanf("%d", &quantidade);
            if (quantidade < 0) {
                printf("Quantidade invalida.\n");
                return;
            }
            estoque[i].quantidade += quantidade; // Atualiza a quantidade em estoque
            printf("Estoque atualizado com sucesso!\n");
            return;
        }
    }
    printf("Produto nao encontrado.\n");
}

// Função para registrar a saída de produtos do estoque
void registrarSaida() {
    int codigo, quantidade;
    printf("\n--- Registrar Saida ---\n");
    printf("Informe o codigo do produto: ");
    scanf("%d", &codigo); // Captura o código do produto
     // Busca o produto no estoque e permite retirar unidades do estoque
    for (int i = 0; i < totalProdutos; i++) {
        if (estoque[i].codigo == codigo) {
            printf("Quantidade atual: %d\n", estoque[i].quantidade);
            printf("Informe a quantidade a remover: ");
            scanf("%d", &quantidade);
            if (quantidade <= 0 || quantidade > estoque[i].quantidade) { // Valida se a quantidade é positiva e suficiente no estoque
                printf("Quantidade invalida ou insuficiente.\n");
                return;
            }
            // Atualiza o estoque e contabiliza as saídas e o caixa
            estoque[i].quantidade -= quantidade;
            estoque[i].saidas += quantidade;
            caixa += quantidade * estoque[i].precoVenda;
            printf("Saida registrada com sucesso!\n");
            // Alerta se o estoque ficar abaixo do limite definido
            if (estoque[i].quantidade < ESTOQUE_BAIXO) {
                printf("Atencao: Estoque baixo para o produto '%s'.\n", estoque[i].nome);
            }
            return;
        }
    }
    printf("Produto nao encontrado.\n");
}

// Função que exibe o saldo atual do caixa
void consultarCaixa() {
    printf("\n--- Consultar Caixa ---\n");
    printf("Saldo no caixa: R$ %.2f\n", caixa);
}

// Função que exibe relatórios e estatísticas do estoque
void listarRelatorios() {
    printf("\n========== Relatorios e Estatisticas ==========\n");
    if (totalProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }
    float valorTotalEstoque = 0, lucroPotencial = 0;
    printf("\nProdutos em Estoque:\n");
    // Calcula o valor total do estoque e o lucro potencial
    for (int i = 0; i < totalProdutos; i++) {
        valorTotalEstoque += estoque[i].quantidade * estoque[i].precoCusto;
        lucroPotencial += estoque[i].quantidade * (estoque[i].precoVenda - estoque[i].precoCusto);
        // Exibe código, nome e quantidade do produto
        printf("Codigo: %d | Nome: %s | Quantidade: %d\n", 
               estoque[i].codigo, estoque[i].nome, estoque[i].quantidade);
    }
     // Exibe o valor total do estoque e o lucro potencial
    printf("\nValor total do estoque: R$ %.2f\n", valorTotalEstoque);
    printf("Lucro potencial: R$ %.2f\n", lucroPotencial);
}
