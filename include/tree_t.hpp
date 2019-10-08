#pragma once
#include "node_t.hpp"
#include <iostream>
#include <vector>

class tree_t
{
private:
    std::vector<node_t> nodos;
    std::vector<std::vector<float>> costes;
    int ini, fin;

public:
    tree_t(std::vector<float> A, int B, int C);
    ~tree_t();

private:
    void nodos(std::vector<float> A);
};