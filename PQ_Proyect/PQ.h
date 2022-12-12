#ifndef PRIORITYQ_H
#define PRIORITYQ_H

#include "skiplist.h"
#include <stdlib.h>     /* srand, rand */
#include <iostream>
#include <vector>
#include <thread>
using namespace std;


class PQ
{
public:
    void operator()(int num) 
	{
        pq.insert_element(num);
    }
    void insert(int n)
    {
        srand(time(NULL));
		for (int i = 0; i<n; i++)
        {
        	int aux = rand()%(2*n)+1;
			pq.insert_element(aux);
		}
    }
    void thr(int n) 
	{
    	int t = 4;
        vector<thread> threads(t);
        for (int i = 0; i < t; i++) 
		{
			threads[i] = thread(&PQ::insert, this, n);
        }
        for (int i = 0; i < t; i++) 
		{
            threads[i].join();
        }
    }
    void pop()
    {
        pq.pop_element();
    }
    int top()
    {
    	return pq.top_element();
    }
    void print() 
	{
        pq.display();
    }
private:
    skiplist pq;
};
#endif
