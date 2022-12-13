#include <iostream>
#include <chrono>
#include <stdlib.h>     /* srand, rand */
#include <thread>
#include <vector>
#include "PQ.h"
using namespace std;


int main() {
	
	int opt;
	cout << "Ingrese la opcion que desea realizar: "<<endl;
	
	cout << "1. Muestra de una lista y sus funciones" <<endl;
	cout << "2. Tiempos de inserción de 100, 1000, 10 000, 100 000, 1 000 000 elementos." << endl;
	
	cin>> opt;
	
	switch(opt)
	{
		case (1):
		{
		    	srand(time(NULL));
		    	PQ s;
		    	s.push(5);
		    	s.push(4);
		    	s.push(12);
		    	s.push(50);
		    	s.push(9);
		    	s.push(10);
		    	cout<<"Print(): "<<endl;
		    	s.print();
		    	cout << "Top(): Elemento mas prioritario"<<endl;
		    	cout << s.top() << endl;
			cout << "Pop(): Eliminar elemento mas preioritario"<<endl;
			s.pop();
			s.print();
			cout << "New Top(): Elemento mas prioritario tras eliminar anterior elemento"<<endl;
		    	cout << s.top() << endl;
			break;
		}
		case(2):
		{
			auto start1 = chrono::steady_clock::now(); 
			PQ s1;
			srand(time(NULL));	  
			s1.thr(100);
			auto stop1 = chrono::steady_clock::now();
			cout << "Insert 100 elem.: "<<chrono::duration_cast<chrono::microseconds>(stop1 -start1).count()<< " microsec." << endl;
			//s1.print();
			//cout << "==============" <<endl;
			//s1.top();
			 
			auto start2 = chrono::steady_clock::now(); 
			PQ s2;
			srand(time(NULL));
			s2.thr(1000);
			auto stop2 = chrono::steady_clock::now(); 
			cout << "Insert 1000 elem.: "<<chrono::duration_cast<chrono::microseconds>(stop2 -start2).count()<< " microsec." << endl;
			//s2.print();
				
			auto start3 = chrono::steady_clock::now(); 
			PQ s3;
			srand(time(NULL));
			s3.thr(10000);
			auto stop3 = chrono::steady_clock::now(); 
			cout << "Insert 10 000 elem.: "<<chrono::duration_cast<chrono::microseconds>(stop3 -start3).count()<< " microsec. " << endl;
			
			auto start4 = chrono::steady_clock::now(); 
			PQ s4;
			srand(time(NULL));
			s4.thr(100000);
			auto stop4 = chrono::steady_clock::now(); 
			cout << "Insert 100 000 elem.: "<<chrono::duration_cast<chrono::microseconds>(stop4 -start4).count()<< " microsec. " << endl;
			
			auto start5 = chrono::steady_clock::now(); 
			PQ s5;
			srand(time(NULL));
			s5.thr(1000000);
			auto stop5 = chrono::steady_clock::now(); 
			cout << "Insert 1 000 000 elem.: "<<chrono::duration_cast<chrono::microseconds>(stop5 -start5).count()<< " microsec. " << endl;
			break;
		}
	}
}
