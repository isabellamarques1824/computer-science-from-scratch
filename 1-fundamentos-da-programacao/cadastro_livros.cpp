 #include <iostream>
 #include <string>
 #include <vector>
 #include <limits>

 struct Livro {
    int id;
    std::string titulo;
    int paginas;
    float preco;
};

int ler_int(const std::string &message,int minimo, int maximo){
    while(true){
        int inteiro;

        std::cout << message;

        if(!(std::cin>>inteiro)){
            std::cout << "Entrada invalida. Digite um numero inteiro.\n";

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Tente novamente: \n";
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if(inteiro > maximo || inteiro < minimo){
            std::cout << "Numero invalido digitado, tente novamente..\n";
            continue;
        }

        return inteiro;

    }


}

std::string ler_string(const std::string &message){
    std::string texto;

    while(true){
        std::cout << message;
        
        std::getline(std::cin, texto);

        if(texto.empty()){
            std::cout << "O texto nao pode estar vazio..\n";
            continue;
        }

        return texto;
    }
}

float ler_preco(const std::string& message) {
    float preco;

    while (true) {
        std::cout << message;

        if (!(std::cin >> preco)) {
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

        if (preco < 0) {
            std::cout << "O preco nao pode ser negativo.\n";
            continue;
        }

        return preco;
    }
}

void exibir_livro(const Livro &livro){
    std::cout<< '\n';
    std::cout<< "ID: " << livro.id << '\n';
    std::cout<< "Titulo: " << livro.titulo << '\n';
    std::cout<< "Paginas: " << livro.paginas << '\n';
    std::cout<< "Preco: " << livro.preco << '\n';
    std::cout<< '\n';
}


//1. Adicionar livro

void adicionar_livro(std::vector<Livro> &livros, int &proximo_id){
    Livro novo_livro;

    novo_livro.titulo = ler_string("Digite o titulo do livro: \n");
    novo_livro.paginas = ler_int("Quantas paginas o livro tem: \n", 1, 5000);
    novo_livro.preco = ler_preco("Digite o preco do livro: \n");

    novo_livro.id = proximo_id;

    livros.push_back(novo_livro);

    proximo_id++;

}

//2. Listar livros

void listar_livros(const std::vector<Livro> &livros){
    if (livros.empty()) {
        std::cout << "Nenhum livro cadastrado.\n";
        return;
    }

    for(const Livro &livro: livros){
        exibir_livro(livro);
    }

}

//3. Buscar livro por ID

void buscar_por_id(const std::vector<Livro> &livros){

    int busca_id = ler_int("Digite o ID do livro: ",0,std::numeric_limits<int>::max());

    for(const Livro &livro: livros){
        if(busca_id == livro.id){
            exibir_livro(livro);
            return;
        }
    }

    std::cout<< "ID não encontrado.\n";
}

//4. Atualizar preco

void atualizar_preco(std::vector<Livro> &livros){
        
    int busca_id = ler_int("Digite o ID do livro: ",0,std::numeric_limits<int>::max());

    for(Livro &livro: livros){
        if(busca_id == livro.id){
            float novo_preco = ler_preco("Digite o novo preco: \n");
            livro.preco = novo_preco;

            std::cout<< "Preco atualizado com sucesso\n";
            return;
        }
  
    }

    std::cout << "ID nao encontrado\n";  
}

//5. Remover livro

void remover_livro(std::vector<Livro> &livros){

    int busca_id = ler_int("Digite o ID do livro: ",0,std::numeric_limits<int>::max());

    for (size_t i = 0; i < livros.size(); i++)
    {
        if(livros[i].id  == busca_id){
            livros.erase(livros.begin() + i);

            std::cout << "Livro removido com sucesso!\n";
            return;
        }
    }

    std::cout<<"ID nao encontrado\n";
}

int main(void){
    std::vector<Livro> livros;
    int proximo_id = 0;

    std::cout << "=== ESTOQUE DE LIVRO ===\n";

    while(true){
        std::cout << "1. Adicionar livro\n";
        std::cout << "2. Listar livros\n";
        std::cout << "3. Buscar livro\n";
        std::cout << "4. Atualizar preco\n";
        std::cout << "5. Remover livro\n";
        std::cout << "6. Sair\n";

        int escolha = ler_int("Escolha uma opcao: \n", 1, 6);

        switch (escolha)
        {
        case 1:
            adicionar_livro(livros, proximo_id);
            break;
        case 2:
            listar_livros(livros);
            break;
        case 3:
            buscar_por_id(livros);
            break;
        case 4:
            atualizar_preco(livros);
            break;
        case 5:
            remover_livro(livros);
            break;
        case 6:
            return 0;
        default:
            std::cout << "Escolha invalida! tente novamente..\n";
            break;
        }
    }
}