//
//  Grafo.h
//  Grafo
//
//  Created by Daniel on 03/11/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#ifndef __Grafo__Grafo__
#define __Grafo__Grafo__

#include <iostream>
#include "NodoA.h"

template <class V, class A>
class Grafo {
    NodoV<V, A> * vertices;
    int numero_vertices;
    
public:
    
    Grafo();
    ~Grafo();
    
    void clear();
    int size();
    bool empty();
    
    void insertarVertice(V info);
    void insertarVertice(NodoV<V, A> * vertice);
    
    void insertarArista(A info, NodoV<V, A> * origen, NodoV<V, A> * destino);
    
    template <typename Vn, typename An>
    friend std::ostream & operator <<(std::ostream & os, Grafo<Vn, An> & grafo);
    
};

template <class V, class A>
Grafo<V, A>::Grafo()
{
    vertices = nullptr;
    numero_vertices = 0;
}

template <class V, class A>
Grafo<V, A>::~Grafo()
{
    clear();
}

template <class V, class A>
void Grafo<V, A>::clear()
{
    NodoV<V, A> * tmp = vertices;
    
    while (tmp) {
        vertices = vertices->getNext();
        delete tmp;
        tmp = vertices;
    }
    
    vertices = nullptr;
    numero_vertices = 0;
}

template <class V, class A>
int Grafo<V, A>::size()
{
    return numero_vertices;
}

template <class V, class A>
bool Grafo<V, A>::empty()
{
    return size() == 0;
}

template <class V, class A>
void Grafo<V, A>::insertarVertice(V info)
{
    NodoV<V, A> * tmp = vertices;
    NodoV<V, A> * prev = nullptr;
    
    while (tmp) {
        prev = tmp;
        tmp = tmp->getNext();
    }
    
    NodoV<V, A> * nuevo = new NodoV<V, A>(info);
    
    if (prev) {
        prev->setNext(nuevo);
    }
    else {
        vertices = nuevo;
    }
    
    ++numero_vertices;
}

template <class V, class A>
void Grafo<V, A>::insertarVertice(NodoV<V, A> * vertice)
{
    NodoV<V, A> * tmp = vertices;
    NodoV<V, A> * prev = nullptr;
    
    while (tmp) {
        prev = tmp;
        tmp = tmp->getNext();
    }
    
    if (prev) {
        prev->setNext(vertice);
    }
    else {
        vertices = vertice;
    }
    
    ++numero_vertices;
    
}

template <class V, class A>
void Grafo<V, A>::insertarArista(A info, NodoV<V, A> * origen, NodoV<V, A> * destino)
{
    origen->adicionarArista(info, destino);
}

template <class V, class A>
std::ostream & operator <<(std::ostream & os, Grafo<V, A> & grafo)
{
    NodoV<V, A> * tmp = grafo.vertices;
    
    while (tmp) {
        os << *tmp << std::endl;
        tmp = tmp->getNext();
    }
    
    return os;
}

#endif /* defined(__Grafo__Grafo__) */
