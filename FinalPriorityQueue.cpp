#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h>
#include<chrono>
using namespace std;

int values = 0;

typedef struct node
{
	int data;
	int priority;

	struct node* next;

} Node;

Node* newNode(int d, int p)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = d;
	temp->priority = p;
	temp->next = NULL;

	return temp;
}

//Obtener el valor de mayor prioridad
int top(Node** head)
{
	return (*head)->data;
}

//elimina el valor de menor prioridad de la Queue (pop back)
void pop(Node** head)
{
	Node* temp = *head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->data = NULL;
	values--;
}

// agrega un nuevo valor a la Queue en la posición acorde a su prioridad
void push(Node** head, int d, int p)
{
	Node* aux = (*head);
	Node* temp = newNode(d, p);
	
	// El nuevo nodo es más prioritario que el antiguo --> actualizar priordad
	if ((*head)->priority > p)
	{
		// Inserta New Node antes del head
		temp->next = *head;
		(*head) = temp;
	}
	else
	{
		//Recorre la lista hasta encontrar el lugar adecuado para el nuevo elemento
		while (aux->next != NULL && aux->next->priority < p)
		{
			aux = aux->next;
		}
		// Se realiza el cambio de valores para respetar la prioridad
		temp->next = aux->next;
		aux->next = temp;
	}
	values++;
}

//revisar si la Queuecola ya no tiene elementos
bool isEmpty(Node** head)
{
	return (*head) == NULL;
}

//Encuentra un elemento en la PQ
int find(Node** head, int d)
{
  Node *it = *head;
  for (int i = 0; i<values; i++)
  {
    if (it->data == d)
    {
      cout << "Elemento encontrado en la posicion: " << i << endl;
      return i;
    }
    it = it->next;
  }
  cout << "Elemento no fue encontrado. " << endl;
  return -1;
}

//impresion de la Queue
void print(Node** head)
{
	Node* i = *head;
	cout << "Priority: "<<endl;
	for (int x = 0; x <= values; x++)
	{
		cout << i->priority << " ";
		i = i->next;
	}
	cout << endl;
	i = *head;
	cout << "Values: "<<endl;
	for (int x = 0; x <= values; x++)
	{
		cout << i->data<<" ";
		i = i->next;
	}
	cout << endl;
}

int main()
{
	int opt;
	cout << "Ingrese la opcion que desea realizar: "<<endl;
	
	cout << "1. Muestra de una lista y sus funciones push, pop, top, print." <<endl;
	cout << "2. Tiempos de inserción de 100, 1000, 10 000 elementos." << endl;
	
	cin>> opt;
	
	switch(opt)
	{
		case (1):
		{
			cout << "Lista: " << endl;
			cout << "4 -> 11 -> 2 -> 8 -> 14 -> 27" << endl;
			Node* pq = newNode(4, 0);
		  	push(&pq,27,5);
		  	push(&pq,8,3);
		  	push(&pq,11,1);
		  	push(&pq,2,2);
		  	push(&pq,14,4);
			print(&pq);
			cout << "==============" << endl;
			cout << "Delete: "<<endl;
			cout << "==============" << endl;
			pop(&pq);
			print(&pq);
			cout << "==============" << endl;
			cout <<" Highest priority value: " << endl;
			cout << "==============" << endl;
			cout << top(&pq)<<endl;
			cout << "==============" << endl;
			cout <<" Find value 11 in pos: " << endl;
			cout << "==============" << endl;
			find(&pq,11);
			cout << "==============" << endl;
			cout <<" Find value 27 in pos: " << endl;
			cout << "==============" << endl;
			find(&pq,27);
			break;
		}
		case (2):
		{
			auto start1 = chrono::steady_clock::now(); 
		  	Node* pq1 = newNode(4, 0);
		  	srand(time(NULL));
		  
		  	for (int i = 1; i <= 100; i++) 
		  	{
		    	push(&pq1,rand()%200,i);
		  	}
		  	auto stop1 = chrono::steady_clock::now();
		  	cout << "Insert 100 elem.: "<<chrono::duration_cast<chrono::microseconds>(stop1 -start1).count()<< " microsec." << endl;
		 
			auto start2 = chrono::steady_clock::now(); 
		  	Node* pq2 = newNode(4, 0);
		  	srand(time(NULL));
		  	for (int i = 1; i <= 1000; i++) 
		  	{
		  	  push(&pq2,rand()%2000+1,i);
		  	}
		  	auto stop2 = chrono::steady_clock::now(); 
		  	cout << "Insert 1000 elem.: "<<chrono::duration_cast<chrono::microseconds>(stop2 -start2).count()<< " microsec." << endl;
		
		  	auto start3 = chrono::steady_clock::now(); 
		  	Node* pq3 = newNode(4, 0);
		  	srand(time(NULL));
		  	for (int i = 1; i <= 10000; i++) 
		  	{
		    	push(&pq3,rand()%20000+1,i);
		  	}
		  	auto stop3 = chrono::steady_clock::now(); 
		  	cout << "Insert 10 000 elem.: "<<chrono::duration_cast<chrono::microseconds>(stop3 -start3).count()<< " microsec. " << endl;
		  	
		  	auto start4 = chrono::steady_clock::now(); 
		  	Node* pq4 = newNode(4, 0);
		  	srand(time(NULL));
		  	for (int i = 1; i <= 100000; i++) 
		  	{
		    	push(&pq4,rand()%200000+1,i);
		  	}
		  	auto stop4 = chrono::steady_clock::now(); 
		  	cout << "Insert 100 000 elem.: "<<chrono::duration_cast<chrono::microseconds>(stop4 -start4).count()<< " microsec. " << endl;
		  	
		  	break;
		}
	}

	return 0;
}
