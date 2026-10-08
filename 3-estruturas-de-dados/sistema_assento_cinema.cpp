#include <iostream>
#include <limits>

int ler_int(const std::string &message, int minimo, int maximo){
    while(true){
        int inteiro;

        std::cout<< message;

        if(!(std::cin>> inteiro)){
            std::cout<< "Insira um numero inteiro: \n";

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            continue;
        }

        if(inteiro < minimo || inteiro > maximo){
            std::cout << "Insira um valor valido\n";
            continue;
        }

        return inteiro;
    }
}

void exibir_sala(){

}

void reservar_assento(){

}

void cancelar_reserva(){

}

void transferir_reserva(){

}

void bloquear_assento(){

}

void desbloquear_assento(){

}

void reservar_grupo(){

}

void exibir_relatorio(){

}

void reorganizar_fileira(){

}


int main(void){
    while(true){
        std::cout<< '\n';
        std::cout<< "========================================\n";
        std::cout<< "       SISTEMA DE ASSENTOS - CINEMA\n";
        std::cout<< "========================================\n";

        std::cout<< '\n';
        std::cout<< "1. Exibir mapa da sala\n";
        std::cout<< "2. Reservar assento\n";
        std::cout<< "3. Cancelar reserva\n";
        std::cout<< "4. Transferir reserva\n";
        std::cout<< "5. Bloquear assento\n";
        std::cout<< "6. Desbloquear assento\n";
        std::cout<< "7. Reservar assentos para grupo\n";
        std::cout<< "8. Exibir relatório da sala\n";
        std::cout<< "9. Reorganizar uma fileira\n";
        std::cout<< '\n';

        std::cout<< "0. Sair\n";
        std::cout<< '\n';

        std::cout<< "Escolha uma opcao:\n";
        int opcao = ler_int(">", 0, 9);

        switch (opcao)
        {
        case 0:
            return 0;
        case 1:
            exibir_sala();
            break;
        case 2:
            reservar_assento();
            break;
        case 3:
            cancelar_reserva();
            break;
        case 4:
            transferir_reserva();
            break;
        case 5:
            bloquear_assento();
            break;
        case 6:
            desbloquear_assento();
            break;
        case 7:
            reservar_grupo();
            break;
        case 8:
            exibir_relatorio();
            break;
        case 9:
            reorganizar_fileira();
            break;
        default:
            std::cout<< "Opcao invalida\n";
            break;
        }


    }
}