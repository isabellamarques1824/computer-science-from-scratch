#include <iostream>
#include <vector>
#include <string>
#include <limits>

struct Produto {
    int id;
    std::string name;
    int quantidade;
    float preco;
};

int ler_inteiro(const std::string& mensagem, int minimo, int maximo) {
    int valor;

    while (true) {
        std::cout << mensagem;

        if (!(std::cin >> valor)) {
            std::cout << "Entrada invalida. Digite um numero inteiro.\n";

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        if (valor < minimo || valor > maximo) {
            std::cout << "Valor fora do intervalo permitido.\n";
            continue;
        }

        return valor;
    }
}


float ler_preco(const std::string& mensagem) {
    float valor;

    while (true) {
        std::cout << mensagem;

        if (!(std::cin >> valor)) {
            std::cout << "Entrada invalida. Digite um numero.\n";

            std::cin.clear();

            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n'
            );

            continue;
        }

        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(),
            '\n'
        );

        if (valor < 0) {
            std::cout << "O preco nao pode ser negativo.\n";
            continue;
        }

        return valor;
    }
}


std::string ler_texto(const std::string& mensagem) {
    std::string texto;

    while (true) {
        std::cout << mensagem;

        std::getline(std::cin, texto);

        if (texto.empty()) {
            std::cout << "O texto nao pode estar vazio.\n";
            continue;
        }

        return texto;
    }
}


// -------------------------
// PRODUTO
// -------------------------

void exibir_produto(const Produto& produto) {
    std::cout << "\n";
    std::cout << "ID: " << produto.id << '\n';
    std::cout << "Nome: " << produto.name << '\n';
    std::cout << "Preco: " << produto.preco << '\n';
    std::cout << "Quantidade: " << produto.quantidade << '\n';
}


void adicionar_produto(
    std::vector<Produto>& produtos,
    int& proximo_id
) {
    Produto novo_produto;

    novo_produto.name = ler_texto(
        "Digite o nome do novo produto: "
    );

    novo_produto.preco = ler_preco(
        "Digite o preco do novo produto: "
    );

    novo_produto.quantidade = ler_inteiro(
        "Quantidade disponivel: ",
        0,
        std::numeric_limits<int>::max()
    );

    novo_produto.id = proximo_id;

    produtos.push_back(novo_produto);

    // Só incrementa depois que o produto realmente foi inserido
    proximo_id++;

    std::cout << "Produto adicionado com sucesso!\n";
    std::cout << "ID do produto: " << novo_produto.id << '\n';
}


void listar_produtos(const std::vector<Produto>& produtos) {
    if (produtos.empty()) {
        std::cout << "Nao existem produtos cadastrados.\n";
        return;
    }

    for (const Produto& produto : produtos) {
        exibir_produto(produto);
    }
}


void buscar_produto(const std::vector<Produto>& produtos) {
    int busca_id = ler_inteiro(
        "Digite o ID do produto desejado: ",
        0,
        std::numeric_limits<int>::max()
    );

    for (const Produto& produto : produtos) {
        if (produto.id == busca_id) {
            exibir_produto(produto);
            return;
        }
    }

    std::cout << "Produto nao encontrado.\n";
}


void atualizar_quantidade(std::vector<Produto>& produtos) {
    int busca_id = ler_inteiro(
        "Digite o ID do produto: ",
        0,
        std::numeric_limits<int>::max()
    );

    for (Produto& produto : produtos) {
        if (produto.id == busca_id) {

            produto.quantidade = ler_inteiro(
                "Digite a nova quantidade: ",
                0,
                std::numeric_limits<int>::max()
            );

            std::cout << "Quantidade atualizada com sucesso!\n";
            return;
        }
    }

    std::cout << "Produto nao encontrado.\n";
}


void remover_produto(std::vector<Produto>& produtos) {
    int busca_id = ler_inteiro("Digite o ID do produto: ",0,std::numeric_limits<int>::max());

    for (std::size_t i = 0; i < produtos.size(); i++) {
        if (produtos[i].id == busca_id) {

            produtos.erase(produtos.begin() + i);

            std::cout << "Produto removido com sucesso!\n";
            return;
        }
    }

    std::cout << "Produto nao encontrado.\n";
}


// -------------------------
// MAIN
// -------------------------

int main() {
    std::vector<Produto> produtos;

    int proximo_id = 0;

    while (true) {
        std::cout << "\n";
        std::cout << "== BEM VINDO AO ESTOQUE ==\n";
        std::cout << "1. Adicionar produto\n";
        std::cout << "2. Listar produtos\n";
        std::cout << "3. Buscar produto\n";
        std::cout << "4. Atualizar quantidade\n";
        std::cout << "5. Remover produto\n";
        std::cout << "6. Sair\n";

        int escolha = ler_inteiro(
            "Escolha uma opcao: ",
            1,
            6
        );

        switch (escolha) {
            case 1:
                adicionar_produto(produtos, proximo_id);
                break;

            case 2:
                listar_produtos(produtos);
                break;

            case 3:
                buscar_produto(produtos);
                break;

            case 4:
                atualizar_quantidade(produtos);
                break;

            case 5:
                remover_produto(produtos);
                break;

            case 6:
                std::cout << "Encerrando o programa...\n";
                return 0;
        }
    }
}