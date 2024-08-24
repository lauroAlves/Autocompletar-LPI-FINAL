#include "../include/autocompletar.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

void Autocompletar::carregarDados(const std::string& arquivoDados) {
    std::ifstream arquivo(arquivoDados);
    std::string linha;

    if (!arquivo.is_open()) {
        throw std::runtime_error("Não foi possível abrir o arquivo.");
    }

    while (std::getline(arquivo, linha)) {
        std::istringstream iss(linha);
        long id;
        std::string nome;
        if (!(iss >> id)) continue; // Lê o ID
        std::getline(iss, nome);   // Lê o nome
        nome = nome.substr(1);     // Remove o espaço extra no início do nome
        listaTermos.inserir(Termo(nome, id));
    }
}

std::vector<Termo> Autocompletar::procurar(const std::string& prefixo, int k) const {
    return listaTermos.buscar(prefixo, k);
}
