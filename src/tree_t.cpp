#include "tree_t.hpp"

tree_t::tree_t(std::vector<float> A, std::vector<float> B, int C, int D) : ini(C),
                                                                           fin(D)
{
    map(A, B);
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

    // mapeo de costes
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
    for (int i = 0; i < n; ++i)
        heur.push_back(B[i + 1]);
}

void tree_t::arbol(int ini, int fin)
{
    node_t *aux;
    aux = new node_t(0, ini, 0, heur[ini]);

    inspec.push_back(aux);
    aux->set_papa(aux);
    camino(aux, fin);
}

//tengo que coger el nodo, inspeccionarlo, generar hijos, coger el nodo
//con menor heuristica sea hijo o no

//si se vuelve a repetir un nodo, vemos cual es el de menor coste y ese ok

//vamos que hay que cambiar casi todo xD

void tree_t::camino(node_t *A, int fin)
{
    if(A->get_id()!=fin)
        if (ready(A))
        {
            nodos.push_back(A);
            if (A->get_cost() <= inspec[inspec.size() - 1]->get_cost())
            {
                inspec.push_back(A);
                generate_sons(A);
                node_t *aux;
                aux = less_heur();
                camino(aux, fin);
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

void tree_t::generate_sons(node_t *A)
{
    for (int i = 0; i < n; ++i)
    {
        float x = costes[A->get_id()][i];

        if ((x != 0) && (A->get_papa()->get_id() != i))
        {
            node_t *nodo;
            nodo = new node_t(A->get_cost() + x, i, A->get_prof() + 1, heur[i + 1]);

            nodo->set_papa(A);
            nodos.push_back(nodo);
            A->set_son(nodo);
        }
    }
}

node_t *tree_t::less_heur()
{
    node_t *aux;
    aux = inspec[0];
    for (unsigned int i = 0; i < nodos.size(); ++i)
    {
        if ((nodos[i]->get_cost() < inspec[inspec.size() - 1]->get_cost()) && (nodos[i]->get_cost() < aux->get_cost()))
            aux = nodos[i];
    }
    return aux;
}

void tree_t::mostrar()
{
    node_t *aux = inspec[inspec.size() - 1];
    std::cout << aux->get_id() << "-->";
    aux = aux->get_papa();
    while (aux->get_id() != aux->get_papa()->get_id())
    {
        std::cout << aux->get_id() << "-->";
        aux = aux->get_papa();
    }
}