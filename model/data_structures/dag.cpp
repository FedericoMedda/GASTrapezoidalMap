#include "dag.h"
#include <cstddef>
#include <iostream>

dag::dag()
{
    //create a new node without anything
    dag* d;
    d = new dag;
    d->x_nodo = nullptr;
    d->y_nodo = 0;
    d->trapezoid_node = '\0';

    d->leftChild = nullptr;
    d->rightChild = nullptr;
}

dag::dag(cg3::Point2d p)
{
    //create a new node just with p (segment endpoint stored)
    dag* d;
    d = new dag;
    d->x_nodo = p;
    d->y_nodo = 0;
    d->trapezoid_node = '\0';

    d->leftChild = nullptr;
    d->rightChild = nullptr;
}


dag::dag(cg3::Segment2d s){
    //create a new node just with s (line segment stored)
    dag* d;
    d = new dag;
    d->x_nodo = nullptr;
    d->y_nodo = s;
    d->trapezoid_node = '\0';

    d->leftChild = nullptr;
    d->rightChild = nullptr;

}

dag::dag(char t)
{
    //create a new node with p and s (endpoint segment and segment stored)
    dag* d;
    d = new dag;
    d->x_nodo = nullptr;
    d->y_nodo = 0;
    d->trapezoid_node = t;

    d->leftChild = nullptr;
    d->rightChild = nullptr;
}


void dag::print(dag* d)
{
    while (d != nullptr){
        if (d->x_nodo && d->y_nodo )
            std::cout << d->trapezoid_node;
        if (d->y_nodo && d->trapezoid_node )
            std::cout << d->x_nodo << " ";
        if (d->x_nodo && d->trapezoid_node )
          // restituisco trapezoide segment class
            std::cout << 'ws';
        }
}

//dir direzione 0 sx 1 dx
bool insert(cg3::Point2d p, dag* d, int dir)
{
    if (d == nullptr){
        dag d(p);
    } //dag da crare

    while (d != nullptr){

        if (d->leftChild == nullptr && d->rightChild == nullptr ){
            //inserisco nuovo nodo
            dag* d1;
            d1 = d;
            d1 = new dag;
            d1->x_nodo = p;
            d1->y_nodo = 0;
            d1->trapezoid_node = '\0';

            d1->leftChild = nullptr;
            d1->rightChild = nullptr;

            if (dir == 0) //inserisco a sx
            {
               d->leftChild = d1;
               return 1;
            }

            if (dir == 1) //inserisco a dx
            {
                d->rightChild = d1;
                return 1;
            }
        }

        insert(p, d->leftChild, dir);
        insert(p, d->rightChild, dir);

    }
    return 0;

}

bool insert(cg3::Segment2d s, dag* d, int dir)
{
    if (d == nullptr){
        dag d(s);
    } //dag da crare

    while (d != nullptr){

        if (d->leftChild == nullptr && d->rightChild == nullptr ){
            //inserisco nuovo nodo
            dag* d1;
            d1 = d;
            d1 = new dag;
            d1->x_nodo = nullptr;
            d1->y_nodo = s;
            d1->trapezoid_node = '\0';

            d1->leftChild = nullptr;
            d1->rightChild = nullptr;

            if (dir == 0) //inserisco a sx
            {
               d->leftChild = d1;
               return 1;
            }

            if (dir == 1) //inserisco a dx
            {
                d->rightChild = d1;
                return 1;
            }
        }

        insert(s, d->leftChild, dir);
        insert(s, d->rightChild, dir);

    }
    return 0;

}
bool insert(char t, dag* d, int dir)
{
    if (d == nullptr){
        dag d(t);
    } //dag da crare

    while (d != nullptr){

        if (d->leftChild == nullptr && d->rightChild == nullptr ){
            //inserisco nuovo nodo
            dag* d1;
            d1 = d;
            d1 = new dag;
            d1->x_nodo = nullptr;
            d1->y_nodo = 0;
            d1->trapezoid_node = t;

            d1->leftChild = nullptr;
            d1->rightChild = nullptr;

            if (dir == 0) //inserisco a sx
            {
               d->leftChild = d1;
               return 1;
            }

            if (dir == 1) //inserisco a dx
            {
                d->rightChild = d1;
                return 1;
            }
        }

        insert(t, d->leftChild, dir);
        insert(t, d->rightChild, dir);

    }
    return 0;
}

bool search(cg3::Point2d p, dag* d)
{
    if (d == nullptr){
        return 0;
    } //dag da crare

    while (d != nullptr){
        if(d->x_nodo == p)
            return 1;

        search(p, d->rightChild);
        search(p, d->leftChild);
    }
    return 0;
}

bool search(cg3::Segment2d s, dag* d)
{
    if (d == nullptr){
        return 0;
    } //dag da crare

    while (d != nullptr){
        if(d->y_nodo == s)
            return 1;

        search(s, d->rightChild);
        search(s, d->leftChild);
    }
    return 0;
}

bool search(char t, dag* d)
{
    if (d == nullptr){
        return 0;
    } //dag da crare

    while (d != nullptr){
        if(d->trapezoid_node == t)
            return 1;

        search(t, d->rightChild);
        search(t, d->leftChild);
    }
    return 0;
}


