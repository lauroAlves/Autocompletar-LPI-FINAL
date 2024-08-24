#include "../include/listaordenada.h"

template <typename T>
void ListaOrdenada<T>::inserir(const T& item) {
    lista.push_back(item);
    std::sort(lista.begin(), lista.end(), [](const T& a, const T& b) {
        return a.getNome() < b.getNome();
    });
}

template <typename T>
std::vector<T> ListaOrdenada<T>::buscar(const std::string& prefixo, int k) const {
    std::vector<T> resultados;
    for (const auto& item : lista) {
        if (item.getNome().find(prefixo) == 0) {
            resultados.push_back(item);
        }
    }
    std::sort(resultados.begin(), resultados.end(), [](const T& a, const T& b) {
        return a.getNome() < b.getNome();
    });
    if (resultados.size() > k) {
        resultados.resize(k);
    }
    return resultados;
}
