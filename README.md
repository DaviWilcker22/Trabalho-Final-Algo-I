
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
- `void cadastrarProduto(...)`

### 🔍 Consulta
- `void consultarProduto(...)`

### ✏️ Edição
- `void editarProduto(...)`

### ➕ Entrada e ➖ Saída
- `void entradaEstoque(...)`  
- `void registrarSaida(...)`

### 💰 Caixa e 📊 Relatório
- `void consultarCaixa(...)`  
- `void listarRelatorios(...)`

### ⚙️ Utilitárias
- `void menu(...)`
- `int verificarCodigoDuplicado(int codigo)`

---

## 🖼️ Demonstração Visual

<div align="center">

### 🎛️ Menu Principal  
<img src="./screenshots/Menu Principal.png" alt="Menu do Sistema" width="400">  
<em>Interface principal com todas as opções disponíveis</em>

### 📝 Cadastro de Produto  
<img src="./screenshots/Cadastrar Produto.png" alt="Tela de cadastro" width="400">  
<em>Campos: código, nome, categoria, preços e quantidade</em>

### 🔍 Consulta de Produto  
<img src="./screenshots/Consulta de Produto.png" alt="Consulta de produto" width="400">  
<em>Exibe todas as informações cadastradas de um item</em>

### ✏️ Edição de Produto  
<img src="./screenshots/Edição de Produto.png" alt="Edição de produto" width="400">  
<em>Permite alterar nome, categoria, preços e mais</em>

### ➕ Entrada em Estoque  
<img src="./screenshots/Entrada de Estoque.png" alt="Entrada em estoque" width="400">  
<em>Adiciona unidades ao inventário de produtos</em>

### ➖ Saída de Estoque  
<img src="./screenshots/Saida de Estoque.png" alt="Saída de estoque" width="400">  
<em>Remove unidades e registra vendas</em>

### 💰 Consultar Caixa  
<img src="./screenshots/Consultar Caixa.png" alt="Caixa" width="300">  
<em>Exibe o saldo acumulado pelas vendas</em>

### 📊 Relatórios e Estatísticas  
<img src="./screenshots/Relatorio de Estoque.png" alt="Relatório de estoque" width="500">  
<em>Visão geral do inventário, valor total e lucro potencial</em>

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
