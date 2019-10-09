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
    node_t(float coste, int id, int profundidad);
    ~node_t();

    void set_papa(node_t *A) { padre = A; };
    node_t *get_papa() { return padre; };

    void set_son(node_t *A) { hijos.push_back(A); };
    std::vector<node_t *> &get_son() { return hijos; };

    int get_prof() { return prof; };
    int get_id() { return id; };
    float get_cost() { return coste; };
};