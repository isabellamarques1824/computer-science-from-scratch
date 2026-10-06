#include <iostream>
#include <vector>

constexpr float NOTA_MINIMA_APROVADA = 5.0f;


std::vector<float> receber_notas(){

    size_t quantidade; 

    std::cout << "Quantas notas voce vai inserir: ";
    std::cin >> quantidade;

    if(quantidade <=0 ){
        std::cout << "Valor de notas inválido!!" << std::endl;
        return {};
    }

    std::vector<float> notas;

    for (size_t i = 0; i < quantidade; i++)
    {
        float nota_aluno;

        std::cout << "Nota " << i+1 << ":" << std::endl;
        std::cin >> nota_aluno;
        if(nota_aluno < 0 || nota_aluno > 10){
            std::cout << "Nota invalida" << std::endl;
            continue;
        }

        notas.push_back(nota_aluno);
    }

    return notas;

}

float acha_maior(const std::vector<float> &notas){
    float maior = notas[0];

    for(float nota: notas){
        if(nota > maior){
            maior = nota;
        }
    }

    return maior;
}

float acha_menor(const std::vector<float> &notas){
    float menor = notas[0];

    for(float nota: notas){
        if(nota < menor){
            menor = nota;
        }
    }

    return menor;
}

float acha_media(const std::vector<float> &notas){
    float soma = 0;

    for(float nota: notas){
        soma += nota;
    }
    
    return soma / notas.size();
}

std::string classificar_nota(float nota){
    if(nota < NOTA_MINIMA_APROVADA && nota >= 0){
        return "nota baixa!";
    }
    else if(nota >= NOTA_MINIMA_APROVADA && nota < 7){
        return "mediana";
    }
    else if(nota >= 7 && nota <= 10){
        return "nota boa parabens";
    }else{
        return "nota invalida amore";
    }
}

void exibir_dados(const std::vector<float> &notas, float media, float maior, float menor){
    std::cout << "NOTAS: " << std::endl;
    std::cout << std::endl;

    std::cout << "Média: " << media << std::endl;
    std::cout << "Maior nota: " << maior << std::endl;
    std::cout << "Menor nota: " << menor << std::endl;

    std::cout << std::endl;

    for(float nota: notas){
        std::string classificacao = classificar_nota(nota);
        std::cout << nota << " :  " << classificacao << std::endl;
    }
}

int main(void){
    std::vector<float> notas_dos_alunos = receber_notas();

    if(notas_dos_alunos.empty()){
        return 1;
    }

    float maior = acha_maior(notas_dos_alunos);
    float menor = acha_menor(notas_dos_alunos);
    float media = acha_media(notas_dos_alunos);

    exibir_dados(notas_dos_alunos, media, maior, menor);
}