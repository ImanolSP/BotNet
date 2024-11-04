#include <iostream>
#include <vector>
#include <map>
#include <set>
#include "Bitacora.hpp"
#include "BitacoraLinea.hpp"
#include "ConexionesComputadora.hpp"
using namespace std;

int main() {
    // Leer y procesar la bitácora
    std::vector<BitacoraLinea> infoBitacora;
    Bitacora bitacora("equipo5.csv");
    infoBitacora = bitacora.leerBitacora();

    // Ordenar la bitácora por fecha
    bitacora.ord();

    cout << "------------------------------------------------------------------------" << endl;
    bitacora.fechas();

    cout << "------------------------------------------------------------------------" << endl;
    bitacora.renglones();

    cout << "------------------------------------------------------------------------" << endl;
    bitacora.read();

    cout << "------------------------------------------------------------------------" << endl;
    bitacora.nombres();

    cout << "------------------------------------------------------------------------" << endl;
    bitacora.buscarServer();

    cout << "------------------------------------------------------------------------" << endl;
    bitacora.correoE();

    cout << "------------------------------------------------------------------------" << endl;
    std::string redin = bitacora.redInter();

    cout << "------------------------------------------------------------------------" << endl;
    ConexionesComputadora<BitacoraLinea> conex;
    const std::string A = conex.setIp(redin);
    
    cout << "------------------------------------------------------------------------" << endl;
    conex.llenarconexiones(infoBitacora, A);

    std::string ipUltimaConexion;
    std::string sitioConTresConsecutivas;
    int opcion;
    cout << "-------------------------------DATE TO SEARCH-----------------------------------------" << endl;

    std::string day;
    std::string month;
    std::string year;
    std::cout<<"enter the day"<<std::endl;
    cin>>day;
    std::cout<<"enter the month"<<std::endl;
    cin>>month;
    std::cout<<"enter the year"<<std::endl;
    cin>>year;
    std::string dateToSearch = day+'-'+month+'-'+year;
    

    std::map<std::string, int> connectionsBySite = conex.conexionesPorDia(dateToSearch);
cout << "------------------------------------------------------------------------" << endl;

std::vector<std::string> sitesInTop5EveryDay =conex.top5CadaDia();

cout << "------------------------------------------------------------------------" << endl;
std::vector<std::string> sitesMeetingCriteria=conex.subsequente();

cout << "------------------------------------------------------------------------" << endl;
/*YA*/
std::string valo=conex.sitioConTraficoAlto();
cout << "------------------------------------------------------------------------" << endl;
const std::string B="nnctxmxm371fgg9kbwcy.xxx";
const std::string C="protonmail.com";
conex.llenarconexionesA(infoBitacora,redin);
conex.llenarconexionesInt(infoBitacora);
cout << "-------------------------------NNNNNNNN-----------------------------------------" << endl;
std::map<std::string, int> conexionesPorFecha;
cout << "------------------------------------------------------------------------" << endl;
cout << "------------------------------------------------------------------------" << endl;
cout << "------------------------------------------------------------------------" << endl;
std::cout<<"Fecha en uso:"<<dateToSearch<<std::endl;
cout << "------------------------------------------------------------------------" << endl;
cout << "------------------------------------------------------------------------" << endl;
std::unordered_map<std::string, std::pair<int, int> > valu=conex.crearMapaConexiones(infoBitacora);
cout << "------------------------------------------------------------------------" << endl;
std::unordered_map<std::string, std::string> resp=conex.IpDeSitio(infoBitacora);
cout << "-----------------------------------set-------------------------------------" << endl;
std::set<std::string> nom=conex.nombresSitios(infoBitacora);
cout << "---------------------------------Nombre raro---------------------------------------" << endl;
std::set<std::string> nomRaro;
cout << "---------------------------------Nombre raro---------------------------------------" << endl;
cout << "---------------------------------DHCP---------------------------------------" << endl;
std::set<std::string> IPs;
cout << "---------------------------------coNEXENTREIP---------------------------------------" << endl;
int noc1;
int noc;
    do {
        cout << "\n============================\n";
        cout << "      MENÚ DE OPCIONES      \n";
        cout << "============================\n";
        cout << "1. Obtener dirección IP actualmente en uso.\n";
        cout << "2. Dirección IP de la última conexión.\n";
        cout << "3. Total de conexiones entrantes.\n";
        cout << "4. Total de conexiones salientes.\n";
        cout << "5. Verificar 3 conexiones seguidas al mismo sitio.\n";
        cout << "6. Sitio con el trafico mas alto.\n";
        cout << "7. Top 5 de cada fecha.\n";
        cout << "8. Top n sitios de una fecha.\n";
        cout << "9. fechas subsequentes.\n";
        cout << "10. Conexiones totales de la fecha dada\n";
        cout << "11. Sitio que aparece en el top 5 todos los dias\n";
        cout << "12.Conexiones salientes de la IP en uso\n";
        cout << "13.Es la direccion IP mas conectada \n";
        cout << "14.Conexiones Entrantes a la direccion IP \n";
        cout << "15.Numero de conexiones que tiene B \n";
        cout << "16.Numero de conexiones que tiene C \n";
        cout << "17.Nombres raros y sus IPs \n";
        cout << "18.Numero computadoras pertenecientes al dominio reto.com con al menos una conex.entrante \n";
        cout << "19.Ips unicas de conex entrantes de 8 comp.diferentes, y saber si existe comunic. con alguna comp. de nombre raro (Es necesario acceder a la opcion 17 primero)  \n";
        cout << "20.Salir \n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                std::cout << "Dirección IP en uso: " << A << std::endl;
                break;
            case 2:
                {
                    BitacoraLinea ultimaConexion = conex.ultimaconexionEntrante();
                    ipUltimaConexion = ultimaConexion.getIPOrigen();
                    std::cout << "Última conexión recibida de: " << ipUltimaConexion << std::endl;
                    if (conex.esIPInterna(ipUltimaConexion)) {
                        std::cout << "La IP es interna." << std::endl;
                    } else {
                        std::cout << "La IP es externa." << std::endl;
                    }
                }
                break;
            case 3:
                cout << "Numero de conexiones Entrantes: " << conex.totalConexionesEntrantes() << endl;
                break;
            case 4:
                cout << "Numero de conexiones Salientes: " << conex.totalConexionesSalientes() << endl;
                break;
            case 5:
                sitioConTresConsecutivas = conex.tieneTresConexionesSeguidas();
                if (!sitioConTresConsecutivas.empty()) {
                    std::cout << "La computadora tiene 3 conexiones seguidas al sitio: " << sitioConTresConsecutivas << std::endl;
                } else {
                    std::cout << "La computadora no tiene 3 conexiones seguidas al mismo sitio web." << std::endl;
                }
                break;
            case 6:
                std::cout <<"El sitio con el trafico mas alto de lo normal es:\n"<< valo << std::endl;
                break;
            case 7:
            conex.topPorFecha(5);
            break;
            case 8:
            conex.top(8,dateToSearch);
            break;
            case 9:
            
        std::cout << "Sitios que aparecen en un dia y en los dias subsequentes(Si aparecen puras fechas, no existen resultados concordantes):" << std::endl;
        for (const std::string& site : sitesMeetingCriteria) {
        std::cout << site << std::endl;
        }

        break;
            case 10:
            if(!connectionsBySite.empty()){std::cout<<"lleno"<<std::endl;}
            else{std::cout<<"vacio"<<std::endl;}
            for (const auto& entry : connectionsBySite) {
            std::cout << "Sitio: " << entry.first << ", Contador: " << entry.second << std::endl;
    } 
            break;
            case 11:
            if (sitesInTop5EveryDay.empty()) {
             std::cout << "Ningun sitio aparece en el top 5 todos los dias." << std::endl;
            } else {
            std::cout << "Sitio que aparece en el top5 cada dia:" << std::endl;
            for (const std::string& site : sitesInTop5EveryDay) {
            std::cout << site << std::endl;
            }
}
            break;
            case 12:
            conexionesPorFecha =conex.ConexionesSalientesdeA(A);/*YA*/
            for (const auto& entry : conexionesPorFecha) {
    std::cout << "Fecha: " << entry.first << ", Conexiones Salientes: " << entry.second << std::endl;
}
            break;
            case 13:
            conex.EsLaMasConectada(A);
            break;
            case 14:
            conex.ConexionesEntrantesA(A);
            break;
            case 15:
             noc=conex.NumeroDeConexionesC(B);
            break;
            case 16:
            noc1=conex.NumeroDeConexionesC(C);
            break;
            case 17:
            nomRaro=conex.IpDominioRaro(resp);
            break;
            case 18:
            conex.cantidadComputadoras(valu,infoBitacora);
            break;
            case 19:
            IPs=conex.NoServidorDHCP(infoBitacora,nom);
            std::cout<<"---Existe comunicacion entre alguna de las IPs y alguno de los sitios raros(Es necesario acceder a la opcion 17 primero):---"<<std::endl;
            conex.comunicEntreIp(IPs,nomRaro,infoBitacora);
            break;
            case 20:
            break;
            default:
                cout << "Opción no válida. Intente nuevamente.\n";
                break;
        }
    } while (opcion != 20);

    return 0;
}
