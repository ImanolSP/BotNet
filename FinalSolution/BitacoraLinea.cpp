//Created by Imanol Santisteban Piñeirua and Josefina Santacruz on 23/8/2023

#include "BitacoraLinea.hpp"

#include <sstream>
#include <iostream>
BitacoraLinea::BitacoraLinea(std::string _fecha, std::string _hora, std::string _ip_Origen, std::string _puerto_Origen, std::string _Nombre_Origen, std::string _IP_Destino, std::string _Puerto_Destino, std::string _Nombre_Destino)
    : fecha(_fecha), hora(_hora), ipOrigen(_ip_Origen), puertoOrigen(_puerto_Origen), nombreOrigen(_Nombre_Origen), ipDestino(_IP_Destino), puertoDestino(_Puerto_Destino), nombreDestino(_Nombre_Destino) {

}
std::string BitacoraLinea::getFecha() const {
    return fecha;
}

std::string BitacoraLinea::getHora() const {
    return hora;
}

std::string BitacoraLinea::getIPOrigen() const {
    return ipOrigen;
}

std::string BitacoraLinea::getPuertoOrigen() const {
    return puertoOrigen;
}

std::string BitacoraLinea::getNombreOrigen() const {
    return nombreOrigen;
}

std::string BitacoraLinea::getIPDestino() const {
    return ipDestino;
}

std::string BitacoraLinea::getPuertoDestino() const {
    return puertoDestino;
}

std::string BitacoraLinea::getNombreDestino() const {
    return nombreDestino;
}

