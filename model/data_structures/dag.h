#ifndef DAG_H
#define DAG_H

#include <list>

class dag
{
    int vertice;
    std::list<int>* l1;

    public:
        dag();
        dag(int n)
        {
            vertice=n;
            l1=new std::list<int>[n];
        }

        /* push_back function is used to add new element at the end of the list container */
        void add_edge(int x, int y)
      {
         l1[x].push_back(y);
      }

};


#endif // DAG_H
