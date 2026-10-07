#include <iostream>

int main() {
    // Cada variável booleana representa uma proposição:
    //
    // p = "O usuário é administrador"
    // q = "O usuário é moderador"
    // r = "O usuário está bloqueado"

    bool admin = true;
    bool moderador = false;
    bool bloqueado = false;

    // Expressão lógica:
    //
    // (p ∨ q) ∧ ¬r
    //
    // Em programação:
    // (admin || moderador) && !bloqueado
    //
    // A expressão exige duas condições:
    // 1. O usuário deve ser administrador OU moderador.
    // 2. O usuário NÃO pode estar bloqueado.

    bool podeAcessar = (admin || moderador) && !bloqueado;

    std::cout << std::boolalpha;

    std::cout << "Admin: " << admin << '\n';
    std::cout << "Moderador: " << moderador << '\n';
    std::cout << "Bloqueado: " << bloqueado << '\n';

    // Com os valores atuais:
    //
    // (V ∨ F) ∧ ¬F
    // V ∧ V
    // V
    //
    // Portanto, a expressão final é verdadeira.

    std::cout << "\nExpressao: (admin || moderador) && !bloqueado\n";
    std::cout << "Resultado: " << podeAcessar << '\n';

    return 0;
}