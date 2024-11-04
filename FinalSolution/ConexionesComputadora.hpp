/*
Created by Imanol Santisteban Piñeirua and Josefina Santacruz on 9/9/2023
Programa que crea y llena las estrucutras de datos elegidas, de igual manera, se implementan diferentes funciones para encontrar el tamaño
y si existen 3 conexiones iguales consecutivas
*/


#ifndef ConexionesComputadora_HPP
#define ConexionesComputadora_HPP
#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include "LinkedList.hpp"
#include "Stack.hpp"
#include "BitacoraLinea.hpp"
#include "BST.hpp"
#include "BinaryTree.hpp"
#include"TreeNode.hpp"
#include "Graph.hpp"


template <typename T>
class ConexionesComputadora{
private:
    std::string ip = "";
    std::string nombre = "";
    Stack<T> *conexionesEntrantes = new Stack<T>();
    Stack<T> *conexionesEntrantes1 = new Stack<T>();
    LinkedList<T> *conexionesSalientes = new LinkedList<T>();
    Graph<std::string, T>* grafoA=new Graph<std::string,T>();
    Graph<std::string, T>* grafoCon=new Graph<std::string,T>();

public:
    ConexionesComputadora() = default;
    ConexionesComputadora(std::string _ip, std::string _name) : ip(_ip), nombre(_name) {};
    Stack<T>* getconexionesEntrantes();
    Stack<T>* getconexionesEntrantes1();
    LinkedList<T>* getconexionesSalientes();
    std::string setIp(std::string interna);
    std::string getip(std::string redinter);
    void llenarconexiones(std::vector<T>& infoBitacora,std::string ip);
    void llenarconexionesA(std::vector<T>& infoBitacora,std::string internal);
    void llenarconexionesInt(std::vector<T>& infoBitacora);
    int NumeroDeConexionesC(std::string);
    bool EsLaMasConectada(std::string A);
    int totalConexionesEntrantes();
    std::map<std::string, int> ConexionesSalientesdeA(std::string);
    void ConexionesEntrantesA(std::string);
    std::string mismoTop5Siempre(int n);
    int totalConexionesSalientes();
    T ultimaconexionEntrante();
    void tresConexCons();
    bool esIPInterna(std::string ip);
    std::string tieneTresConexionesSeguidas();
    
    class Sit {
        public:
  std::string name; 
  int conexiones;  
  bool operator>(const Sit &other) const {
        // esto se hizo ya que la funcion insert no contaba con la sobrecarga ecesaria para manejar este tipo
        return conexiones > other.conexiones;
    }
    bool operator==(const Sit &other) const {
        // esto se hizo ya que la funcion insert no contaba con la sobrecarga ecesaria para manejar este tipo
        return (name == other.name) && (conexiones == other.conexiones);
    }
~Sit(){}

Sit(std::string name, int conexiones) {
    this->name = name;
    this->conexiones = conexiones; 
  }
};

    std::vector<std::string> top5CadaDia();
    std::vector<std::string> subsequente();
    std::string sitioConTraficoAlto();

    std::map<std::string,int> conexionesPorDia(std::string fecha);

    void top(int,std::string);

    void topPorFecha(int);
    std::unordered_map<std::string, std::pair<int, int> >  crearMapaConexiones(std::vector<T>& infoBitacora);
    std::unordered_map<std::string, std::string> IpDeSitio(std::vector<T>& infoBitacora);
    std::set<std::string> nombresSitios(std::vector<T>& infoBitacora);
    std::set<std::string> IpDominioRaro(std::unordered_map<std::string, std::string>);
    void cantidadComputadoras(std::unordered_map<std::string, std::pair<int, int> > mapaConexiones,std::vector<T>& infoBitacora);
    std::set<std::string> NoServidorDHCP(std::vector<T>& infoBitacora,std::set<std::string> sitios);
    void comunicEntreIp(std::set<std::string>,std::set<std::string>,std::vector<T>& infoBitacora);

    ~ConexionesComputadora() {
        if (conexionesEntrantes) {
        delete conexionesEntrantes;
    }
    if (conexionesSalientes) {
        delete conexionesSalientes;
    }
    if (conexionesEntrantes1) {
        delete conexionesEntrantes1;
    }
    if (grafoA) {
        delete grafoA;
    }
    if (grafoCon) {
        delete grafoCon;
    }
    }

};



template <class T>
std::string ConexionesComputadora<T>::getip(std::string redinter) {
    
    return ip; 
}

template <class T>
std::string ConexionesComputadora<T>::setIp(std::string interna) {
    std::string val;
    std::cout << "Enter the number:" << std::endl;
    std::cin >> val;
    ip = interna + '.' + val;
    return ip;
}

template <class T>
void ConexionesComputadora<T>::llenarconexiones(std::vector<T>& infoBitacora,std::string ip) {
     
    for (auto lineas : infoBitacora) {
        if (lineas.getIPOrigen() == ip) {
            conexionesSalientes->insert_back(lineas);
        } else if (lineas.getIPDestino() == ip) {
            conexionesEntrantes->push(lineas);
        }
    }
    for(auto lineas:infoBitacora){
        conexionesEntrantes1->push(lineas);
    }
}

template <class T>
int ConexionesComputadora<T>::totalConexionesEntrantes() {
    Node<T>* tmp = conexionesEntrantes->top();
    while (tmp != nullptr) {
        T dato = tmp->getInfo();
        std::cout << "Fecha: " << dato.getFecha() << std::endl;
        std::cout << "Nombre Destino: " << dato.getNombreDestino() << std::endl;
        // Print other relevant connection information as needed
        tmp = tmp->getNext();}
    return conexionesEntrantes->size();
}

template <class T>
int ConexionesComputadora<T>::totalConexionesSalientes() {
    return conexionesSalientes->size();
}

template <class T>
T ConexionesComputadora<T>::ultimaconexionEntrante(){
    Node<T>* topNode = conexionesEntrantes->top();
        return topNode->getInfo(); 
}
template <class T>
bool ConexionesComputadora<T>::esIPInterna(std::string ip) {
    // Aquí estamos usando solo dos patrones comunes de IPs internas
    if (ip.find("192.168.") == 0 || ip.find("10.") == 0) {
        return true;
    }
    return false;
}

template <class T>
std::string ConexionesComputadora<T>::tieneTresConexionesSeguidas() {
    int contador = 0;
    std::string sitioPrevio = "";
    Node<T>* current = conexionesSalientes->first();

    while (current) {
        T conexion = current->getInfo();
        if (conexion.getPuertoDestino() == "80" || conexion.getPuertoDestino() == "433") {
            if (sitioPrevio == "" || sitioPrevio == conexion.getIPDestino()) {
                contador++;
            } else {    
                contador = 1; // reset
            }

            if (contador == 3) {
                return sitioPrevio;
            }

            sitioPrevio = conexion.getIPDestino();
        }
        current = current->getNext();
    }

    return ""; // regresa string vacio si no se encontraron 3 conexiones consecutivas
}

template <class T>
std::map<std::string,int> ConexionesComputadora<T>::conexionesPorDia(std::string fecha){
std::map<std::string,int> conexporsitio;
Node<T>*tmp=conexionesEntrantes1->top();

for(tmp;tmp!=nullptr;tmp=tmp->getNext()){
    T dato=tmp->getInfo();
    if(dato.getFecha()==fecha){
        if(dato.getNombreDestino()!="-"&&dato.getNombreDestino()!="reto.com"){
            conexporsitio[dato.getNombreDestino()]++;
        }
    }
}
return conexporsitio;

}

template <class T>
void ConexionesComputadora<T>::top(int n, std::string fecha) {
    BST<Sit>*bst=new BST<Sit>();
    std::map<std::string, int> sites = conexionesPorDia(fecha);

    for (auto& site : sites) {
        TreeNode<Sit>*val= new TreeNode<Sit>(Sit(site.first,site.second));
        bst->insert(val);
    }

    std::vector<Sit> topSites = bst->topNod(n); 
    int rank=0;
    std::cout << "Top " << n << " sitios con el mayor número de conexiones " << fecha << ":" << std::endl;
     std::cout<<""<<std::endl;
    for (const Sit& site : topSites) {
        rank++;
        std::cout <<rank<<"->"<< site.name << " - " << site.conexiones << " conexiones" << std::endl;
        std::cout<<""<<std::endl;
    }
    
    topSites.clear();
    bst->clear();
    if (bst->empty() == true) {
        std::cout << "vacio" << std::endl;
    } else {
        std::cout << "lleno" << std::endl;
    }
  delete bst;
}

template <class T>
void ConexionesComputadora<T>::topPorFecha(int n){
std::vector<std::string> fechasunicas;
std::map<std::string, int> conexporfecha;
Node<T>* tmp=nullptr;
tmp = conexionesEntrantes1->top();
        while (tmp != nullptr) {
            T dato = tmp->getInfo();
            std::string fecha = dato.getFecha();
            conexporfecha[fecha] += 1;
            tmp = tmp->getNext();
}

for (const auto& entry : conexporfecha) {
            std::string fecha = entry.first;
            top(n, fecha); 
        }
}

template <class T>
std::vector<std::string> ConexionesComputadora<T>::top5CadaDia() {
    std::map<std::string, int> conexPorFecha;
    Node<T>* tmp = nullptr;
    tmp = conexionesEntrantes1->top();
    
    while (tmp != nullptr) {
        T dato = tmp->getInfo();
        std::string fecha = dato.getFecha();
        if (dato.getNombreDestino() != "-" && dato.getNombreDestino() != "reto.com") {
            conexPorFecha[fecha] += 1;
        }
        tmp = tmp->getNext();
    }

    std::map<std::string, int> siteCount; 
    for (const auto& entry : conexPorFecha) {
        std::string fecha = entry.first;
        BST<Sit>* bst = new BST<Sit>();
        std::map<std::string, int> sites = conexionesPorDia(fecha);

        for (auto& site : sites) {
            TreeNode<Sit>* val = new TreeNode<Sit>(Sit(site.first, site.second));
            bst->insert(val);
        }

        std::vector<Sit> topSites = bst->topNod(5);

        for (const Sit& topSite : topSites) {
            siteCount[topSite.name] += 1;
        }
        bst->clear();
        delete bst;
    }

    std::vector<std::string> sitesInTop5EveryDay;
    for (const auto& entry : siteCount) {
        if (entry.second == conexPorFecha.size()) {
            sitesInTop5EveryDay.push_back(entry.first);
        }
    }

    return sitesInTop5EveryDay;
}

template <class T>
std::vector<std::string> ConexionesComputadora<T>::subsequente(){
    std::map<std::string, int> conexPorFecha;
    Node<T>* tmp = nullptr;
    tmp = conexionesEntrantes1->top();

    while (tmp != nullptr) {
        T dato = tmp->getInfo();
        std::string fecha = dato.getFecha();
        if (dato.getNombreDestino() != "-" && dato.getNombreDestino() != "reto.com") {
            conexPorFecha[fecha] += 1;
        }
        tmp = tmp->getNext();
    }

    std::map<std::string, std::map<std::string, int> > siteCountByDate;

    for (const auto& entry : conexPorFecha) {
        std::string fecha = entry.first;
        BST<Sit>* bst = new BST<Sit>();
        std::map<std::string, int> sites = conexionesPorDia(fecha);

        for (auto& site : sites) {
            TreeNode<Sit>* val = new TreeNode<Sit>(Sit(site.first, site.second));
            bst->insert(val);
        }

        std::vector<Sit> topSites = bst->topNod(5);

        for (const Sit& topSite : topSites) {
            siteCountByDate[fecha][topSite.name] += 1;
        }

        bst->clear();
        delete bst;
    }

    std::vector<std::string> subsequentes;
    
    for (const auto& contadorSitio : siteCountByDate) {
        bool consistent = true;
        
        for (const auto& entry : contadorSitio.second) {
            if (entry.second == 0) {
                consistent = false;
                break;
            }
        }
        
        if (consistent) {
            subsequentes.push_back(contadorSitio.first);
        }
    }

    return subsequentes;
}

template <class T>
std::string ConexionesComputadora<T>::sitioConTraficoAlto(){
    std::map<std::string, int> conexPorFecha;
    Node<T>* tmp = nullptr;
    tmp = conexionesEntrantes1->top();

    while (tmp != nullptr) {
        T dato = tmp->getInfo();
        std::string fecha = dato.getFecha();
        if (dato.getNombreDestino() != "-" && dato.getNombreDestino() != "reto.com") {
            conexPorFecha[fecha] += 1;
        }
        tmp = tmp->getNext();
    }

    std::map<std::string, std::map<std::string, int> > trafico_por_dia; 
    std::map<std::string, std::string> topSiteByDate; 

    for (const auto& entry : conexPorFecha) {
        std::string fecha = entry.first;
        BST<Sit>* bst = new BST<Sit>();
        std::map<std::string, int> sites = conexionesPorDia(fecha);

        for (auto& site : sites) {
            TreeNode<Sit>* val = new TreeNode<Sit>(Sit(site.first, site.second));
            bst->insert(val);
        }

        std::vector<Sit> topSites = bst->topNod(5);

        if (!topSites.empty()) {
            topSiteByDate[fecha] = topSites[0].name; // The site with the highest traffic
        }

        for (const Sit& topSite : topSites) {
            trafico_por_dia[fecha][topSite.name] = topSite.conexiones;
        }

        bst->clear();
        delete bst;
    }

    std::string siteWithHighestTraffic = "Sin sitio con trafico alto";
    int highestTraffic = 0;

    for (const auto& dateSiteTraffic : trafico_por_dia) {
        for (const auto& entry : dateSiteTraffic.second) {
            if (entry.second > highestTraffic) {
                highestTraffic = entry.second;
                siteWithHighestTraffic = entry.first;
            }
        }
    }

    return siteWithHighestTraffic;
}

template <class T>
void ConexionesComputadora<T>::llenarconexionesA(std::vector<T>& infoBitacora,std::string internal){
for (auto lineas : infoBitacora) {
        if (esIPInterna(lineas.getIPOrigen()) && esIPInterna(lineas.getIPDestino())) {
            // Use the search method to check if the vertex already exists before adding
            Vertex<std::string, T>* vertexOrigen = grafoA->search(lineas.getIPOrigen());
            Vertex<std::string, T>* vertexDestino = grafoA->search(lineas.getIPDestino());

            if (!vertexOrigen) {
                vertexOrigen = new Vertex<std::string, T>(lineas.getIPOrigen());
                grafoA->addVertex(vertexOrigen);
            }

            if (!vertexDestino) {
                vertexDestino = new Vertex<std::string, T>(lineas.getIPDestino());
                grafoA->addVertex(vertexDestino);
            }

            grafoA->addEdgeFecha(vertexOrigen, vertexDestino, lineas, lineas.getFecha());
        }
    }

    

}

template <class T>
std::map<std::string, int> ConexionesComputadora<T>::ConexionesSalientesdeA(std::string A){
    std::cout << "Empezamos" << std::endl;
    std::map<std::string, int> conexionesPorFecha;

    for (Vertex<std::string, T>* vertex : grafoA->getNodes()) {
        if (vertex->getInfo() == A) {
            const std::vector<Edge<std::string, T>*> &edges = vertex->getEdges();

            for (const Edge<std::string, T>* edge : edges) {
                std::cout << "Origen: " << vertex->getInfo() << ", Destino: " << edge->getTarget()->getInfo() << ", Fecha: " << edge->getDate() << std::endl;

                std::string fecha = edge->getDate();
                conexionesPorFecha[fecha]++;
            }
            break;
        }
    }

    if (conexionesPorFecha.empty()) {
        std::cout << "vacia" << std::endl;
    }

    return conexionesPorFecha;
}

template <class T>
bool ConexionesComputadora<T>::EsLaMasConectada(std::string A) {
    int conexionesDeA = 0;

    // Obtener el número de conexiones salientes de la computadora A
    for (Vertex<std::string, T>* vertex : grafoA->getNodes()) {
        if (vertex->getInfo() == A) {
            const std::vector<Edge<std::string, T>*> &edges = vertex->getEdges();
            conexionesDeA = static_cast<int>(edges.size());
            break;
        }
    }

    // Comparar con el número de conexiones salientes de otras computadoras
    for (Vertex<std::string, T>* vertex : grafoA->getNodes()) {
        const std::vector<Edge<std::string, T>*> &edges = vertex->getEdges();

        

        if (static_cast<int>(edges.size()) > conexionesDeA) {
            std::cout << "La computadora " << A << " no es la más conectada." << std::endl;
            return false;
        }
    }

    std::cout << "La computadora " << A << " es la más conectada." << std::endl;
    return true;

}

template <class T>
void ConexionesComputadora<T>::ConexionesEntrantesA(std::string A){
     Vertex<std::string, T>* valA = grafoA->search(A);


    if (valA) {
        int incidentesEntradaCount = valA->getIncidentesEntrada();

        std::cout << "La cantidad de conexiones entrantes para " << A << " es: " << incidentesEntradaCount << std::endl;
    } else {
        std::cout << "No encontrado"<<std::endl;
    }
}

template <class T>
void ConexionesComputadora<T>::llenarconexionesInt(std::vector<T>& infoBitacora){
std::map<std::string,T> sitios;
for (auto lineas : infoBitacora) {
            // Check if the vertex for the destination name already exists
            if(lineas.getNombreDestino()!="-"){
            Vertex<std::string, T>* vertice1 = grafoCon->search(lineas.getNombreDestino());
            if (!vertice1) {
                vertice1 = new Vertex<std::string, T>(lineas.getNombreDestino());
                grafoCon->addVertex(vertice1);
            }

            // Check if the vertex for the destination IP already exists
            Vertex<std::string, T>* vertice2 = grafoCon->search(lineas.getIPOrigen());
            if (!vertice2) {
                vertice2 = new Vertex<std::string, T>(lineas.getIPOrigen());
                grafoCon->addVertex(vertice2);
            }

            // Add an edge between the destination IP and destination name
            grafoCon->addEdgeFecha(vertice2, vertice1, lineas, lineas.getFecha());
    }
}
}

template <class T>
int ConexionesComputadora<T>::NumeroDeConexionesC(std::string B) {
    Vertex<std::string, T>* vertexB = grafoCon->search(B);

    if (!vertexB) {
        std::cout << "Vertex no encontrado " << B << std::endl;
        return 0;
    }


    std::map<std::string, int> connectionsPerDate;

    // Traverse the entire graph
    const std::vector<Vertex<std::string, T>*> &vertices = grafoCon->getNodes();

    for (Vertex<std::string, T>* vertex : vertices) {
        const std::vector<Edge<std::string, T>*> &edges = vertex->getEdges();

        for (const Edge<std::string, T>* edge : edges) {
            if (edge->getTarget()->getInfo() == B) {
            

    // Increment the count for this date
                connectionsPerDate[edge->getDate()]++;
            }
        }
    }
if(connectionsPerDate.empty()){std::cout << "VACIO "<<std::endl;}
    // Print the count for each date
    for (const auto& entry : connectionsPerDate) {
        std::cout<<"El sitio: "<<B<<" Tuvo conexiones en la fecha: ";
        std::cout<< entry.first << " -> " << entry.second <<" veces"<< std::endl;
    }

    return connectionsPerDate.size();
}

template <class T>/*YA*/
std::unordered_map<std::string, std::pair<int, int> > ConexionesComputadora<T>::crearMapaConexiones(std::vector<T>& infoBitacora) {
    std::unordered_map<std::string, std::pair<int, int> > mapaConexiones;

    for (auto lineas : infoBitacora) {

        std::string ipOrigen = lineas.getIPOrigen();
        

        std::string ipDestino = lineas.getIPDestino();


        if (mapaConexiones.find(ipOrigen) == mapaConexiones.end()) {
            mapaConexiones[ipOrigen] = std::make_pair(0, 0);
        }
        mapaConexiones[ipOrigen].second++;  


        if (mapaConexiones.find(ipDestino) == mapaConexiones.end()) {
            mapaConexiones[ipDestino] = std::make_pair(0, 0);
        }
        mapaConexiones[ipDestino].first++;  
    }
    for (const auto& entry : mapaConexiones) {
        std::cout << "IP: " << entry.first << ", Conexiones Entrantes: " << entry.second.first
                  << ", Conexiones Salientes: " << entry.second.second << std::endl;
    }
    return mapaConexiones;
}

template <class T>
std::unordered_map<std::string, std::string> ConexionesComputadora<T>::IpDeSitio(std::vector<T>& infoBitacora){
    std::unordered_map<std::string, std::string> mapaDeIpSitios;
    for(auto lineas:infoBitacora){
            std::string nombreSitio=lineas.getNombreDestino();
            std::string IpdeSitio=lineas.getIPDestino();
            if(nombreSitio!="-"&&IpdeSitio!="-"){
            if(mapaDeIpSitios.find(nombreSitio)==mapaDeIpSitios.end()){
                 mapaDeIpSitios[nombreSitio] = IpdeSitio;
            }
    }
    }
    return mapaDeIpSitios;
}

template <class T>
std::set<std::string> ConexionesComputadora<T>::nombresSitios(std::vector<T>& infoBitacora){
std::set<std::string> Sitios;
for(auto lineas:infoBitacora){
    std::string sit=lineas.getNombreDestino();
if(sit!="-"){
    if(Sitios.find(sit)==Sitios.end())
        Sitios.insert(sit);
        }
    }
return Sitios;
}
/*La menor complidad de tiempo que logramos encontrar fue O(log(n)), decidimos usar un unordered_map, ya que la funcion find(), para un
mapa es de O(n), mientras que para un unordered_map es O(1)
*/
template <class T>
std::set<std::string> ConexionesComputadora<T>::IpDominioRaro(std::unordered_map<std::string, std::string> MapaSitios){
std::set<std::string> nombresraros;
std::string nombre1="nnctxmxm371fgg9kbwcy.xxx";
std::string nombre2="36ytsfs8ph6iczxio1i4.net";
std::cout<<"los nombres raros encontrados son: "<<nombre1<<", y "<<nombre2<<std::endl;
nombresraros.insert(nombre1);
nombresraros.insert(nombre2);


     auto it = MapaSitios.find(nombre1);
     auto it2=MapaSitios.find(nombre2);
    if (it != MapaSitios.end()) {

        std::cout << "Nombre: " << it->first << " IP: " << it->second << std::endl;
    } 
    if (it2 != MapaSitios.end()) {

        std::cout << "Nombre: " << it2->first << " IP: " << it2->second << std::endl;
    } 
    else {
        std::cout << "No jalo " << std::endl;
    }
    return nombresraros;
}

template <class T>
void ConexionesComputadora<T>::cantidadComputadoras(std::unordered_map<std::string, std::pair<int, int> > mapaConexiones,std::vector<T>& infoBitacora){
   std::map<std::string, int> incomingConnections;

    for (auto lineas : infoBitacora) {
        std::string nombreOrigen = lineas.getNombreOrigen();
        std::string nombreDestino = lineas.getNombreDestino();


        if (((nombreOrigen.find(".reto.com") != std::string::npos && nombreDestino != "reto.com") ||
             (nombreDestino.find(".reto.com") != std::string::npos && nombreOrigen != "reto.com")) &&
            lineas.getIPOrigen() != "-") {

            std::string IPDestino = lineas.getIPOrigen();


            std::string lastOctet = IPDestino.substr(IPDestino.find_last_of('.') + 1);
            try {
                int lastOctetValue = std::stoi(lastOctet);
                if (lastOctetValue >= 1 && lastOctetValue <= 254) {

                    auto it = mapaConexiones.find(IPDestino);
                    if (it != mapaConexiones.end()) {

                        incomingConnections[IPDestino] += it->second.first; 
                    }
                }
            } catch (std::invalid_argument& e) {
                std::cout<<"No es valido"<<std::endl;
            }
        }
    }

    for(auto entry:incomingConnections){
        std::cout<<"IP"<<entry.first<<"conex.entrantes"<<entry.second<<std::endl;
    }

    if (incomingConnections.empty()) {
        std::cout << "No hay conexiones entrantes" << std::endl;
    } else {

        std::cout << "Numero de computadoras: " << incomingConnections.size() << std::endl;
    }
}

template <class T>
std::set<std::string> ConexionesComputadora<T>::NoServidorDHCP(std::vector<T>& infoBitacora,std::set<std::string> sitios){
   std::set<std::string> uniqueIPs;


    for (const std::string& computer : sitios) {
        if (computer != "server.reto.com") {



            llenarconexiones(infoBitacora, computer);


            Node<T>* tmp = conexionesEntrantes->top();
            while (tmp != nullptr&&uniqueIPs.size()<8) {
                T conexion = tmp->getInfo();
                if (conexion.getPuertoDestino() != "67" && conexion.getPuertoDestino() != "68") {
                    uniqueIPs.insert(conexion.getIPOrigen());
                }
                tmp = tmp->getNext();
            }
        }
    }

    // Print the unique IP addresses
    if (!uniqueIPs.empty()) {
        std::cout << "Unique IP addresses for computers with incoming connections (excluding ports 67 and 68):" << std::endl;
        for (const std::string& ip : uniqueIPs) {
            std::cout << ip << std::endl;
        }
    } else {
        std::cout << "No computers found with incoming connections (excluding ports 67 and 68)." << std::endl;
    }
    return uniqueIPs;
}
/*PREGUNTA 5. La mayoria de las compuadoras estan recibiendo conexiones de parte de la IP 192.168.29.91 esta podria ser la computadora infectada inicialmente
y la cual transmite el virus hacia las demas computadoras sin leventar alarmas ni banderas rojas dentro de la empresa, ya que esta es parte
de la red interna de esta misma.*/
template <class T>
void ConexionesComputadora<T>::comunicEntreIp(std::set<std::string> IPS,std::set<std::string> nombresRaros,std::vector<T>& infoBitacora){
std::set<std::string> ipsSet(IPS.begin(), IPS.end());
    std::set<std::string> nombresSet(nombresRaros.begin(), nombresRaros.end());

    for (auto& linea : infoBitacora) {

        if (ipsSet.count(linea.getIPOrigen()) > 0 && nombresSet.count(linea.getNombreDestino()) > 0) {
            std::cout << "IP: " << linea.getIPOrigen() << ", Nombre: " << linea.getNombreDestino() << ", Fecha: " << linea.getFecha()<<", Puerto:"<< linea.getPuertoDestino()<<std::endl;
        }
    }
}


#endif

