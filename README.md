
# 📦 Sistema de Gestão de Estoque  
[![Badge Concluído](https://img.shields.io/badge/status-Concluído-green)]()  
[![Licença](https://img.shields.io/badge/license-MIT-blue)]()

---

## 🏫 Informações do Projeto

**🎓 Universidade:** Universidade Federal do Piauí – Campus Senador Helvídio Nunes de Barros  
**💻 Curso:** Bacharelado em Sistemas de Informação  
**📚 Disciplina:** Algoritmos e Programação I  
**👩‍🏫 Professor(a):** Dra. Alcilene Dalília de Sousa  

**👥 Equipe:**
- Davi Wilcker Vieira de Araujo Bezerra  
- Daniel de Negreiros Sousa

---

## 📖 Descrição do Projeto

Sistema de gerenciamento de estoque desenvolvido em C que permite o controle de produtos de forma simples e eficiente.  
Inclui funcionalidades como:  
📝 Cadastro | 🔍 Consulta | ✏️ Edição | ➕ Entrada | ➖ Saída | 💰 Caixa | 📊 Relatórios

---

## 📁 Estrutura do Projeto

```
Gestao_estoque/
├── 📄 main.c             # Arquivo principal com todas as funcionalidades
├── 📁 screenshots/       # Imagens das telas do sistema (demonstração visual)
└── 📄 README.md          # Documentação do projeto
```

---

## ⚙️ Como Compilar e Executar

### 💻 Windows
```bash
gcc main.c -o main.exe
.\main.exe
```

---

## ✨ Funcionalidades

1. **📝 Cadastrar Produto**
   - Impede códigos duplicados
   - Validação de entrada
   - Limite de 100 produtos

2. **🔍 Consultar Produto**
   - Busca por código
   - Exibe informações detalhadas

3. **✏️ Editar Produto**
   - Permite editar nome, categoria, preço de venda e custo

4. **➕ Entrada de Produtos**
   - Aumenta a quantidade em estoque
   - Verifica entradas inválidas

5. **➖ Saída de Produtos**
   - Diminui a quantidade no estoque
   - Atualiza valor em caixa
   - Alerta para produtos com quantidade < 3

6. **💰 Consultar Caixa**
   - Mostra o valor acumulado em vendas

7. **📊 Relatórios**
   - Lista todos os produtos
   - Mostra valor total do estoque
   - Calcula lucro potencial

---

## 🔧 Visão Geral das Funções

### 📌 Cadastro
`void cadastrarProduto(...)`
- **Argumentos:** nenhum
- **Retorno:** nenhum
- **Descrição:** Solicita dados do usuário para cadastrar um novo produto no estoque, realizando validações como código único e valores válidos.

### 🔍 Consulta
`void consultarProduto(...)`
- **Argumentos:** nenhum
- **Retorno:** nenhum
- **Descrição:** Solicita o código do produto e exibe todas as informações cadastradas caso o produto seja encontrado.

### ✏️ Edição
`void editarProduto(...)`
- **Argumentos:** nenhum
- **Retorno:** nenhum
- **Descrição:** Permite alterar os dados (nome, categoria, preços) de um produto já cadastrado, após buscar pelo código.

### ➕ Entrada e ➖ Saída
`void entradaEstoque(...)` 
- **Argumentos:** nenhum
- **Retorno:** nenhum
- **Descrição:** Solicita código e quantidade para adicionar produtos ao estoque, atualizando a quantidade armazenada.

`void registrarSaida(...)`
- **Argumentos:** nenhum
- **Retorno:** nenhum
- **Descrição:** Registra a saída (venda/remoção) de produtos do estoque, atualizando a quantidade, as saídas registradas e o saldo do caixa. Alerta se o estoque ficar baixo.

### 💰 Caixa e 📊 Relatório
`void consultarCaixa(...)`
- **Argumentos:** nenhum
- **Retorno:** nenhum
- **Descrição:** Exibe o saldo acumulado no caixa, que representa o total obtido pelas vendas.

`void listarRelatorios(...)`
- **Argumentos:** nenhum
- **Retorno:** nenhum
- **Descrição:** Lista todos os produtos cadastrados com suas quantidades, calcula o valor total do estoque e o lucro potencial baseado no preço de custo e venda.

### ⚙️ Utilitárias
`void menu(...)`
- **Argumentos:** nenhum
- **Retorno:** nenhum
- **Descrição:** Exibe o menu principal do sistema e gerencia a navegação entre as funções por meio das opções do usuário.

`int verificarCodigoDuplicado(int codigo)`
- **Argumentos:**
  - `codigo` — código do produto a ser verificado (inteiro)
- **Retorno:**
  - 1 se o código já existir no estoque
  - 0 caso contrário
- **Descrição:** Verifica se um código de produto já está cadastrado, impedindo duplicatas.




---

## 🖼️ Demonstração Visual

<div align="center">

### 🎛️ Menu Principal  
<figure>
  <figure style="display: inline-block; text-align: center; margin: 20px;">
  <img src="./screenshots/Menu Principal.png" alt="Menu do Sistema" width="400">
  <figcaption><em>Interface principal com todas as opções disponíveis</em></figcaption>
</figure>


### 📝 Cadastro de Produto 
<figure style="display: inline-block; text-align: center; margin: 20px;">
  <img src="./screenshots/Cadastrar Produto.png" alt="Tela de cadastro" width="400">
  <figcaption><em>Campos: código, nome, categoria, preços e quantidade</em></figcaption>
</figure>

### 🔍 Consulta de Produto 
<figure style="display: inline-block; text-align: center; margin: 20px;">
  <img src="./screenshots/Consulta de Produto.png" alt="Consulta de produto" width="400">
  <figcaption><em>Exibe todas as informações cadastradas de um item</em></figcaption>
</figure>

### ✏️ Edição de Produto 
<figure style="display: inline-block; text-align: center; margin: 20px;">
  <img src="./screenshots/Edição de Produto.png" alt="Edição de produto" width="400">
  <figcaption><em>Permite alterar nome, categoria, preços e mais</em></figcaption>
</figure>

### ➕ Entrada em Estoque  
<figure style="display: inline-block; text-align: center; margin: 20px;">
  <img src="./screenshots/Entrada de Estoque.png" alt="Entrada em estoque" width="400">
  <figcaption><em>Adiciona unidades ao inventário de produtos</em></figcaption>
</figure>

### ➖ Saída de Estoque
<figure style="display: inline-block; text-align: center; margin: 20px;">
  <img src="./screenshots/Saida de Estoque.png" alt="Saída em estoque" width="400">
  <figcaption><em>Remove unidades e registra vendas</em></figcaption>
</figure>

### 💰 Consultar Caixa  
<figure style="display: inline-block; text-align: center; margin: 20px;">
  <img src="./screenshots/Consultar Caixa.png" alt="Caixa" width="300">
  <figcaption><em>Exibe o saldo acumulado pelas vendas</em></figcaption>
</figure>

### 📊 Relatórios e Estatísticas 
<figure style="display: inline-block; text-align: center; margin: 20px;">
  <img src="./screenshots/Relatorio de Estoque.png" alt="Relatório de estoque" width="500">
  <figcaption><em>Visão geral do inventário, valor total e lucro potencial</em></figcaption>
</figure>

</div>


---

## 🛠️ Tecnologias Utilizadas

- 📑 **Vetores** para armazenar até 100 produtos  
- 🧱 **Structs** para modelagem dos dados  
- 🏷️ **Typedef** para definição de tipos personalizados  
- 🔍 **Algoritmos de busca e verificação** para controle de estoque

---

## 🐞 Bugs e Limitações Conhecidas

| Problema                     | Gravidade | Descrição |
|-----------------------------|-----------|-----------|
| 📛 Limite no tamanho dos nomes | ⚠️ Médio  | Campos de texto limitados a 49 caracteres (`char`) |
| 💾 Ausência de persistência     | ⚠️ Alto   | Dados são perdidos ao encerrar o programa |
| 🖥️ Portabilidade limitada       | ⚠️ Médio  | Melhor funcionamento em Windows |
| 🧪 Validação scanf()           | ⚠️ Médio  | Não verifica se a entrada é do tipo esperado |

---

## 📄 Licença

Este projeto está licenciado sob a **Licença MIT**.
