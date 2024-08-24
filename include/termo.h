#ifndef TERMO_H
#define TERMO_H

#include <string>

class Termo {
private:
    std::string nome;
    long id;

public:
    // Construtor padrão
    Termo();

    // Construtor com parâmetros
    Termo(const std::string& nome, long id);

    std::string getNome() const;
    long getId() const;
};

#endif // TERMO_H
