#include "pila.h"

using namespace std;

namespace photos{
	
	pila::pila(){
		testa=0;
		sz=0;
		
	}
	
	pila::pila(const char* filename){
		//inizializzo la pila da file
		ifstream in;
		in.open(filename,ios::binary);
		if(in.fail()) exit(6); //sostituire con eccezzione
		T e;
		int dim = 5;
		int i=0;
		while(i<dim){
			e.deserialize(in);
			if(push(e)){
			cout << "inserimento riuscito!\n";
			sz++;
			i++;
			}else break;
		}
		in.close();
	}
	
	bool pila::push(const T & e){
		if(full()) return false;
		Nodo* node = new Nodo;
		node->elem=e;
		node->next=testa;
		testa=node;
		return true;
	}
	
	bool pila::pop(T & e){
		if(empty()) return false;
		e=testa->elem;
		Nodo* temp=testa;
		testa=testa->next;
		delete temp;
		return true;
	}
	
	
	bool pila::top(T & e)const{
		if(empty()) return false; //lanciare un eccezione
		e=testa->elem;
		return true;
	}
	
	pila::~pila(){
		Nodo * t=0;
		while(!testa){
			t=testa;
			delete t;
			testa=testa->next;
		}
	}
	
	void pila::save_file(const char* filename)const{
		ofstream of;
		of.open(filename, ios::binary);
		if(of.fail()) exit(5); //eccezzione
		Nodo* t=testa;
		while(t){
			t->elem.serialize(of);
			t=t->next;
		}
		of.close();
	}
	
	void pila::stampa()const{
		Nodo* t;
		t=testa;
		while(t){
			cout << t->elem << endl;
		}
	}
	
	
}
