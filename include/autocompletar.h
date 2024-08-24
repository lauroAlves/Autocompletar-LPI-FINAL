#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include "listaordenada.h"
#include "termo.h"
#include <string>
#include <vector>

class Autocompletar {
private:
    ListaOrdenada<Termo> listaTermos;

public:
    void carregarDados(const std::string& arquivoDados);
    std::vector<Termo> procurar(const std::string& prefixo, int k) const;
};

#endif // AUTOCOMPLETE_H
