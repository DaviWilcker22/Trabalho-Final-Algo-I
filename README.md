# Sistema de Gestão de Estoque  
[![Badge Concluído](https://img.shields.io/badge/status-Concluído-green)]()  
[![Licença](https://img.shields.io/badge/license-MIT-blue)]()


---

## Informações do Projeto

**Universidade:** Universidade Federal do Piauí – Campus Senador Helvídio Nunes de Barros  
**Curso:** Bacharelado em Sistemas de Informação  
**Disciplina:** Algoritmos e Programação I  
**Professor(a):** Dra. Alcilene Dalília de Sousa  

**Equipe:**
- Davi Wilcker Vieira de Araujo Bezerra.
- Daniel de Negreiros Sousa.

---

## Descrição do Projeto

Sistema de gerenciamento de estoque desenvolvido em C que permite o controle de produtos de forma simples e eficiente.  
Inclui funcionalidades como:  
Cadastro | Consulta | Edição | Entrada | Saída | Caixa | Relatórios

---

## Estrutura do Projeto

```
projeto_estoque/
├── 📄 main.c             # Arquivo principal com todas as funcionalidades
├── 📁 screenshots/          # Imagens das telas do sistema (demonstração visual)
└── 📄 README.md          # Documentação do projeto
```

---

## Como Compilar e Executar

### Windows
```bash
gcc main.c -o main.exe
.\main.exe
```
---

## Funcionalidades

1. **Cadastrar Produto**
   - Impede códigos duplicados
   - Validação de entrada
   - Limite de 100 produtos

2. **Consultar Produto**
   - Busca por código
   - Exibe informações detalhadas

3. **Editar Produto**
     - Permite editar:
     - Nome
     - Categoria
     - Preço de venda e custo

4. **Entrada de Produtos**
   - Aumenta quantidade no estoque
   - Verifica entradas inválidas

5. **Saída de Produtos**
   - Diminui quantidade no estoque
   - Atualiza valor em caixa
   - Alerta para produtos com quantidade < 3

6. **Consultar Caixa**
   - Valor acumulado com base nas vendas

7. **Relatórios**
   - Lista de todos os produtos
   - Valor total de estoque
   - Cálculo de lucro potencial

---


## Demonstração Visual

<div align="center">

  <h3>Menu Principal</h3>
  <img src="./screenshots/Menu Principal.png" alt="Menu do Sistema" width="400">
  <p><em>Interface principal com todas as opções disponíveis</em></p>

  <h3>Cadastro de Produto</h3>
  <img src="./screenshots/Cadastrar Produto.png" alt="Tela de cadastro" width="400">
  <p><em>Campos: código, nome, categoria, preços e quantidade</em></p>

  <h3>Consulta de Produto</h3>
  <img src="./screenshots/Consulta de Produto.png" alt="Consulta de produto" width="400">
  <p><em>Exibe todas as informações cadastradas de um item</em></p>

  <h3>Edição de Produto</h3>
  <img src="./screenshots/Edição de Produto.png" alt="Edição de produto" width="400">
  <p><em>Permite alterar nome, categoria, preços e mais</em></p>

  <h3>Entrada em Estoque</h3>
  <img src="./screenshots/Entrada de Estoque.png" alt="Entrada em estoque" width="400">
  <p><em>Adiciona unidades ao inventário de produtos</em></p>

  <h3>Saída de Estoque</h3>
  <img src="./screenshots/Saida de Estoque.png" alt="Saída de estoque" width="400">
  <p><em>Remove unidades e registra vendas</em></p>

  <h3>Consultar Caixa</h3>
  <img src="./screenshots/Consultar Caixa.png" alt="Caixa" width="300">
  <p><em>Exibe o saldo acumulado pelas vendas</em></p>

  <h3>Relatórios e Estatísticas</h3>
  <img src="./screenshots/Relatorio de Estoque.png" alt="Relatório de estoque" width="500">
  <p><em>Visão geral do inventário, valor total e lucro potencial</em></p>

</div>


---

## Tecnologias Utilizadas

- **Vetores** para armazenar até 100 produtos  
- **Structs** para modelagem dos dados 
- **typedef** para definição de tipos personalizados  
- **Algoritmos de busca e verificação** 


---

## 🐞 Bugs e Limitações Conhecidas

|    Problema   |    Gravidade   |    Descrição   |
|---------------|----------------|----------------|
| Limite de caracteres | Médio|Nomes e categorias aceitam até 49 caracteres. |
| Sem salvamento de dados | Alto | Os dados se perdem ao fechar o programa. |
| Portabilidade limitada | Médio | Funciona melhor no Windows que em Linux/macOS. |
| Entrada com `scanf()` | Médio | Não verifica se o tipo digitado está correto. |



---


