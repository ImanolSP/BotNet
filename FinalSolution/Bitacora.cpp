//Created by Imanol Santisteban Piñeirua and Josefina Santacruz on 23/8/2023

#include "Bitacora.hpp"
#include "BitacoraLinea.hpp"

#include <fstream>
#include <sstream>
#include <iostream>
#include <unordered_set>

using namespace std;
std::vector<BitacoraLinea> infoBitacora;
Bitacora::Bitacora(std::string archivo) : archivo(archivo) {}


std::vector<BitacoraLinea> Bitacora::leerBitacora() {
    std::ifstream bita;
    bita.open(archivo);
    if (!bita.is_open()) {
        std::cout << "Unable to open the file" << std::endl;
        
    }
    std::string linea;

    while (getline(bita, linea)) {
        std::istringstream ss(linea);
        std::string fecha, hora, ipOrigen, puertoOrigen, nombreOrigen, ipDestino, puertoDestino, nombreDestino;

        if (getline(ss, fecha, ',') && getline(ss, hora, ',') &&
            getline(ss, ipOrigen, ',') && getline(ss, puertoOrigen, ',') &&
            getline(ss, nombreOrigen, ',') && getline(ss, ipDestino, ',') &&
            getline(ss, puertoDestino, ',') && getline(ss, nombreDestino)) {
            BitacoraLinea nuevaLinea(fecha, hora, ipOrigen, puertoOrigen, nombreOrigen, ipDestino, puertoDestino, nombreDestino);
            infoBitacora.push_back(nuevaLinea);
        }
    }
    bita.close();
    return infoBitacora;
}

void Bitacora::insertion(std::vector<BitacoraLinea>& vec){
int n = vec.size();
    for (int i = 1; i < n; i++) {
        BitacoraLinea key = vec[i];
        int j = i - 1;
        
        while (j >= 0 && key.getFecha() < vec[j].getFecha()) {
            vec[j + 1] = vec[j];
            j = j - 1;
        }
        
        vec[j + 1] = key;
    }
}

void Bitacora::ord(){
   if (infoBitacora.empty()) {
        cout << "El vector está vacío." << endl;
        return;
    }

    insertion(infoBitacora);

}

void Bitacora::fechas() {
    if (infoBitacora.empty()) {
        cout << "El vector está vacío." << endl;
        return;
    }

    string primeraFecha = infoBitacora[0].getFecha();
    string segundaFechaDistinta = "";
    int count = 0;
    bool primeraFechaEncontrada = false;

    for (int i = 1; i < infoBitacora.size(); i++) {
        string currentDate = infoBitacora[i].getFecha();

        if (currentDate != primeraFecha) {
            if (!primeraFechaEncontrada) {
                primeraFechaEncontrada = true;
            } else if (segundaFechaDistinta.empty()) {
                segundaFechaDistinta = currentDate;
                count = 1;
            } else if (currentDate == segundaFechaDistinta) {
                count++;
            } else {
                break; // Salir del ciclo si aparece una tercera fecha distinta
            }
        }
    }

    cout << "Segunda fecha distinta: " << segundaFechaDistinta << endl;
    cout << "Número de veces que se repite la segunda fecha distinta: " << count << endl;
}

int Bitacora::renglones() {
    cout<<"Numero de renglones:";
    cout<<infoBitacora.size()<<endl;
}

void Bitacora::read() {
    // Usamos un unordered_set para guardar números únicos. 
    // Esto hace que la  búsqueda sea más rápida y eficiente para ver si un número ya se vio
    unordered_set<int> uniqueNumbers; 
    
    cout << "Puertos destino:" << endl;

    // Iteramos sobre cada línea en infoBitacora
    for (int i = 0; i < infoBitacora.size(); i++) {
        // Si el puerto de destino es "-",  seguimos con la siguiente iteración.
        if (infoBitacora[i].getPuertoDestino() == "-") {
            continue; 
        }
        
        // Convertimos el puerto de destino a un entero
        int puertoDestinoValor = stoi(infoBitacora[i].getPuertoDestino());

        // Intentamos insertar el puerto en el set.
        // Si el puerto es único (no estaba en el set), el método insert retorna un par.
        // El segundo valor del par (second) será true si el valor fue insertado con éxito (es decir, era único).
        if (uniqueNumbers.insert(puertoDestinoValor).second) {
            // Si es un puerto único, imprimimos el puerto.
            cout << puertoDestinoValor << endl;
        }
    }
}

void Bitacora::buscarServer(){
vector <string> encontrados;
int count=0;
for(int i=0; i<infoBitacora.size();i++){
    string b=infoBitacora[i].getNombreOrigen();
    string c=infoBitacora[i].getNombreDestino();
    if(b=="server.reto.com"||c=="server.reto.com"){
count++;
encontrados.push_back(b);
encontrados.push_back(c);
    }
    
    
}

if(encontrados.empty()){
        cout<<"No existen serivodres llamados server.reto.com"<<endl;
        cout<<"Encontrados:"<<count<<endl;
    }
    else{
        cout<<"Numero de server.reto.com encontrados:"<<count<<endl;;
    }
}

void Bitacora::correoE(){
    unordered_set <string> correos;
    cout << "Servicios de correo electrónico:" << std::endl;

    for (int i = 0; i < infoBitacora.size(); i++) {
        string corr = infoBitacora[i].getNombreDestino();
        int a = corr.find(".");
        string b = corr.substr(0, a);

        // Revisamos si el mail es univo para no imprimirlo mas veces.De igual manera agregamos el mail al vector.
        if ((b == "protonmail" || b == "yahoo" || b == "outlook" || b == "gmail" || b == "hotmail") &&
            correos.find(b) == correos.end()) {
            cout << b << endl;
            correos.insert(b);
        }
    }
}

void Bitacora::nombres() {
    // Imprimimos un encabezado para mostrar los nombres que coinciden.
    cout << "Nombres concordantes:" << endl;

    // Usamos un unordered_set para almacenar nombres únicos. 
    // El unordered_set garantiza una búsqueda rápida y eficiente para determinar si un nombre ya se ha visto.
    unordered_set<string> nombresUnicos;

    // Iteramos sobre cada línea en infoBitacora.
    for (int i = 0; i < infoBitacora.size(); i++) {
        // Obtenemos el nombre de origen de la línea actual.
        string nomb = infoBitacora[i].getNombreOrigen();
        
        // Buscamos la posición del primer punto en el nombre.
        int a = nomb.find(".");
        
        // Extraemos la parte del nombre que está antes del punto.
        string v = nomb.substr(0, a);

        // Verificamos si el nombre coincide con alguno de los nombres deseados.
        if (v == "raymond" || v == "samuel" || v == "benjamin" || v == "betty" || 
            v == "katherine" || v == "jeffrey" || v == "scott") {

            // Intentamos insertar el nombre en el set.
            // Si el nombre es único (no estaba en el set), el método insert retorna un par.
            // El segundo valor del par (second) será true si el valor fue insertado con éxito (es decir, era único).
            if (nombresUnicos.insert(v).second) {
                // Si el nombre es único y coincide con alguno de los nombres deseados, lo imprimimos.
                cout << v << endl;
            }
        }
    }
}
 
string Bitacora::redInter() {
    // Utilizamos un unordered_set para guardar direcciones de red únicas.
    // Los unordered_sets automáticamente manejan la unicidad de los elementos entonces is hay repetidos no los va  aguardara
    unordered_set<string> redesUnicas;

    // Iteramos a través de cada línea en infoBitacora.
    for (int i = 0; i < infoBitacora.size(); i++) {
        // Obtenemos la dirección IP de origen de la línea actual.
        string ip = infoBitacora[i].getIPOrigen();

        // sacamos la parte relevante de la dirección IP (primeros 10 caracteres).
        // Esto puede representar, por ejemplo, una subred específica o una porción particular de la dirección IP.
        string dir = ip.substr(0, 10);

        // Verificamos que la dirección extraída no sea un guion ("-").
        if (dir != "-") {
            // Insertamos la dirección en el unordered_set. 
            // Como los sets garantizan la unicidad, no tenemos que preocuparnos por duplicados.
            redesUnicas.insert(dir);
        }
    }

    // Imprimimos las direcciones de red únicas recolectadas.
    cout << "Direcciones de red:" << endl;
    string redIn;
    for (const string& red : redesUnicas) {
        cout << red << endl;
        redIn=red;
    }
    return redIn;
}



