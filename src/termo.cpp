#include "../include/termo.h"

Termo::Termo() : nome(""), id(0) {}

Termo::Termo(const std::string& nome, long id) : nome(nome), id(id) {}

std::string Termo::getNome() const {
    return nome;
}

long Termo::getId() const {
    return id;
}
