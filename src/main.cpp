#include <iostream>
#include <fstream>
#include <vector>

#include "tree_t.hpp"
#include "node_t.hpp"

int main()
{
    std::fstream fichero;
    std::string aux;

    std::cout << " (open) para abrir." << std::endl;
    std::cout << " (ls) para mostrar contenido directorio." << std::endl;
    std::cout << " (cd) para moverse entre directorio." << std::endl;
    std::cout << " Introduzca comando ";

    while (!fichero.is_open())
    {
        std::cout << ": ";
        aux.clear();
        std::cin >> aux;

        if (aux == "open")
        {
            std::cout << "Introduzca nombre fichero: ";
            aux.clear();
            std::cin >> aux;
            fichero.open(aux);
        }
        if (aux == "ls")
        {
            std::cout << "xD ";
        }
        if (aux == "cd")
        {
            std::cout << "xD ";
        }
    }

    std::cout << "Lectura correcta" << std::endl;
    std::vector<float> val;
    int ini, fin;

    while (!fichero.eof())
    {
        getline(fichero, aux);
        val.push_back(std::stof(aux));
    }

    std::cout << "Los nodos van del 1 al " << val[0] << " ." << std::endl;
    std::cout << "Introduzca inicio: ";
    std::cin >> ini;
    std::cout << "Introduzca fin: ";
    std::cin >> fin;

    tree_t arbol(val, ini, fin);
}