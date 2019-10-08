#pragma once
#include <iostream>
#include <vector>

class node_t
{
private:
    node_t *padre;
    std::vector<node_t *> hijos;
    float coste;
    float heur;
    int id;
    int prof;

public:
    node_t(float A, int B, int C);
    ~node_t();
};