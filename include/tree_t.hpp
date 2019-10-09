#pragma once
#include "node_t.hpp"
#include <iostream>
#include <vector>

class tree_t
{
private:
    std::vector<node_t *> nodos;
    std::vector<std::vector<float>> costes;
    int ini, fin, n;

public:
    tree_t(std::vector<float> A, int B, int C);
    ~tree_t();
    void mostrar();

private:
    void map(std::vector<float> A);
    void arbol(int ini, int fin);
    void camino(node_t *A, int fin);
};