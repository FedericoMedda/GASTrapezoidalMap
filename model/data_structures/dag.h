#ifndef DAG_H
#define DAG_H

#include <list>
#include <ctime>
#include <cg3/data_structures/arrays/arrays.h>

#include <cg3/geometry/point2.h>
#include <cg3/geometry/segment2.h>
#include <cg3/geometry/polygon2.h>

// implementazioen dag -> http://cglab.ca/~cdillaba/comp5008/mulmuley.html

class dag
{
    public:
        cg3::Point2d x_nodo; //stores segment endpoint
        cg3::Segment2d y_nodo; //stores a line segment
        char trapezoid_node; //stores trapezoid

        dag* leftChild;
        dag* rightChild;

        //costruttori
        dag ();
        dag(cg3::Point2d p);
        dag(cg3::Segment2d s);
        dag(char t);


        void print(dag* d);

        bool insert(cg3::Point2d p, dag* d, int dir);
        bool insert(cg3::Segment2d s, dag* d, int dir);
        bool insert(cg3::Polygon2 t, dag* d, int dir);

        bool search(cg3::Point2d p, dag* d);
        bool search(cg3::Segment2d s, dag* d);
        bool search(cg3::Polygon2 t, dag* d);
};


#endif // DAG_H
