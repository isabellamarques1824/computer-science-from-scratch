# Fundamentos de Programação e Sintaxe Básica em C++

Resumo dos principais conceitos de programação e da sintaxe básica de C++.

---

# Fundamentos de Programação

## Variáveis

Variáveis armazenam valores que podem ser utilizados e modificados durante a execução do programa.

```cpp
int idade = 19;
float altura = 1.66f;
double salario = 2500.50;
char letra = 'A';
bool ativo = true;
std::string nome = "Isabella";
```

Principais tipos:

```text
int       → números inteiros
float     → números decimais
double    → números decimais com maior precisão
char      → um caractere
bool      → true ou false
string    → texto
```

Sempre que possível, inicialize a variável no momento da declaração.

```cpp
int contador = 0;
```

---

## Constantes

Uma constante representa um valor que não deve mudar.

```cpp
const int MAXIMO = 100;
```

Quando o valor pode ser determinado em tempo de compilação:

```cpp
constexpr int MAXIMO = 100;
```

---

# Operadores

## Aritméticos

```cpp
+
-
*
/
%
```

Exemplo:

```cpp
int soma = 10 + 5;
int resto = 10 % 3;
```

---

## Comparação

```cpp
==
!=
>
<
>=
<=
```

Exemplo:

```cpp
idade >= 18
```

---

## Lógicos

```cpp
&&   // AND
||   // OR
!    // NOT
```

Exemplo:

```cpp
if (idade >= 18 && possui_carteira) {
}
```

---

## Incremento e decremento

```cpp
contador++;
contador--;
```

---

# Entrada e Saída

## Saída

```cpp
std::cout << "Hello World\n";
```

Também pode usar:

```cpp
std::cout << "Idade: " << idade << '\n';
```

---

## Entrada

```cpp
int idade;

std::cin >> idade;
```

---

## Texto com espaços

```cpp
std::string nome;

std::getline(std::cin, nome);
```

`getline()` lê a linha inteira.

---

# Condicionais

## If

```cpp
if (idade >= 18) {
    std::cout << "Maior de idade";
}
```

---

## If / Else

```cpp
if (nota >= 7) {
    std::cout << "Aprovado";
} else {
    std::cout << "Reprovado";
}
```

---

## Else If

```cpp
if (nota >= 9) {
    std::cout << "Excelente";
}
else if (nota >= 7) {
    std::cout << "Bom";
}
else {
    std::cout << "Reprovado";
}
```

---

## Switch

Útil quando uma variável pode assumir várias opções conhecidas.

```cpp
switch (opcao) {
    case 1:
        std::cout << "Opcao 1";
        break;

    case 2:
        std::cout << "Opcao 2";
        break;

    default:
        std::cout << "Opcao invalida";
        break;
}
```

---

# Estruturas de Repetição

## For

Usado quando sabemos aproximadamente quantas vezes queremos repetir algo.

```cpp
for (int i = 0; i < 10; i++) {
    std::cout << i << '\n';
}
```

---

## While

Executa enquanto uma condição for verdadeira.

```cpp
while (contador < 10) {
    contador++;
}
```

---

## Range-based For

Usado para percorrer elementos de containers.

```cpp
for (int numero : numeros) {
    std::cout << numero << '\n';
}
```

---

# Funções

Funções agrupam uma responsabilidade específica do programa.

```cpp
int somar(int a, int b) {
    return a + b;
}
```

Chamando:

```cpp
int resultado = somar(10, 5);
```

---

## Função sem retorno

```cpp
void mensagem() {
    std::cout << "Ola!";
}
```

---

## Parâmetros por valor

```cpp
void funcao(int numero) {
}
```

A função recebe uma cópia do valor.

---

## Parâmetros por referência

```cpp
void funcao(int& numero) {
}
```

A função trabalha diretamente com a variável original.

Alterações feitas nela permanecem fora da função.

---

## Referência constante

```cpp
void funcao(const std::string& texto) {
}
```

Permite acessar o objeto original:

- sem criar uma cópia
- sem permitir sua modificação

Regra prática:

```text
Tipos pequenos
→ passar por valor

Objetos maiores que serão apenas lidos
→ const T&

Objetos que serão modificados
→ T&
```

---

# Escopo

Uma variável só existe dentro do bloco onde foi declarada.

```cpp
if (true) {
    int numero = 10;
}
```

`numero` deixa de existir ao sair do bloco.

---

# Arrays

Array possui tamanho fixo.

```cpp
int numeros[5] = {1, 2, 3, 4, 5};
```

Acesso:

```cpp
numeros[0];
```

Os índices começam em:

```text
0
```

Então:

```text
índice:  0  1  2  3  4
valor:   1  2  3  4  5
```

---

# std::vector

`std::vector` representa uma sequência dinâmica de elementos.

```cpp
std::vector<int> numeros;
```

---

## Criar com valores

```cpp
std::vector<int> numeros = {10, 20, 30};
```

---

## Adicionar

```cpp
numeros.push_back(40);
```

---

## Acessar

```cpp
numeros[0];
```

Ou com verificação de limite:

```cpp
numeros.at(0);
```

---

## Quantidade

```cpp
numeros.size();
```

---

## Verificar se está vazio

```cpp
numeros.empty();
```

---

## Primeiro elemento

```cpp
numeros.front();
```

---

## Último elemento

```cpp
numeros.back();
```

---

## Remover último elemento

```cpp
numeros.pop_back();
```

---

## Remover por posição

```cpp
numeros.erase(numeros.begin() + indice);
```

---

## Limpar

```cpp
numeros.clear();
```

---

## Percorrer

```cpp
for (const int& numero : numeros) {
    std::cout << numero << '\n';
}
```

---

# std::string

```cpp
std::string nome = "Isabella";
```

---

## Tamanho

```cpp
nome.size();
```

---

## Verificar se está vazia

```cpp
nome.empty();
```

---

## Concatenar

```cpp
std::string nome_completo = nome + " Jardim";
```

---

## Acessar caractere

```cpp
nome[0];
```

---

# Struct

Uma `struct` permite criar um tipo que agrupa vários dados relacionados.

```cpp
struct Pessoa {
    std::string nome;
    int idade;
    float altura;
};
```

Criando:

```cpp
Pessoa pessoa;
```

Atribuindo valores:

```cpp
pessoa.nome = "Isabella";
pessoa.idade = 19;
pessoa.altura = 1.66f;
```

Acessando:

```cpp
std::cout << pessoa.nome;
```

---

# Referências

```cpp
int numero = 10;

int& referencia = numero;
```

`referencia` representa a mesma variável.

```cpp
referencia = 20;
```

Agora:

```cpp
numero == 20
```

---

# Const

`const` impede modificações.

```cpp
const int numero = 10;
```

Também pode ser usado com referências:

```cpp
const Produto& produto
```

Isso significa:

```text
acessar o objeto original
+
não permitir modificá-lo
```

---

# Tratamento Básico de Entrada

Se o programa espera:

```cpp
int numero;
std::cin >> numero;
```

e o usuário digita texto, `std::cin` entra em estado de erro.

Detectar:

```cpp
if (!(std::cin >> numero)) {
}
```

Limpar o estado:

```cpp
std::cin.clear();
```

Descartar a entrada inválida:

```cpp
std::cin.ignore(
    std::numeric_limits<std::streamsize>::max(),
    '\n'
);
```

---

# Erros e Validação

Existem diferentes tipos de erro.

## Tipo inválido

Esperava:

```text
int
```

Recebeu:

```text
banana
```

---

## Valor inválido

O tipo está correto, mas o valor não faz sentido.

```cpp
int idade = -500;
```

Pode ser tratado com:

```cpp
if (idade < 0) {
}
```

---

# Try / Catch

Exceções podem ser tratadas com:

```cpp
try {
    // operação
}
catch (const std::exception& erro) {
    std::cout << erro.what();
}
```

Uma exceção pode ser lançada com:

```cpp
throw std::invalid_argument("Valor invalido");
```

Não é necessário usar exceções para todo erro.

Erros esperados normalmente podem ser tratados com validações comuns.

---

# Complexidade Básica

A quantidade de operações executadas por um algoritmo cresce conforme o tamanho da entrada.

Exemplos:

```text
O(1)
→ custo constante

O(n)
→ percorre todos os elementos

O(n²)
→ dois loops dependentes

O(log n)
→ reduz o espaço de busca a cada etapa
```

Exemplo `O(n)`:

```cpp
for (int numero : numeros) {
    std::cout << numero;
}
```

---

# Estado e Mutabilidade

O estado representa os valores atuais armazenados pelo programa.

```cpp
int contador = 0;

contador++;
```

O estado de `contador` mudou de:

```text
0 → 1
```

Uma variável mutável pode mudar.

```cpp
int numero = 10;
numero = 20;
```

Uma variável constante não pode.

```cpp
const int numero = 10;
```

---

# Modularização

Evite colocar toda a lógica dentro de `main()`.

Prefira:

```cpp
int ler_numero();
void exibir_resultado();
float calcular_media();
```

Cada função deve representar uma responsabilidade clara.

---

# Boas Práticas

- Inicialize variáveis sempre que possível.
- Use nomes claros para variáveis e funções.
- Crie funções pequenas e com responsabilidades claras.
- Evite repetição de código.
- Use `const` quando algo não deve ser modificado.
- Use `const T&` para evitar cópias desnecessárias.
- Use `T&` quando precisar modificar o objeto original.
- Valide entradas externas.
- Verifique valores antes de utilizá-los.
- Evite acessar índices inválidos.
- Mantenha os dados em estados válidos.
- Prefira recursos da biblioteca padrão.
- Evite macros quando `const` ou `constexpr` resolverem.
- Não confunda posição de um elemento com sua identidade.
- Prefira código simples e legível.
- Evite otimização prematura.
- Divida problemas grandes em problemas menores.
- Evite funções gigantes.
- Trate erros de maneira previsível.
- Escreva código pensando também em manutenção.

---

# Resumo Mental

```text
Variável
→ guarda estado

Condicional
→ toma decisões

Loop
→ repete operações

Função
→ agrupa comportamento

Struct
→ agrupa dados

Vector
→ sequência dinâmica

Referência &
→ acessa o objeto original

const
→ impede alteração

const T&
→ acessa sem copiar e sem alterar

T&
→ acessa e permite alterar
```

---

# Prioridade ao Programar

```text
1. Entender o problema
2. Fazer funcionar
3. Garantir que está correto
4. Tratar casos inválidos
5. Tornar o código legível
6. Reduzir duplicações
7. Melhorar eficiência quando necessário
```

---

## Fundamentos de Programação

**Status: Concluído ✅**