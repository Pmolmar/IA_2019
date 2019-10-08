#include "tree_t.hpp"

tree_t::tree_t(std::vector<float> A, int B, int C) : ini(B),
                                                     fin(C)
{
    map(A);
    arbol(ini, fin);
}

tree_t::~tree_t()
{
}

void tree_t::map(std::vector<float> A)
{
    int aux = 1;
    n = A[0];

    costes.resize(A[0]);

    for (int i = 0; i < n; i++)
    {
        costes[i].resize(A[0]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; ++j)
        {
            costes[i][j] = A[aux];
            aux++;
        }
    }
}

void tree_t::arbol(int ini, int fin)
{
    node_t *aux;
    aux = new node_t(0, ini, 0);

    camino(aux, fin);
}

void tree_t::camino(node_t *A, int fin)
{
    nodos.push_back(A);

    if (A->get_id() != fin)
    {
        for (int i = 0; i < n; ++i)
        {
            float x = costes[A->get_id()][i];

            if (x != 0)
            {
                node_t *nodo;
                nodo = new node_t(A->get_cost() + x, i, A->get_prof() + 1);

                nodo->set_papa(A);
                A->set_son(nodo);

                camino(nodo, fin);
            }
        }
    }
}

void tree_t::mostrar()
{
    for(int i = 0; i < nodos.size(); ++i)
        std::cout<< nodos[i]->get_id();
    // traza(nodos[0], 0);
}

void tree_t::traza(node_t *A, int i)
{
    std::cout << A->get_id() << "{" << A->get_prof() << "}"
              << "--->";
    if (i < nodos.size())
        traza(nodos[i + 1], i + 1);
}