#include "tree_t.hpp"

tree_t::tree_t(std::vector<float> A, std::vector<float> B, int C, int D) : ini(C),
                                                                           fin(D)
{
    map(A,B);
    arbol(ini, fin);
}

tree_t::~tree_t()
{
}

void tree_t::map(std::vector<float> A, std::vector<float> B)
{
    int aux = 1;
    n = A[0];

    //redimension de matriz de costes
    costes.resize(n);

    for (int i = 0; i < n; i++)
        costes[i].resize(n);

    //mapeo de costes
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; ++j)
        {
            costes[i][j] = A[aux];
            costes[j][i] = A[aux];
            aux++;
        }
        costes[i][i] = -1;
    }
    
    //mapeo de heuristicos
    for(int i = 0; i < n; ++i)
        heur[i]=B[i+1];

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; ++j)
    //         std::cout<<costes[i][j]<<'\t';
    //     std::cout<<std::endl;
    // }
}

void tree_t::arbol(int ini, int fin)
{
    node_t *aux;
    aux = new node_t(0, ini, 0, heur[ini]);

    camino(aux, fin);
}

//tengo que coger el nodo, inspeccionarlo, generar hijos, coger el nodo
//con menor heuristica sea hijo o no

//si se vuelve a repetir un nodo, vemos cual es el de menor coste y ese ok

//vamos que hay que cambiar casi todo xD

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
                nodo = new node_t(A->get_cost() + x, i, A->get_prof() + 1, heur[i + 1]);

                nodo->set_papa(A);
                if (!ready(nodo))
                {
                    A->set_son(nodo);
                    camino(nodo, fin);
                }
            }
        }
    }
}

bool tree_t::ready(node_t *A)
{
    for (unsigned int i = 0; i < inspec.size(); i++)
    {
        if (inspec[i]->get_id() == A->get_id())
            return true;
    }
    return false;
}

void tree_t::mostrar()
{
    for (unsigned int i = 0; i < nodos.size(); ++i)
        std::cout << '(' << nodos[i]->get_prof() << ')' << nodos[i]->get_id() << "->";
}