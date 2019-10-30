#include "node_t.hpp"

node_t::node_t(float A, int B, int C, float D) : coste(A),
                                                 id(B),
                                                 prof(C),
                                                 heur(D)
{
}

node_t::~node_t()
{
}

bool node_t::antecesor(int i)
{
    if (padre->get_id() == get_id())
        return false;

    if (padre->get_id() == i)
        return true;
    else
        padre->antecesor(i);
}