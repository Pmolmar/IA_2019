#include "node_t.hpp"

node_t::node_t(float A, int B, int C) : coste(A),
                                        id(B),
                                        prof(C), 
                                        heur(0)
{
}

node_t::~node_t()
{
}