#include <iostream>
#include <fstream>
#include <vector>

#include "tree_t.hpp"
#include "node_t.hpp"

int main()
{
    std::fstream f1;
    std::fstream f2;
    std::string aux;

    std::cout << " (open) para abrir." << std::endl;
    std::cout << " (ls) para mostrar contenido directorio." << std::endl;
    std::cout << " (cd) para moverse entre directorio." << std::endl;
    std::cout << " Introduzca comando ";

    while ((!f1.is_open()) && (!f2.is_open()))
    {
        std::cout << ": ";
        aux.clear();
        std::cin >> aux;

        if (aux == "open")
        {
            std::cout << "Introduzca nombre f1: ";
            aux.clear();
            std::cin >> aux;
            f1.open(aux);

            std::cout << "Introduzca nombre f2: ";
            aux.clear();
            std::cin >> aux;
            f2.open(aux);
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
    std::vector<float> heu;
    int ini, fin;

    while (!f1.eof())
    {
        getline(f1, aux);
        val.push_back(std::stof(aux));
    }

    while (!f2.eof())
    {
        getline(f2, aux);
        heu.push_back(std::stof(aux));
    }

    if (val[0] == heu[0])
    {
        std::cout << "Los nodos van del 0 al " << val[0] - 1 << " ." << std::endl;
        std::cout << "Introduzca inicio: ";
        std::cin >> ini;
        std::cout << "Introduzca fin: ";
        std::cin >> fin;

        tree_t arbol(val, heu, ini, fin);
        arbol.mostrar();
    }
    else
        std::cout<<"Fichero no valido."<<std::endl;
}