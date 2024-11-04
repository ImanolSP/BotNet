//Created by Imanol Santisteban Piñeirua and Josefina Santacruz on 23/8/2023

#ifndef BITACORA_HPP
#define BITACORA_HPP
using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include "BitacoraLinea.hpp"


class Bitacora {
private:
    std::string archivo;

public:

    Bitacora(std::string archivo);
    void fechas();
    std::vector<BitacoraLinea>leerBitacora();
    int renglones();
    void read();
    void buscarServer();
    void nombres();
    void correoE();
    string redInter();
    void insertion(std::vector<BitacoraLinea>& vec);
    void ord();
};

#endif