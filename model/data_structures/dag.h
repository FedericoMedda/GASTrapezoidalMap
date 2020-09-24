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
    cg3::Point2d x_nodo; //stores segment endpoint
    cg3::Segment2d y_nodo; //stores a line segment
    cg3::Polygon2 trapezoid_node; //stores trapezoid

    dag* leftChild;
    dag* rightChild;

    public:
        dag ();
        dag(cg3::Point2d p);
        dag(cg3::Segment2d s);
        dag(cg3::Point2d p, cg3::Segment2d s);


        void print(dag d);

        dag insert(cg3::Point2d p);
        dag insert(cg3::Segment2d s);
        dag insert(cg3::Polygon2 p);

        bool delete_node(dag g, cg3::Point2d p);
        bool delete_node(dag d, cg3::Segment2d s);
        bool delete_node(dag d, cg3::Polygon2 p);

};


#endif // DAG_H
