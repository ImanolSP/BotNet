//
//  Graph.hpp
//  Graph
//
//  Created by Vicente Cubells on 10/11/20.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <iostream>
#include <vector>
#include <algorithm>
#include "Vertex.hpp"

template <class V, class E>
class Graph {
private:
    std::vector < Vertex<V, E> * > nodes;
    
public:
    
    Graph() {}
    ~Graph();
    
    void addVertex(V & );
    void addVertex(Vertex<V,E> * );
    void addEdge(Vertex<V,E> *, Vertex<V,E> *, const E & );
    void addEdgeFecha(Vertex<V,E> *, Vertex<V,E> *, const E &,const std::string & date );
    void removeEdge(Vertex<V,E> *, Vertex<V,E> *, const E & );
    const std::vector<Vertex<V, E> *> & getNodes() const;

    void getIncidentesEntradaporVertex();

    void imprimir();
    Vertex<V, E> * search(const V & );
    Vertex<V, E> * search(const Vertex<V,E> *);
    
    template <class Vn, class En>
    friend std::ostream & operator <<(std::ostream &, const Graph<Vn,En> &);
};

template <class V, class E>
Graph<V,E>::~Graph()
{
    for (auto v: nodes) {
        delete v;
    }
    
    nodes.clear();
}

template <class V, class E>
void Graph<V,E>::addVertex(V & value )
{
    auto vertex = new Vertex<V, E>(value);
    
    nodes.push_back(vertex);
}

template <class V, class E>
void Graph<V,E>::addVertex(Vertex<V,E> * vertex )
{
    nodes.push_back(vertex);
}

template <class V, class E>
void Graph<V,E>::addEdge(Vertex<V,E> * source, Vertex<V,E> * target, const E & value)
{
    /* Buscar vertex origen */
    auto node = find(nodes.begin(), nodes.end(), source);
    if(*node==nullptr){std::cout<<"No encontrado"<<std::endl;}
    /* Crear un edge y adicionarlo al vertex */
    Edge<V, E> * edge = new Edge<V,E>(value, target);
    
    (*node)->addEdge(edge);
}
template <class V, class E>
void Graph<V,E>::addEdgeFecha(Vertex<V,E> * source, Vertex<V,E> * target, const E & value, const std::string & date)
{
    Edge<V, E> * edge = new Edge<V, E>(value, target, date);
    source->addEdge(edge);
}

template <class V, class E>
void Graph<V,E>::removeEdge(Vertex<V,E> * source, Vertex<V,E> * target, const E & value )
{
    /* Buscar vertex origen */
    auto node = find(nodes.begin(), nodes.end(), source);
    
    Vertex<V,E> * vertex = (*node);
    
    auto * edges = vertex->getEdges();
    
    Edge<V,E> * to_remove = nullptr;
    
    for (auto e : *edges) {
        if (e->getInfo() == value && e->getTarget() == target) {
            to_remove = e;
            break;
        }
    }
    
    if (to_remove) {
        vertex->removeEdge(to_remove);
    }
    
}

template <class V, class E>
Vertex<V, E>* Graph<V,E>::search(const V& value)
{
    for (Vertex<V, E>* vertex : nodes) {
        if (vertex->getInfo() == value) {
            return vertex; // Return the found vertex
        }
    }

    return nullptr; // Return nullptr if not found
}

template <class V, class E>
Vertex<V, E>* Graph<V,E>::search(const Vertex<V,E>* value)
{
    auto node = find(nodes.begin(), nodes.end(), value);

    if (node != nodes.end()) {
        return *node; // Return the found vertex
    }

    return nullptr; // Return nullptr if not found
}
template <class V,class E>
void Graph<V,E>::getIncidentesEntradaporVertex(){
    for(auto v:nodes){
        std::cout<<v->getInfo()<<":"<<v->getIncidentesEntrada();
        std::cout<<std::endl;
    }
}

template <class V,class E>
void Graph<V,E>::imprimir(){
    for(auto v:nodes){
        std::cout<<"Vertex:"<<v->getInfo();
        std::cout<<std::endl;
    }
}

template <class V, class E>
std::ostream & operator <<(std::ostream & os, const Graph<V,E> & graph)
{
    os << "--- Graph ---" << std::endl;
    
    for (auto v :  graph.nodes) {
        os << *v;
    }
    
    return os;
}
template <class V, class E>
const std::vector<Vertex<V, E> *> & Graph<V,E>::getNodes() const{
return nodes;
}

#endif /* Graph_hpp */
