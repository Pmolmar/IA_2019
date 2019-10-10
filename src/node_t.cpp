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