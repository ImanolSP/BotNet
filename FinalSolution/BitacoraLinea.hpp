//Created by Imanol Santisteban Piñeirua and Josefina Santacruz on 23/8/2023

#ifndef BITACORALINEA_HPP
#define BITACORALINEA_HPP

#include <iostream>
#include <string>
#include <vector>

class BitacoraLinea {
private:
    std::string fecha, hora, ipOrigen, puertoOrigen, nombreOrigen, ipDestino, puertoDestino, nombreDestino;

public:
bool operator<(const BitacoraLinea& other) const {
        return fecha < other.fecha;
    }
    BitacoraLinea(std::string _fecha, std::string _hora, std::string _ip_Origen, std::string _puerto_Origen, std::string _Nombre_Origen, std::string _IP_Destino, std::string _Puerto_Destino, std::string _Nombre_Destino);

    std::string getFecha() const;
    std::string getHora() const;
    std::string getIPOrigen() const;
    std::string getPuertoOrigen() const;
    std::string getNombreOrigen() const;
    std::string getIPDestino() const;
    std::string getPuertoDestino() const;
    std::string getNombreDestino() const;
    bool operator==(const BitacoraLinea& other) const {
    return fecha == other.fecha && hora == other.hora && ipOrigen == other.ipOrigen /* add more comparisons as needed */;
}

bool operator!=(const BitacoraLinea& other) const {
    return !(*this == other);
}
   std::string toString() const {
        std::string result;
        result += "Fecha: " + fecha + "\n";
        result += "Hora: " + hora + "\n";
        result += "IP Origen: " + ipOrigen + "\n";
        result += "Puerto Origen: " + puertoOrigen + "\n";
        result += "Nombre Origen: " + nombreOrigen + "\n";
        result += "IP Destino: " + ipDestino + "\n";
        result += "Puerto Destino: " + puertoDestino + "\n";
        result += "Nombre Destino: " + nombreDestino + "\n";
        return result;
    }


};


#endif