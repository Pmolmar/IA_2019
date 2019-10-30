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
    std::string dir = ".";
    bool end = false;

    while (!end)
    {
        std::cout <<"-----------------------------"<<std::endl;
        std::cout << " (open) para abrir." << std::endl;
        std::cout << " (list) para mostrar contenido directorio." << std::endl;
        std::cout << " (goto) para moverse entre directorios. " << std::endl;
        std::cout << " (home) para volver al directorio inicial" << std::endl;
        std::cout << " (exit) salida. " << std::endl;
        std::cout << " Introduzca comando ";

        while ((!f1.is_open()) && (!f2.is_open()))
        {
            std::cout <<": ";
            aux.clear();
            std::cin >> aux;

            if (aux == "open")
            {
                std::cout << "Introduzca nombre f1: ";
                aux.clear();
                std::cin >> aux;
                aux = dir + "/" + aux;
                f1.open(aux);

                std::cout << "Introduzca nombre f2: ";
                aux.clear();
                std::cin >> aux;
                aux = dir + "/" + aux;
                f2.open(aux);
            }
            if (aux == "list")
            {
                aux = ("ls -l ");
                aux = aux + dir + " | cut -d ' ' -f 10";
                system(aux.c_str());
            }
            if (aux == "goto")
            {
                std::cout << "Introduzca directorio: ";
                std::cin >> aux;
                dir.push_back('/');
                dir = dir + aux;
            }
            if (aux == "exit")
            {
                end = true;
                break;
            }
            if(aux == "home")
                dir = ".";
        }

        if ((f1.is_open()) && (f2.is_open()))
        {
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

            f1.close();
            f2.close();

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
                std::cout << "Ficheros incompatibles." << std::endl;
        }
    }
}