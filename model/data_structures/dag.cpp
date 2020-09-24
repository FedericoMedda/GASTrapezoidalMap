#include "dag.h"
#include <iostream>

dag::dag()
{
    //create a new node without anything
    dag* d;
    d = new dag;
    d->x_nodo = 0;
    d->y_nodo = 0;
    d->trapezoid_node = 0;

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
    d->trapezoid_node = 0;

    d->leftChild = nullptr;
    d->rightChild = nullptr;
}


dag::dag(cg3::Segment2d s){
    //create a new node just with s (line segment stored)
    dag* d;
    d = new dag;
    d->x_nodo = 0;
    d->y_nodo = s;
    d->trapezoid_node = 0;

    d->leftChild = nullptr;
    d->rightChild = nullptr;

}

dag::dag(cg3::Point2d p, cg3::Segment2d s)
{
    //create a new node with p and s (endpoint segment and segment stored)
    dag* d;
    d = new dag;
    d->x_nodo = p;
    d->y_nodo = s;
    d->trapezoid_node = 0;

    d->leftChild = nullptr;
    d->rightChild = nullptr;
}


void dag::print(dag d){
    if (d.leftChild == nullptr && d.leftChild == nullptr) // vuoto
    {


    }
}

dag insert(cg3::Point2d p){}
dag insert(cg3::Segment2d s){}
dag insert(cg3::Polygon2 p){}

bool delete_node(dag g, cg3::Point2d p){

}

bool delete_node(dag d, cg3::Segment2d s){

}

bool delete_node(dag d, cg3::Polygon2 p){

}

