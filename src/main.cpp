#include <iostream>
#include "../include/autocompletar.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Uso: " << argv[0] << " <arquivo_dados> <k>" << std::endl;
        return 1;
    }

    std::string arquivoDados = argv[1];
    int k = std::stoi(argv[2]);

    Autocompletar autocompletar;
    try {
        autocompletar.carregarDados(arquivoDados);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    std::string prefixo;
    while (true) {
        std::cout << "Entre com o termo a ser auto-completado: (digite \"sair\" para encerrar o programa): " << std::endl;
        std::getline(std::cin, prefixo);
        if (prefixo == "sair") {
            break;
        }

        auto resultados = autocompletar.procurar(prefixo, k);
        for (const auto& termo : resultados) {
            std::cout << termo.getId() << " " << termo.getNome() << std::endl;
        }
    }

    return 0;
}
