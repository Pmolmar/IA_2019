#pragma once
#include "node_t.hpp"
#include <iostream>
#include <vector>

class tree_t
{
private:
    std::vector<node_t *> nodos;
    std::vector<node_t *> inspec;
    std::vector<std::vector<float>> costes;
    std::vector<float> heur;
    int ini, fin, n;

public:
    tree_t(std::vector<float> costes, std::vector<float> heuristicos, int ini, int fin);
    ~tree_t();
    void mostrar();

private:
    void map(std::vector<float> coste, std::vector<float> heur);
    void arbol(int ini, int fin);
    void camino(node_t *A, int fin);
    bool ready (node_t* A);
};