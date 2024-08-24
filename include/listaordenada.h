#ifndef LISTAORDENADA_H
#define LISTAORDENADA_H

#include <vector>
#include <algorithm>
#include <string>
#include "termo.h"

template <typename T>
class ListaOrdenada {
private:
    std::vector<T> lista;

public:
    void inserir(const T& item);
    std::vector<T> buscar(const std::string& prefixo, int k) const;
};

#include "../src/listaordenada.cpp"  // Inclui a implementação do template

#endif // LISTAORDENADA_H
